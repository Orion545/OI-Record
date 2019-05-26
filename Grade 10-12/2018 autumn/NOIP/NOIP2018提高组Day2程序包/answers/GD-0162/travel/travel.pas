//rv-3 decp
type
  arr=array[0..500] of longint;
var
  n,m,i,j,k,x,y,stp,csq:longint;
  a:array[1..500] of arr;
  ix,rem:longint;
  f,seq,asq,pnt:array[1..500] of longint;
  flag:array[1..500] of boolean;
  ans:string;
  gf:boolean;

procedure sort(l,r:longint;var va:arr);
var
  i,j,x,y:longint;
begin
  i:=l;
  j:=r;
  x:=va[(l+r) div 2];
  repeat
    while va[i]<x do inc(i);
    while x<va[j] do dec(j);
    if not(i>j) then
    begin
      y:=va[i];
      va[i]:=va[j];
      va[j]:=y;
      inc(i);
      j:=j-1;
    end;
  until i>j;
  if l<j then sort(l,j,va);
  if i<r then sort(i,r,va);
end;

procedure append(v1,v2:longint);
begin
  inc(a[v1,0]); a[v1,a[v1,0]]:=v2;
  if not flag[v1] then
  begin
    inc(ix);
    f[ix]:=v1;
    flag[v1]:=true;
  end;
end;

function min(a,b:longint):longint;
begin
  if a<b then exit(a)
  else
    exit(b);
end;

procedure nxt(var x:longint);
begin
  inc(x);
  if x>5000 then x:=1;
end;

procedure upd;
var
  i:longint;
  s,ts:string;
begin
  s:='';
  for i:=1 to n do
  begin
    str(seq[i],ts);s:=s+ts+' ';
  end;
  if (s<ans)or(ans='') then
  begin
    ans:=s;
    asq:=seq;
  end;
end;

procedure dfs(x,v:longint);
var
  i:longint;
begin
  flag[x]:=true;
  seq[v]:=x;
  for i:=1 to a[x,0] do
  begin
    if (not flag[a[x,i]]) then
    begin
      //gf:=false;
      dfs(a[x,i],v+1);
    end;
  end;
  if v=n then upd;
  flag[x]:=false;
end;

begin
  assign(input,'travel.in');
  assign(output,'travel.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  stp:=maxlongint;
  for i:=1 to m do
  begin
    readln(x,y);
    append(x,y); append(y,x);
    stp:=min(min(x,stp),y);
  end;
 { for i:=1 to ix do
    sort(1,a[i,0],a[i]);}
  fillchar(flag,sizeof(flag),false);
  flag[stp]:=true;
  rem:=n-1;
  dfs(stp,1);
  {head:=1; tail:=2; f[head]:=stp; flag[stp]:=true;
  while (head<>tail) do
  begin
    if tail=-1 then tail:=1;
    inc(csq);
    seq[csq]:=f[head];
    for i:=1 to a[f[head],0] do
    begin
      if not flag[a[f[head],i]] then
      begin
        f[tail]:=a[f[head],i];
        flag[a[f[head],i]]:=true;
        nxt(tail);
      end;
    end;
    nxt(head);
  end;    }
  //for i:=1 to n do write(seq[i],' ');
  writeln(ans);
  close(input);
  close(output);
end.
