var
        a:array[0..2000,0..2000] of longint;
        b:array[0..2000,0..2000] of longint;
        vis:array[0..2000] of boolean;
        i,n,m,x,y,z,ans:Longint;

begin
        assign(input,'track.in');
        reset(input);
        assign(output,'track.out');
        rewrite(output);
        readln(n,m);
        ans:=0;
        for i:=1 to n-1 do
        begin
                readln(x,y,z);
                a[x,y]:=z;
                inc(b[x,0]);
                b[x,b[x,0]]:=y;
                a[y,x]:=z;
                inc(b[y,0]);
                b[y,b[y,0]]:=x;
                ans:=ans+z;
        end;
        write(ans);
        close(input);
        close(output);
end.
