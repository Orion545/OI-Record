var
  g:array[-2..10000,-2..10000] of longint;
  a,s,d,f,j,k,l,da:longint;

procedure dd(t,y:longint);
begin
  if (t=a) and (s=y) then begin da:=da+2;
  //for j:=1 to a do
  //begin for k:=1 to s do write(g[j,k],' '); writeln; end; writeln;
  exit; end;
  if (y=s) then
  begin
    g[t,y]:=1;
    dd(t+1,1);
    g[t,y]:=0;
    dd(t+1,1);
    exit;
  end;

  if (g[t-1,y+1]=0) then
  begin
    if not((t>=3) and (g[t-1,y-1]=g[t-2,y]) and (y>=2)) then begin g[t,y]:=1;
    dd(t,y+1); end;
    g[t,y]:=0;
    dd(t,y+1);
  end else
  begin
    g[t,y]:=1;
    dd(t,y+1);
  end;
end;

begin
  assign(input,'game.in');
  assign(output,'game.out');
  reset(input);
  rewrite(output);
  readln(a,s);
  if ((a<=3) and (s<=3)) or (a=3) then dd(1,1);
  if (a=2) and (s>3) then
  begin
    da:=4;
    for j:=2 to s do da:=(da*3) mod 1000000007;
  end;
  writeln(da);
  close(input);
  close(output);
end.
