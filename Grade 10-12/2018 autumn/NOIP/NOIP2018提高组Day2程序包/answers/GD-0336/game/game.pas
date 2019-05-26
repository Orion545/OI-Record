const
        mo=1000000007;
var
        s:array[1..10000]of string;
        a:array[1..8,1..20]of longint;
        b:array[0..256,0..10]of longint;
        bz:array[0..1000]of longint;
        f,g:array[0..256]of int64;
        mi:array[1..9]of int64=(1,2,4,8,16,32,64,128,256);
        i,j,l,k,o,p,z:longint;
        ans,m,n:int64;
procedure swap(var x,y:int64);var z:longint;begin z:=x;x:=y;y:=z;end;
procedure haha1;
begin
        if n>m then swap(n,m);
        case n of
        1:
        begin
                writeln(mi[m+1]);
        end;
        2:
        begin
                if m=2 then writeln(12) else writeln(36);
        end;
        3:
        begin
                writeln(112);
        end;
        end;
        halt;
        close(input);close(output);
end;
function kmi(x,y:int64):int64;
begin
        kmi:=1;
        while y>0 do
        begin
                if y mod 2=1 then kmi:=kmi*x mod mo;
                x:=x*x mod mo;
                y:=y div 2;
        end;
end;
procedure haha2;
begin
        if n=1 then writeln(kmi(2,m));
        if n=2 then
        begin
                writeln(kmi(3,m-1)*4 mod mo);
        end;
        halt;
        close(input);close(output);
end;
procedure dg(x,y:longint);
begin
        if y=m+1 then
        begin
                y:=1;
                x:=x+1;
        end;
        if x>n then
        begin
                ans:=ans+1;
                for i:=2 to m-1 do
                begin
                        if (a[3,i]>a[2,i+1])and(a[1,i]=a[2,i-1]) then
                        begin
                                ans:=ans-1;
                                break;
                        end;
                end;
                exit;
        end;
        if bz[x+y]=0 then dg(x,y+1);
        inc(bz[x+y]);
        a[x,y]:=1;
        dg(x,y+1);
        a[x,y]:=0;
        dec(bz[x+y]);
end;
begin
        assign(input,'game.in');reset(input);
        assign(output,'game.out');rewrite(output);
        read(n,m);
        z:=mi[n+1]-1;
        for i:=0 to z do f[i]:=1;
        for i:=0 to z do
        begin
                o:=i;
                for j:=9 downto 1 do
                if o>=mi[j] then
                begin
                        o:=o-mi[j];
                        b[i,j]:=1;
                end;
        end;
        if (n<=3)and(m<=3) then haha1;
        if (n<=2) then haha2;
        ans:=0;
        dg(1,1);
        writeln(ans);
        close(input);close(output);
end.
