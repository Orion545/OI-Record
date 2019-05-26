var
  h,i,j,n,m,p:longint;
  f:array[0..8,0..1000000]of longint;
  a:array[0..1000000,0..4]of longint;
begin
  assign(input,'game.in');
  reset(input);
  assign(output,'game.out');
  rewrite(output);
  readln(n,m);
  f[1,1]:=2;f[1,2]:=4;f[1,3]:=8;
  f[2,1]:=4;f[2,2]:=12;f[2,3]:=36;
  f[3,1]:=8;f[3,2]:=36;f[3,3]:=112;

  p:=1000000007;
  a[3,1]:=8;a[3,2]:=16;a[3,3]:=4;a[3,4]:=8;
  for i:=4 to m do
  begin
    a[i,1]:=(a[i-1,1]+a[i-1,2])mod p;
    for j:=1 to 4 do
      a[i,2]:=(a[i,2]+a[i-1,j])mod p;
    a[i,3]:=(a[i-1,1]+a[i-1,2])mod p;
    for j:=1 to 4 do
      a[i,4]:=(a[i,4]+a[i-1,j])mod p;

    for j:=1 to 4 do
      f[2,i]:=(f[2,i]+a[i,j])mod p;
  end;
  writeln(f[n,m]);
  close(output);
  close(input);
end.