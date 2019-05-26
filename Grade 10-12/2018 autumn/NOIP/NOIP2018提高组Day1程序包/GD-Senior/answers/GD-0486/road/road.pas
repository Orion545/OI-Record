var n,i,j,ll,rr,min,now:longint;
    tot:int64;
    a,jl,wz:array[0..100001] of longint;
    use:array[0..100001] of boolean;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
    i:=l;
    j:=r;
    x:=a[(l+r) div 2];
    repeat
        while a[i]<x do inc(i);
        while x<a[j] do dec(j);
        if not(i>j) then begin
            y:=a[i];
            a[i]:=a[j];
            a[j]:=y;
            y:=wz[i];
            wz[i]:=wz[j];
            wz[j]:=y;
            inc(i);
            j:=j-1;
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
end;
begin
assign(input,'road.in');reset(input);
assign(output,'road.out');rewrite(output);
    read(n);
    for i:=1 to n do begin
        read(a[i]);
        jl[i]:=a[i];
        wz[i]:=i;
    end;
    sort(1,n);
    for i:=1 to n do use[i]:=false;
    for i:=n downto 1 do if not use[wz[i]] then begin
        now:=wz[i];
        while (now<>0) and (jl[now]=jl[wz[i]]) do dec(now);
        min:=jl[now];
        ll:=now+1;
        now:=wz[i];
        while (now<>n+1) and (jl[now]=jl[wz[i]]) do inc(now);
        if min<jl[now] then min:=jl[now];
        rr:=now-1;
        tot:=tot+jl[wz[i]]-min;
        for j:=ll to rr do begin
            use[j]:=true;
            jl[j]:=min;
        end;
    end;
    write(tot);
close(input);close(output);
end.