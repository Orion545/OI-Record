var
        n,i:longint;
        ans:int64;
        a:array[0..100001]of int64;
begin
        assign(input,'road.in');
        reset(input);
        assign(output,'road.out');
        rewrite(output);
        read(n);
        for i:=1 to n do read(a[i]);
        for i:=0 to n-1 do
        begin
                if(a[i]<a[i+1])then ans:=ans+(a[i+1]-a[i]);
        end;
        writeln(ans);
        close(input);
        close(output);
end.