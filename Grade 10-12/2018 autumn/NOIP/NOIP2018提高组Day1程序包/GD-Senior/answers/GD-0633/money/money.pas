var
  TT,n,ans:longint;
  a,v:array [0..25010] of longint;
procedure qsort(l,r:longint);
var
  mid,i,j,t:longint;
begin
  if l>r then exit;
  i:=l; j:=r;
  mid:=a[(l+r) div 2];
  repeat
    while a[i]<mid do inc(i);
    while a[j]>mid do dec(j);
    if i<=j then
      begin
        t:=a[i]; a[i]:=a[j]; a[j]:=t;
        inc(i); dec(j);
      end;
  until i>j;
  qsort(i,r);
  qsort(l,j);
end;

procedure init;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do
    read(a[i]);
  qsort(1,n);
end;

procedure main;
var
  i,j:longint;
begin
  fillchar(v,sizeof(v),0);
  ans:=0;
  for i:=1 to n do
    if v[a[i]]=0 then
      begin
        v[a[i]]:=1;
        for j:=0 to a[n]-a[i] do
          if v[j]=1 then
            v[j+a[i]]:=1;
        inc(ans);
      end;
  writeln(ans);
end;

begin
  assign(input,'money.in');
  assign(output,'money.out');
  reset(input);
  rewrite(output);
  readln(TT);
  while TT>0 do
    begin
      init;
      main;
      dec(TT);
    end;
  close(input);
  close(output);
end.
