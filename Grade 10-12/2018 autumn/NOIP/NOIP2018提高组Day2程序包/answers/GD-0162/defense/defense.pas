var
  n,m,i,j,k,l,x,y,a,b,ans:longint;
  p:array[1..101] of longint;
  f:array[1..101] of integer;
  cv:array[1..101,1..101] of boolean;
  r:array[1..101,0..101] of longint;
  c:char;

procedure append(v1,v2:longint);
begin
  inc(r[v1,0]); r[v1,r[v1,0]]:=v2;
end;

function sumt():longint;
var
  i,j:longint;
begin
  sumt:=0;
  for i:=1 to n do
  begin
    if f[i]>0 then inc(sumt,p[i]);
    for j:=1 to r[i,0] do
      if (f[i]<=0)and(f[r[i,j]]<=0)and(i<>j) then exit(maxlongint);
  end;
end;

procedure dfs(x:longint);
var
  i,t:longint;
  flag:boolean;
begin
  if x>n then
  begin
    t:=sumt;
    if t<ans then ans:=t;
    exit;
  end;
  if f[x]<0 then dfs(x+1)
  else
  begin
   // flag:=false;
    //if x=n then if v<ans then ans:=v;
  //  for i:=1 to r[x,0] do
  //    if f[r[x,i]]>0 then flag:=true;
    for i:=1 to r[x,0] do
      if f[r[x,i]]=0 then f[r[x,i]]:=-1;
    f[x]:=1;
    dfs(x+1);
    //if flag then
   // begin
      f[x]:=0;
      for i:=1 to r[x,0] do
        if f[r[x,i]]=-1 then f[r[x,i]]:=0;
      dfs(x+1);
   // end;
  end;
end;

begin
  assign(input,'defense.in');
  assign(output,'defense.out');
  reset(input);
  rewrite(output);
  read(n,m); read(c);read(c);read(c);
  readln;
  for i:=1 to n do read(p[i]);
  for i:=1 to n-1 do
  begin
    readln(x,y);
    append(x,y); append(y,x);
    cv[x,y]:=true; cv[y,x]:=true;
  end;
  for i:=1 to m do
  begin
    fillchar(f,sizeof(f),0); ans:=maxlongint;
    readln(a,x,b,y);
    if (x=0)and(y=0)and(cv[a,b]) then
    begin
      writeln('-1');
      continue;
    end;
    if x=0 then f[a]:=-2
    else
      f[a]:=1;
    if y=0 then f[b]:=-2
    else
      f[b]:=1;
    dfs(1);
    writeln(ans);
  end;
  close(input);
  close(output);
end.