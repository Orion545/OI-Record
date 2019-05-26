@echo off
:loop
	gen.exe > in.in
	t1.exe < in.in > my.out
	ggq.exe < in.in > ggq.out
	fc my.out ggq.out
if not errorlevel 1 goto loop
pause
goto loop