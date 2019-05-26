program money;
var a:array[1..200] of longint;
    f,b:array[0..50000] of boolean;
    tt,z,i,j,k,n,c,max,ans:longint;

procedure qs(l,r:longint);
var x,i,j,t:longint;
begin
    i:=l;
    j:=r;
    x:=a[(i+j) div 2];
    repeat
        while a[i]<x do inc(i);
        while x<a[j] do dec(j);
        if i<=j then
        begin
            t:=a[i];
            a[i]:=a[j];
            a[j]:=t;
            inc(i);
            dec(j);
        end;
    until i>j;
    if i<r then qs(i,r);
    if l<j then qs(l,j);
end;

begin
    assign(input,'money.in');reset(input);
    assign(output,'money.out');rewrite(output);
    readln(tt);
    for z:=1 to tt do
    begin
        readln(n);
        fillchar(f,sizeof(f),false);
        c:=0;
        for i:=1 to n do
        begin
            inc(c);
            read(a[c]);
            if f[a[c]]=false then f[a[c]]:=true else dec(c);
        end;
        readln;
        qs(1,c);
        max:=a[c];
        for k:=1 to c do
        begin
            fillchar(b,sizeof(b),false);
            b[0]:=true;
            for i:=1 to max do
                for j:=1 to k do
                    if (i-a[j]>=0) and (f[a[j]]=true) then
                        if b[i-a[j]]=true then b[i]:=true;
            for i:=k+1 to c do if b[a[i]]=true then f[a[i]]:=false;
        end;
        ans:=0;
        for i:=1 to c do if f[a[i]]=true then inc(ans);
        writeln(ans);
    end;
    close(input);close(output);
end.