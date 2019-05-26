//rv-3 - Yuzu
var
  t,n,i,j,k,l,mx:longint;
  f,f1:array[0..25001] of boolean;
  a:array[0..101] of longint;

{function chk(x:longint):boolean;
var
  i,j,k,l:longint;
begin

  if f[x] then exit(true)
  else
    exit(false);
end; }

begin
  assign(input,'money.in');
  assign(output,'money.out');
  reset(input);
  rewrite(output);
  readln(t);
  while t>0 do
  begin
    fillchar(f,sizeof(f),false);
    fillchar(f1,sizeof(f1),false);
    mx:=0;
    dec(t);
    readln(n);
    for i:=1 to n do
    begin
      read(a[i]);
      if a[i]>mx then mx:=a[i];
      f1[a[i]]:=true;
    end;
    for i:=1 to mx do
    begin
      for j:=1 to n do
      begin
        if a[j]=mx then continue;
        for k:=1 to i div a[j] do
        begin
          if k>1 then f[a[j]*k]:=true;
          if f[i-a[j]*k] or (f1[i-a[j]*k]) then f[i]:=true;
        end;
      end;
    end;
    for i:=1 to n do if f[a[i]] then dec(n);
    writeln(n);
  end;
  close(input);
  close(output);
end.
