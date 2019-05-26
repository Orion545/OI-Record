var t,n,m,i,j,k,l,min,ans,max,ii,cl:longint;
    a:array [1..50000] of byte;
    bo:boolean;

procedure clean;
begin
  ans:=ans+1;
  cl:=1;
  while i+(min*cl)<=max do
  begin
    a[i+(min*cl)]:=0;
    cl:=cl+1;
  end;
end;


begin
  assign(input,'money.in');
  reset(input);
  assign(output,'money.out');
  rewrite(output);

  readln(t);
  for ii:=1 to t do
  begin
    readln(n);
    max:=0;
    min:=maxlongint;
    fillchar(a,sizeof(a),0);
    bo:=true;
    ans:=0;
    for i:=1 to n do
    begin
      read(m);
      a[m]:=1;
      if m>max then max:=m;
      if m<min then min:=m;
      if m=1 then bo:=false;
    end;
    if bo=false then writeln(1)
    else
    begin
    for i:=min to max do
      if a[i]=1 then
        clean;
    writeln(ans);
    end;
  end;

  close(input);
  close(output);
end.

