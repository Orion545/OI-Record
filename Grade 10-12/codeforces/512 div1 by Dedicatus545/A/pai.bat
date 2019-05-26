@echo
:loop
	gen.exe > in.in
	A.exe < in.in > my.out
	PR.exe < in.in > std.out
	fc my.out std.out
if not errorlevel 1 goto loop
pause
goto loop
