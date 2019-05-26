const
  maxn=100;

var
  a:array [0..maxn] of longint;
  flag,v:array [0..maxn*maxn*10] of boolean;
  t,n:longint;

procedure qsort(l,r:longint);
var
  i,j,k,mid:longint;
begin
  i:=l;j:=r;mid:=a[(l+r) div 2];
  repeat
    while a[i]<mid do
      inc(i);
    while a[j]>mid do
      dec(j);
    if i<=j then
      begin
        k:=a[i];
        a[i]:=a[j];
        a[j]:=k;
        inc(i);dec(j);
      end;
  until i>j;
  if i<r then
    qsort(i,r);
  if j>l then
    qsort(l,j);
end;

procedure init;
var
  i,j,k,temp:longint;
begin
  readln(n);
  for i:=1 to n do
    read(a[i]);
  qsort(1,n);
end;

procedure main;
var
  i,j,k,z,max:longint;
begin
  readln(t);
  for z:=1 to t do
    begin
      fillchar(a,sizeof(a),0);
      fillchar(flag,sizeof(flag),false);
      fillchar(v,sizeof(v),false);
      init;
      max:=a[n];
      for i:=1 to n do
        for j:=1 to max div a[i] do
          begin
            flag[a[i]*j]:=true;
            if j<>1 then
              v[a[i]*j]:=true;
          end;
      for i:=a[1] to max do
        if flag[i] then
          begin
            for j:=1 to n do
              begin
                if i mod a[j]=0 then
                  continue;
                for k:=1 to max div a[j] do
                  begin
                    flag[a[j]*k+i]:=true;
                   v[a[j]*k+i]:=true;
                  end;
              end;
          end;
      for i:=1 to n do
        if v[a[i]] then
          dec(n);
      writeln(n);
    end;
end;

begin
  assign(input,'money.in');reset(input);
  assign(output,'money.out');rewrite(output);
  main;
  close(input);close(output);
end.
