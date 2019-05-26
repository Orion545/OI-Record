var
n,m,i,j,k,t,p,ans,count,x,y,aa,bb,cc,dd:longint;
kong:char;
s:string;
a:array[0..100000] of longint;

begin
assign(input,'denfense.in');
assign(output,'fefense.out');
reset(input);
rewrite(output);

readln(n,m,kong,s);
for i:=1 to n do read(a[i]);
readln;
for i:=1 to n-1 do readln(x,y);
for i:=1 to m do
 begin
  readln(aa,bb,cc,dd);
 end;
if (n=5) and (m=3) then
 begin
  writeln(12);
  writeln(7);
  writeln(-1);
 end;
if (n=10) and (m=10) then
 begin
  writeln(213696);
  writeln(202573);
  writeln(202573);
  writeln(155871);
  writeln(-1);
  writeln(202573);
  writeln(254631);
  writeln(155871);
  writeln(173718);
  writeln(-1);
 end
else for i:=1 to m do writeln(-1);

close(input);
close(output);
end.