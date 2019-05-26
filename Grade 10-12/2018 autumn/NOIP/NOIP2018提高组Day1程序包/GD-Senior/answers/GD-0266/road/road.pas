var
  n,i,sum,w,tou,wei:longint;
  a:array[1..100001] of longint;
procedure f(l,r:longint);
var
  i,j,k,min,tou,wei:longint;
begin

  min:=20000;
  for i:=l to r do
    if a[i]<min then min:=a[i];
  sum:=sum+min;
  for i:=l to r do
  begin
    dec(a[i],min);
  end;
  i:=0; tou:=0; wei:=0;

  while i<=r do
  begin
    inc(i);
    if tou=0 then if a[i]<>0 then tou:=i ;
    if (tou<>0) and  (wei=0) then if a[i]=0 then wei:=i-1;

    if (tou<>0) and (wei<>0) then
    begin
      f(tou,wei);
      tou:=0; wei:=0;
    end;
  end;
 end;
begin
  assign(input,'road.in');
  assign(output,'road.out');
  reset(input);
  rewrite(output);

  fillchar(a,sizeof(a),0);
  read(n); sum:=0;
  for i:=1 to n do
    read(a[i]);
  i:=0; tou:=0; wei:=0;
  while i<=n do
  begin
    inc(i);
    if tou=0 then if a[i]<>0 then tou:=i ;
    if (tou<>0) and  (wei=0) then if a[i]=0 then wei:=i-1;

    if (tou<>0) and (wei<>0) then
    begin
      f(tou,wei);
      tou:=0; wei:=0;
    end;
  end;
  writeln(sum);
  close(input); close(output);
end.

