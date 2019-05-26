var
        i,j,k,l,n,m,t,maxx:longint;
        a:array[1..1000] of longint;
        flag:array[1..100000] of boolean;
        gs:array[0..100000] of longint;
function max(x,y:longint):longint;
begin
        if x>y then exit(x);exit(y);
end;
procedure qsort(l,r:longint);
var
        i,j,k,mid:longint;
begin
        i:=l;j:=r;
        mid:=gs[(l+r) div 2];
        repeat
                while gs[i]<mid do inc(i);
                while gs[j]>mid do dec(j);
                if i<=j then
                begin
                        k:=gs[i];
                        gs[i]:=gs[j];
                        gs[j]:=k;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if i<r then qsort(i,r);
        if l<j then qsort(l,j);
end;
begin
        assign(input,'money.in');reset(input);
        assign(output,'money.out');rewrite(output);
        readln(t);
        while t>0 do
        begin
                dec(t);
                readln(n);
                maxx:=0;
                for i:=1 to n do
                begin
                        read(a[i]);
                        maxx:=max(maxx,a[i]);
                end;
                for i:=1 to n do
                begin
                        for j:=i+1 to n do
                        begin
                                if a[i]>a[j] then
                                begin
                                        k:=a[i];
                                        a[i]:=a[j];
                                        a[j]:=k;
                                end;
                        end;
                end;
                gs[0]:=1;
                gs[1]:=0;
                m:=0;
                fillchar(flag,sizeof(flag),false);
                for i:=1 to n do
                if not flag[a[i]] then
                begin
                        inc(m);
                        qsort(1,gs[0]);
                        l:=gs[0];
                        for j:=1 to maxx div i do
                        begin
                                for k:=1 to l do
                                begin
                                        if a[i]*j+gs[k]>maxx then break;
                                        if not flag[a[i]*j+gs[k]] then
                                        begin
                                                flag[a[i]*j+gs[k]]:=true;
                                                inc(gs[0]);
                                                gs[gs[0]]:=a[i]*j+gs[k];
                                        end;
                                end;
                        end;
                end;
                writeln(m);
        end;
        close(input);close(output);
end.
