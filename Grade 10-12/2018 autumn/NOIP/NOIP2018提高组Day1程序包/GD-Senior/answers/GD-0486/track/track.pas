var n,m,i,j,k,rea,tot,r,maxfa:longint;
    a,b,l,map,last,fa,cos,llxx,rrxx,dian:array[0..30001] of longint;
    use:array[0..30001] of boolean;
    p,gg:boolean;
procedure sort(ll,rr:longint);
var i,j,x,y:longint;
begin
    i:=ll;
    j:=rr;
    x:=l[(ll+rr) div 2];
    repeat
        while l[i]<x do inc(i);
        while x<l[j] do dec(j);
        if not(i>j) then begin
            y:=l[i];
            l[i]:=l[j];
            l[j]:=y;
            inc(i);
            j:=j-1;
        end;
    until i>j;
    if ll<j then sort(ll,j);
    if i<rr then sort(i,rr);
end;
function getfa(a:longint):longint;
begin
    while fa[a]<>0 do a:=fa[a];
    exit(a);
end;
{procedure getdeep(dep,wz:longint);
var now:longint;
begin
    now:=last[wz];
    deep[wz]:=dep;
    while now<>0 do begin
        getdeep(dep+1,wz);
        now:=map[now];
    end;
end;  }
procedure maketree(a,b,l:longint);
begin
    if (fa[a]<>0) and (fa[b]<>0) then begin
        fa[getfa(a)]:=fa[getfa(b)];
        inc(tot);
        map[tot]:=last[b];
        dian[tot]:=a;
        cos[tot]:=l;
        last[b]:=tot;
    end else if fa[a]=0 then begin
        fa[a]:=b;
        inc(tot);
        map[tot]:=last[b];
        dian[tot]:=a;
        cos[tot]:=l;
        last[b]:=tot;
    end else begin
        fa[b]:=a;
        inc(tot);
        map[tot]:=last[a];
        dian[tot]:=b;
        cos[tot]:=l;
        last[a]:=tot;
    end;
end;
function ok(mm,ll,rr:longint):longint;
var l,r,lx,rx,rea,ssb,ssa,cost:longint;
begin
    l:=ll;
    r:=rr;
    lx:=1;
    rx:=1;
    llxx[1]:=l;
    rrxx[1]:=r;
    if use[l] then exit(0);
    if use[r] then exit(0);
    while fa[l]<>0 do begin
        l:=fa[l];
        inc(lx);
        llxx[lx]:=l;
        if use[l] then exit(0);
    end;
    while fa[r]<>0 do begin
        r:=fa[r];
        inc(rx);
        rrxx[rx]:=r;
        if use[r] then exit(0);
    end;
    for i:=lx downto 1 do
        for j:=rx downto 1 do if llxx[i]=rrxx[j] then rea:=llxx[i];
    cost:=0;
    while fa[ll]<>fa[rea] do begin
        ssa:=last[fa[ll]];
        ssb:=dian[ssa];
        while ssb<>ll do begin
            ssa:=map[ssa];
            ssb:=dian[ssa];
        end;
        cost:=cost+cos[ssa];
        ll:=fa[ll];
    end;
    while fa[rr]<>fa[rea] do begin
        ssa:=last[fa[rr]];
        ssb:=dian[ssa];
        while ssb<>rr do begin
            ssa:=map[ssa];
            ssb:=dian[ssa];
        end;
        cost:=cost+cos[ssa];
        rr:=fa[rr];
    end;
    if cost>=mm then exit(rea) else exit(0);
end;
procedure plus(l,r,faa:longint);
begin
    while l<>fa[faa] do begin
        use[l]:=true;
        l:=fa[l];
    end;
    while r<>fa[faa] do begin
        use[r]:=true;
        r:=fa[r];
    end;
end;
procedure jian(l,r,faa:longint);
begin
    while l<>fa[faa] do begin
        use[l]:=false;
        l:=fa[l];
    end;
    while r<>fa[faa] do begin
        use[r]:=false;
        r:=fa[r];
    end;
end;
procedure pd(mm,now,start:longint);
var i,rea:longint;
begin
    if now=m then gg:=true;
    if gg then exit;
    if start=n then exit;
    for i:=start+1 to n do begin
        rea:=ok(mm,start,i);
        if rea<>0 then begin
            plus(start,i,rea);
            pd(mm,now+1,i);
            jian(start,i,rea);
            if gg then exit;
        end;
    end;
    pd(mm,now,start+1);
end;
procedure ef(l,r:longint);
var mid:longint;
begin
    if l=r then begin
        write(l);
        exit;
    end;
    mid:=(l+r) div 2+1;
    gg:=false;
    pd(mid,0,1);
    if gg then ef(mid,r) else ef(l,mid-1);
end;
begin
assign(input,'track.in');reset(input);
assign(output,'track.out');rewrite(output);
    read(n,m);
    r:=0;
    tot:=0;
    p:=true;
    for i:=1 to n do use[i]:=false;
    for i:=1 to n-1 do begin
        read(a[i],b[i],l[i]);
        if a[i]<>1 then p:=false;
        maketree(a[i],b[i],l[i]);
        r:=r+l[i];
    end;
    if p then begin
        sort(1,n);
        write(l[n-m+1]);
    end else begin
        maxfa:=getfa(1);
        //getdeep(1,maxfa);
        ef(1,r div m);
    end;
close(input);close(output);
end.
