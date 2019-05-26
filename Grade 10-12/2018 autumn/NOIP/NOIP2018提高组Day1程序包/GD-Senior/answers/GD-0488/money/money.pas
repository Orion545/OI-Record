var
        t,i,j,k,l,n,m,ans:longint;
        a:array[0..100] of longint;
        bj:array[0..100] of boolean;
        bz:array[0..25000] of longint;
function dg(t,x:longint):boolean;
var
        i:longint;
begin
        if (t=0) then exit(false);
        if (x mod a[t]=0) then
        begin
                bz[x]:=1;
                exit(true);
        end;
        if (bj[t]=false) then
                dg(t-1,x);
        for i:=0 to x div a[t] do
        begin
                if (bz[x-a[t]*i]=1) then
                begin
                        bz[x]:=1;
                        exit(true);
                end;
        end;
        for i:=0 to x div a[t] do
        begin
                if (bz[x-a[t]*i]=0) then
                begin
                        if (dg(t-1,x-a[t]*i)) then
                        begin
                                bz[x]:=1;
                                exit(true);
                        end;
                end;
        end;
        bz[x]:=2;
        exit(false);
end;
begin
        assign(input,'money.in');reset(input);
        assign(output,'money.out');rewrite(output);
        readln(t);
        for l:=1 to t do
        begin
                fillchar(bz,sizeof(bz),0);
                fillchar(bj,sizeof(bj),true);
                ans:=0;
                readln(n);
                for i:=1 to n do
                        read(a[i]);
                for i:=1 to n do
                        for j:=i+1 to n do
                                if (a[i]>a[j]) then
                                begin
                                        a[0]:=a[i];
                                        a[i]:=a[j];
                                        a[j]:=a[0];
                                end;
                for i:=2 to n do
                begin
                        bj[i]:=not dg(i-1,a[i]);
                        if (bj[i]) then
                                inc(ans);
                end;
                writeln(ans);
        end;
        close(input);
        close(output);
end.
