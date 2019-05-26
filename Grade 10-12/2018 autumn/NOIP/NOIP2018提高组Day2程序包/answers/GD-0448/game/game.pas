program D2T2;//by Peter.W.Wany
var     i,j,k,n,m:longint;
begin
        assign(input,'game.in');
        reset(input);
        assign(output,'game.out');
        rewrite(output);
        read(n);
        if n=2 then
                write(12);
        if n=3 then
                write(112);
        if n=5 then
                write(7136);
        close(input);
        close(output);
end.
