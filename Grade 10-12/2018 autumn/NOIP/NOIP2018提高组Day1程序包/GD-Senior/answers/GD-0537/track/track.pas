const
  maxn=30010;
  maxm=70000;
  inf='track.in';
  ouf='track.out';
var
  a,du,lea,dep,lg,fa,dis:array[0..maxn]of longint;
  v:array[1..maxn]of boolean;
  e:array[1..maxm,1..2]of longint;
  sum:longint;
  last,next:array[1..maxm]of longint;
  f:array[0..maxn,0..30]of longint;
  n,m,i,x,y,j,ans:longint;

procedure add(x,y,z:longint);
begin
  inc(sum);
  e[sum,1]:=y;e[sum,2]:=z;
  next[sum]:=last[x];
  last[x]:=sum;
end;

procedure build(x,y:longint);
var
  i:longint;
begin
  i:=last[x];dep[x]:=y; v[x]:=true;
  while i<>0 do
  begin
    if not v[e[i,1]] then
    begin
      dis[e[i,1]]:=dis[x]+e[i,2];
      fa[e[i,1]]:=x;
      inc(du[x]);
      build(e[i,1],y+1);
    end;
    i:=next[i];
  end;
end;

procedure st;
var
  i,j:longint;
begin
  for i:=1 to n do
    f[i,0]:=fa[i];
  for j:=1 to 30 do
    for i:=1 to n do
      f[i,j]:=f[f[i,j-1],j-1];
end;

function lca(tx,ty:longint):longint;
var
  i,t,k,x,y:longint;
begin
  x:=tx;y:=ty;
  if dep[x]<dep[y] then
  begin
    t:=x;x:=y;y:=t;
  end;
  while dep[x]<>dep[y] do x:=f[x,lg[dep[x]-dep[y]]];
  if x=y then exit(x);
  k:=lg[dep[x]];
  while k>=0 do
  begin
    if f[x,k]<>f[y,k] then
    begin
      x:=f[x,k];y:=f[y,k];
    end;
    dec(k);
  end;
  exit(f[x,0]);
end;

function max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;

function min(a,b:longint):longint;
begin
  if a<b then exit(a) else exit(b);
end;

procedure init;
var
  i,x,y,z,mm:longint;
begin
  readln(n,m);
  mm:=10000000;
  for i:=1 to n-1 do
  begin
    readln(x,y,z);
    add(x,y,z);
    add(y,x,z);
    mm:=min(mm,z);
  end;
  if m=n-1 then
  begin
    writeln(mm);

    close(input);close(output);
    halt;
  end;
  build(1,1);
  for i:=1 to n do
    if du[i]=0 then
    begin
      inc(lea[0]);
      lea[lea[0]]:=i;
    end;
  for i:=1 to n do
    lg[i]:=trunc(ln(i)/ln(2));
  st;
end;

function get(x,y:longint):longint;
var
  k:longint;
begin
  k:=lca(x,y);
  get:=dis[x]+dis[y]-dis[k]*2;
end;


begin
  assign(input,inf);reset(input);
  assign(output,ouf);rewrite(output);
  init;
  for i:=1 to lea[0]-1 do
    for j:=i+1 to lea[0] do
      ans:=max(ans,get(lea[i],lea[j]));
  writeln(ans);
  close(input);close(output);
end.
