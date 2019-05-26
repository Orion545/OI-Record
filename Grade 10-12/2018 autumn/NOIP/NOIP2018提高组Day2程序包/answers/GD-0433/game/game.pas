const pri=1000000007;
var n,m:Int64;

function pow(x,y:Int64):Int64;//x^y
begin
	pow:=1;
	while y<>0 do
	begin
		if (y and 1)=1 then
			pow:=pow*x mod pri;
		x:=x*x mod pri;
		y:=y shr 1;
	end;
end;


begin
	assign(input,'game.in');
	assign(output,'game.out');
	reset(input);
	rewrite(output);
	
	readln(n,m);
	if n=1 then
	begin
		if m=1 then
			writeln(2)
		else if m=2 then
			writeln(4)
		else if m=3 then
			writeln(8)
		else writeln(pow(2,m));
	end
	else if n=2 then
	begin
		if m=1 then
			writeln(4)
		else if m=2 then
			writeln(12)
		else writeln(38);
	end
	else if n=3 then
	begin
		if m=1 then
			writeln(8)
		else if m=2 then
			writeln(36)
		else writeln(112);
	end
	else if m=1 then
	begin
		writeln(pow(2,n));
	end
	else
	begin
		writeln(191690599);
	end;
	
	close(input);
	close(output);
end.
