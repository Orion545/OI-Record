var
  r,w:text;
  a,b,c,d,e:array[0..10000] of longint;
  i,j,n,m,max,k,f,g,ans:integer;

procedure kp(l,r: longint);
var
  i,j,x,y:longint;
begin
  i:=l;
  j:=r;
  x:=a[(l+r) div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if not(i>j) then
    begin
      y:=a[i];
      a[i]:=a[j];
      a[j]:=y;
      inc(i);
      j:=j-1;
    end;
  until i>j;
  if l<j then kp(l,j);
  if i<r then kp(i,r);
end;


begin
  assign(r,'money.in');
  reset(r);
  assign(w,'money.out');
  rewrite(w);
  readln(r,n);
  for i:=1 to n do
  begin
    fillchar(a,sizeof(a),0);
    fillchar(b,sizeof(b),0);
    fillchar(c,sizeof(c),0);
    readln(r,m);
    for j:=1 to m do read(r,a[j]);
    kp(1,m);
    b[0]:=1;
    c[0]:=a[1];
    k:=0;
    for j:=2 to m do
    begin
      f:=a[j] mod a[1];
      if b[f]<>1 then
                 begin
                   inc(k);
                   c[k]:=a[j];
                   b[f]:=1;
                 end;
    end;
    fillchar(b,sizeof(b),0);
    for j:=1 to k do
      b[j]:=c[j] mod c[0];
    ans:=k+1;
    for j:=2 to k do
    begin
      d:=b;
      e:=c;
      for f:=j-1 downto 1 do
      begin
        if (c[f]<>0)and(b[f]<>0)and(d[j]>=d[f]) then
        begin
            g:=d[j] div d[f];
            if (d[j] div d[f])<=(e[j] div e[f]) then
            begin
              if (d[j] mod d[f])=0 then
              begin
               dec(ans);
               c[j]:=0;
              end
              else
              begin
                d[j]:=d[j] mod d[f];
                e[j]:=(e[j]-g*e[f]);
              end;
            end;
        end;
      end;
    end;
    writeln(w,ans);
  end;
  close(r);
  close(w);
end.
