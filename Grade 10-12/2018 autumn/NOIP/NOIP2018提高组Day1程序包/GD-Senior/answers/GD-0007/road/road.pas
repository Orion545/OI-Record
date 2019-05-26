var n,i,j,k,l,max,ans,m,r:longint;
    bo:boolean;
    d:array [0..100000] of longint;

function min(a,b:longint):longint;
begin
  if a>=b then exit(b)
  else exit(a);
end;

begin
  assign(input,'road.in');
  reset(input);
  assign(output,'road.out');
  rewrite(output);

  readln(n);
  ans:=0;
  l:=0;
  d[0]:=maxlongint;
  bo:=true;
  for i:=1 to n do
  begin
    read(d[i]);
    if bo=true then
      begin
        m:=d[i];
        bo:=false;
      end;
    if d[i]>d[i-1] then
      begin
        if d[i-1]-l>0 then
          ans:=ans+d[i-1]-l;
        ans:=ans+min(m-l,m-d[i-1]);
        l:=d[i-1];
        m:=d[i];
      end;
  end;
  if d[n]>d[n-1] then
    ans:=ans+d[n]-l
  else if d[n]<d[n-1] then
    ans:=ans+min(m-l,m-d[n]);
  write(ans);

  close(input);
  close(output);
end.

