var
        i,j,k,l,n,m:longint;
        dl,d:array[0..200000] of int64;
        ans:int64;
begin
        assign(input,'road.in');reset(input);
        assign(output,'road.out');rewrite(output);
        readln(n);
        for i:=1 to n do
        begin
                read(d[i]);
        end;
        for i:=1 to n do
        begin
                if dl[m]>d[i] then
                begin
                        ans:=ans+dl[m]-d[i];
                end;
                while (m>0) and (d[i]<=dl[m]) do
                begin
                        dl[m]:=0;
                        dec(m);
                end;
                inc(m);
                dl[m]:=d[i];
        end;
        if m>0 then ans:=ans+dl[m];
        writeln(ans);
        close(input);close(output);
end.
