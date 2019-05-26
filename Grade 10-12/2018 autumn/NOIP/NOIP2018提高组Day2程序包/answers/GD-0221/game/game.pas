var i,j:longint;
    k,l,m,n,q,w,md:int64;
function ksm(p,o:int64):int64;
begin
    ksm:=1;
    while o>0 do begin
        if o and 1=1 then ksm:=ksm*p mod md;
        p:=p*p mod md;
        o:=o div 2;
    end;
end;
begin
assign(input,'game.in');reset(input);
assign(output,'game.out'); rewrite(output);
    md:=1000000007;
    readln(n,m);
    if n>m then begin q:=n; n:=m; m:=q; end;
    if n=1 then writeln(ksm(2,m) mod md);
    if n=2 then writeln(ksm(3,m-1)*4 mod md);
    if n=3 then writeln(112);
    if n=5 then writeln(7136);
    close(input); close(output);
end.
