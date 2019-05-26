var
  i,n,m,t,x,y:longint;
  a:array[0..5000,0..5000]of boolean;
  b:array[0..5000]of boolean;
  s:array[0..5000]of longint;

procedure dfs1(k:longint);
var
  i:longint;
begin
  for i:=2 to n do
    if (not b[i])and(a[k,i]) then
    begin
      inc(t);
      s[t]:=i;
      b[i]:=true;
      dfs1(i);
      b[i]:=false;
    end;
end;

function min(a,b:longint):longint; begin if a<b then exit(a); exit(b); end;
procedure dfs2(t,k:longint);
var
  i:longint;
begin

  {for i:=2 to n do
    if (not b[i])and(a[last,i]) then
    begin
      if s[t]=0 then s[t]:=i else s[t]:=min(s[t],i);
      b[i]:=true;
      dfs2(t+1,i,last);
      b[i]:=false;
    end;  }

  for i:=2 to n do
    if (not b[i])and(a[k,i]) then
    begin
      if s[t]=0 then s[t]:=i else s[t]:=min(s[t],i);
      b[i]:=true;
      dfs2(t+1,k);
      dfs2(t+1,i);

    end;
end;
begin
  assign(input,'travel.in');
  reset(input);
  assign(output,'travel.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    readln(x,y);
    a[x,y]:=true;
    a[y,x]:=true;
  end;

  b[1]:=true;
  s[1]:=1;
  t:=1;
  if m=n-1 then dfs1(1)
  else dfs2(2,1);

  for i:=1 to n do write(s[i],' ');
  close(output);
  close(input);
end.