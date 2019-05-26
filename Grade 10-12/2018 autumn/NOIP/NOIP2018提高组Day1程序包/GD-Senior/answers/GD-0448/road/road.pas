program T1;//by Peter.W.Wany
var     i,j,k,n,m,ans:longint;
        z:array[0..100001]of longint;
function fmin(l,r:longint):longint;
var     i,min:longint;
begin
        min:=maxlongint;
        for i:=l to r do
                if min>z[i] then
                        min:=z[i];
        exit(min);
end;
procedure pu(l,r:longint);
var     i,k,day:longint;
begin
        day:=fmin(l,r);
        ans:=ans+day;
        k:=l;
        for i:=l to r do
        begin
                z[i]:=z[i]-day;
                if z[i]=0 then
                begin
                        if k<=i-1 then
                                pu(k,i-1);
                        k:=i+1;
                end;
        end;
        if k<=r then
                pu(k,r);
end;
begin
        assign(input,'road.in');
        reset(input);
        assign(output,'road.out');
        rewrite(output);
        readln(n);
        for i:=1 to n do
        begin
                read(z[i]);
        end;
        pu(1,n);
        write(ans);
        close(input);
        close(output);
end.