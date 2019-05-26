const
  maxn=100;
  maxm=25000;
  inf='money.in';
  ouf='money.our';
var
  a:array[0..maxn]of longint;
  v,f,rem:array[1..25000]of boolean;
  pre:array[1..maxm]of longint;
  n,i,j,k:longint;
  ans:longint;

function gcd(a,b:longint):longint;
begin
  if a mod b=0 then exit(b);
  gcd:=gcd(b,a mod b);
end;

procedure qsort(l,r:longint);
var
  i,j,key:longint;
begin
  if l>r then exit;
  i:=l;j:=r;
  key:=a[(l+r)div 2];
  repeat
    while a[i]<key do inc(i);
    while a[j]>key do dec(j);
    if i<=j then
    begin
      a[0]:=a[i];a[i]:=a[j];a[j]:=a[0];
      inc(i);dec(j);
    end;
  until i>j;
  qsort(l,j);
  qsort(i,r);
end;

function max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;

procedure init;
var
  i,mm,j:longint;
begin
  readln(n);   mm:=0;
  for i:=1 to n do
  begin
    read(a[i]);
    mm:=max(a[i],mm);
  end;
  qsort(1,n);
  j:=0;
  for i:=1 to mm do
  begin
    if i=a[j+1] then inc(j);
    pre[i]:=j;
  end;
end;

function dfs(x,y,k:longint):boolean;
var
  i:longint;
begin
  dfs:=false; rem[x]:=false;
  if pre[x]=0 then exit(false);
  if rem[x] then exit(true);
  for i:=k downto 1 do
  begin
    if (y=0)and(a[i]=x) then continue;
    if x mod a[i]=0 then
    begin
      if x<>a[i] then rem[x]:=true;
      exit(true);
    end;
    for k:=1 to x div a[i] do
    begin
      rem[x]:=dfs(x-k*a[i],y+1,i-1);
      if rem[x] then exit(true);
    end;
  end;
end;

begin
  assign(input,inf);reset(input);
  assign(output,ouf);rewrite(output);
  init;
 { if n=2 then
  begin
    if (gcd(a[1],a[2])=a[1])or(a[1]=a[2]) then writeln(1) else writeln(2);
    close(input);close(output);
    halt;

  end;}
  for i:=1 to n do
    for j:=i+1 to n do
      if gcd(a[i],a[j])=a[i] then
      begin
        rem[a[j]]:=true;
        v[j]:=true;
      end;
  for i:=n downto 1 do
    if v[i]=false then v[i]:=dfs(a[i],0,pre[a[i]]-1);

  for i:=1 to n do
    if v[i]=false then inc(ans);
  writeln(ans);
  close(input);close(output);
end.
