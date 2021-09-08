#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <string>
#include <qmessagebox.h>
#include <iostream>
#include <QFileDialog>
#include <stdio.h>
#include <QProcess>
#include <QObject>
using namespace std;


//Variables
string UUID;
string path;
bool join_alerts = false;
bool chat_reminders = false;
bool kick = false;
int timeout;
QProcess process;

//Functions

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setOpenExternalLinks(true);
    fstream config_file;
    config_file.open("command-line/cfg/settings.cfg", ios::in);
    if(!config_file.is_open())
    {
        QMessageBox::critical(this, "ERROR", "Failed to open config file");
        exit(1);
    }
    string line;
    getline(config_file, line);
    //Read Steam UUID
    getline(config_file, line);
    for (int x = 7;line[x] != 0; x++) {
        UUID += line [x];
    }
    ui->steamUUID->setText(QString::fromStdString(UUID));
    //Read TF2 Directory
    getline(config_file, line);
    for (int x = 16;line[x] != 0; x++) {
        path += line [x];
    }
    ui->directory->setText(QString::fromStdString(path));
    //Read join_alerts
    getline(config_file, line);
    if(line[13] == 't')
    {
        join_alerts = true;
    }
    ui->messageonjoin->setChecked(join_alerts);
    //Read chat_reminders
    getline(config_file, line);
    if(line[17] == 't')
    {
        chat_reminders = true;
    }
    ui->reminders->setChecked(chat_reminders);
    //Read kick
    getline(config_file, line);
    if(line[7] == 't')
    {
        kick = true;
    }
    ui->autokick->setChecked(kick);
    //Read timeout
    string cache;
    getline(config_file, line);
    for (int x = 9;line[x] != 0; x++) {
        cache += line [x];
    }
    config_file.close();
    timeout = stoi(cache);
    ui->spinBox->setValue(timeout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectDirectory_clicked()
{
    ui->directory->setText(QFileDialog::getExistingDirectory(this, "Open Team Fortress 2 Folder"));
}

void MainWindow::on_startbutton_clicked()
{
    if(process.processId() == 0)
    {
    UUID = ui->steamUUID->text().toStdString();
    path = ui->directory->text().toStdString();
    join_alerts = ui->messageonjoin->isChecked();
    chat_reminders = ui->reminders->isChecked();
    kick = ui->autokick->isChecked();
    timeout = ui->spinBox->value();
    fstream config_file;
    config_file.open("command-line/cfg/settings.cfg", ios::out);
    config_file << "# (optional) uuid of user (to not try and kick bots on enemy team)" << endl
                << "user = " << UUID << endl << "tf2_directory = " << path << endl
                << "join_alert = " << (join_alerts?"true":"false") << endl
                << "chat_reminders = " << (chat_reminders?"true":"false") << endl
                << "kick = " << (kick?"true":"false") << endl
                << "period = " << timeout;
    config_file.close();
    ui->startbutton->setText("Stop");
    process.setWorkingDirectory("command-line");
#ifdef _WIN32
    process.setProgram("tf2_bot_kicker.exe");
#else
    process.setProgram("./tf2_bot_kicker");
#endif
    process.setProcessChannelMode(QProcess::MergedChannels);
    connect(&process, SIGNAL(readyRead()), SLOT(readData()));
    process.start();
    process.waitForStarted();
    }
    else {
        process.close();
        ui->startbutton->setText("Start");
        ui->consoleLog->append("Stopped.");
    }

}
void MainWindow::readData()
{
    ui->consoleLog->append(process.readAll());
}
