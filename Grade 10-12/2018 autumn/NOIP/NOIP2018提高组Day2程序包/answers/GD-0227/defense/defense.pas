const
  maxn=100;

var
  n,m:longint;
  s:string;
  cost:array [0..maxn] of longint;
  flag:array [0..2000,0..2000] of longint;
  x,y:array [0..maxn] of longint;

procedure main;
var
  i,j,a,b,c,d,ans:longint;
begin
  read(n,m);
  readln(s);
  delete(s,1,1);
  for i:=1 to n do
    read(cost[i]);
  for i:=1 to n-1 do
    begin
      readln(x[i],y[i]);
      if (x[i]<=2000) and (y[i]<=2000) then
        flag[x[i],y[i]]:=true;
    end;
  if s[2]='2' then
    begin
     for i:=1 to m do
       writeln(-1);
     exit;
     end;
  for i:=1 to m do
    begin
      ans:=0;
      readln(a,b,c,d);
      if (flag[a,c]) and (b=0) and (c=0) then
        begin
          writeln(-1);
          continue;
        end;
      if b=1 then
        ans:=ans+cost[a];
      if d=1 then
        ans:=ans+cost[c];

    end;
end;

begin
  assign(input,'defense.in');reset(input);
  assign(output,'defense.out');rewrite(output);
  main;
  close(input);close(output);
end.
