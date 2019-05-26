const
  maxn=1000;
  p=1000000007;
  dx:array [1..2] of longint=(1,0);
  dy:array [1..2] of longint=(0,1);

var
  c:array [0..maxn,0..maxn] of longint;
  two:array [0..maxn*maxn] of longint;
  n,m,temp:longint;

procedure init;
begin
  readln(n,m);
end;

procedure main;
var
  i,j,ans:longint;
begin
  ans:=0;
  if n>m then
    begin
      i:=n;
      n:=m;
      m:=i;
    end;
  if n=1 then
    begin
      two[0]:=1;
      for i:=1 to m do
        two[i]:=(two[i-1]*2) mod p;
      writeln(two[m]);
    end;
  if n=2 then
    begin
      temp:=(n-1)*(m-1);
      two[0]:=1;
      for i:=1 to temp do
        two[i]:=(two[i-1]*2) mod p;
      c[0,1]:=1;
      for i:=1 to temp do
        c[i,0]:=1;
      for i:=1 to maxn do
        for j:=1 to i do
          c[i,j]:=(c[i-1,j]+c[i-1,j-1]) mod p;
      for i:=0 to temp do
        ans:=(ans+(c[temp,i]*two[i] mod p)) mod p;
      writeln(ans*4);
    end;
  if n>2 then
    begin
      temp:=(n-1)*(m-1);
      two[0]:=1;
      for i:=1 to temp do
        two[i]:=(two[i-1]*2) mod p;
      for i:=1 to m do
        ans:=ans+two[temp-i+1];
      writeln(ans*4);
    end;
end;

begin
  assign(input,'game.in');reset(input);
  assign(output,'game.out');rewrite(output);
  init;
  main;
  close(input);close(output);
end.
