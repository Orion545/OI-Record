@echo off
:loop
	DG.exe > in.txt
	DD.exe < in.txt > out.txt
	fc out.txt std.txt
if not errorlevel1 goto loop
pause
goto loop