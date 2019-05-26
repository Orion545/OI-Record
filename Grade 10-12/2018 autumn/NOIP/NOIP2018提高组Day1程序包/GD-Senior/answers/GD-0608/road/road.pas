var
n,m,i,j,k,t,p,now,left,right:longint;
a:array[0..1000000] of longint;
ans:int64;
begin

assign(input,'road.in');
assign(output,'road.out');
reset(input);
rewrite(output);

readln(n);
ans:=0;
for i:=1 to n do read(a[i]);
readln;
if n=1 then
  begin
    writeln(a[1]);
	close(input); close(output);
	halt;
  end;

left:=a[1];
ans:=ans+a[1];
for j:=2 to n do
  begin
    now:=a[j];
	left:=a[j-1];
    if now>left then ans:=ans+now-left else continue;
  end;
writeln(ans);

close(input);
close(output);

end.
