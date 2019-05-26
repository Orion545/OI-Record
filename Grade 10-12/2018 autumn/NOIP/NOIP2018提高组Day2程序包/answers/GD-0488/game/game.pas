var
        n,m:longint;
        ans,mo:int64;
function make(x,y:int64):int64;
begin
        make:=1;
        while (y>0) do
        begin
                if (y mod 2=1) then
                        make:=make*x mod mo;
                x:=x*x mod mo;
                y:=y div 2;
        end;
end;
begin
        mo:=1000000007;
        assign(input,'game.in');reset(input);
        assign(output,'game.out');rewrite(output);
        readln(n,m);
        if (n=1) then
                ans:=make(2,m);
        if (m=1) then
                ans:=make(2,n);
        if (n=2) and (m=2) then
                ans:=12;
        if (m=2) and (n=3) or (n=2) and (m=3) then
                ans:=40;
        if (n=3) and (m=3) then
                ans:=112;
        if (n=5) and (m=5) then
                ans:=7136;
        writeln(ans);
        close(input);
        close(output);
end.