var
        a,x1,x,b,y,i,j,k,l,n,m:longint;
        f,ans:array[0..100000,0..1] of int64;
        star:array[0..200000,1..2] of longint;
        fa,p,deep,went,last:array[0..200000] of longint;
        ch1,ch2,ch3,ch4:char;
        ax:int64;
        bj,bz:boolean;
procedure make(x,a,b:longint);
begin
        star[x,1]:=a;
        star[x,2]:=b;
        went[x]:=last[a];
        last[a]:=x;
end;
function min(a,b:int64):int64;
begin
        if (a<b) then
                exit(a);
        exit(b);
end;
procedure dg(x,t:longint);
var
        i:longint;
begin
        deep[x]:=t;
        i:=last[x];
        f[x,0]:=0;
        f[x,1]:=p[x];
        while (i>0) do
        begin
                if (deep[star[i,2]]=0) then
                begin
                        fa[star[i,2]]:=x;
                        dg(star[i,2],t+1);
                        f[x,0]:=f[x,0]+f[star[i,2],1];
                        f[x,1]:=f[x,1]+min(f[star[i,2],1],f[star[i,2],0]);
                end;
                i:=went[i];
        end;
end;
procedure dg2(x:longint);
var
        i:longint;
begin
        i:=last[x];
        f[x,0]:=0;
        f[x,1]:=p[x];
        if (bz) and (bj) then
        begin
                f[x,0]:=ans[x,0];
                f[x,1]:=ans[x,1];
                exit;
        end;
        while (i>0) do
        begin
                if (deep[star[i,2]]>deep[x]) then
                begin
                        dg2(star[i,2]);
                        f[x,0]:=f[x,0]+f[star[i,2],1];
                        f[x,1]:=f[x,1]+min(f[star[i,2],1],f[star[i,2],0]);
                end;
                i:=went[i];
        end;
        if (x=a) then
        begin
                f[x,x1 xor 1]:=ax;
                bz:=true;
        end;
        if (x=b) then
        begin
                f[x,y xor 1]:=ax;
                bj:=true;
        end;
end;
begin
        ax:=100000000001;
        assign(input,'defense.in');reset(input);
        assign(output,'defense.out');rewrite(output);
        readln(n,m,ch1,ch2,ch3);
        for i:=1 to n do
                read(p[i]);
        for i:=1 to n-1 do
        begin
                readln(x,y);
                make(i*2,x,y);
                make(i*2+1,y,x);
        end;
        dg(1,1);
        ans:=f;
                for i:=1 to m do
                begin
                        read(a,x,b,y);
                        if (fa[a]=b) or (fa[b]=a) then
                        begin
                                if (x=y) and (x=0) then
                                begin
                                        writeln(-1);
                                        continue;
                                end;
                        end;
                        x1:=x;
                        bj:=false;
                        bz:=false;
                        dg2(1);
                        writeln(min(f[1,1],f[1,0]));
                end;
        close(input);
        close(output);
end.