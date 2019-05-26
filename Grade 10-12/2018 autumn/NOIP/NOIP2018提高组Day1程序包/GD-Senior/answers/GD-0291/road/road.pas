var
  r,w:text;
  n,ans,i:longint;
  a:array[0..100001] of longint;
procedure sea(l,h:longint);
var
  min,i,l1,r1:longint;
begin
  if l>h then exit;
  min:=a[l];
  for i:=l+1 to h do
    if a[i]<min then min:=a[i];
  for i:=l to h do
    dec(a[i],min);
  inc(ans,min);
  l1:=l;
  for i:=l to h do
    if a[i]=0 then
              begin
                r1:=i-1;
                sea(l1,r1);
                l1:=i+1;
              end;
  sea(l1,h);
end;


begin
  assign(r,'road.in');
  reset(r);
  assign(w,'road.out');
  rewrite(w);
  readln(r,n);
  for i:=1 to n do
    read(r,a[i]);
  a[0]:=0;
  a[n+1]:=0;
  ans:=0;
  sea(1,n);
  writeln(w,ans);
  close(r);
  close(w);
end.
