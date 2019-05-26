var
        n,x,i,last,ans:longint;
begin
        assign(input,'road.in');
        assign(output,'road.out');
        reset(input);
        rewrite(output);
        readln(n);
        for i:=1 to n+1 do begin
                x:=0;
                if i<=n then read(x);
                if x<last then ans:=ans+last-x;
                last:=x;
        end;
        writeln(ans);
        close(input);
        close(output);
end.
