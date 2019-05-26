var
bz : array[1..100] of boolean;
f :array[0..25000] of boolean;
a : array[0..100] of longint;
n,i,j,ans,max,zm : longint;
procedure kuaipai(l,r:longint);
var i,j,k:longint;
        begin
                i:=l;j:=r;k:=a[(l+r)shr 1];
                repeat
                while a[i]<k do inc(i);
                while a[j]>k do dec(j);
                if i<=j then begin
                        a[0]:=a[i];a[i]:=a[j];a[j]:=a[0];
                        inc(i);dec(j);
                end;
                until i>j;
                if i<r then kuaipai(i,r);
                if l<j then kuaipai(l,j);
        end;
begin
assign(input,'money.in');reset(input);
assign(output,'money.out');rewrite(output);
readln(zm);
while zm>0 do begin
dec(zm);
fillchar(f,sizeof(f),0);fillchar(bz,sizeof(bz),0);
fillchar(a,sizeof(a),0);ans:=0;max:=0;
read(n);
for i := 1 to n do begin
        read(a[i]);if a[i]>max then max:=a[i];
end;
kuaipai(1,n);
//for i := 1 to n do write(a[i],' ');writeln;
for i := 1 to n do
        for j := 1 to i-1 do
        if a[i] mod a[j] =0 then bz[i]:=true;

f[0]:=true;
for i := 1 to n do
if (not bz[i])and(not f[a[i]]) then begin
//        write(a[i],' ');
        inc(ans);
        for j := 0 to max-a[i] do
        f[j+a[i]]:=f[j+a[i]]or f[j];
end;
writeln(ans);
end;
close(input);close(output);
end.
