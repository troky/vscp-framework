@echo off

rem ********************************************************************************
rem Author: Andreas Merkle, http://www.blue-andi.de
rem ********************************************************************************

rem GNU32 tools
set SED=..\gnu32\sed.exe
set EXPAND=..\gnu32\expand.exe

echo Generate VSCP events ...
java -jar ../xslt/saxon/saxon9he.jar -s:../vscp-protocol/vscp-protocol.xml -xsl:vscp-protocol2vscp-events.xsl
if not %ERRORLEVEL% == 0 (
pause
)

rem Convert unix to windows line endings
echo Convert line endings ...
%SED% -i "s/$//" vscp_evt_*

rem Convert tabs to spaces
echo Convert tabs to spaces ...
for /f "delims=" %%a in ('dir /b /a-d "*.h"') do (
    %EXPAND% -t 4 %%a > temp.tmp
    type temp.tmp > %%a
)
for /f "delims=" %%a in ('dir /b /a-d "*.c"') do (
    %EXPAND% -t 4 %%a > temp.tmp
    type temp.tmp > %%a
)

rem Remove temporary files
del temp.tmp
del /Q sed*

rem Copy generated files to project
copy /Y vscp_evt_* ..\..\vscp\events

del /Q vscp_evt_*
