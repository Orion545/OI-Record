var i,j:longint;
    k,l,m,n,q,w,ans:int64;
    a,b,st,ed:array[0..100505] of int64;
function solve(l,r,vl:int64):int64;
var i:longint;
    mn,tot,q,fr,ed:int64;
begin
    if l=r then exit(a[l]-vl);
    mn:=maxlongint*(maxlongint-1);
    tot:=0;
    q:=0;
    fr:=l-1;
    for i:=l to r do if a[i]<mn then mn:=a[i];
    for i:=l to r do if a[i]=mn then begin
        if i-1>=fr+1 then q:=q+solve(fr+1,i-1,mn);
        fr:=i;
    end;
    if fr+1<=r then q:=q+solve(fr+1,r,mn);
    q:=q+mn-vl;
    exit(q);
end;
begin
assign(input,'road.in'); reset(input);
assign(output,'road.out');rewrite(output);
    readln(n);
    for i:=1 to n do read(a[i]);
    readln;
    ans:=solve(1,n,0);
    writeln(ans);
    close(input); close(output);
end.
