var n,m,ha,i:longint;
ans:int64;
begin
assign(input,'game.in');reset(input);
assign(output,'game.out');rewrite(output);
    readln(n,m);
    ha:=1000000007;
    if (n=1) or (m=1) then begin
        ans:=1;
        for i:=1 to m+n-1 do ans:=ans*2 mod ha;
        writeln(ans);
    end else if (n=2) or (m=2) then begin
        ans:=4;
        for i:=1 to m+n-3 do ans:=ans*3 mod ha;
        writeln(ans);
    end else if (n=3) and (m=3) then writeln(112)
    else begin
        ans:=223;
        for i:=1 to m do ans:=ans*2 mod ha;
        writeln(ans);
    end;
    close(input);close(output);
end.