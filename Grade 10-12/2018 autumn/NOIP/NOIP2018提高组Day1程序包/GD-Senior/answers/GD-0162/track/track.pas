//rv-3 - Die gedanken sind frei
const
  maxn=1000;
type
  node=record
    dst,l:longint;
    flag:boolean;
  end;
var
  n,m,i,j,k,l,x,y,ans,cnt:longint;
  r:array[1..maxn,1..maxn] of node;
  cr:array[1..maxn] of longint;
  f:array[1..maxn,1..maxn] of boolean;
  d:array[1..maxn,1..maxn] of longint;

procedure dfs(x,v,mnt,dp:longint);
var
  i,j,mtp:longint;
begin
  inc(cnt);
  if cnt>40000000 then exit;
  if (mnt<maxlongint)and(ans>0)and(mnt<ans) then exit;
  if dp>m then
  begin
    if (mnt>ans)and(mnt<maxlongint) then
    begin
      ans:=mnt;
    end;
    exit;
  end;
  for i:=1 to cr[x] do
  begin
    if not f[x,r[x,i].dst] then
    begin
      f[x,r[x,i].dst]:=true; f[r[x,i].dst,x]:=true;
      dfs(r[x,i].dst,v+r[x,i].l,mnt,dp);
      f[x,r[x,i].dst]:=false; f[r[x,i].dst,x]:=false;
    end;
    for j:=1 to n do
      if v<mnt then dfs(j,0,v,dp+1)
      else
        dfs(j,0,mnt,dp+1);
  end;
end;

procedure iroute(vx,vy,len:longint);
begin
  inc(cr[vx]);
  r[vx,cr[vx]].dst:=vy;
  r[vx,cr[vx]].l:=len;
end;

begin
  assign(input,'track.in');
  assign(output,'track.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  ans:=maxlongint;
  for i:=1 to n-1 do
  begin
    readln(x,y,l);
    iroute(x,y,l); iroute(y,x,l);
    d[x,y]:=l; d[y,x]:=l;
    if l<ans then ans:=l;
  end;
  for i:=1 to n do dfs(i,0,maxlongint,1);
  writeln(ans);
  close(input);
  close(output);
end.