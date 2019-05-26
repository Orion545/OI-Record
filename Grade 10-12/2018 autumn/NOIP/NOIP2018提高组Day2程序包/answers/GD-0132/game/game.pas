
var
 i,n,m,k:longint;ans:int64;
function power(a,b:longint):int64;
begin
 if b=0 then exit(1);
if b=((b shr 1) shl 1) then
 exit(power(((a*a) mod 1000000007),(b shr 1)))
 else exit((a mod 1000000007)*power(((a*a) mod 1000000007),(b shr 1)));
//exit(1);
end;


begin
assign(input,'game.in');reset(input);
assign(output,'game.out');rewrite(output);
readln(n,m);if n>m then begin k:=m;m:=n;n:=k; end;
 ans:=1;

//if n<3 then begin ans:=(((3*(m-1)) mod 1000000007)*4) mod 1000000007;  end
//else
//begin
for i:=2 to n do ans:=ans*i*i;
k:=power((n+1),(m-n+1)) mod 1000000007;
ans:=(ans*k) mod 1000000007;
// end;

writeln(ans);
 
close(input);
close(output);
end.

