const
  maxn=2000;

type
  rec=record
        t,next:longint;
  end;

var
  map:array[0..maxn+1,0..maxn+1] of boolean;
  edge:array[0..maxn+1] of rec;
  v,use:array[0..maxn+1] of boolean;
  g,cost,indegree:array[0..maxn+1] of longint;
  n,m,i,x,y,a,b,total,min,ans,j:longint;
  s:string;

function check:boolean;
var
  i,q:longint;
  flag:array[0..maxn+1] of boolean;
begin
  fillchar(flag,sizeof(flag),false);
  for i:=1 to n do
    if v[i] then
      begin
        flag[i]:=true;
        q:=g[i];
        while q<>0 do
          begin
            flag[edge[q].t]:=true;
            q:=edge[q].next;
        end;
  end;
  for i:=1 to n do
    if not flag[i] then exit(false);
  exit(true);
end;

procedure dfs;
var
  i:longint;
begin
  if check then
    begin
      if min<ans then
        ans:=min;
      exit;
  end;
  for i:=1 to n do
    if not(v[i]) and not(use[i]) then
      begin
        v[i]:=true;
        min:=min+cost[i];
        dfs;
        v[i]:=false;
        min:=min-cost[i];
  end;
end;

procedure add(x,y:longint);
begin
  inc(total);
  edge[total].t:=y;
  edge[total].next:=g[x];
  g[x]:=total;
end;

begin
  assign(input,'defense.in');reset(input);
  assign(output,'defense.out');rewrite(output);
  readln(n,m,s);
  for i:=1 to n do
    if i<n then read(cost[i])
      else readln(cost[i]);
  for i:=1 to n-1 do
    begin
      readln(x,y);
      inc(indegree[x]);inc(indegree[y]);
      map[x,y]:=true;
      map[y,x]:=true;
      add(x,y);
      add(y,x);
  end;
  for j:=1 to m do
    begin
      readln(a,x,b,y);
      if (x=0) and (y=0) and ((indegree[a]=1) or (indegree[b]=1)) and (map[a,b]) then
        begin
          writeln(-1);
          continue;
      end;
      ans:=maxlongint;
      min:=0;
      fillchar(use,sizeof(use),false);
      fillchar(v,sizeof(v),false);
      if x=0 then use[a]:=true;
      if y=0 then use[b]:=true;
      if x=1 then
        begin
          v[a]:=true;
          min:=min+cost[a];
      end;
      if y=1 then
        begin
          v[b]:=true;
          min:=min+cost[b];
      end;
      dfs;
      writeln(ans);
  end;
  close(input);close(output);
end.