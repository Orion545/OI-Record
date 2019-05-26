var  k,n,i,ans:longint;
    num:array[0..110000]of longint;
begin
assign(input,'road.in');reset(input);
assign(output,'road.out');rewrite(output);
    readln(n);
    for i:=1 to n do read(num[i]);k:=0;
    for i:=1 to n do if k>=num[i]then k:=num[i]
    else begin
        inc(ans,num[i]-k);
        k:=num[i];
    end;
    writeln(ans);
close(input);close(output);
end.
