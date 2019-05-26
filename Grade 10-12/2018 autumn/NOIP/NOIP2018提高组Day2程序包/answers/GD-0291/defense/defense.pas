var
  r,w:text;
  n,m,x,y,ans,i,j,x1,y1:longint;
  v:array[0..1000000] of longint;
  a,c:array[0..10000,0..10000] of integer;
  ye,no:array[0..100000] of integer;


procedure pay(k:longint);
var
  i:longint;
begin
  ye[k]:=1;
  for i:=1 to n do
    if c[k,i]=1 then
                begin
                  c[k,i]:=0;
                  c[i,k]:=0;
                  for j:=1 to n do
                  if c[i,j]=1 then
                  begin
                    c[j,i]:=0;
                    c[i,j]:=0 ;
                    pay(j);
                  end;
                end;

end;
procedure pan(k:longint);
var
  i:longint;
begin
  for i:=1 to n do
    if c[k,i]=1 then
                begin
                  c[k,i]:=0;
                  c[i,k]:=0 ;
                  pay(i);
                end;
end;

begin
  assign(r,'defense.in');
  reset(r);
  assign(w,'defense.out');
  rewrite(w);
  readln(r,n,m);
  for i:=1 to n do
    read(r,v[i]);
  fillchar(a,sizeof(a),0);
  for i:=1 to n-1 do
  begin
    readln(r,x1,y1);
    a[x1,y1]:=1;
    a[y1,x1]:=1;
  end;
  for i:=1 to m do
  begin
    readln(r,x,x1,y,y1);
    if (a[x,y]=1)and(x1=0)and(y1=0) then writeln(w,'-1')
    else
    begin
      if (x1=1)and(y1=1) then
      begin
        c:=a;
        fillchar(ye,sizeof(ye),0);
        fillchar(no,sizeof(no),0);
        pay(x);
        pay(y);
        ans:=0;
        for j:=1 to n do
          if ye[j]=1 then inc(ans,v[j]);
        writeln(w,ans);
      end
      else
      if (x1=1)or(y1=1) then
      begin
        c:=a;
        fillchar(ye,sizeof(ye),0);
        fillchar(no,sizeof(no),0);
        if x1=1 then pay(x)
                else pan(x);
        if y1=1 then pay(y)
                else pan(y);
        ans:=0;
        if x1=0 then ye[x]:=0;
        if y1=0 then ye[y]:=0;
        for j:=1 to n do
          if ye[j]=1 then inc(ans,v[j]);
        writeln(w,ans);
      end
      else
      begin
        c:=a;
        fillchar(ye,sizeof(ye),0);
        fillchar(no,sizeof(no),0);
        pan(x);
        pan(y);
        ans:=0;
        ye[x]:=0;
        ye[y]:=0;
        for j:=1 to n do
          if ye[j]=1 then inc(ans,v[j]);
        writeln(w,ans);
      end;
    end;
  end;
  close(r);
  close(w);
end.
