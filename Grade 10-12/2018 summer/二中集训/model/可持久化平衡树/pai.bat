@echo off
:loop
	data.exe > in.in
	�ɳ־û�ƽ����.exe < in.in > my.out
	std.exe < in.in > std.out
	fc my.out std.out
if not errorlevel 1 goto loop
pause 
goto loop