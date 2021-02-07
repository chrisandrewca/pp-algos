
REM verify the script is being run from the base directory
if "%cd%" neq "C:\codez\pp" (

	REM please run this script from the base directory
	exit
)

if not exist ".\bin" (
	mkdir "bin"
)

cd bin

tcc ^
	I..\include ^
	..\main.c ^
	..\insertion-sort.c ^
	-o pp-tcc.exe

cd ..

REM .\bin\pp.exe aan bbb ccc
.\bin\pp.exe insertion-sort
echo:
echo %errorlevel%