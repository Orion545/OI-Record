const
  maxn=5000;

var
  map:array[0..maxn+1,0..maxn+1] of boolean;
  n,m,top,i,x,y:longint;
  ans:array[0..maxn+1] of longint;
  v:array[0..maxn+1] of boolean;

procedure dfs(x,dep:longint);
var
  i:longint;
begin
  if dep=n then exit;
  for i:=1 to n do
    if (map[x,i]) and not(v[i]) then
      begin
        v[i]:=true;
        inc(top);
        ans[top]:=i;
        dfs(i,dep+1);
  end;
end;

begin
  assign(input,'travel.in');reset(input);
  assign(output,'travel.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do
    begin
      readln(x,y);
      map[x,y]:=true;
      map[y,x]:=true;
  end;
  inc(top);
  ans[top]:=1;
  v[1]:=true;
  dfs(1,1);
  for i:=1 to n do
    write(ans[i],' ');
  writeln;
  close(input);close(output);
end.
