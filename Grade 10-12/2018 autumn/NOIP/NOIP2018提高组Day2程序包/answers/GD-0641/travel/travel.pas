var
        n,m,i,j,x,y,tot,x1,y1,h:longint;
        bz:array[1..5000]of boolean;
        last,next,tov,fa,deep:array[0..10000]of longint;
        b,ans,f:array[0..5000]of longint;
        map:array[1..5000,1..5000]of boolean;
        p:array[1..5000,1..2]of longint;
procedure insert(x,y:longint);
begin
        inc(tot);
        tov[tot]:=y;
        next[tot]:=last[x];
        last[x]:=tot;
end;
procedure q(l,r:longint);
var
        i,j,mid,t:longint;
begin
        i:=l;
        j:=r;
        mid:=b[(l+r)div 2];
        repeat
                while(b[i]<mid)do inc(i);
                while(b[j]>mid)do dec(j);
                if(i<=j)then
                begin
                        t:=b[i];
                        b[i]:=b[j];
                        b[j]:=t;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if(i<r)then q(i,r);
        if(l<j)then q(l,j);
end;
procedure bl(t:longint);
var
        i,y:longint;
        a:array[0..5000]of longint;
begin
        inc(f[0]);
        f[f[0]]:=t;
        i:=last[t];
        a[0]:=0;
        bz[t]:=true;
        while(i<>0)do
        begin
                y:=tov[i];
                inc(a[0]);
                a[a[0]]:=y;
                i:=next[i];
        end;
        b:=a;
        q(1,b[0]);
        a:=b;
        for i:=1 to a[0] do
        begin
                if(bz[a[i]]=false)then bl(a[i]);
        end;
end;
procedure dg(t,s:longint);
var
        i,y:longint;
begin
        i:=last[t];
        bz[t]:=true;
        deep[t]:=s;
        while(i<>0)do
        begin
                y:=tov[i];
                if(bz[y]=false)then
                begin
                        bz[y]:=true;
                        fa[y]:=t;
                        dg(y,s+1);
                end;
                i:=next[i];
        end;
end;
procedure dg1(t,l,r:longint);
var
        i,y:longint;
        a:array[0..5000]of longint;
begin
        inc(f[0]);
        f[f[0]]:=t;
        i:=last[t];
        a[0]:=0;
        bz[t]:=true;
        while(i<>0)do
        begin
                y:=tov[i];
                if(t=l)and(y=r)then
                begin
                        i:=next[i];
                        continue;
                end;
                if(t=r)and(y=l)then
                begin
                        i:=next[i];
                        continue;
                end;
                inc(a[0]);
                a[a[0]]:=y;
                i:=next[i];
        end;
        b:=a;
        q(1,b[0]);
        a:=b;
        for i:=1 to a[0] do
        begin
                if(bz[a[i]]=false)then dg1(a[i],l,r);
        end;
end;
begin
        assign(input,'travel.in');
        reset(input);
        assign(output,'travel.out');
        rewrite(output);
        read(n,m);
        for i:=1 to m do
        begin
                read(x,y);
                insert(x,y);
                insert(y,x);
                map[x,y]:=true;
                map[y,x]:=true;
        end;
        if(m=n-1)then
        begin
                bl(1);
                for i:=1 to f[0] do write(f[i],' ');
        end
        else
        begin
                dg(1,0);
                for i:=1 to n-1 do
                begin
                        for j:=i+1 to n do
                        begin
                                if(map[i,j])then
                                begin
                                        if(fa[i]<>j)and(fa[j]<>i)then break;
                                end;
                        end;
                        if(map[i,j])then
                        begin
                                if(fa[i]<>j)and(fa[j]<>i)then break;
                        end;
                end;
                x:=i;
                y:=j;
                x1:=x;
                y1:=y;
                h:=1;
                p[h,1]:=x1;
                p[h,2]:=y1;
                while(deep[x1]>deep[y1])do
                begin
                        inc(h);
                        p[h,1]:=x1;
                        p[h,2]:=fa[x1];
                        x1:=fa[x1];
                end;
                while(deep[y1]>deep[x1])do
                begin
                        inc(h);
                        p[h,1]:=y1;
                        p[h,2]:=fa[y1];
                        y1:=fa[y1];
                end;
                while(x1<>y1)do
                begin
                        inc(h);
                        p[h,1]:=x1;
                        p[h,2]:=fa[x1];
                        inc(h);
                        p[h,1]:=y1;
                        p[h,2]:=fa[y1];
                        x1:=fa[x1];
                        y1:=fa[y1];
                end;
                for i:=1 to n do ans[i]:=n+1;
                for i:=1 to h do
                begin
                        fillchar(bz,sizeof(bz),false);
                        f[0]:=0;
                        dg1(1,p[i,1],p[i,2]);
                        for j:=1 to n do
                        begin
                                if(ans[j]<>f[j])then break;
                        end;
                        if(ans[j]>f[j])then
                        begin
                                for j:=1 to n do ans[j]:=f[j];
                        end;
                end;
                for i:=1 to n do write(ans[i],' ');
        end;
        close(input);
        close(output);
end.
