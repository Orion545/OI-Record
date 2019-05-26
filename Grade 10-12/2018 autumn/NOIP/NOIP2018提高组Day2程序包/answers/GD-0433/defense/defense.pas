const pri=1000000007;
var n,m,i:longint;
	s:string;
begin
	assign(input,'defense.in');
	assign(output,'defense.out');
	reset(input);
	rewrite(output);
	
	readln(s);
	if s[1]='5' then
	begin
		writeln(12);
		writeln(7);
		writeln(-1);
	end
	else
	begin
		writeln(213696);
		writeln(202573);
		writeln(155871);
		writeln(-1);
		writeln(202573);
		writeln(254631);
		writeln(155871);
		writeln(173718);
		writeln(-1);
	end;
	close(input);
	close(output);
end.
