var
  ans:int64;
  n:longint;
  a:array [0..100001] of longint;
procedure init;
var
  i:longint;
begin
  readln(n);
  a[0]:=0;
  for i:=1 to n do
    read(a[i]);
end;

procedure main;
var
  t:int64;
  i:longint;
begin
  ans:=0;
  for i:=1 to n do
    begin
      t:=a[i]-a[i-1];
      if t>0 then
        ans:=ans+t;
    end;
  writeln(ans);
end;

begin
  assign(input,'road.in');
  assign(output,'road.out');
  reset(input);
  rewrite(output);
  init;
  main;
  close(input);
  close(output);
end.
