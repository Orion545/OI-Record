var next,get,n,m,i,j,k,ll,rr,tot:longint;
    map:array[0..20000,1..2] of longint;
    last,nows,minl,nn:array[0..20000] of longint;
    back:array[0..5001] of boolean;
procedure getmap(st,en:longint);
begin
    inc(tot);
    map[tot,next]:=last[st];
    map[tot,get]:=en;
    last[st]:=tot;
end;
procedure pd;
var i:longint;
begin
    for i:=1 to n do if nows[i]>minl[i] then exit;
    for i:=1 to n do if nows[i]<minl[i] then minl[i]:=nows[i];
end;
procedure bfs(now,dep:longint);
var i,p,nex:longint;
begin
    for i:=1 to n do if nn[i]>3 then exit;
    for i:=1 to dep do if nows[i]>minl[i] then exit;
    if dep=n then begin
        nows[n]:=now;
        pd;
    end else begin
        p:=0;
        for i:=1 to dep do if nows[i]=now then p:=i;
        if dep=1 then p:=0;
        if p=0 then begin
            nex:=last[now];
            nows[dep]:=now;
            while nex<>0 do begin
                p:=0;
                for i:=1 to dep do if nows[i]=map[nex,get] then p:=i;
                if p=0 then bfs(map[nex,get],dep+1);
                nex:=map[nex,next];
            end;
            for i:=1 to dep do if nows[i]=now then p:=i;
            for i:=p-1 downto 1 do begin
                back[nows[i]]:=true;
                inc(nn[nows[i]]);
                bfs(nows[i],dep);
                dec(nn[nows[i]]);
                back[nows[i]]:=false;
            end;
            nows[dep+1]:=0;
        end else if back[now] then begin
            nex:=last[now];
            while nex<>0 do begin
                p:=0;
                for i:=1 to dep do if nows[i]=map[nex,get] then p:=i;
                if p=0 then bfs(map[nex,get],dep+1);
                nex:=map[nex,next];
            end;
        end;
    end;
end;
begin
assign(input,'travel.in');reset(input);
assign(output,'travel.out');rewrite(output);
    next:=1;
    get:=2;
    read(n,m);
    for i:=1 to m do begin
        read(ll,rr);
        getmap(ll,rr);
        getmap(rr,ll);
    end;
    for i:=2 to n do minl[i]:=maxlongint;
    for i:=1 to n do back[i]:=false;
    minl[1]:=1;
    nows[1]:=1;
    bfs(1,1);
    for i:=1 to n-1 do write(minl[i],' ');
    write(minl[n]);
close(input);close(output);
end.
