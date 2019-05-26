var
  a,g:array[0..500000] of longint;
  s,d,f,j,k,l,n,m,da,pp:longint;

procedure kp(t,y:longint);
var z,x,c,v:longint;
begin
  z:=t; x:=y; c:=a[(t+y) div 2];
  repeat
    while (a[z]<c) do z:=z+1;
    while (a[x]>c) do x:=x-1;
    if (z<=x) then
    begin
      c:=a[z]; a[z]:=a[x]; a[x]:=c;
      z:=z+1; x:=x-1;
    end;
  until z>x;

  if x>t then kp(t,x);
  if y>z then kp(z,y);
end;

begin
  assign(input,'money.in');
  assign(output,'money.out');
  reset(input);
  rewrite(output);

  readln(d);
  for j:=1 to d do
  begin
    da:=0;
    readln(f);
    for k:=1 to f do read(a[k]); readln;
    //kp(1,f);

    for k:=1 to f-1 do
    for l:=k+1 to f do
    if a[l]<a[k] then
    begin pp:=a[k]; a[k]:=a[l]; a[l]:=pp; end;

    for k:=1 to f do
    begin
      if g[a[k]]=0 then
      begin
        da:=da+1;
        g[a[k]]:=1;
        for l:=1 to a[f]-a[k]+1 do
        if g[l]=1 then g[l+a[k]]:=1;
      end;
    end;

    for k:=1 to f do a[k]:=0;
    for k:=1 to 50000 do g[k]:=0;
    writeln(da);
  end;

  close(input);
  close(output);
end.
