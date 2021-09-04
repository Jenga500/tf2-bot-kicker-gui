/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCheckBox *reminders;
    QCheckBox *messageonjoin;
    QTextBrowser *consoleLog;
    QSpinBox *spinBox;
    QLabel *TimeoutLabel;
    QCheckBox *autokick;
    QSpacerItem *horizontalSpacer;
    QPushButton *startbutton;
    QLineEdit *steamUUID;
    QLabel *TF2DirectoryLabel;
    QLineEdit *directory;
    QToolButton *selectDirectory;
    QLabel *SteamUUIDLabel;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(665, 472);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        reminders = new QCheckBox(centralwidget);
        reminders->setObjectName(QString::fromUtf8("reminders"));

        gridLayout->addWidget(reminders, 5, 0, 1, 4);

        messageonjoin = new QCheckBox(centralwidget);
        messageonjoin->setObjectName(QString::fromUtf8("messageonjoin"));

        gridLayout->addWidget(messageonjoin, 4, 0, 1, 4);

        consoleLog = new QTextBrowser(centralwidget);
        consoleLog->setObjectName(QString::fromUtf8("consoleLog"));

        gridLayout->addWidget(consoleLog, 11, 0, 1, 4);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(999);

        gridLayout->addWidget(spinBox, 8, 3, 1, 1);

        TimeoutLabel = new QLabel(centralwidget);
        TimeoutLabel->setObjectName(QString::fromUtf8("TimeoutLabel"));

        gridLayout->addWidget(TimeoutLabel, 8, 0, 1, 2);

        autokick = new QCheckBox(centralwidget);
        autokick->setObjectName(QString::fromUtf8("autokick"));

        gridLayout->addWidget(autokick, 6, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 8, 2, 1, 1);

        startbutton = new QPushButton(centralwidget);
        startbutton->setObjectName(QString::fromUtf8("startbutton"));

        gridLayout->addWidget(startbutton, 9, 0, 1, 1);

        steamUUID = new QLineEdit(centralwidget);
        steamUUID->setObjectName(QString::fromUtf8("steamUUID"));

        gridLayout->addWidget(steamUUID, 1, 0, 1, 3);

        TF2DirectoryLabel = new QLabel(centralwidget);
        TF2DirectoryLabel->setObjectName(QString::fromUtf8("TF2DirectoryLabel"));

        gridLayout->addWidget(TF2DirectoryLabel, 2, 0, 1, 2);

        directory = new QLineEdit(centralwidget);
        directory->setObjectName(QString::fromUtf8("directory"));

        gridLayout->addWidget(directory, 3, 0, 1, 3);

        selectDirectory = new QToolButton(centralwidget);
        selectDirectory->setObjectName(QString::fromUtf8("selectDirectory"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("folder");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        selectDirectory->setIcon(icon);

        gridLayout->addWidget(selectDirectory, 3, 3, 1, 1);

        SteamUUIDLabel = new QLabel(centralwidget);
        SteamUUIDLabel->setObjectName(QString::fromUtf8("SteamUUIDLabel"));

        gridLayout->addWidget(SteamUUIDLabel, 0, 0, 1, 4);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 12, 0, 1, 4);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Team Fortress 2 bot kicker", nullptr));
        reminders->setText(QCoreApplication::translate("MainWindow", "Continously remind the enemy team of bots in their team until they are kicked", nullptr));
        messageonjoin->setText(QCoreApplication::translate("MainWindow", "Send a message to the enemy team whenever a bot joins their team", nullptr));
        spinBox->setSuffix(QString());
        spinBox->setPrefix(QString());
        TimeoutLabel->setText(QCoreApplication::translate("MainWindow", "Timeout between trying to kick bots:", nullptr));
        autokick->setText(QCoreApplication::translate("MainWindow", "Automatically vote kick bots in your team", nullptr));
        startbutton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        TF2DirectoryLabel->setText(QCoreApplication::translate("MainWindow", "Team Fortress 2 Installation Directory:", nullptr));
        selectDirectory->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        SteamUUIDLabel->setText(QCoreApplication::translate("MainWindow", "Your Steam UUID (Optional. Used to know if bots are in your team):", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Based on <a href=\"https://github.com/Googe14/tf2_bot_kicker\"><span style=\" text-decoration: underline; color:#007af4;\">tf2_bot_kicker by Googe14 </span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
