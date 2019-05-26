@echo off
:loop
	F.exe > in.in
	E.exe < in.in > my.out
	D.exe <in.in > std.out
	fc my.out std.out
if not errorlevel 1 goto loop
pause
goto loop