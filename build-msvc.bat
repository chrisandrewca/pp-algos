
cls

REM verify the script is being run from the base directory
if "%cd%" neq "C:\codez\pp" (

	REM please run this script from the base directory
	exit
)

if not exist ".\bin" (
	mkdir "bin"
)

cd bin

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvars64.bat"

cl ^
	/Wall ^
	/I ..\include ^
	..\main.c ^
	..\insertion-sort.c ^
	..\merge-sort.c ^
	/link ^
	/out:pp.exe

cd ..

REM .\bin\pp.exe aan bbb ccc
.\bin\pp.exe merge-sort
REM echo:
REM echo %errorlevel%