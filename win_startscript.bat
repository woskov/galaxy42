

:: BatchGotAdmin
:-------------------------------------
::REM  --> Check for permissions
::>nul 2>&1 "%SYSTEMROOT%\system32\cacls.exe" "%SYSTEMROOT%\system32\config\system"

REM --> If error flag set, we do not have admin.
::if '%errorlevel%' NEQ '0' (
::    echo Requesting administrative privileges...
::    goto UACPrompt
::) else ( goto gotAdmin )

::UACPrompt
::    echo Set UAC = CreateObject^("Shell.Application"^) > "%temp%\getadmin.vbs"
::    echo UAC.ShellExecute "%~s0", "", "", "runas", 1 >> "%temp%\getadmin.vbs"

::    "%temp%\getadmin.vbs"
::    exit /B

:gotAdmin
::	c:\Users\galaxy42\tunserver.elf.exe
::    if exist "%temp%\getadmin.vbs" ( del "%temp%\getadmin.vbs" )
::    pushd "%CD%"
::    CD /D "%~dp0"

:--------------------------------------

echo Set UAC = CreateObject^("Shell.Application"^) > "./getadmin.vbs"
echo UAC.ShellExecute "%~s1", "", "", "runas", 1 >> "./getadmin.vbs"
::todo path have to be in 

"./getadmin.vbs"



::c:\Users\galaxy42\tunserver.elf.exe