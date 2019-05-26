type
  arr=record
    y,w,next:longint;
  end;
var
  sumt,sumk,sum,max,ans:int64;
  n,m,nm:longint;
  bo1,bo2:boolean;
  a:array [0..1000001] of arr;
  ls,wt,bo:array [0..500001] of longint;
procedure add(x,y,w:longint);
begin
  inc(nm);
  a[nm].y:=y; a[nm].w:=w;
  a[nm].next:=ls[x]; ls[x]:=nm;
end;

function min(o,p:longint):longint;
begin
  if o<p then exit(o);
  exit(p);
end;

procedure qsort(l,r:longint);
var
  mid,i,j,t:longint;
begin
  if l>r then exit;
  i:=l; j:=r;
  mid:=wt[(l+r) div 2];
  repeat
    while wt[i]>mid do inc(i);
    while wt[j]<mid do dec(j);
    if i<=j then
      begin
        t:=wt[i]; wt[i]:=wt[j]; wt[j]:=t;
        inc(i); dec(j);
      end;
  until i>j;
  qsort(i,r);
  qsort(l,j);
end;

procedure init;
var
  i,x,y,w:longint;
begin
  readln(n,m);
  nm:=0;
  bo1:=true; bo2:=true;
  for i:=1 to n-1 do
    begin
      readln(x,y,w);
      add(x,y,w); add(y,x,w);
      if x+1<>y then bo1:=false;
      if x<>1 then bo2:=false;
      sumt:=sumt+w; wt[i]:=w;
    end;
  qsort(1,n-1);
  sumk:=0;
  for i:=1 to min(m*2,n-1) do
    sumk:=sumk+wt[i];
end;

procedure dfs(x:longint);
var
  i:longint;
  boo:boolean;
begin
  bo[x]:=2;
  i:=ls[x]; boo:=true;
  while i<>0 do
    with a[i] do
      begin
        ans:=ans+w;
        if bo[y]=0 then
          begin
            boo:=false;
            dfs(y);
          end;
        ans:=ans-w;
        i:=next;
      end;
  if boo then
    if max<ans then
      max:=ans;
end;

procedure main;
var
  i,ii:longint;
begin
  ans:=0; max:=0;
  for i:=1 to n do
    begin
      fillchar(bo,sizeof(bo),0);
      dfs(i);
    end;
  sum:=max;
  writeln(sum);
end;

begin
  assign(input,'track.in');
  assign(output,'track.out');
  reset(input);
  rewrite(output);
  init;
  if bo1 then writeln(sumt) else
  if bo2 then writeln(sumk) else
  if m=n-1 then writeln(wt[n-1]) else
  if m=1 then main else
  writeln(wt[1]+wt[2]);
  close(input);
  close(output);
end.
