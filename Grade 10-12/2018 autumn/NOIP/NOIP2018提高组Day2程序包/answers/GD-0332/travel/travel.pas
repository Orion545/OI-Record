type
  arr=array[0..6000]of longint;
var
  top,num,tot,sum,n,m,i,j:longint;
  f:boolean;
  last,ans,s,a:array[0..6000]of longint;
  e:array[0..10000,1..2]of longint;
  v:array[0..6000]of boolean;

procedure add(x,y:longint);
begin
  inc(tot);
  e[tot,1]:=y;
  e[tot,2]:=last[x];
  last[x]:=tot;
end;

procedure init;
var
  i,x,y:longint;
begin
  readln(n,m);
  for i:=1 to m do
    begin
      readln(x,y);
      add(x,y);
      add(y,x);
    end;
end;

procedure up(x:longint;var a:arr);
var
  i,t:longint;
begin
  i:=x;
  while(a[i div 2]>a[i])and(i div 2>0)do
    begin
      t:=a[i div 2];a[i div 2]:=a[i];a[i]:=t;
      i:=i div 2;
    end;
end;

procedure insert(x:longint;var a:arr);
begin
  inc(a[0]);
  a[a[0]]:=x;
  up(a[0],a);
end;

procedure delete(var a:arr);
var
  t,i,j:longint;
begin
  a[1]:=a[a[0]];dec(a[0]);
  i:=1;
  while((i*2<=a[0])and(a[i*2]<a[i]))or((i*2+1<=a[0])and(a[i*2+1]<a[i])) do
    begin
      if(i*2+1<=a[0])and(a[i*2+1]<a[i*2]) then j:=i*2+1
        else j:=i*2;
      t:=a[i];a[i]:=a[j];a[j]:=t;
      i:=j;
    end;
end;

procedure dfs2(x:longint);
var
  i,min,s:longint;
  d:arr;
begin
  inc(top);ans[top]:=x;
  v[x]:=false;
  fillchar(d,sizeof(d),0);
  i:=last[x];
  while i>0 do
    begin
      if (v[e[i,1]])
        then insert(e[i,1],d);
      i:=e[i,2];
    end;
  while d[0]>0 do
    begin
      dfs2(d[1]);
      delete(d);
    end;
end;

begin
  assign(input,'travel.in');reset(input);
  assign(output,'travel.out');rewrite(output);
  init;
  f:=true;
  num:=0;
  fillchar(v,sizeof(v),true);
  f:=true;
  dfs2(1);
  for i:=1 to n do
    write(ans[i],' ');
  close(input);close(output);
end.


