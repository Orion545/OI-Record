@echo off
:loop
	gen.exe > in.in
	C.exe < in.in > std.out
	CC.exe < in.in > my.out
	fc std.out my.out
if not errorlevel 1 goto loop
pause
goto loop