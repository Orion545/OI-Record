const
  maxn=100010;
  maxm=maxn*2;
  inf='defense.in';
  ouf='defense.out';
var
  a,fa:array[1..maxn]of longint;
  f,g:array[1..maxn,0..1]of int64;
  e,last,next:array[1..maxm]of longint;
  v,lea:array[1..maxn]of boolean;
  n,m,i,x,y:longint;
  x1,y1,x2,y2:longint;
  ans,sum:int64;

procedure add(x,y:longint);
begin
  inc(sum);
  e[sum]:=y;
  next[sum]:=last[x];
  last[x]:=sum;
end;

procedure build(x:longint);
var
  i:longint;
begin
  i:=last[x];v[x]:=true;
  while i<>0 do
  begin
    if not v[e[i]] then
    begin
      fa[e[i]]:=x;
      v[e[i]]:=true;
      build(e[i]);
    end;
    i:=next[i];
  end;
end;

function min(a,b:longint):longint;
begin
  if a<b then exit(a) else exit(b);
end;

procedure dfs(x:longint);
var
  i,sum,flag,kk:longint;
begin
  i:=last[x];v[x]:=true;
  flag:=0;sum:=0;
  while i<>0 do
  begin
    if not v[e[i]] then
    begin
      dfs(e[i]);
      sum:=sum+min(f[e[i],1],f[e[i],0]);
      flag:=1;
    end;
    i:=next[i];
  end;
  if flag=0 then
  begin
    f[x,0]:=0;f[x,1]:=a[x];
    lea[x]:=true;
    exit;
  end;
  f[x,1]:=a[x];
  i:=last[x];
  while i<>0 do
  begin
    if e[i]=fa[x] then
    begin
      i:=next[i];
      continue;
    end;
    f[x,1]:=f[x,1]+min(f[e[i],1],f[e[i],0]);
    kk:=min(f[e[i],1],f[e[i],0]);
    if lea[e[i]] then f[x,0]:=min(f[x,0],sum+f[e[i],1])
                 else f[x,0]:=min(f[x,0],sum-kk+f[e[i],1]);
    i:=next[i];
  end;
end;

procedure init;
var
  i:longint;
  ch:char;
begin
  read(n,m);
  read(ch);
  read(ch);
 // read(ch);
  readln;
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n-1 do
  begin
    readln(x,y);
    add(x,y);add(y,x);
  end;
  build(1);
  fillchar(v,sizeof(v),false);
//  fillchar(f,sizeof(f),$7f div 3);

end;

procedure clean;
var
  i:longint;
begin
  for i:=1 to n do
  begin
    g[i,0]:=maxlongint div 3;
    g[i,1]:=maxlongint div 3;
  end;
end;

procedure dfs1(x,x1,y1,x2,y2:longint);
var
  i,flag,kk,hh:longint;
  sum:int64;
begin
  i:=last[x];v[x]:=true;
  flag:=0;sum:=0;
  while i<>0 do
  begin
    if not v[e[i]] then
    begin
      dfs1(e[i],x1,y1,x2,y2);
      sum:=sum+min(g[e[i],1],g[e[i],0]);
      flag:=1;
    end;
    i:=next[i];
  end;
  if flag=0 then
  begin
    g[x,0]:=0;g[x,1]:=a[x];
    lea[x]:=true;
    if x=x1 then g[x1,1-y1]:=maxlongint div 3;
    if x=x2 then g[x2,1-y2]:=maxlongint div 3;
    exit;
  end;
  g[x,1]:=a[x];
  i:=last[x];hh:=0;
  while i<>0 do
  begin
    if e[i]=fa[x] then
    begin
      i:=next[i];
      continue;
    end;
    g[x,1]:=g[x,1]+min(g[e[i],1],g[e[i],0]);
    kk:=min(g[e[i],1],g[e[i],0]);
    if (lea[e[i]])and(g[e[i],0]=0) then hh:=hh+g[e[i],1]
                 else g[x,0]:=min(g[x,0],sum-kk+g[e[i],1]);
    if (g[x,0]>10000000)and(hh<>0) then g[x,0]:=0;
    g[x,0]:=g[x,0]+hh;
    i:=next[i];
  end;
  if x=x1 then g[x1,1-y1]:=maxlongint div 3;
  if x=x2 then g[x2,1-y2]:=maxlongint div 3;
end;


begin
  assign(input,inf);reset(input);
  assign(output,ouf);rewrite(output);
  init;
  for i:=1 to m do
  begin
    readln(x1,y1,x2,y2);
    clean;
    fillchar(v,sizeof(v),false);
    dfs1(1,x1,y1,x2,y2);
    ans:=min(g[1,0],g[1,1]);
    if ans<100000000 then writeln(min(g[1,0],g[1,1]))
    else writeln(-1);
  end;
  close(input);close(output);
end.























