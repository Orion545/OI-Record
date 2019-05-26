var
  r,w:text;
  a:array[0..1000,0..1000] of integer;
  p:array[0..1000000] of longint;
  b:array[0..100000] of integer;
  n,m,x,y,i,j,now:longint;
  t:boolean;
procedure dao;
var
  i,j:longint;
begin
  for i:=b[0]-1 downto 1 do
  begin
    for j:=1 to n do
      if a[b[i],j]=1 then
                  begin
                    a[b[i],j]:=0;
                    a[j,b[i]]:=0;
                    now:=j;
                    inc(b[0]);
                    b[b[0]]:=j;
                    p[j]:=1;
                    write(w,now,' ');
                    exit;
                  end;
    inc(b[0]);
    b[b[0]]:=b[b[i]];
  end;
end;

begin
  assign(r,'travel.in');
  reset(r);
  assign(w,'travel.out');
  rewrite(w);
  readln(r,n,m);
  fillchar(a,sizeof(a),0);
  for i:=1 to m do
  begin
    readln(r,x,y);
    a[x,y]:=1;
    a[y,x]:=1;
  end;
  fillchar(p,sizeof(p),0);
  now:=1;
  p[1]:=1;
  b[1]:=1;
  b[0]:=1;
  write(w,now,' ');
  for i:=2 to n do
  begin
    t:=false;
    for j:=1 to n do
      if (a[now,j]=1)and(p[j]=0) then
      begin
        a[now,j]:=0;
        a[j,now]:=0;
        now:=j;
        inc(b[0]);
        b[b[0]]:=now;
        write(w,now,' ');
        p[now]:=1;
        t:=true;
        break;
      end;
    if not t then dao;
  end;
  close(r);
  close(w);
end.
