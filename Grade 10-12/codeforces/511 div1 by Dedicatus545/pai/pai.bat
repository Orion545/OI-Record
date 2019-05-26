@echo off
:loop
	gen.exe > in.in
	aa.exe < in.in > std.out
	bb.exe < in.in > my.out
	fc my.out std.out
if not errorlevel 1 goto loop
pause
goto loop
