var
  tot,max,t,k,n,i,j,ans:longint;
  a,s:array[0..200]of longint;
  f:array[0..30000]of boolean;

procedure qsort(l,r:longint);
var
  i,j,t:longint;
begin
  i:=l;j:=r;t:=a[(l+r)div 2];
  repeat
    while a[i]<t do inc(i);
    while a[j]>t do dec(j);
    if i<=j then
      begin
        a[0]:=a[i];a[i]:=a[j];a[j]:=a[0];
        inc(i);dec(j);
      end;
  until i>j;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
end;

procedure mark;
var
  i,j:longint;
begin
  j:=1;
  for i:=1 to max do
    begin
      if i+s[tot]>max then break;
      if f[i]=false then f[i+s[tot]]:=false;
    end;
end;

begin
  assign(input,'money.in');reset(input);
  assign(output,'money.out');rewrite(output);
  readln(t);
  for k:=1 to t do
    begin
      ans:=0;max:=0;tot:=0;
      readln(n);
      fillchar(f,sizeof(f),true);
      for i:=1 to n do
        begin
          read(a[i]);
          if a[i]>max then max:=a[i];
        end;
      qsort(1,n);
      for i:=1 to n do
        if f[a[i]] then
          begin
            inc(tot);inc(ans);
            s[tot]:=a[i];
            f[a[i]]:=false;
            mark;
          end;
      writeln(ans);
    end;
  close(input);close(output);
end.
