var t,k,ans,n,i,j,max:longint;
pp:array[-50000..50000] of boolean;
p:array[-50000..50000] of longint;
s:array[1..1000] of longint;
begin
assign(input,'money.in');reset(input);
assign(output,'money.out');rewrite(output);
    readln(t);
    for k:=1 to t do begin
        readln(n);
        ans:=n;
        max:=0;
        fillchar(pp,sizeof(pp),false);
        fillchar(p,sizeof(p),0);
        for i:=1 to n do begin
            read(s[i]);
            pp[s[i]]:=true;
            if s[i]>max then max:=s[i];
        end;
        p[0]:=1;
        for i:=1 to max do begin
            for j:=1 to n do begin
                p[i]:=p[i]+p[i-s[j]];
                if pp[i] and (p[i]>1) then begin
                   dec(ans);
                   break;
                end;
            end;
        end;
        writeln(ans);
    end;
    close(input);close(output);
end.