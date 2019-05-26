var
a : array[0..100000] of longint;
i,j,d,n : longint;
ans: int64;
begin
assign(input,'road.in');reset(input);
assign(output,'road.out');rewrite(output);
read(n);
ans:=0;
for i := 1 to n do begin
        read(a[i]);
        d:=a[i]-a[i-1];
        if d>0 then ans:=ans+d;
end;
write(ans);
close(input);close(output);
end.