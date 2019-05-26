const max=10000;
var
  i,n,t:longint;
  a:array[0..110]of longint;
  b,c:array[0..1000000]of boolean;
procedure work;
var
  i,j,k,ans:longint;

begin
  readln(n);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(c,sizeof(c),0);
  for i:=1 to n do read(a[i]);

  b[0]:=true;c[0]:=true;
  ans:=0;
  for i:=1 to n do
    for j:=0 to max do
      if b[j] then
        b[j+a[i]]:=true;

  for j:=1 to max do
    if b[j] then
      if not c[j] then
      begin
        inc(ans);
        for k:=0 to max do
          if c[k] then
            c[k+j]:=true;
      end;
  writeln(ans);
end;

begin
  assign(input,'money.in');
  reset(input);
  assign(output,'money.out');
  rewrite(output);
  readln(t);
  for i:=1 to t do
    work;

  close(output);
  close(input);
end.
