var
        q,n,i,h,t,x,mn,ans:longint;
        a:array[1..100] of longint;
        d:array[1..26000] of longint;
        bz:array[0..26000] of boolean;
function max(a,b:longint):longint;
begin
        if a>b then exit(a) else exit(b);
end;
begin
        assign(input,'money2.in');
        reset(input);
        assign(output,'money.out');
        rewrite(output);
        readln(q);
        while q>0 do
        begin
                dec(q);
                readln(n);
                fillchar(bz,sizeof(bz),true);
                h:=0; t:=0;
                mn:=0;
                for i:=1 to n do
                begin
                        read(a[i]);
                        mn:=max(mn,a[i]);
                        inc(t);
                        d[t]:=a[i];
                end;
                while h<t do
                begin
                        inc(h);
                        for i:=1 to n do
                        begin
                                x:=d[h]+a[i];
                                if x>mn then continue;
                                if bz[x] then
                                begin
                                        bz[x]:=false;
                                        inc(t);
                                        d[t]:=x;
                                end;
                        end;
                end;
                ans:=0;
                for i:=1 to n do
                        if bz[a[i]] then inc(ans);
                writeln(ans);
        end;
        close(input);
        close(output);
end.