const
        moder=1000000007;
var
        f:array[0..8,0..512] of int64;
        n,m,i,j,k:Longint;
        sum,s:int64;
begin
        assign(input,'game.in');reset(input);
        assign(output,'game.out');rewrite(output);
        read(n,m);
        fillchar(f,sizeof(f),0);
        s:=1;
        k:=0;
        for i := 1 to n do
                for j := 1 to m do
                        if i<j then inc(k);
        for i := 1 to k do s:=(s*2) mod moder;
        s:=(s-1)*4 mod moder;
        sum:=1;
        for i := 1 to n*m do sum:=(sum*2) mod moder;
        sum:=(sum-s) mod moder;
        writeln(sum);
        close(input);close(output);
end.
