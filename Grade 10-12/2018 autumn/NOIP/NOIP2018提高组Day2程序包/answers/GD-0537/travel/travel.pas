const
  maxn=6000;
  maxm=maxn*2;
  inf='travel.in';
  ouf='travel.out';

type
  arr=array[0..maxn]of longint;

var
  a,ans:array[0..maxn]of longint;
  last,next,e:array[1..maxm]of longint;
  n,m,now,i,j,sum:longint;
  heap:array[0..maxn*4]of longint;
  v:array[1..maxn]of boolean;

procedure add(x,y:longint);
begin
  inc(sum);
  e[sum]:=y;
  next[sum]:=last[x];
  last[x]:=sum;
end;

procedure swap(var x,y:longint);
var
  t:longint;
begin
  t:=x;x:=y;y:=t;
end;

procedure init;
var
  i,x,y:longint;
begin
  readln(n,m);
  for i:=1 to m do
  begin
    readln(x,y);
    add(x,y);
    add(y,x);
  end;
end;

function min(a,b:longint):longint;
begin
  if a<b then exit(a) else exit(b);
end;

procedure dfs(x:longint);
var
  i,k:longint;
begin
  v[x]:=true;write(x,' ');


  while true do
  begin
    i:=last[x];
    k:=maxlongint;
    while i<>0 do
    begin
      if not v[e[i]] then k:=min(e[i],k);
      i:=next[i];
    end;
    if k=maxlongint then break;
    if not v[k] then dfs(k);
  end;
end;

begin
  assign(input,inf);reset(input);
  assign(output,ouf);rewrite(output);
  init;
  dfs(1);
  close(input);close(output);
end.
