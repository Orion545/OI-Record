var
  first,next,dw,dc,fir,ne,jd,cd:array[0..200000] of longint;
  zcl,lll,llc,pd:array[0..100000] of longint;
  n,m,s,d,f,j,k,a,b,l,bs,sj,xj,ls,dda,jds,ddd:longint;

procedure add(t,y,u:longint);
begin
  bs:=bs+1;
  dw[bs]:=y;
  dc[bs]:=u;
  next[bs]:=first[t];
  first[t]:=bs;
end;

procedure plpq(i,fq:longint);
var z,x,c,v:longint;
begin

  z:=first[i];
  while (z>0) do
  begin
    x:=dw[z];
    if (x<>fq) then
    begin
      jds:=jds+1;
      jd[jds]:=x;
      ne[jds]:=fir[i];
      cd[jds]:=dc[z];
      fir[i]:=jds;
      plpq(x,i);
    end;
    z:=next[z];
  end;
end;

procedure kp(t,y:longint);
var z,x,c,v:longint;
begin
  z:=t; x:=y; c:=llc[(t+y) div 2];
  repeat
    while llc[z]>c do z:=z+1;
    while llc[x]<c do x:=x-1;
    if (z<=x) then
    begin
      v:=llc[z]; llc[z]:=llc[x]; llc[x]:=v;
      z:=z+1; x:=x-1;
    end;
  until z>x;

  if x>t then kp(t,x);
  if y>z then kp(z,y);
end;

procedure clcq(i,fq:longint);
var z,x,c,v,llw,tt,ww:longint;
begin
  zcl[i]:=0;

  z:=first[i];
  while (z>0) do
  begin
    x:=dw[z];
    if (x<>fq) then
    begin
      clcq(x,i);
    end;
    z:=next[z];
  end;

  z:=fir[i];  llw:=0;
  while z>0 do
  begin
    llw:=llw+1;
    lll[llw]:=jd[z];
    llc[llw]:=cd[z]+zcl[jd[z]];
    z:=ne[z];
  end;

  if llw=0 then begin zcl[i]:=0; exit; end;

  kp(1,llw);

  tt:=1; ww:=llw;
  for z:=1 to llw do pd[z]:=0;
  {while (tt<=ww) do
  begin
    if llc[tt]>=dda then begin pd[tt]:=1; ddd:=ddd+1; tt:=tt+1;
    continue; end else

    if (llc[tt]+llc[ww]>=dda) and (tt<ww) then
    begin pd[tt]:=1; pd[ww]:=1;ddd:=ddd+1; tt:=tt+1; ww:=ww-1;
    continue; end else

    if (tt<ww) then begin ww:=ww-1;
    continue; end else

    if tt=ww then break;
  end; }
  while (tt<=llw) and (llc[tt]>=dda) do
  begin ddd:=ddd+1; pd[tt]:=1; tt:=tt+1; end;

  for z:=ww downto tt+1 do
  if pd[z]=0 then
  for x:=z-1 downto tt do
    if (pd[x]=0) and (llc[z]+llc[x]>=dda) and (pd[z]=0) then
    begin pd[z]:=1; pd[x]:=1; ddd:=ddd+1; break;end;

  for z:=1 to llw do if pd[z]=0 then begin zcl[i]:=llc[z]; exit; end;
end;

begin
  assign(input,'track.in');
  assign(output,'track.out');
  reset(input);
  rewrite(output);

  readln(n,m);
  for j:=1 to n-1 do
  begin
    readln(a,b,l);
    add(a,b,l);
    add(b,a,l);
    sj:=sj+l;
  end;

  plpq(1,0);

  xj:=0;
  while (xj+5<sj) do
  begin
    ls:=0; dda:=(sj+xj) div 2; ddd:=0;
    clcq(1,0);
    if ddd>=m then xj:=dda else sj:=dda-1;
  end;

  for j:=sj downto xj do
  begin
    dda:=j; ddd:=0; clcq(1,0);
    if ddd>=m then begin writeln(j); break; end;
  end;

  close(input);
  close(output);
end.
