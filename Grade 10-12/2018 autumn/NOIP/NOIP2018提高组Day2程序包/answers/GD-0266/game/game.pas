var
  n,m,i:longint;
  s,j:int64;
begin
  assign(input,'game.in');
  assign(output,'game.out');
  reset(input);
  rewrite(output);

  readln(n,m);
  if n=1 then
  begin
    s:=1;
    for i:=1 to m do
      s:=s*2;
  end;
  if n=2 then
  begin
    j:=1;  s:=0;
    for i:=1 to m-1 do j:=j*2;
    for i:=1 to j do
      s:=s+i;
    s:=(s*4) mod 1000000009;
  end;

  writeln(s);
  close(input); close(output);
end.
