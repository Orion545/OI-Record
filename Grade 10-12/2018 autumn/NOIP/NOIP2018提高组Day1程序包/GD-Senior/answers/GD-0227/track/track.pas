const
  maxn=50000;

var
  a,b,c,l:array [0..maxn] of longint;
  n,m:longint;
  flag1,flag2:boolean;

procedure qsort(l1,r:longint);
var
  i,j,k,mid:longint;
begin
  i:=l1;j:=r;mid:=l[(l1+r) div 2];
  repeat
    while l[i]<mid do
      inc(i);
    while l[j]>mid do
      dec(j);
    if i<=j then
      begin
        k:=a[i];
        a[i]:=a[j];
        a[j]:=k;
        k:=b[i];
        b[i]:=b[j];
        b[j]:=k;
        k:=l[i];
        l[i]:=l[j];
        l[j]:=k;
        inc(i);dec(j);
      end;
  until i>j;
  if i<r then
    qsort(i,r);
  if j>l1 then
    qsort(l1,j);
end;

procedure init;
var
  i,j:longint;
begin
  readln(n,m);
  flag1:=true;flag2:=true;
  for i:=1 to n-1 do
    begin
      readln(a[i],b[i],l[i]);
      if a[i]<>1 then
        flag1:=false;
      if b[i]<>a[i]+1 then
        flag2:=false;
    end;
  qsort(1,n);
end;

function min(a,b:longint):longint;
begin
  if a<b then
    exit(a);
  exit(b);
end;

procedure main;
var
  i,j,min1:longint;
  sum:int64;
begin
  sum:=0;
  if flag1 and (m=1) then
    begin
      writeln(min(l[1]+l[2],l[3]));
      exit;
    end;
  if flag2 then
    begin
      for i:=1 to m do
        sum:=sum+l[i];
      writeln(min(sum,l[m+1]));
      exit;
    end;
  if flag1 then
    begin
      min1:=maxlongint;
      if m<=n div 2 then
        for i:=1 to m do
          min1:=min(l[i]+l[n-i+1],min1);
      if m>n div 2 then
        begin
          for i:=1 to m-n div 2 do
            min1:=min(l[i]+l[n-i+1],min1);
          for i:=m-n div 2+1 to n-m+n div 2 do
            min1:=min(l[i],min1);
          writeln(min1);
        end;
    end;
end;

begin
  assign(input,'track.in');reset(input);
  assign(output,'track.out');rewrite(output);
  init;
  main;
  close(input);close(output);
end.