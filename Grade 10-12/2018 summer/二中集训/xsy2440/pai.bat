@echo off
:loop
	gen.exe > in.in
	std.exe < in.in > std.out
	Zootopia.exe < in.in > my.out
	fc std.out my.out
if not errorlevel 1 goto loop
pause
goto loop
