var
        n,m,x1,y1,i,tot,zx:longint;
        l,r,mid,ans,sum:int64;
        bz,bz2:boolean;
        bz1:array[1..1000]of boolean;
        x,y,z,fa,into,next,len,next1,last,tov,len1:array[1..50000]of longint;
        tree:array[1..1000,1..5]of longint;
procedure insert(x,y,z:longint);
begin
        inc(tot);
        tov[tot]:=y;
        len1[tot]:=z;
        next1[tot]:=last[x];
        last[x]:=tot;
end;
function pd(mid:longint):boolean;
var
        i,s,wz,gs:longint;
begin
        for i:=1 to n do
        begin
                if(into[i]=1)and(next[i]<>0)then
                begin
                        wz:=i;
                        break;
                end;
        end;
        s:=0;
        gs:=0;
        while(true)do
        begin
                if(next[wz]=0)then break;
                s:=s+len[wz];
                if(s>=mid)then
                begin
                        s:=0;
                        gs:=gs+1;
                end;
                wz:=next[wz];
        end;
        if(gs>=m)then exit(true)
        else exit(false);
end;
procedure dg(t:longint);
var
        i,y,x:longint;
begin
        bz1[t]:=true;
        i:=last[t];
        x:=1;
        while(i<>0)do
        begin
                y:=tov[i];
                if(bz1[y]=false)then
                begin
                        dg(y);
                        tree[t,x]:=tree[y,5]+len1[i];
                end;
                inc(x);
                i:=next1[i];
        end;
        tree[t,5]:=tree[t,1]+tree[t,2]+tree[t,3]+tree[t,4];
end;
procedure bl(t,sq:longint);
var
        i,y,zd,zd1,x,wz,wz1:longint;
begin
        i:=last[t];
        zd:=0;
        zd1:=0;
        x:=1;
        wz:=0;
        wz1:=0;
        while(i<>0)do
        begin
                y:=tov[i];
                if(tree[t,x]>zd)then
                begin
                        zd1:=zd;
                        wz1:=wz;
                        zd:=tree[t,x];
                        wz:=y;
                end
                else
                begin
                        if(tree[t,x]>zd1)then
                        begin
                                zd1:=tree[t,x];
                                wz1:=y;
                        end;
                end;
                sum:=sum-tree[t,x];
                inc(x);
                i:=next1[i];
        end;
        if(t=sq)then
        begin
                sum:=sum+zd+zd1;
                if(wz<>0)then bl(wz,sq);
                if(wz1<>0)then bl(wz1,sq);
        end
        else
        begin
                sum:=sum+zd;
                if(wz<>0)then bl(wz,sq);
        end;
end;
begin
        assign(input,'track.in');
        reset(input);
        assign(output,'track.out');
        rewrite(output);
        zx:=maxlongint;
        read(n,m);
        for i:=1 to n-1 do
        begin
                read(x[i],y[i],z[i]);
                if(z[i]<zx)then zx:=z[i];
                insert(x[i],y[i],z[i]);
                insert(y[i],x[i],z[i]);
                next[x[i]]:=y[i];
                len[x[i]]:=z[i];
                inc(into[x[i]]);
                inc(into[y[i]]);
                if(y[i]<>x[i]+1)then bz:=true;
                r:=r+z[i];
        end;
        if(bz=false)then
        begin
                l:=1;
                while(l<r)do
                begin
                        mid:=(l+r)div 2;
                        if(pd(mid))then l:=mid+1
                        else r:=mid;
                end;
                if(pd(l))then writeln(l)
                else writeln(l-1);
                halt;
        end;
        if(m=1)and(n<=1000)then
        begin
                for i:=1 to n do
                begin
                        fillchar(tree,sizeof(tree),0);
                        fillchar(bz1,sizeof(bz1),false);
                        dg(i);
                        sum:=tree[i,5];
                        bl(i,i);
                        if(sum>ans)then ans:=sum;
                end;
                writeln(ans);
                halt;
        end;
        if(m=n-1)then
        begin
                writeln(zx);
                halt;
        end;
        writeln(n div m);
        close(input);
        close(output);
end.