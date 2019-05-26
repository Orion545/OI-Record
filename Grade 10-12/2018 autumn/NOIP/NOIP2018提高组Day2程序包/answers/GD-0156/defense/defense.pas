var
  i,n,m:longint;
  p,f,v:array[0..2000]of longint;
  s:string;
  a:array[0..2000,0..2000]of boolean;
  c:array[0..2000]of boolean;

function min(a,b:longint):longint;begin if a<b then exit(a); exit(b); end;
function  dfs1(k:longint):longint;
var
  w:longint;
begin
  w:=0;
  if c[k+1] then
    w:=min(p[i],dfs(k-1) )
  else w:=dfs(k-1);
  exit(w);


end;
procedure work;
var
  i,j,t:longint;
  a,x,b,y:longint;
begin
  t:=0;
  readln(a,x,b,y);
  fillchar(v,sizeof(v),0);
  v[a]:=x;v[b]:=y;
  if (x=0)and(y=0)and(a[x,y]) then writeln(-1)
  else
  begin
    if (x=1)and(y=0) then
    begin
      inc(t,p[a]);
      c[a]:=true;
      inc(t,dfs1(a-1));
      inc(t,dfs2(a+1));
    end;
  end;

end;
begin
  assign(input,'defense.in');
  reset(input);
  assign(output,'defense.out');
  rewrite(output);
  readln(n,m,s);
  for i:=1 to n do read(p[i]);
  for i:=1 to n-1 do
  begin
    readln(x,y);
    a[x,y]:=true;
    a[y,x]:=true;
  end;
  for i:=1 to m do work;
  close(output);
  close(input);
end.