var
  g,h:array[0..1000000] of longint;
  a,s,d,f,j,k,l,n:longint;
begin
  assign(input,'road.in');
  assign(output,'road.out');
  reset(input);
  rewrite(output);

  readln(n);
  for j:=1 to n do read(h[j]); readln;
  d:=0; f:=0;
  j:=1;
  h[n+1]:=1000000;
  while (j<=n) do
  begin
    k:=j;
    while (h[j+1]<=h[j]) do j:=j+1;
    f:=f+h[k]-d;
    d:=h[j];
    j:=j+1;
  end;
  writeln(f);

  close(input);
  close(output);
end.