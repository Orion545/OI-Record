type
  data=record
    x,y,c:longint;
    b:array[0..1000]of boolean;
  end;
var
  i,n,m,ans:longint;
  head,tail,last:longint;
  a,list:array[0..10000]of data;

procedure change(a,b:longint);
var
  j:longint;
begin
  list[tail].x:=a;
  list[tail].y:=b;
  list[tail].c:=list[head].c+list[i].c;
  for j:=1 to n-1 do list[tail].b[j]:=list[head].b[j] or list[i].b[j];
end;
function check(a,b:data):boolean;
var
  c,d,e,f,j:longint;
begin
  for j:=1 to n-1 do if (list[head].b[j]) and (list[i].b[j]) then exit(false);
  c:=a.x;d:=a.y;
  e:=b.x;f:=b.y;
  if c=e then change(d,f)
  else if c=f then change(d,e)
  else if d=e then change(c,f)
  else if d=f then change(c,e)
  else exit(false);

  exit(true);
end;

begin
  assign(input,'track.in');
  reset(input);
  assign(output,'track.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to n-1 do read(list[i].x,list[i].y,list[i].c);
  for i:=1 to n-1 do list[i].b[i]:=true;

  head:=1;tail:=n;last:=n-1;
  while head<=last do
  begin
    for i:=head+1 to last do
      if check(list[head],list[i]) then
        inc(tail);
    last:=tail-1;
    inc(head);
  end;

  ans:=0;
  if m=1 then
  begin
    for i:=1 to last do
      if list[i].c>ans then ans:=list[i].c;
    writeln(ans);
  end
  else
    writeln(list[last-m+1].c);

  close(output);
  close(input);
end.
