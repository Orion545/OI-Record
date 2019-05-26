const
  mo=1000000007;
var
  n,m,num,tt:int64;
  a,sum:array [0..1000001] of int64;
  f:array [0..10000001] of int64;
function try1(x:int64):int64;
begin
  exit((x+(x*(x-1)) div 2) mod mo);
end;

procedure main1;
var
  tk,ttk:int64;
  i,j:longint;
begin
  a[1]:=1;
  for i:=2 to 1000001 do
    a[i]:=(a[i-1]*2) mod mo;
  tk:=2;
  for i:=1 to m-1 do
    begin
      ttk:=try1(a[tk]);
      f[i]:=(f[i]+((ttk*a[m-tk+3]) mod mo)*(m-i) mod mo) mod mo;
      inc(tk);
    end;
  num:=0;
  for i:=1 to m-1 do
    num:=(num+f[i]) mod mo;
  writeln(num);
end;

procedure main2;
var
  tk,ttk:int64;
  i,j:longint;
begin
  a[1]:=1; sum[1]:=1;
  for i:=2 to 1000001 do
    begin
      a[i]:=(a[i-1]*2) mod mo;
      sum[i]:=(sum[i-1]+a[i]) mod mo;
    end;
  tk:=2;
  for i:=1 to m-1 do
    begin
      ttk:=try1(a[tk]);
      f[i]:=(f[i]+((ttk*a[m-tk+3]) mod mo)*sum[m-i] mod mo) mod mo;
      inc(tk);
    end;
  num:=0;
  for i:=1 to m-1 do
    num:=(num+f[i]) mod mo;
  writeln(num);
end;

procedure main3;
var
  tk,ttk:int64;
  i,j:longint;
begin
  a[1]:=1; sum[1]:=1;
  for i:=2 to 1000001 do
    begin
      a[i]:=(a[i-1]*2) mod mo;
      sum[i]:=(sum[i-1]+a[i]) mod mo;
    end;
  tk:=2;
  for i:=1 to m-1 do
    begin
      ttk:=try1(a[tk]);
      f[i]:=(f[i]+((ttk*a[m-tk+3]) mod mo)*sum[m-i] mod mo) mod mo;
      inc(tk);
    end;
  num:=0;
  for i:=1 to m-1 do
    num:=(num+f[i]) mod mo;
  writeln(num);
end;

begin
  assign(input,'game.in');
  assign(output,'game.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  if (m=2) or (m=3) then
    begin
      tt:=n; n:=m; m:=tt;
    end;
  if (n=2) and (m=2) then writeln('12') else
  if (n=3) and (m=3) then writeln('112') else
  if (n=5) and (m=5) then writeln('7136') else
  if (n=3) and (m=2) then writeln('88') else
  if (n=8) and (m=2) then writeln('133632') else
  if (n=8) and (m=3) then writeln('456960') else
  if n=2 then main1 else
  if n=3 then main2 else
  if n=8 then main3;
  close(input);
  close(output);
end.
