var
  i,n:longint;
  ans:int64;
  a:array[0..110000]of longint;
begin
  assign(input,'road.in');
  reset(input);
  assign(output,'road.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    if a[i]>a[i-1] then inc(ans,a[i]-a[i-1]);
  end;

  writeln(ans);
  close(output);
  close(input);

end.