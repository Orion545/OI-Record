var
        n,i,ans:longint;
        a:array[0..200000] of longint;
begin
        assign(input,'road.in');reset(input);
        assign(output,'road.out');rewrite(output);

        readln(n);

        for i:=1 to n do read(a[i]);

        for i:=1 to n do if a[i]>a[i-1] then ans:=ans+a[i]-a[i-1];

        writeln(ans);

        close(input);close(output);
end.