var n,i:longint;
ans:int64;
s:array[0..200000] of longint;
begin
assign(input,'road.in');reset(input);
assign(output,'road.out');rewrite(output);
    readln(n);
    for i:=1 to n do begin
        read(s[i]);
        ans:=ans+abs(s[i-1]-s[i]);
    end;
    ans:=(ans+s[n]) div 2;
    writeln(ans);
    close(input);close(output);
end.
