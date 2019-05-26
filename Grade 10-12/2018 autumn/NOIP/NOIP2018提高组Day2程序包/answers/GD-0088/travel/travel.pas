type
        arr=array[0..1000000] of longint;
var
        n,m,i,j,k,l,x,y,tot,xx,head,tail:longint;
        a,last,next,tov,bz,pd:array[0..5000] of longint;
        c:array[0..5000,0..5000] of longint;
        b:arr;
procedure add(x,y:longint);
begin
        inc(tot);
        next[tot]:=last[x];
        last[x]:=tot;
        tov[tot]:=y;
end;
procedure kp(l,r,kk:longint);
var
        i,j,m,t:longint;
begin
        i:=l;
        j:=r;
        m:=c[kk,(l+r) div 2];
        repeat
                while c[kk,i]<m do inc(i);
                while c[kk,j]>m do dec(j);
                if i<=j then
                begin
                        t:=c[kk,i];
                        c[kk,i]:=c[kk,j];
                        c[kk,j]:=t;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if i<r then kp(i,r,kk);
        if l<j then kp(l,j,kk);
end;
procedure dg(x:longint);
var
        xx,yy,i,j,k,num,qs:longint;
begin
        kp(1,c[x,0],x);
        write(x,' ');
        for i:=1 to c[x,0] do
                dg(c[x,i]);
end;
begin
        assign(input,'travel.in');reset(input);
        assign(output,'travel.out');rewrite(output);
        readln(n,m);
        if m=n-1 then
        begin
                for i:=1 to m do
                begin
                        readln(x,y);
                        if (pd[x]=0)and(pd[y]=0) then
                        begin
                                if x<y then
                                begin
                                        inc(c[x,0]);
                                        c[x,c[x,0]]:=y;
                                        pd[x]:=1;
                                        pd[y]:=1;
                                end
                                else
                                begin
                                        inc(c[y,0]);
                                        c[y,c[y,0]]:=x;
                                        pd[x]:=1;
                                        pd[y]:=1;
                                end;
                        end
                        else
                        if (pd[x]=1)and(pd[y]=0) then
                        begin
                                inc(c[x,0]);
                                c[x,c[x,0]]:=y;
                                pd[y]:=1;
                        end
                        else
                        if (pd[x]=0)and(pd[y]=1) then
                        begin
                                inc(c[y,0]);
                                c[y,c[y,0]]:=x;
                                pd[x]:=1;
                        end
                        else
                        if (pd[x]=1)and(pd[y]=1) then
                        begin
                                if x<y then
                                begin
                                        inc(c[x,0]);
                                        c[x,c[x,0]]:=y;
                                        pd[x]:=1;
                                        pd[y]:=1;
                                end
                                else
                                begin
                                        inc(c[y,0]);
                                        c[y,c[y,0]]:=x;
                                        pd[x]:=1;
                                        pd[y]:=1;
                                end;
                        end;
                end;
                dg(1);
        end;
        close(input);close(output);
end.
