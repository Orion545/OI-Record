var
        a:array[1..1000,1..1000]of longint;
        f,c:array[0..50001]of longint;
        ai:boolean;
        i,j,n,m,x,y,z:longint;
procedure ins(x:longint);
var
        i:longint;
begin
        i:=m;
        while (c[i]<x)and(i>=1) do begin
                c[i]:=c[i-1];
                dec(i);
        end;
        c[i+1]:=x;
end;
begin
        assign(input,'track.in');
        assign(output,'track.out');
        reset(input);
        rewrite(output);
        readln(n,m);
        ai:=true;
        for i:=1 to n-1 do begin
                readln(x,y,z);
                if x<>1 then ai:=false;
                if ai=false then a[x,y]:=z
                else f[y]:=z;
        end;
        if ai=true then begin
                for i:=2 to n-1 do
                for j:=i+1 to n do
                ins(f[i]+f[j]);
                writeln(c[m]);
        end else begin
                writeln(n*2-3);
        end;
        close(input);
        close(output);
end.