var a:array[0..105]of longint;
    b:array[-25005..25005]of boolean;
    t:longint;

procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
    i:=l;
    j:=r;
    x:=a[(l+r) div 2];
    repeat
        while a[i]<x do inc(i);
        while x<a[j] do dec(j);
        if not(i>j) then begin
            y:=a[i];
            a[i]:=a[j];
            a[j]:=y;
            inc(i);
            dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
end;

function work:longint;
var n,i,j,tot:longint;
begin
    fillchar(b,sizeof(b),false);
    b[0]:=true;
    tot:=0;
    readln(n);
    for i:=1 to n do read(a[i]);
    sort(1,n);
    for i:=1 to n do
        if not b[a[i]] then begin
            inc(tot);
            for j:=1 to a[n] do
                b[j]:=b[j] or b[j-a[i]];
        end;
    exit(tot);
end;

begin
    assign(input,'money.in');reset(input);
    assign(output,'money.out');rewrite(output);
    readln(t);
    for t:=1 to t do writeln(work);
    close(input);close(output);
end.
