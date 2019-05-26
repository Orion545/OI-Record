@echo off
:loop
	gen > in.txt
	C.exe < in.txt > my.txt
	std.exe < in.txt > std.txt
	fc my.txt std.txt
if not errorlevel 1 goto loop
pause
goto loop