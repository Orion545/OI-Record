var
        ans,t,n,i,j,k,zd:longint;
        a:array[1..1000]of longint;
        bz,f:array[1..50000]of boolean;
begin
        assign(input,'money.in');
        reset(input);
        assign(output,'money.out');
        rewrite(output);
        read(t);
        while(t>0)do
        begin
                read(n);
                fillchar(bz,sizeof(bz),false);
                fillchar(f,sizeof(f),false);
                zd:=0;
                for i:=1 to n do
                begin
                        read(a[i]);
                        if(a[i]>zd)then zd:=a[i];
                        f[a[i]]:=true;
                end;
                for i:=1 to n do
                begin
                        for j:=1 to zd-a[i] do
                        begin
                                if(bz[j])or(f[j])then
                                begin
                                        for k:=1 to (zd-j)div a[i] do
                                        begin
                                                bz[j+a[i]*k]:=true;
                                        end;
                                end;
                        end;
                        for j:=2 to zd div a[i] do
                        begin
                                bz[a[i]*j]:=true;
                        end;
                end;
                ans:=0;
                for i:=1 to zd do
                begin
                        if(f[i])and(bz[i]=false)then
                        begin
                                inc(ans);
                        end;
                end;
                writeln(ans);
                dec(t);
        end;
        close(input);
        close(output);
end.