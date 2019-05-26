var
        a:array[0..500] of longint;
        f:array[0..500] of boolean;
        min,t,i,j,k,l,m,n,ans:Longint;


procedure kp(l,r:longint);
var
        i,j,x,y:longint;
begin
        i:=l;
        j:=r;
        x:=a[(i+j) div 2];
        while i<=j do
        begin
                while a[i]<x do inc(i);
                while a[j]>x do dec(j);
                if i<=j then
                begin
                        y:=a[i];
                        a[i]:=a[j];
                        a[j]:=y;
                        inc(i);
                        dec(j);
                end;
        end;
        if i<r then kp(i,r);
        if l<j then kp(l,j);
end;

begin
        assign(input,'money.in');
        reset(input);
        assign(output,'money.out');
        rewrite(output);
        readln(t);
        for t:=1 to t do
        begin
                readln(n);
                for i:=1 to n do
                        read(a[i]);
                kp(1,n);
                fillchar(f,sizeof(f),1);
                for i:=1 to n-1 do
                        for j:=i+1 to n do
                                if a[j] mod a[i]=0  then f[j]:=false;
                for i:=1 to n-2 do
                        for j:=i+1 to n-1 do
                                for k:=j+1 to n do
                                        if f[k] then
                                                for l:=1 to a[k] div a[i] do
                                                begin
                                                        for m:=1 to a[k] div a[j] do
                                                                if a[i]*l+a[j]*m=a[k] then
                                                                begin
                                                                        f[k]:=false;
                                                                        break;
                                                                end;
                                                        if not f[k] then break;
                                                end;
                ans:=0;
                for i:=1 to n do
                        if f[i] then inc(ans);
                writeln(ans);
        end;
        close(input);
        close(output);
end.