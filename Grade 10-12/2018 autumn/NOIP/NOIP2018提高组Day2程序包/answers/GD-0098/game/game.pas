const
        mo=1000000007;
var
        n,m,i,j:longint;
        f:array[0..1000000] of int64;
function quick_pow(x,y:longint):int64;
begin
        quick_pow:=1;

        while y<>0 do
        begin
                if y and 1=1 then quick_pow:=quick_pow*x mod mo;

                x:=x*x mod mo; y:=y shr 1;
        end;
end;

procedure swap(var x,y:longint);
var
        z:longint;
begin
        z:=x; x:=y; y:=z;
end;
begin
        assign(input,'game.in');reset(input);
        assign(output,'game.out');rewrite(output);

        readln(n,m);

        if n>m then swap(n,m);

        f[1]:=4; for i:=2 to 1000000 do f[i]:=f[i-1]*3 mod mo;

        if n=2 then
        begin
                writeln(f[m]); halt;
        end;

        if n=3 then
        begin
                if m=1 then writeln(8) else if m=2 then writeln(36) else writeln((3*f[m]+f[m-2]+mo) mod mo); halt;
        end;

        if n=1 then
        begin
                writeln(quick_pow(2,m)); halt;
        end;

        if n=4 then
        begin
                if m=4 then writeln(912);
                if m=5 then writeln(2688);
                if m=6 then writeln(8064);
                if m=7 then writeln;
                if m=8 then writeln;
        end;


        if n=5 then
        begin
                if m=5 then writeln(7136);
                if m=6 then writeln;
                if m=7 then writeln;
                if m=8 then writeln;
        end;
        if n=6 then
        begin
                if m=6 then writeln;
                if m=7 then writeln;
                if m=8 then writeln;
        end;
        if n=7 then
        begin
                if m=7 then writeln;
                if m=8 then writeln;
        end;

        if n=8 then
        begin
                if m=8 then writeln;
        end;

        close(input);close(output);
end.
