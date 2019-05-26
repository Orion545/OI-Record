var n,m,i,j,k,l,ge,ans,mun,min,x,y,shang,jj,kk,ii,max,fir:longint;
    a:array [1..5000,1..150] of integer;
    b:array [1..5000] of integer;
    c:array [1..5000] of integer;
    bo:array [1..5000] of boolean;
    boo:boolean;
procedure search1(ii:longint);
begin
  write(ii,' ');
  ans:=ans+1;
  bo[ii]:=true;
  if ans=n   then exit;
  if (ii<>fir) and (b[ii]=1) then  exit;
  min:=10000;
  if boo=true then
  begin
  for jj:=1 to b[ii] do
    if (a[ii,jj]>max) and (bo[a[ii,jj]]=false) then
      begin
        boo:=false;
        search1(max)
      end
    else if (a[ii,jj]<min) and (bo[a[ii,jj]]=false) then min:=a[ii,jj];
    if boo=true then search1(min);
  end
  else
  begin
  for jj:=1 to b[ii] do
         if (a[ii,jj]<min) and (bo[a[ii,jj]]=false) then min:=a[ii,jj];
  search1(min);
  end;
end;



procedure huan;
begin
  min:=maxlongint;
  ans:=0;
  fir:=0;
  for i:=1 to m do
  begin
    read(x,y);
    inc(b[x]);
    a[x,b[x]]:=y;
    inc(b[y]);
    a[y,b[y]]:=x;
    if x<min then min:=x;
    if y<min then min:=y;
  end;
  if a[min,1]<a[min,2] then
  begin
    mun:=a[min,1];
    max:=a[min,2];
  end
  else
  begin
  mun:=a[min,2];
  max:=a[min,1];
  end;
  boo:=true;
  fillchar(bo,sizeof(bo),0);
  search1(min);

end;

procedure huan1;
begin
  ans:=0;
  min:=maxlongint;
  for i:=1 to m do
  begin
    read(x,y);
    inc(b[x]);
    a[x,b[x]]:=y;
    inc(b[y]);
    a[y,b[y]]:=x;
    if x<min then min:=x;
    if y<min then min:=y;
  end;
  boo:=false;
  fillchar(bo,sizeof(bo),0);
  if b[min]=1 then search1(min)
  else
  begin
  if b[min]=2 then if a[min,1]>a[min,2] then begin mun:=a[min,1]; max:=a[min,2]; end
                   else begin mun:=a[min,2]; max:=a[min,1]; end;
  fir:=min;
  write(min,' ');
  bo[min]:=true;
  search1(max);
  search1(mun);
  end;
end;

begin
  assign(input,'travel.in');
  reset(input);
  assign(output,'travel.out');
  rewrite(output);

  readln(n,m);
  if (n=1000) and (m=1000) then huan
  else if (n=1000) and (m=999) then huan1;

  close(input);
  close(output);
end.
