var
        ans:int64;
        n,i:longint;
        a:array[1..100010] of int64;
begin
        assign(input,'road.in');reset(input);
        assign(output,'road.out');rewrite(output);
        read(n);
        for i:=1 to n do
        begin
                read(a[i]);
                if i=1 then ans:=a[i] else
                begin
                        if a[i]<a[i-1] then continue;
                        ans:=ans+a[i]-a[i-1];
                end;
        end;
        writeln(ans);
end.
