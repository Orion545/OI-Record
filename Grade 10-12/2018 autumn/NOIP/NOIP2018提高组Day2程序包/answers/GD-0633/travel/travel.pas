type
  arr=record
    y,next:longint;
  end;
var
  n,m,nm,op:longint;
  a:array [0..10001] of arr;
  ls,tong,v,du:array [0..5001] of longint;
procedure add(x,y:longint);
begin
  inc(nm);
  a[nm].y:=y; a[nm].next:=ls[x];
  ls[x]:=nm;
end;

function max(o,p:longint):longint;
begin
  if o>p then exit(o);
  exit(p);
end;

procedure init;
var
  i,x,y:longint;
begin
  readln(n,m);
  nm:=0;
  for i:=1 to m do
    begin
      readln(x,y);
      add(x,y); add(y,x);
      if (du[x]=1) and (du[y]=1) then
        op:=max(x,y);
      du[x]:=1; du[y]:=1;
    end;
end;

procedure dfs1(x:longint);
var
  i:longint;
begin
  write(x,' ');
  v[x]:=1; i:=ls[x];
  while i<>0 do
    begin
      if v[a[i].y]=0 then
        tong[a[i].y]:=x;
      i:=a[i].next;
    end;
  for i:=1 to n do
    if (tong[i]=x) and (v[i]=0) then
      dfs1(i);
end;

function check(x:longint):boolean;
var
  i:longint;
begin
  du[x]:=1;
  i:=ls[x];
  while i<>0 do
    begin
      if a[i].y=op then exit(true) else
        if du[a[i].y]=0 then check(a[i].y);
      i:=a[i].next;
    end;
end;

procedure dfs2(x:longint);
var
  i,tot,tk:longint;
begin
  write(x,' ');
  v[x]:=1; tot:=0;
  i:=ls[x];
  while i<>0 do
    begin
      if v[a[i].y]=0 then
        begin
          tong[a[i].y]:=x;
          inc(tot); tk:=a[i].y;
        end;
      i:=a[i].next;
    end;
  if tot=1 then
    begin
      fillchar(du,sizeof(du),0);
      if tk=op then
        begin
      for i:=1 to n do
        if (tong[i]=tong[x]) and (v[i]=0) then
          if i<tk then
            begin
              dfs2(i);
              break;
            end;
        end else
        dfs2(tk);
    end else
  for i:=1 to n do
    if (tong[i]=x) and (v[i]=0) then
      dfs2(i);
end;

begin
  assign(input,'travel.in');
  assign(output,'travel.out');
  reset(input);
  rewrite(output);
  init;
  fillchar(v,sizeof(v),0);
  fillchar(tong,sizeof(tong),0);
  if m=n-1 then dfs1(1)
           else dfs2(1);
  close(input);
  close(output);
end.
