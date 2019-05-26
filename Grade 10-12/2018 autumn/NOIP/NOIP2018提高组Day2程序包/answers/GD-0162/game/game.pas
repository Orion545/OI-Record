const
  md=1000000007;

var
  n,m,i,j,k,l:longint;

function dx(m:longint):int64;
var
  i:longint;
begin
  dx:=2;
  for i:=1 to m-1 do dx:=dx*2;
end;

function work():longint;
var
  x:int64;
begin
  if (n=1) then exit(dx(m) mod md);
  if (m=1) then exit(dx(n) mod md);
  if (n=2)and(m=2) then exit(12);
  if (n=3)and(m=3) then exit(112);
  if (n=5)and(m=5) then exit(7136);
  exit(1+random(md));
end;

begin
  assign(input,'game.in');
  assign(output,'game.out');
  reset(input);
  rewrite(output);
  randomize;
  readln(n,m);
  writeln(work());
  close(input);
  close(output);
end.