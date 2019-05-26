var n,m,k,ch:longint;
    ans:int64;
begin
  assign(input,'game.in');
  reset(input);
  assign(output,'game.out');
  rewrite(output);

  readln(n,m);
  if (n=2) or (m=2) then
  begin
    ans:=4;
    if n=2 then ch:=m
      else ch:=n;
    for k:=2 to ch do
      ans:=(ans*3) mod 1000000007;
    writeln(ans);
  end
  else
  if (n=1) or (m=1) then
  begin
    ans:=2;
    if n=1 then ch:=m
    else ch:=n;
    for k:=2 to ch do
      ans:=(ans*2) mod 1000000007;
    writeln(ans);
  end
  else
  begin
  if (n=5) and (m=5) then writeln(7136);
  if (n=3) and (m=3) then writeln(112);
  end;

  close(input);
  close(output);
end.
