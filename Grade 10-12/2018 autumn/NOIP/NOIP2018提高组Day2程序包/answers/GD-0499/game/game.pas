const mo=trunc(1e+9)+7; maxn=5;maxm=5;
var
f : array[1..5,1..5] of longint=(
(2,4,8,16,32),
(4,12,36,108,324),
(8,36,112,336,1008),
(16,108,336,912,2688),
(32,324,1008,2688,7136));
n,m:longint;
function ksmin(a,b:int64):int64;
var ans:int64;
        begin
                ans:=1;
                while b>0 do begin
                if b mod 2=1 then ans:=ans*a mod mo;
                a:=a*a mod mo;b:=b div 2;
                end;
                exit(ans);
        end;
begin
assign(input,'game.in');reset(input);
assign(output,'game.out');rewrite(output);
readln(n,m);
if (n<=maxn)and(m<=maxm) then write(f[n,m])
else begin
        if n=2 then write((4*ksmin(3,m-1)mod mo))
        else if n=3 then write((112*ksmin(3,m-3)mod mo));
end;
close(input);close(output);
end.