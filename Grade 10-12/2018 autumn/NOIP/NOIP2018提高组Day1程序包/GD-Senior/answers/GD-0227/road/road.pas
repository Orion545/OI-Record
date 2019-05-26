const
  maxn=100000;

var
  a:array [0..maxn+1] of longint;
  n:longint;

procedure init;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do
    read(a[i]);
end;

function min(a,b:longint):longint;
begin
  if a<b then
    exit(a);
  exit(b);
end;

procedure main;
var
  i,j,l,r,min1:longint;
  ans:int64;
  flag:boolean;
begin
  flag:=false;
  ans:=0;
  while not flag do
    begin
      flag:=true;
      l:=0;
      while (a[l]=0) and (l<=n) do
        inc(l);
      if l>n then
        break;
      r:=l;
      min1:=maxlongint;
      while a[r]>0 do
        begin
          min1:=min(min1,a[r]);
          inc(r);
          flag:=false;
        end;
      for i:=l to r-1 do
        dec(a[i],min1);
      inc(ans,min1);
    end;
  writeln(ans);
end;

begin
  assign(input,'road.in');reset(input);
  assign(output,'road.out');rewrite(output);
  init;
  main;
  close(input);close(output);
end.
