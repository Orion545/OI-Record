const
  maxn=100010;
  inf='road.in';
  ouf='road.out';
var
  a,lg:array[1..maxn]of int64;
  f:array[1..maxn,0..30]of int64;
  mi:array[0..30]of int64;
  n,ans,x,y:int64;
  i:longint;

procedure st;
var
  i,j:longint;
begin
  for i:=1 to n do
    f[i,0]:=i;
  for j:=1 to 30 do
    for i:=1 to n do
    begin
      if i+mi[j]-1>n then break;
      if a[f[i,j-1]]<a[f[i+mi[j-1],j-1]] then f[i,j]:=f[i,j-1]
                                         else f[i,j]:=f[i+mi[j-1],j-1];
    end;
end;

function rmq(l,r:longint):longint;
var
  k:longint;
begin
  k:=lg[r-l+1];
  if a[f[l,k]]<a[f[r-mi[k]+1,k]] then rmq:=f[l,k] else rmq:=f[r-mi[k]+1,k];

end;

procedure init;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    lg[i]:=trunc(ln(i)/ln(2));
  end;
  mi[0]:=1;
  for i:=1 to 30 do
    mi[i]:=mi[i-1]*2;

  st;
end;

procedure dfs(l,r,y:int64);
var
  i,po:longint;
begin
  po:=rmq(l,r);
  ans:=ans+a[po]-y;
  if l=r then exit;
  if po-1>=l then dfs(l,po-1,a[po]);
  if po+1<=r then dfs(po+1,r,a[po]);
end;

begin
  assign(input,inf);reset(input);
  assign(output,ouf);rewrite(output);
  init;
 { readln(t);
  for i:=1 to t do
  begin
    readln(x,y);
    writeln(rmq(x,y));
  end;  }
  dfs(1,n,0);
  writeln(ans);
  close(input);close(output);
end.
