#!/bin/bash
rm -r command-line/*
wget https://github.com/Googe14/tf2_bot_kicker/releases/latest/download/TF2_Bot_Kicker_Linux.zip -P command-line
unzip command-line/TF2_Bot_Kicker_Linux.zip -d command-line
mv command-line/TF2_Bot_Kicker_Linux/* command-line/
rmdir command-line/TF2_Bot_Kicker_Linux/
rm command-line/TF2_Bot_Kicker_Linux.zip
kdialog --msgbox "Add<b> bind F7 \"exec command\" </b>to your tf2 autoexec.cfg"
kdialog --msgbox "Add <b>-condebug -conclearlog</b> to your tf2 launch options on Steam."
chmod a+x command-line/tf2_bot_kicker
./TF2BotKickerGUI
