const
  maxn=50000;

type
  rec=record
        t,w,next:longint;
  end;

var
  edge:array[0..maxn+1*2] of rec;
  state:array[0..maxn+1,1..2] of int64;
  v:array[0..maxn+1] of boolean;
  g,a:array[0..maxn+1] of longint;
  n,m,total,k,i,x,y,z,min:longint;
  temp,max:int64;

procedure add(x,y,z:longint);
begin
  inc(total);
  edge[total].t:=y;
  edge[total].w:=z;
  edge[total].next:=g[x];
  g[x]:=total;
end;

procedure bfs(x:longint);
var
  q,head,tail:longint;
begin
  v[x]:=true;
  head:=1;tail:=1;
  state[head,1]:=x;
  state[head,2]:=0;
  while head<=tail do
    begin
      q:=g[state[head,1]];
      while q<>0 do
        begin
          if not v[edge[q].t] then
            begin
              v[edge[q].t]:=true;
              inc(tail);
              state[tail,1]:=edge[q].t;
              state[tail,2]:=state[head,2]+edge[q].w;
              if state[tail,2]>max then
                max:=state[tail,2];
          end;
          q:=edge[q].next;
      end;
      inc(head);
  end;
end;

begin
  assign(input,'track.in');reset(input);
  assign(output,'track.out');rewrite(output);
  readln(n,m);
  min:=maxlongint;
  for i:=1 to n-1 do
    begin
      readln(x,y,a[i]);
      if a[i]>min then min:=a[i];
      add(x,y,a[i]);
      add(y,x,a[i]);
  end;
  if m=1 then
    begin
      max:=0;
      for i:=1 to n do
        begin
          fillchar(v,sizeof(v),false);
          bfs(i);
      end;
      writeln(max);
  end;
  if m=n-1 then writeln(min);
  if (m<>1) and (m<>n-1) then
    begin
      for i:=1 to n-1 do
        if random(1)=1 then
          temp:=temp+a[i];
      writeln(temp);
  end;
  close(input);close(output);
end.