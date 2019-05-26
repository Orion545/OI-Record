var
  a,s,d,f,j,k,l,n,m,bs,da:longint;  t:string;
  first,next,dw,p,pd:array[0..1000000] of longint;
  dp:array[0..100000,0..1,0..1] of longint;

procedure add(t,y:longint);
begin
  bs:=bs+1;
  dw[bs]:=y;
  next[bs]:=first[t];
  first[t]:=bs;
end;

{procedure ddpp(t,y,u:longint);
var z,x,c,v:longint;
begin
  x:=0;
  z:=first[t];
  while z>0 do
  begin
    if dw[z]<>y then begin x:=x+1; ddpp(dw[z],t,y);
    z:=next[z];
  end;
end;}

function min(t,y:longint):longint;
begin
  if t>y then exit(y) else exit(t);
end;

procedure bss(t,y,u,mm:longint);
var z,x,c,v:longint;
begin
  if t=n then begin if pd[y]=0 then
  begin m:=m+min(p[t],p[y]); end;
  if mm<da then da:=mm; exit; end;

  z:=first[t];

  if t=a then
  begin
    if (s=0) and (u=0) then exit;
    if s=0 then
    while z>0 do
    begin
      if dw[z]<>y then begin pd[t]:=0;bss(dw[z],t,pd[y],mm); end;
      z:=next[z];
    end;
    if s=1 then
    while z>0 do
    begin
      if dw[z]<>y then begin pd[t]:=1; bss(dw[z],t,pd[y],mm+p[t]);
      pd[t]:=0; end;
      z:=next[z];
    end;
    exit;
  end;

  if t=d then
  begin
    if (f=0) and (u=0) then exit;
    if f=0 then
    while z>0 do
    begin
      if dw[z]<>y then begin pd[t]:=0; bss(dw[z],t,pd[y],mm);  end;
      z:=next[z];
    end;
    if f=1 then
    while z>0 do
    begin
      if dw[z]<>y then begin pd[t]:=1; bss(dw[z],t,pd[y],mm+p[t]);
      pd[t]:=0; end;
      z:=next[z];
    end;
    exit;
  end;

  while z>0 do
  begin
    x:=dw[z];
    if x<>y then
    begin
      if u=0 then
      begin
        pd[t]:=1; bss(x,t,pd[y],mm+p[t]); pd[t]:=0;
      end;
      if u=1 then
      begin
        pd[t]:=1; bss(x,t,pd[y],mm+p[t]); pd[t]:=0;
        pd[t]:=0; bss(x,t,pd[y],mm);
      end;
    end;
    z:=next[z];
  end;
end;

begin
  assign(input,'defense.in');
  assign(output,'defense.out');
  reset(input);
  rewrite(output);

  readln(n,m,t);
  for j:=1 to n do read(p[j]); readln;
  for j:=1 to n-1 do
  begin
    readln(a,s);
    add(a,s);
    add(s,a);
  end;

  for j:=1 to m do
  begin
    readln(a,s,d,f);
    da:=maxlongint div 3;
    for k:=1 to n do pd[k]:=0;
    bss(1,0,1,0);
    if da=maxlongint div 3 then da:=-1;
    writeln(da);
  end;

  close(input);
  close(output);
end.