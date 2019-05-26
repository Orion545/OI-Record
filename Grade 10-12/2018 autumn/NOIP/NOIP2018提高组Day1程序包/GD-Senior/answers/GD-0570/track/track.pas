var tot,n,m,i,a,b,c,r,k,l,mid,ans:longint;
p:boolean;
s:array[1..1000000] of longint;
begin
assign(input,'track.in');reset(input);
assign(output,'track.out');rewrite(output);
    readln(n,m);
    for i:=1 to n-1 do begin
        readln(a,b,c);
        s[b]:=c;
        r:=r+c;
    end;
    l:=0;
    for k:=1 to 50 do begin
        mid:=(l+r) div 2;
        tot:=m;
        ans:=0;
        p:=false;
        for i:=2 to n do begin
            ans:=ans+s[i];
            if ans>=mid then begin
               dec(tot);
               ans:=0;
            end;
            if tot<=0 then begin
                p:=true;
                break;
            end;
        end;
        if p then begin
            l:=mid;
        end
        else r:=mid-1;
    end;
    writeln(r);
close(input);close(output);
end.