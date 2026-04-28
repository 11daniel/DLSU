@echo off
set /a delay=%random% %% 5 + 1
timeout /t %delay% /nobreak
echo Here's your random message!
