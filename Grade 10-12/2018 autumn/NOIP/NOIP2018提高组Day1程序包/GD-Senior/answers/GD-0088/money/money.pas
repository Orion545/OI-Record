var
        t,n,m,i,j,k,l,xxx:longint;
        a,b,bz:array[0..101] of longint;
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
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if i<r then kp(i,r);
        if l<j then kp(l,j);
end;
function pd(x,y,z:longint):boolean;
var
        i,j,k,xx,yy:longint;
begin
        xx:=z div x;
        yy:=z div y;
        for i:=0 to xx do
        begin
                for j:=0 to yy do
                begin
                        if i*x+j*y=z then exit(true);
                        if i*x+j*y>z then break;
                end;
        end;
        exit(false);
end;
begin
        assign(input,'money.in');reset(input);
        assign(output,'money.out');rewrite(output);
        readln(t);
        for l:=1 to t do
        begin
                fillchar(b,sizeof(b),0);
                m:=0;
                fillchar(bz,sizeof(bz),0);
                readln(n);
                for i:=1 to n do
                        read(a[i]);
                kp(1,n);
                inc(m);
                b[m]:=a[1];
                for i:=2 to n do
                        if a[i] mod a[1]=0 then bz[i]:=1;
                k:=2;
                while (m=1)and(k<=n) do
                begin
                        if bz[k]<>1 then
                        begin
                                inc(m);
                                b[m]:=a[k];
                        end;
                        inc(k);
                end;
                if m=1 then
                begin
                        writeln(1);

                end
                else
                begin
                while k<=n do
                begin
                        xxx:=0;
                        for i:=1 to m-1 do
                        begin
                        if xxx=0 then
                        begin
                                for j:=i+1 to m do
                                begin
                                        if xxx=0 then
                                        begin
                                        if pd(b[i],b[j],a[k])=false then
                                        begin
                                                inc(m);
                                                b[m]:=a[k];
                                                xxx:=1;
                                        end;
                                        end;
                                end;
                        end;
                        end;
                        inc(k);
                end;
                writeln(m);
                end;
        end;
        close(input);close(output);
end.
