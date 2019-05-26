var
  first,next,lww,dl,pd,g,h:array[0..15000] of longint;
  a,s,d,f,j,k,l,n,m,dt,dw,bs:longint;

procedure add(t,y:longint);
begin
  bs:=bs+1;
  lww[bs]:=y;
  next[bs]:=first[t];
  first[t]:=bs;
end;

procedure shuchu(t,y:longint);
var z,x,c,v,q,w:longint;
begin
  write(t,' ');
  z:=first[t];
  while z>0 do
  begin
    if lww[z]<>y then shuchu(lww[z],t);
    z:=next[z];
  end;
  {while z>0 do
  begin
    if lww[z]<>y then c:=c+1;
  end;

  for v:=1 to c do
  begin
    z:=first[t]; q:=maxlongint div 3; w:=0;
    while z>0 do
    begin
      if (lww[z]<>y) and (pd[lww[z]=0) and (lww[
    end;
  end;}
end;

procedure kp(t,y:longint);
var z,x,c,v:longint;
begin
  z:=t; x:=y; c:=h[(t+y) div 2];
  repeat
    while h[z]>c do z:=z+1;
    while h[x]<c do x:=x-1;
    if z<=x then
    begin
      v:=g[z]; g[z]:=g[x]; g[x]:=v;
      v:=h[z]; h[z]:=h[x]; h[x]:=v;
      z:=z+1; x:=x-1;
    end;
  until z>x;
  if x>t then kp(t,x);
  if y>z then kp(z,y);
end;

begin
  assign(input,'travel.in');
  assign(output,'travel.out');
  reset(input);
  rewrite(output);

  readln(n,m);
  for j:=1 to m do
  begin
    readln(a,s);
    g[j*2-1]:=a; h[j*2-1]:=s;
    g[j*2]:=s; h[j*2]:=a;
  end;

  kp(1,2*m);
  for j:=1 to 2*m do
  add(g[j],h[j]);

  if m=n-1 then shuchu(1,0);

  close(input);
  close(output);
end.
