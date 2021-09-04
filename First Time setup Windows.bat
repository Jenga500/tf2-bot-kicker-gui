@echo off
powershell -Command "& {wget -outf command-line/TF2_Bot_Kicker_Windows.zip https://github.com/Googe14/tf2_bot_kicker/releases/latest/download/TF2_Bot_Kicker_Windows.zip}"
tar -xf command-line/TF2_Bot_Kicker_Windows.zip -C command-line
robocopy command-line\TF2_Bot_Kicker_Windows command-line /S /MOV
rd /s /q command-line\TF2_Bot_Kicker_Windows
del command-line\TF2_Bot_Kicker_Windows.zip
Msg * /W Add ^

bind F7 \"exec command\" ^

to your tf2 autoexec.cfg
Msg * /W Add^

-condebug -conclearlog^

to your tf2 launch options on Steam.
TF2BotKickerGUI.exe
