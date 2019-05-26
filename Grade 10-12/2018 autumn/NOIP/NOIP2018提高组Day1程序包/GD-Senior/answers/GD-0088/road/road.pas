var
        n,m,i,j,k,wz,ans,min,l,r:longint;
        a,b,c:array[0..1000000] of longint;
procedure kp(l,r:longint);
var
        i,j,k:longint;
begin
        k:=a[(l+r) div 2];
        i:=l;
        j:=r;
        repeat
                while a[i]<k do inc(i);
                while a[j]>k do dec(j);
                if i<=j then
                begin
                        a[0]:=a[i];
                        a[i]:=a[j];
                        a[j]:=a[0];
                        b[0]:=b[i];
                        b[i]:=b[j];
                        b[j]:=b[0];
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if i<r then kp(i,r);
        if l<j then kp(l,j);
end;
begin
        assign(input,'road.in');reset(input);
        assign(output,'road.out');rewrite(output);
        readln(n);
        for i:=1 to n do
        begin
                read(a[i]);
                b[i]:=i;
        end;
        c:=a;
        kp(1,n);
        for i:=1 to n do
        begin
                l:=b[i]-1;
                r:=b[i]+1;
                inc(ans,c[b[i]]);
                while c[l]<>0 do
                begin
                        dec(c[l],c[b[i]]);
                        dec(l);
                end;
                while c[r]<>0 do
                begin
                        dec(c[r],c[b[i]]);
                        inc(r);
                end;
                c[b[i]]:=0;
        end;
        writeln(ans);
        close(input);close(output);
end.