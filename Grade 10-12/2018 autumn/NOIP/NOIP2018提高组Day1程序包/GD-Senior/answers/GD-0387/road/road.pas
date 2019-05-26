program road;
var
  d:array[1..100000] of integer;
  n,i,j,ans:longint;

procedure tp(l,r:longint);
var
        i,min:longint;
begin
        if l>r then exit;
        min:=10000;
        for i:=l to r do
                if min>d[i] then min:=d[i];
        for i:=l to r do
                d[i]:=d[i]-min;
        ans:=ans+min;
        for i:=l to r do
                begin
                        if (d[i]=0) then begin
                                tp(l,i-1);
                                l:=i+1;
                        end;
                        if (i=r) and (d[i]<>0) then
                                tp(l,i);
                end;
end;

begin
        assign(input,'road.in');reset(input);
        assign(output,'road.out');rewrite(output);
        read(n);
        for i:=1 to n do
                read(d[i]);
        tp(1,n);
        write(ans);
        close(input);close(output);
end.