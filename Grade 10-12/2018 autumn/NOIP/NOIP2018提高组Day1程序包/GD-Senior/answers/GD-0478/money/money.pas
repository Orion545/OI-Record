var
        a,f:array[0..100000] of longint;
        n,i,j,k,t,maxa,ans:longint;
begin
        assign(input,'money.in');reset(input);
        assign(output,'money.out');rewrite(output);
        read(t);
        while t>0 do
        begin
                read(n);
                fillchar(f,sizeof(f),0);
                maxa:=0;
                for i := 1 to n do
                begin
                        read(a[i]);
                        if maxa<a[i] then maxa:=a[i];
                end;
                for i := 1 to n do
                begin
                        k:=1;
                        while a[i]*k<=maxa do
                        begin
                                inc(f[a[i]*k]);
                                inc(k);
                        end;
                end;
                for k := 1 to n do
                begin
                        for i := 1 to maxa do
                        begin
                                for j := 1 to (i div 2) do
                                begin
                                        if (f[j]<>0)and(f[i-j]<>0) then inc(f[i]);
                                end;
                        end;
                end;
                ans:=n;
                for i := 1 to n do
                begin
                        //write(f[i],' ');
                        if f[a[i]]>1 then dec(ans);
                end;
                //writeln;
                writeln(ans);
                dec(t);
        end;
        close(input);close(output);
end.
