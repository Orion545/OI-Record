
var
 i,n,m,k,j,kk,jj,o,oo:longint;ss:string;
 p,u,v,s:array[-1..100000] of longint;


function jo(num:longint):integer;
begin
    if ((num shr 1 )shl 1)=num then exit(1);exit(0);

end;

 procedure answ;
 begin
     readln(k,kk,j,jj);
     if k>j then begin oo:=kk;kk:=jj;jj:=oo;o:=k;k:=j;j:=o;end;
 writeln(min(s[n]+(1-(jo(n) xor jo(k-kk)))*p[k]+p[j]*(1-(jo(n) xor jo(j-jj))),s[n-1]+(1-(jo(n-1) xor jo(k-kk)))*p[k]+p[j]*(1-(jo(n-1) xor jo(j-jj)))));

 end;
//s[n]+(1-(jo(n) xor jo(k-kk)))*p[k]+p[j]*(1-(jo(n) xor jo(j-jj))),s[n-1]+(1-(jo(n-1) xor jo(k-kk)))*p[k]+p[j]*(1-(jo(n-1) xor jo(j-jj)))


begin
assign(input,'defense.in');reset(input);
assign(output,'defense.out');rewrite(output);
readln(n,m,ss);s[0]:=0;s[-1]:=0;
for i:=1 to n do begin read(p[i]);s[i]:=s[i-2]+p[i];end;
for i:=1 to n-1 do  readln(u[i],v[i]);
for i:=1 to m do answ;

 close(input);
close(output);
end.


