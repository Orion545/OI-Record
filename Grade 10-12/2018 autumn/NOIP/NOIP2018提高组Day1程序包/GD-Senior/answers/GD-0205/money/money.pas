var
        bz:boolean;
        t,o,n,i,j:longint;
        s:array[0..200] of longint;
        a:array[1..200] of longint;
procedure swap(var a,b:longint);
var
        c:longint;
begin
        c:=a;
        a:=b;
        b:=c;
end;
procedure qsort(l,r:longint);
var
        i,j,m:longint;
begin
        i:=l;
        j:=r;
        m:=a[(i+j) div 2];
        repeat
                while a[i]<m do inc(i);
                while a[j]>m do dec(j);
                if i<=j then
                begin
                        swap(a[i],a[j]);
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if l<j then qsort(l,j);
        if i<r then qsort(i,r);
end;
procedure pd(x:longint);
var
        i:longint;
begin
        if x=0 then
        begin
                bz:=true;
                exit;
        end;
        for i:=1 to s[0] do
        begin
                if x<s[i] then exit;
                pd(x-s[i]);
                if bz then exit;
        end;
end;
begin
        assign(input,'money.in');reset(input);
        assign(output,'money.out');rewrite(output);
        readln(t);
        for o:=1 to t do
        begin
                read(n);
                for i:=1 to n do read(a[i]);
                qsort(1,n);
                s[0]:=1;
                s[1]:=a[1];
                for i:=2 to n do
                begin
                        for j:=1 to s[0] do if a[i] mod s[j]=0 then break;
                        if a[i] mod s[j]=0 then continue;
                        bz:=false;
                        pd(a[i]);
                        if not(bz) then
                        begin
                                inc(s[0]);
                                s[s[0]]:=a[i];
                        end;
                end;
                writeln(s[0]);
        end;
end.