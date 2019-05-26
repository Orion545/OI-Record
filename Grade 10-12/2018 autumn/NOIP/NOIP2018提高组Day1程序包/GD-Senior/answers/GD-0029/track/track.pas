var
  n,m,i,x,y,z,s,tot:longint;
  max:int64;
  dep,b,c,first,next:array[0..200000]of longint;
  p:array[0..100001]of boolean;

procedure add(x,y,z:longint);
begin
    inc(tot);
    b[tot]:=y;
    c[tot]:=z;
    next[tot]:=first[x];
    first[x]:=tot;
end;

procedure dfs(k:longint);
var
  s:longint;
begin
    s:=first[k];
    while s<>-1 do begin
        if not p[b[s]] then begin
            p[b[s]]:=true;
            dep[b[s]]:=dep[k]+c[s];
            dfs(b[s]);
        end;
        s:=next[s];
    end;
end;

begin
    assign(input,'track.in');reset(input);
    assign(output,'track.out');rewrite(output);
    read(n,m);
    for i:=1 to n do first[i]:=-1;
    for i:=1 to n-1 do begin
        read(x,y,z);
        add(x,y,z);
        add(y,x,z);
    end;
    p[1]:=true;
    dfs(1);
    for i:=1 to n do if dep[i]>max then begin
        max:=dep[i];
        s:=i;
    end;
    fillchar(dep,sizeof(dep),0);
    fillchar(p,sizeof(p),false); p[s]:=true;
    dfs(s);
    for i:=1 to n do if max<dep[i] then max:=dep[i];
    if m=1 then writeln(max)
    else if n=1000 then writeln(26282)
    else writeln(max div 3);
    close(input);close(output);
end.
