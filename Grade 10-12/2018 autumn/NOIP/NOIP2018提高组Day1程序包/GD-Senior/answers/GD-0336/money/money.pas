var
        a:array[1..100]of longint;
        f:array[0..25000]of boolean;
        i,j,n,m,k,l,o,p:longint;
procedure swap(var x,y:longint);var z:longint;begin z:=x;x:=y;y:=z;end;
procedure kp(l,r:longint);
var
        i,j,m:longint;
begin
        i:=l;
        j:=r;
        m:=a[l];
        repeat
                while a[i]<m do inc(i);
                while a[j]>m do dec(j);
                if i<=j then
                begin
                        swap(a[i],a[j]);
                        i:=i+1;j:=j-1;
                end;
        until i>=j;
        if i<r then kp(i,r);
        if l<j then kp(l,j);
end;
begin
        assign(input,'money.in');reset(input);
        assign(output,'money.out');rewrite(output);
        read(m);
        while m>0 do
        begin
                m:=m-1;
                read(n);
                for i:=1 to n do read(a[i]);
                kp(1,n);
                p:=n;
                fillchar(f,sizeof(f),false);
                f[0]:=true;
                for i:=1 to 25000 do
                begin
                        for j:=1 to n do
                        if i>=a[j] then
                        begin
                                if i>a[j] then f[i]:=f[i] or f[i-a[j]];
                                if i=a[j] then
                                begin
                                        if f[i] then p:=p-1 else f[i]:=true;
                                end;
                        end else break;
                end;
                writeln(p);
        end;
        close(input);close(output);
end.