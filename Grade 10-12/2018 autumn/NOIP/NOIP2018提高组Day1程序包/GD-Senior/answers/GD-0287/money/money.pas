const
  maxn=200;

var
  a,stack:array[0..maxn+1] of longint;
  n,t,top,l,i:longint;
  p:boolean;
  v:array[0..maxn+1] of boolean;

procedure check(x:longint);
var
  i,j:longint;
begin
  for i:=top downto 1 do
    if x mod stack[i]=0 then
      p:=false;
  if not p then exit;
  for i:=top downto 1 do
    begin
      if not v[i] then
        begin
          v[i]:=true;
          for j:=1 to x div stack[i] do
            check(x-(stack[i]*j));
          v[i]:=false;
      end;
  end;
end;

procedure qsort(l,r:longint);
var
  i,j,mid,t:longint;
begin
  i:=l;j:=r;
  mid:=a[l+random(r-l+1)];
  repeat
    while a[i]<mid do inc(i);
    while a[j]>mid do dec(j);
    if i<=j then
      begin
        t:=a[i];a[i]:=a[j];a[j]:=t;
        inc(i);dec(j);
    end;
  until i>j;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);
end;

begin
  assign(input,'money.in');reset(input);
  assign(output,'money.out');rewrite(output);
  readln(t);
  for l:=1 to t do
    begin
      readln(n);
      for i:=1 to n do
        if i<n then read(a[i])
          else readln(a[i]);
      qsort(1,n);
      top:=1;
      stack[top]:=a[1];
      for i:=2 to n do
        begin
          fillchar(v,sizeof(v),false);
          p:=true;
          check(a[i]);
          if p then
            begin
              inc(top);
              stack[top]:=a[i];
          end;
      end;
      writeln(top);
  end;
  close(input);close(output);
end.