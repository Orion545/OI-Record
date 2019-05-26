const
  maxn=5000;

var
  list:array [0..maxn,0..maxn] of longint;
  data:array [0..maxn] of longint;
  v,flag:array [0..maxn] of boolean;
  return1:boolean;
  n,m,z:longint;

procedure sort(x,n:longint);
var
  i,j,k:longint;
begin
  for i:=1 to n do
    for j:=i+1 to n do
      if list[x,i]>list[x,j] then
        begin
          k:=list[x,i];
          list[x,i]:=list[x,j];
          list[x,j]:=k;
        end;
end;

procedure init;
var
  i,j,x,y:longint;
begin
  readln(n,m);
  for i:=1 to m do
    begin
      readln(x,y);
      inc(list[x,0]);
      list[x,list[x,0]]:=y;
      inc(list[y,0]);
      list[y,list[y,0]]:=x;
    end;
  for i:=1 to n do
    sort(i,list[i,0]);
end;

procedure print;
var
  i:longint;
begin
  for i:=1 to z do
    write(data[i],' ');
end;

procedure dfs(dep,x:longint);
var
  i,j:longint;
  temp:boolean;
begin
  if z=n then
    begin
      print;
      close(input);close(output);
      halt;
    end;
  temp:=true;
  for i:=1 to list[x,0] do
    if not v[list[x,i]] then
      begin
        temp:=false;
        inc(z);
        data[z]:=list[x,i];
        flag[x]:=true;
        v[list[x,i]]:=true;
        if return1 then
          return1:=false;
        dfs(dep+1,list[x,i]);
        if not return1 then
          begin
            dec(z);
            flag[x]:=false;
            data[z+1]:=0;
            v[list[x,i]]:=false;
          end;
      end
    else
      if (i=list[x,0]) and temp then
        begin
          return1:=true;
        end;
end;

begin
  assign(input,'travel.in');reset(input);
  assign(output,'travel.out');rewrite(output);
  init;
  z:=1;data[1]:=1;flag[1]:=true;
  v[1]:=true;
  dfs(1,1);
  close(input);close(output);
end.