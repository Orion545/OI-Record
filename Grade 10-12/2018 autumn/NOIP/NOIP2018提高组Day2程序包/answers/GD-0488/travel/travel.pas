var
        x,y,n,m,i,j,k,l:longint;
        a,star:array[0..20000,1..2] of longint;
        total,f,went,last,deep:array[0..20000] of longint;
procedure make(x,a,b:longint);
begin
        star[x,1]:=a;
        star[x,2]:=b;
        went[x]:=last[a];
        last[a]:=x;
end;
procedure kp(l,r:longint);
var
        i,j,mid:longint;
begin
        i:=l;
        j:=r;
        mid:=a[(l+r) div 2,2];
        repeat
                while (a[i,2]>mid) do inc(i);
                while (a[j,2]<mid) do dec(j);
                if (i<=j) then
                begin
                        a[0]:=a[i];
                        a[i]:=a[j];
                        a[j]:=a[0];
                        inc(i);
                        dec(j);
                end;
        until(i>j);
        if (i<r) then kp(i,r);
        if (l<j) then kp(l,j);
end;
procedure dg(x,t:longint);
var
        i:longint;
begin
        write(x,' ');
        i:=last[x];
        deep[x]:=t;
        while (i>0) do
        begin
                if (deep[star[i,2]]=0) then
                        dg(star[i,2],t+1);
                i:=went[i];
        end;
end;
procedure dg1(x,t:longint);
var
        i:longint;
begin
        deep[x]:=t;
        f[t]:=x;
        i:=last[x];
        while (i>0) do
        begin
                if (deep[star[i,2]]=0) then
                begin
                        dg1(star[i,2],t+1);
                end;
                i:=went[i];
        end;
end;
procedure dg2(x,y:longint);
var
        i,j:longint;
begin
        for i:=1 to n do
        begin
                if (f[x]>f[y]) then
                begin
                        for j:=y downto x do
                                write(f[j],' ');
                        exit;
                end;
                write(f[x],' ');
                inc(x);
        end;
end;
function pd:boolean;
var
        i:longint;
begin
        for i:=1 to n do
                if (total[i]>2) then
                        exit(false);
        exit(true);
end;
begin
        assign(input,'travel.in');reset(input);
        assign(output,'travel.out');rewrite(output);
        readln(n,m);
        for i:=1 to m do
        begin
                readln(x,y);
                a[i,1]:=x;
                a[i,2]:=y;
                a[i+m,1]:=y;
                a[i+m,2]:=x;
                inc(total[x]);
                inc(total[y]);
        end;
        kp(1,2*m);
        for i:=1 to 2*m do
        begin
                make(i,a[i,1],a[i,2]);
        end;
        if (m=n-1) then
        begin
                dg(1,1);
        end
        else
        begin
                if (pd) then
                begin
                        dg1(1,1);
                        dg2(1,n);
                end
                else
                        dg(1,1);
        end;
        close(input);
        close(output);
end.
