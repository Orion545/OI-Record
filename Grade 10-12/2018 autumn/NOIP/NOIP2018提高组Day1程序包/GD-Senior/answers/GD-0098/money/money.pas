var
        t,n,i,j,ans,maxn:longint;
        a:array[0..1000] of longint;
        f:array[-25000..25000] of boolean;
procedure qsort(l,r:longint);
var
        i,j,t,mid:longint;
begin
        i:=l;
        j:=r;
        mid:=a[(l+r) shr 1];

        while i<j do
        begin
                while a[i]<mid do inc(i);
                while a[j]>mid do dec(j);

                if i<=j then
                begin
                        t:=a[i]; a[i]:=a[j]; a[j]:=t;

                        inc(i); dec(j);
                end;
        end;

        if i<r then qsort(i,r); if l<j then qsort(l,j);
end;
begin
        assign(input,'money.in');reset(input);
        assign(output,'money.out');rewrite(output);

        readln(t);

        while t>0 do
        begin
                readln(n); maxn:=0; fillchar(f,sizeof(f),false); f[0]:=true;

                for i:=1 to n do
                begin
                        read(a[i]); if a[i]>maxn then maxn:=a[i];
                end;

                qsort(1,n);

                ans:=1; for i:=1 to maxn do if not f[i] then f[i]:=f[i] or f[i-a[1]];

                for i:=2 to n do
                        if not f[a[i]] then
                        begin
                                inc(ans);

                                for j:=1 to maxn do if not f[j] then f[j]:=f[j] or f[j-a[i]];
                        end;

                writeln(ans); dec(t);
        end;

        close(input);close(output);
end.
