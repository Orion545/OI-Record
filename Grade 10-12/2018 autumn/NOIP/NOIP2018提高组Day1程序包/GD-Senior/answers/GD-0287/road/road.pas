var
  n,i,x,last:longint;
  ans:int64;

begin
  assign(input,'road.in');reset(input);
  assign(output,'road.out');rewrite(output);
  readln(n);
  last:=0;
  for i:=1 to n do
    begin
      if i<n then read(x)
        else readln(x);
      if x>last then
        ans:=ans+(x-last);
      last:=x;
  end;
  writeln(ans);
  close(input);close(output);
end.