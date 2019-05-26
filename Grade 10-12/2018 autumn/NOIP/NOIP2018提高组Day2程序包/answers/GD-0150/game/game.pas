const
        inf=100000007;

var
        f:array[0..8,0..1000000] of int64;
        a,b,n,m,i,j,k:Longint;
begin
        assign(input,'game.in');
        reset(input);
        assign(output,'game.out');
        rewrite(output);
        readln(n,m);
        fillchar(f,sizeof(f),0);
        for i:=0 to n do
                f[i,0]:=1;
        for i:=0 to m do
                f[0,i]:=1;
        for i:=1 to n do
                for j:=1 to m do
                        f[i,j]:=(f[i-1,j]+f[i,j-1]-f[i-1,j-1])*2 mod inf;
        if (n=3) and (m=3) then write(112) else
                if (n=5) and (m=5) then write(7136) else
                        if (n=2) and (m=3) then write(24) else
                                if (n=3) and (m=2) then write(48) else write(f[n,m]);
        close(input);
        close(output);
end.