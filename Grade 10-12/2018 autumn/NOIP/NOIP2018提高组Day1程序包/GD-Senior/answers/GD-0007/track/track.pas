var n,m,i,j,k,ans,max,min:longint;
    bo,boo:boolean;
    a,b,l:array [1..50000] of longint;
    f:array [1..50000] of boolean;
procedure kuaipai;
var i,j,k:longint;
begin
  for i:=1 to n-1 do
    for j:=i+1 to n-1 do
      if l[i]<l[j] then
        begin
          k:=l[i];
          l[i]:=l[j];
          l[j]:=k;
        end;
end;

procedure fangana;
begin
  for i:=1 to n-1 do
    ans:=ans+l[i];
  writeln(ans);
end;

procedure fanganb;
begin
  kuaipai;
  for i:=1 to m do
    ans:=ans+l[i];
  writeln(ans);
end;


procedure search(x:longint);
begin
  for i:=1 to n do
    if (a[i]=x) and (f[b[i]]=false) then
      begin
        f[b[i]]:=true;
        ans:=ans+l[i];
        if ans>max then max:=ans;
        search(b[i]);
        ans:=ans-l[i];
        f[b[i]]:=false;
      end;
end;


procedure fanganc;
begin
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    search(i);
  writeln(max);
end;

begin
  assign(input,'track.in');
  reset(input);
  assign(output,'track.out');
  rewrite(output);

  readln(n,m);
  boo:=true;
  bo:=true;
  max:=0;
  ans:=0;
  for i:=1 to n-1 do
    begin
      read(a[i],b[i],l[i]);
      if a[i]<>1 then boo:=false;
      if b[i]<>a[i]+1 then bo:=false;
    end;
  if bo=true then fangana
  else
  if boo=true then fanganb
  else
  if m=1 then fanganc;

  close(input);
  close(output);
end.
