var
        h,i,j,k,l,n,m,ans:longint;
        a:array[0..100000] of longint;
begin
        assign(input,'road.in');reset(input);
        assign(output,'road.out');rewrite(output);
        readln(n);
        h:=0;
        ans:=0;
        for i:=1 to n do
        begin
                read(a[i]);
                if (a[i]>h) then
                        ans:=ans+a[i]-h;
                h:=a[i];
        end;
        writeln(ans);
        close(input);
        close(output);
end.