var
  n,i:longint;
  ans:int64;
  a:array[0..105000]of longint;

begin
  assign(input,'road.in');reset(input);
  assign(output,'road.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  ans:=a[1];
  for i:=2 to n do
    begin
      if a[i]>a[i-1] then
        ans:=ans+(a[i]-a[i-1]);
    end;
  writeln(ans);
  close(input);close(output);
end.