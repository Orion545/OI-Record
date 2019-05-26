const
        mo=1000000007;
var
        ans:int64;
        n,m,i,j,k,x,r,s:longint;
        e:array[0..256,0..8] of longint;
        p:array[0..256,0..256] of longint;
        f:array[0..1,0..256] of int64;
function power(a,b:int64):int64;
var
        s:int64;
begin
        s:=1;
        while b<>0 do
        begin
                if b mod 2=1 then s:=s*a mod mo;
                a:=sqr(a) mod mo;
                b:=b div 2;
        end;
        exit(s);
end;
begin
        assign(input,'game.in');
        reset(input);
        assign(output,'game.out');
        rewrite(output);
        readln(m,n);
        s:=(1 shl m)-1;
        f[0,0]:=1;
        for i:=1 to s do
        begin
                x:=i; j:=1;
                while x<>0 do
                begin
                        if x mod 2=1 then
                        begin
                                inc(e[i,0]);
                                e[i,e[i,0]]:=j;
                        end;
                        x:=x div 2;
                        inc(j);
                end;
                f[0,i]:=1;
        end;
        ans:=power(2,n*m);
        for i:=1 to s do
        begin
                for j:=0 to s do
                begin
                        if i and j>0 then
                        begin
                                inc(p[i,0]);
                                p[i,p[i,0]]:=j;
                        end;
                end;
        end;
        for i:=0 to n-1 do
        begin
                r:=i mod 2;
                fillchar(f[1-r],sizeof(f[1-r]),0);
                for j:=0 to s do
                begin
                        if i>1 then ans:=(ans-f[r,j]) mod mo;
                        //x:=s xor (j div 2);
                        x:=(s xor j)div 2;
                        for k:=1 to p[x,0] do f[1-r,p[x,k]]:=(f[1-r,p[x,k]]+f[r,j]) mod mo;
                end;
        end;
        r:=n mod 2;
        for i:=0 to s do ans:=(ans-f[r,i]) mod mo;
        writeln(ans);
        close(input);
        close(output);
end.
