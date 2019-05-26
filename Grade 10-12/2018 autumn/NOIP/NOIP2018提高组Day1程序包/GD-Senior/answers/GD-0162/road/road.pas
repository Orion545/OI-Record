//rv-1 - Hina
const
  maxn=10000;
var
  n,i,j,k:longint;
  d:array[0..maxn] of integer;
  p:array[0..maxn,0..maxn] of integer;
  cnt:int64;

procedure work(l,r,pload:longint);
var
  i,j:longint;
begin
  if l>r then exit;
  {i:=l; j:=r;
  if d[p[l,r]]-pload=0 then
  begin
    work(l,p[l,r]);
    work(p[l,r],r);
  end;}
  if pload<d[p[l,r]] then inc(cnt,d[p[l,r]]-pload);
  pload:=d[p[l,r]];
  //inc(cur,pload*(r-l+1));
  work(l,p[l,r]-1,pload);
  work(p[l,r]+1,r,pload);
end;

begin
  assign(input,'road.in');
  assign(output,'road.out');
  reset(input);
  rewrite(output);
  p[1,1]:=1;
  readln(n);
  d[0]:=high(integer);
  for i:=1 to n do
  begin
    read(d[i]);
    //inc(tot,d[i]);
    for j:=1 to i do
      if p[j,i-1]<n then
        if d[i]<d[p[j,i-1]] then p[j,i]:=i
        else
          p[j,i]:=p[j,i-1];
  end;
  work(1,n,0);
  writeln(cnt);
  close(input);
  close(output);
end.
