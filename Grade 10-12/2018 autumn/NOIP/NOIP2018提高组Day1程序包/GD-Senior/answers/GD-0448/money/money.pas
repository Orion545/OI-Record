program T2;//by Peter.W.Wany
var     i,j,k,n,m,t,ans:longint;
        z:array[0..101]of longint;
        f:array[0..25001]of boolean;
procedure kp(l,r:longint);
var     i,j,m,h:longint;
begin
        i:=l;
        j:=r;
        m:=z[(i+j)div 2];
        repeat
                while z[i]<m do
                        inc(i);
                while z[j]>m do
                        dec(j);
                if i<=j then
                begin
                        h:=z[i];
                        z[i]:=z[j];
                        z[j]:=h;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if i<r then
                kp(i,r);
        if j>l then
                kp(l,j);
end;
begin
        assign(input,'money.in');
        reset(input);
        assign(output,'money.out');
        rewrite(output);
        readln(t);
        for k:=1 to t do
        begin
                ans:=0;
                fillchar(f,sizeof(f),0);
                f[0]:=true;
                fillchar(z,sizeof(z),0);
                readln(n);
                for i:=1 to n do
                begin
                        read(z[i]);
                end;
                readln;
                kp(1,n);
                for i:=1 to n do
                begin
                        if not(f[z[i]]) then
                        begin
                                inc(ans);
                                for j:=0 to z[n]-z[i] do
                                        if f[j] then
                                                f[j+z[i]]:=true;
                        end;
                end;
                writeln(ans);
        end;
        close(input);
        close(output);
end.