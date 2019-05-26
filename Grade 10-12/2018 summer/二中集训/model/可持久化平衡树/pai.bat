@echo off
:loop
	data.exe > in.in
	可持久化平衡树.exe < in.in > my.out
	std.exe < in.in > std.out
	fc my.out std.out
if not errorlevel 1 goto loop
pause 
goto loop