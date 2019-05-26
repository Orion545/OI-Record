var n,i,x,y:longint;
    ans:int64;
begin
    assign(input,'road.in');reset(input);
    assign(output,'road.out');rewrite(output);
    read(n);
    for i:=1 to n do begin
        read(y);
        if y>x then ans:=ans+y-x;
        x:=y;
    end;
    writeln(ans);
    close(input);close(output);
end.
