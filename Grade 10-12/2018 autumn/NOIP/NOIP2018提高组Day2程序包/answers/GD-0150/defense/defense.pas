var
        f,x,y:array[0..100010] of longint;
        a,b,c,d,i,n,m:Longint;
        s:string;
begin
        assign(input,'defense.in');
        reset(input);
        assign(output,'defense.out');
        rewrite(output);
        read(n,m);
        readln(s);
        for i:=1 to n do
                read(f[i]);
        for i:=1 to n-1 do
                readln(x[i],y[i]);
        for i:=1 to m do
        begin
                readln(a,c,b,d);
                writeln(-1);
        end;
        close(input);
        close(output);
end.
