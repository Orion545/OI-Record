var
        a:array[1..100000]of int64;
        i,n:longint;
        ans:int64;
function max(x,y:int64):int64;
begin
        if x>y then exit(x) else exit(y);
end;
begin
        assign(input,'road.in');reset(input);
        assign(output,'road.out');rewrite(output);
        read(n);
        for i:=1 to n do read(a[i]);
        ans:=a[1];
        for i:=2 to n do ans:=ans+max(a[i]-a[i-1],0);
        writeln(ans);
        close(input);close(output);
end.