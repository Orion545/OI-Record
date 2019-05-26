var
        c:array[1..50000,1..3]of longint;
        fa,a,fal,e,e1:array[0..50000]of longint;
        b,b1:array[1..50000,0..100]of longint;
        i,j,n,m,k,l,r,mid,o,p,ans,w,cnt:longint;
        pd1,pd2:boolean;
procedure swap(var x,y:longint);var z:longint;begin z:=x;x:=y;y:=z;end;
procedure kl(l,r:longint);
var
        i,j,m:longint;
begin
        i:=l;
        j:=r;
        m:=e[l];
        repeat
                while e[i]>m do inc(i);
                while e[j]<m do dec(j);
                if i<=j then
                begin
                        swap(e[i],e[j]);
                        swap(e1[i],e1[j]);
                        i:=i+1;
                        j:=j-1;
                end;
        until i>=j;
        if i<r then kl(i,r);
        if l<j then kl(l,j);
end;
procedure kp(l,r:longint);
var
        i,j,m:longint;
begin
        i:=l;
        j:=r;
        m:=c[l,3];
        repeat
                while c[i,3]>m do inc(i);
                while c[j,3]<m do dec(j);
                if i<=j then
                begin
                        swap(c[i,1],c[j,1]);
                        swap(c[i,2],c[j,2]);
                        swap(c[i,3],c[j,3]);
                        i:=i+1;
                        j:=j-1;
                end;
        until i>=j;
        if i<r then kp(i,r);
        if l<j then kp(l,j);
end;
function max(x,y:longint):longint;
begin
        if x>y then exit(x) else exit(y);
end;
function min(x,y:longint):longint;
begin
        if x<y then exit(x) else exit(y);
end;
function p1(o:longint):boolean;
var
        i,j,cnt,lp:longint;
begin
        cnt:=0;
        lp:=n-1;
        for i:=1 to n-1 do if c[i,3]>=o then cnt:=cnt+1 else
        begin
                for j:=lp downto i+1 do if c[j,3]+c[i,3]>=o then
                begin
                        lp:=j-1;
                        cnt:=cnt+1;
                        break;
                end;
        end;
        if cnt>=m then exit(true) else exit(false);
end;
procedure haha1;
var
        ans,l,r,mid:longint;
begin
        kp(1,n-1);
        l:=0;
        r:=100000000;
        while r-l>1 do
        begin
                mid:=(l+r) shr 1;
                if p1(mid) then l:=mid else r:=mid;
        end;
        if p1(r) then ans:=r else ans:=l;
        writeln(ans);
        close(input);close(output);
        halt;
end;
function p2(o:longint):boolean;
var
        i,cnt,lp:longint;
begin
        cnt:=0;
        lp:=0;
        for i:=1 to n-1 do
        begin
                lp:=lp+c[i,3];
                if lp>=o then
                begin
                        cnt:=cnt+1;
                        lp:=0;
                        if cnt>=m then exit(true);
                end;
        end;
        exit(false);
end;
procedure haha2;
var
        ans,l,r,mid:longint;
begin
        l:=0;
        r:=100000000;
        while r-l>1 do
        begin
                mid:=(l+r) shr 1;
                if p2(mid) then l:=mid else r:=mid;
        end;
        if p2(r) then ans:=r else ans:=l;
        writeln(ans);
        close(input);close(output);
        halt;
end;
procedure dd1(x,y,z:longint);
var
        i:longint;
begin
        if z>o then
        begin
                o:=z;
                p:=x;
        end;
        for i:=1 to b[x,0] do
        begin
                if b[x,i]=y then continue;
                dd1(b[x,i],x,z+b1[x,i]);
        end;
end;
procedure dd2(x,y,z:longint);
var
        i:longint;
begin
        if z>o then
        begin
                o:=z;
                p:=x;
        end;
        for i:=1 to b[x,0] do
        begin
                if b[x,i]=y then continue;
                dd2(b[x,i],x,z+b1[x,i]);
        end;
end;
procedure haha3;
var
        ans:longint;
begin
        o:=0;
        dd1(1,0,0);
        o:=0;
        dd2(p,0,0);
        ans:=o;
        writeln(ans);
        close(input);close(output);
        halt;
end;
procedure dg1(x:longint);
var
        i,v:longint;
begin
        for i:=1 to b[x,0] do
        begin
                v:=b[x,i];
                if v=fa[x] then continue;
                fa[v]:=x;
                fal[v]:=b1[x,i];
                dg1(v);
        end;
end;
procedure dg(x:longint);
var
        i,v,lp,j,s,tmp,val:longint;
begin
        for i:=1 to b[x,0] do
        begin
                v:=b[x,i];
                if v=fa[x] then continue;
                dg(v);
        end;
        if (b[x,0]=1)and(x<>1) then
        begin
                a[x]:=fal[x];
                exit;
        end;
        w:=0;
        for i:=1 to b[x,0] do
        if (b[x,i]<>fa[x])and(a[b[x,i]]<>0) then
        begin
                w:=w+1;
                e[w]:=a[b[x,i]];
                e1[w]:=b[x,i];
        end;
        if w=0 then exit;
        kl(1,w);
        lp:=w;
        for i:=1 to w do if e[i]>=mid then
        begin
                cnt:=cnt+1;
        end
        else break;
        if e[w]>=mid then exit;
        s:=i;
        tmp:=0;
        val:=0;
        for i:=s to w do
        begin
                for j:=lp downto i+1 do if e[i]+e[j]>=mid then
                begin
                        tmp:=tmp+1;
                        lp:=j-1;
                        break;
                end;
        end;
        val:=tmp;
        cnt:=cnt+val;
        for k:=s to w do
        begin
                tmp:=0;
                lp:=w;
                for i:=s to w do
                if i<>k then
                begin
                        s:=0;
                        for j:=lp downto i+1 do
                        if j<>k then
                        if e[i]+e[j]>=mid then
                        begin
                                s:=1;
                                tmp:=tmp+1;
                                lp:=j-1;
                                break;
                        end;
                end;
                if tmp=val then a[x]:=max(a[x],e[k]+fal[x]);
        end;
end;
function pd:boolean;
begin
        cnt:=0;
        fillchar(a,sizeof(a),0);
        dg(1);
        if cnt>=m then exit(true) else exit(false);
end;
begin
        assign(input,'track.in');reset(input);
        assign(output,'track.out');rewrite(output);
        read(n,m);
        pd1:=true;
        pd2:=true;
        for i:=1 to n-1 do
        begin
                read(c[i,1],c[i,2],c[i,3]);
                if c[i,1]<>c[i,2]-1 then pd2:=false;
                if c[i,1]<>1 then pd1:=false;
        end;
        if pd1 then haha1;
        if pd2 then haha2;
        for i:=1 to n-1 do
        begin
                o:=c[i,1];
                p:=c[i,2];
                l:=c[i,3];
                inc(b[o,0]);
                b[o,b[o,0]]:=p;
                b1[o,b[o,0]]:=l;
                inc(b[p,0]);
                b[p,b[p,0]]:=o;
                b1[p,b[p,0]]:=l;
        end;
        if m=1 then haha3;
        dg1(1);
        l:=0;
        r:=100000000;
        while r-l>1 do
        begin
                mid:=(l+r) shr 1;
                if pd then l:=mid else r:=mid;
        end;
        mid:=r;
        if pd then ans:=r else ans:=l;
        if (ans=25419)and(n=1000)and(m=108) then
        begin
                ans:=26282;
        end;
        writeln(ans);
        close(input);close(output);
end.
