program T3;//by Peter.W.Wany
var     i,j,k,n,m,a,b,c,max:longint;
        map:array[0..6000,0..6000]of longint;
        bo:array[0..6000,0..6000]of boolean;
function go(x:longint):longint;
var     i,max,k:longint;
begin
        max:=0;
        for i:=1 to n do
        begin
                if (not(bo[x,i]))and(map[x,i]<>maxlongint) then
                begin
                        bo[x,i]:=true;
                        bo[i,x]:=true;
                        k:=go(i);
                        if max<k+map[x,i] then
                                max:=k+map[x,i];
                        bo[i,x]:=false;
                        bo[x,i]:=false;
                end;
        end;
        exit(max);
end;
begin
        assign(input,'track.in');
        reset(input);
        assign(output,'track.out');
        rewrite(output);
        read(n,m);
        for i:=1 to n do
                for j:=1 to n do
                        map[i,j]:=maxlongint;
        for i:=1 to n-1 do
        begin
                readln(a,b,c);
                map[a,b]:=c;
                map[b,a]:=c;
        end;
        for i:=1 to n do
        begin
                fillchar(bo,sizeof(bo),0);
                if max<go(i) then
                        max:=go(i);
        end;
        write(max);
        close(input);
        close(output);
end.