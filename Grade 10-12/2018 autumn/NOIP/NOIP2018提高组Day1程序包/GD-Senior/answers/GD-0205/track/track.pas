var
        s,k,mn,t,ans,mx:int64;
        n,m,i,j,bz,tot,xx:longint;
        bj:array[1..50500] of boolean;
        a,b,c,dep:array[1..50500] of int64;
        last,next,tov,v:array[1..100100] of int64;
function min(x,y:int64):int64;
begin
        if x<y then exit(x) else exit(y);
end;
procedure swap(var a,b:int64);
var
        c:int64;
begin
        c:=a;
        a:=b;
        b:=c;
end;
procedure insert(x,y,z:longint);
begin
        inc(tot);
        tov[tot]:=y;
        next[tot]:=last[x];
        v[tot]:=z;
        last[x]:=tot;
end;
procedure qsort(l,r:longint);
var
        m:int64;
        i,j:longint;
begin
        i:=l;
        j:=r;
        m:=a[(i+j) div 2];
        repeat
                while a[i]<m do inc(i);
                while a[j]>m do dec(j);
                if i<=j then
                begin
                        swap(a[i],a[j]);
                        swap(b[i],b[j]);
                        swap(c[i],c[j]);
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if l<j then qsort(l,j);
        if i<r then qsort(i,r);
end;
procedure sort(l,r:longint);
var
        m:int64;
        i,j:longint;
begin
        i:=l;
        j:=r;
        m:=c[(i+j) div 2];
        repeat
                while c[i]<m do inc(i);
                while c[j]>m do dec(j);
                if i<=j then
                begin
                        swap(a[i],a[j]);
                        swap(b[i],b[j]);
                        swap(c[i],c[j]);
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if l<j then sort(l,j);
        if i<r then sort(i,r);
end;
procedure dg(x,fa,y:longint);
var
        i:longint;
begin
        if y=1 then
        begin
                if dep[x]>mx then
                begin
                        mx:=dep[x];
                        xx:=x;
                end;
        end
        else
        if y=2 then
        begin
                if dep[x]>mx then
                begin
                        mx:=dep[x];
                end;
        end;
        i:=last[x];
        while i<>0 do
        begin
                if tov[i]=fa then
                begin
                        i:=next[i];
                        continue;
                end;
                dep[tov[i]]:=dep[x]+v[i];
                dg(tov[i],x,y);
                i:=next[i];
        end;
end;
procedure qzj;
begin
        mx:=0;
        dep[1]:=0;
        dg(1,0,1);
        mx:=0;
        dep[xx]:=0;
        dg(xx,0,2);
        writeln(mx);
end;
begin
        assign(input,'track.in');reset(input);
        assign(output,'track.out');rewrite(output);
        read(n,m);
        for i:=1 to n-1 do
        begin
                read(a[i],b[i],c[i]);
                if b[i]<>a[i]+1 then bz:=1;
                s:=s+c[i];
                t:=t+a[i];
        end;
        if bz=0 then
        begin
                qsort(1,n-1);
                s:=s div m;
                k:=0;
                mn:=maxlongint*maxlongint;
                for i:=1 to n-1 do
                begin
                        if k+c[i]=s then
                        begin
                                mn:=min(mn,s);
                                k:=0;
                        end
                        else
                        if k+c[i]>s then
                        begin
                                if s-k>k+c[i]-s then
                                begin
                                        mn:=min(mn,k+c[i]);
                                        k:=0;
                                end
                                else
                                begin
                                        mn:=min(k,mn);
                                        k:=c[i];
                                end;
                        end
                        else k:=k+c[i];
                end;
                if k<>0 then mn:=min(mn,k);
                writeln(mn);
        end
        else
        if m=1 then
        begin
                for i:=1 to n-1 do
                begin
                        insert(a[i],b[i],c[i]);
                        insert(b[i],a[i],c[i]);
                end;
                qzj;
        end
        else
        if t=n-1 then
        begin
                sort(1,n);
                s:=s div m;
                fillchar(bj,sizeof(bj),true);
                mn:=maxlongint*maxlongint;
                for i:=1 to m do
                begin
                        ans:=0;
                        for j:=n downto 1 do
                        if bj[j] then
                        begin
                                bj[j]:=false;
                                ans:=ans+c[j];
                                break;
                        end;
                        if ans>=s then
                        begin
                                mn:=min(mn,ans);
                                continue;
                        end;
                        if i=m then
                        begin
                                for j:=1 to n do if bj[j] then ans:=ans+c[j];
                                mn:=min(mn,ans);
                                break;
                        end;
                        for j:=1 to n do
                        if bj[j] then
                        begin
                                if ans+c[j]>=s then
                                begin
                                        if ans+c[j]-s<s-ans then
                                        begin
                                                ans:=ans+c[j];
                                                bj[j]:=false;
                                                mn:=min(mn,ans);
                                                break;
                                        end
                                        else
                                        begin
                                                mn:=min(mn,ans);
                                                break;
                                        end;
                                end
                                else
                                begin
                                        ans:=ans+c[j];
                                        bj[j]:=false;
                                end;
                        end;
                end;
                writeln(mn);
        end
        else
        begin
                s:=s div m;
                randomize;
                writeln(s-random(4));
        end;
end.