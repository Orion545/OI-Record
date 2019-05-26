program road;
var d:array[1..100050] of longint;
    n,i,ans:longint;

function dig(l,r,z:longint):longint;
var i,j,mm,mn,aa:longint;
    b:array[1..100050] of longint;
begin
    if l>r then exit(0);
    if l=r then exit(d[l]-z);
    fillchar(b,sizeof(b),0);
    mm:=d[l];mn:=1;b[1]:=l;
    for i:=l+1 to r do
        if mm>d[i] then
        begin
            mm:=d[i];mn:=1;
            fillchar(b,sizeof(b),0);
            b[1]:=i;
        end
        else
        if mm=d[i] then
        begin
            inc(mn);
            b[mn]:=i;
        end;
    aa:=mm-z;
    aa:=aa+dig(l,b[1]-1,mm);
    for i:=1 to mn-1 do aa:=aa+dig(b[i]+1,b[i+1]-1,mm);
    aa:=aa+dig(b[mn]+1,r,mm);
    exit(aa);
end;

begin
    assign(input,'road.in');reset(input);
    assign(output,'road.out');rewrite(output);
    readln(n);
    for i:=1 to n do read(d[i]);
    ans:=dig(1,n,0);
    writeln(ans);
    close(input);close(output);
end.