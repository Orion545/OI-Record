var
  n,m,i,x,y,dep:longint;
  bo:boolean;
  map:array[0..5002,0..5002]of boolean;
  p,pp:array[0..5002]of boolean;
  ans,tic:array[0..5002]of longint;

procedure dfs(k:longint);
var
  i:longint;
begin
    for i:=1 to n do if not p[i] and map[k,i] then begin
        p[i]:=true;
        inc(dep); ans[dep]:=i;
        dfs(i);
    end;
end;

procedure dfs1(k,last:longint);
var
  i,j:longint;
begin
    for i:=1 to n do if not bo then begin
        if map[k,i] and (i<>last) and pp[i] then begin
            bo:=true;
            break;
        end;
        if not pp[i] and map[i,k] then begin
            pp[i]:=true;
            inc(dep); tic[dep]:=i;
            dfs1(i,k);
            if bo then exit;
        end;
    end;
    if not bo then exit;
    for j:=1 to dep do if tic[j]=i then break;
    inc(j);
    while tic[j]<tic[dep] do inc(j);
    map[tic[j],tic[j-1]]:=false; map[tic[j-1],tic[j]]:=false;
    exit;
end;

begin
    assign(input,'travel.in');reset(input);
    assign(output,'travel.out');rewrite(output);
    read(n,m);
    for i:=1 to m do begin
        read(x,y);
        map[x,y]:=true; map[y,x]:=true;
    end;
    dep:=1; pp[1]:=true; tic[1]:=1; bo:=false;
    if m=n then begin
        pp[1]:=true;
        dfs1(1,0);
    end;
    p[1]:=true; dep:=1; ans[1]:=1;
    dfs(1);
    for i:=1 to dep do write(ans[i],' ');
    close(input);close(output);
end.