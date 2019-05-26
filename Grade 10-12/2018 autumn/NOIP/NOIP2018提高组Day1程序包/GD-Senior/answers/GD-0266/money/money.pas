var
  t,n,m,i,j,k,i1,i2:longint;
  a,b:array[1..101] of longint;
procedure qsort(l,r:longint);
var
  i,j,mid,p:longint;
begin
  i:=l; j:=r;
  mid:=a[(l+r) div 2];
  repeat
    while a[i]<mid do inc(i);
    while a[j]>mid do dec(j);
    if i<=j then
    begin
      p:=a[i];
      a[i]:=a[j];
      a[j]:=p;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
end;

begin
  assign(input,'money.in');
  assign(output,'money.out');
  reset(input);
  rewrite(output);

  j:=0;
  read(t);
  for k:=1 to t do
  begin
    read(n);
    for i:=1 to n do
      read(a[i]);
    if n=2 then
    begin
      if a[2]>=a[1] then
      if (a[2] mod a[1])=0 then j:=1 else j:=2;
      if a[1]>a[2] then
      if (a[1] mod a[2])=0 then j:=1 else j:=2;
    end;

    if n=3 then
    begin
      qsort(1,n);
      j:=1;
      if a[2] mod a[1]=0 then a[2]:=0 else inc(j);
      if (a[2]=0) and (a[3] mod a[1]<>0) then inc(j);

      if (a[2]<>0)  then
      begin
        for i1:=0 to 100 do
        for i2:=0 to 100 do
        if a[1]*i1+a[2]*i2=a[3] then begin a[3]:=0; break; end;
        if a[3]<>0 then inc(j);
      end;
    end;

    writeln(j);
  end;
   close(input);
   close(output);

end.







