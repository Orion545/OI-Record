var
  n,m,i,j:longint;
  l,r:int64;
  sum,tot,ans:int64;
  e:array[0..100000,1..3]of longint;
  a,f:array[0..100000]of longint;
  last:array[0..50000]of longint;
  f1,f2,f3:boolean;

function min(x,y:int64):int64;
begin
  if x<y then exit(x)
    else exit(y);
end;

procedure add(x,y,z:longint);
begin
  inc(tot);
  e[tot,1]:=y;
  e[tot,2]:=last[x];
  e[tot,3]:=z;
  last[x]:=tot;
end;

procedure add1(z:longint);
begin
  inc(sum);
  a[sum]:=z;
end;

procedure init;
var
  i,x,y,z:longint;
begin
  readln(n,m);
  l:=1;
  if m=1 then f1:=true
    else f1:=false;
  f2:=true;f3:=true;
  for i:=1 to n-1 do
    begin
      readln(x,y,z);
      if x<>1 then f2:=false;
      if y<>x+1 then f3:=false;
      add(x,y,z);
      add(y,x,z);
      add1(z);
      f[x]:=z;
      r:=r+z;
    end;
end;

procedure qsort(l,r:longint);
var
  i,j,t:longint;
begin
  i:=l;j:=r;t:=a[(l+r)div 2];
  repeat
    while a[i]>t do inc(i);
    while a[j]<t do dec(j);
    if i<=j then
      begin
        a[0]:=a[i];a[i]:=a[j];a[j]:=a[0];
        inc(i);dec(j);
      end;
  until i>j;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
end;

function check(x:int64):boolean;
var
  i,s,ss:longint;
begin
  s:=0;ss:=0;
  for i:=1 to n-1 do
    begin
      s:=s+f[i];
      if s>=x then
        begin
          inc(ss);
          s:=0;
        end;
    end;
  if ss>=m then exit(true)
    else exit(false);
end;

procedure main1;
var
  d:array[0..100000]of longint;
  dis:array[0..50000]of longint;
  v:array[0..50000]of boolean;
  k,head,tail,i,y,x:longint;
begin
  ans:=0;
  for k:=1 to n do
    if e[last[k],2]=0 then
      begin
        for i:=1 to n do
          begin
            v[i]:=true;
            dis[i]:=maxlongint;
          end;
        v[k]:=false;head:=1;tail:=1;
        d[1]:=k;dis[k]:=0;
        while head<=tail do
          begin
            x:=d[head];
            i:=last[x];
            while i>0 do
              begin
                y:=e[i,1];
                if (dis[x]+e[i,3]<dis[y])and(v[y]) then
                  begin
                    dis[y]:=dis[x]+e[i,3];
                    inc(tail);
                    d[tail]:=y;
                    v[y]:=false;
                  end;
                i:=e[i,2];
              end;
            inc(head);
          end;
        for i:=1 to n do
          if dis[i]>ans then ans:=dis[i];
      end;
  writeln(ans);
end;

procedure main3;
var
  i,j:longint;
  t:int64;
begin
  ans:=0;
  while l<=r do
    begin
      t:=(l+r)div 2;
      if check(t) then
        begin
          ans:=t;
          l:=t+1;
        end
      else r:=t-1;
    end;
  writeln(ans);
end;

procedure main2;
var
  i,j:longint;
begin
  ans:=123456789101112;
  qsort(1,sum);
  for i:=1 to m do
    ans:=min(ans,a[i]+a[2*m-i+1]);
  writeln(ans);
end;

begin
  assign(input,'track.in');reset(input);
  assign(output,'track.out');rewrite(output);
  init;
  if f2 then main2
    else begin
           if f1 then main1
             else main3;
         end;
  close(input);close(output);
end.