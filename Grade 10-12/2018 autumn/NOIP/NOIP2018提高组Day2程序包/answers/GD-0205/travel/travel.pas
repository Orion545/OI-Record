var
        z:boolean;
        n,m,i,j,head,mnn:longint;
        hu:array[0..5010] of longint;
        bz,h:array[1..5010] of boolean;
        x,y:array[1..10010] of longint;
        st,en,fa,mn:array[1..5010] of longint;
procedure swap(var a,b:longint);
var
        c:longint;
begin
        c:=a;
        a:=b;
        b:=c;
end;
procedure qsort(l,r:longint);
var
        i,j,m1,m2:longint;
begin
        i:=l;
        j:=r;
        m1:=x[(i+j) div 2];
        m2:=y[(i+j) div 2];
        repeat
                while (x[i]<m1)or((x[i]=m1)and(y[i]<m2)) do inc(i);
                while (x[j]>m1)or((x[j]=m1)and(y[j]>m2)) do dec(j);
                if i<=j then
                begin
                        swap(x[i],x[j]);
                        swap(y[i],y[j]);
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if l<j then qsort(l,j);
        if i<r then qsort(i,r);
end;
procedure dg(o:longint);
var
        i:longint;
begin
        write(o,' ');
        bz[o]:=true;
        for i:=st[o] to en[o] do
        begin
                if bz[y[i]] then continue;
                dg(y[i]);
        end;
end;
procedure zh(o:longint);
var
        i,xx:longint;
begin
        bz[o]:=true;
        for i:=st[o] to en[o] do
        begin
                if bz[y[i]] then
                begin
                        if y[i]=fa[o] then continue;
                        xx:=o;
                        while xx<>y[i] do
                        begin
                                {inc(hu[0]);
                                hu[hu[0]]:=xx;
                                mn[hu[0]]:=y[st[xx]];  }
                                h[xx]:=true;
                                xx:=fa[xx];
                        end;
                        head:=y[i];
                        h[y[i]]:=true;
                        z:=true;
                        exit;
                end;
                fa[y[i]]:=o;
                zh(y[i]);
                if z then exit;
        end;
end;
function pd:longint;
var
        i,j,mn:longint;
begin
        mn:=maxlongint;
        pd:=0;
        for i:=1 to hu[0] do
        begin
                for j:=st[hu[i]] to en[hu[i]] do
                if y[j]<mn then
                begin
                        mn:=y[j];
                        pd:=i;
                end;
        end;
        mnn:=mn;
end;
procedure dfs(o:longint);
var
        i:longint;
begin
        if not(bz[o]) then
        begin
                write(o,' ');
                bz[o]:=true;
                inc(hu[0]);
                hu[hu[0]]:=o;
        end;
        for i:=st[o] to en[o] do
        begin
                if bz[y[i]] then continue;
                if h[o] then
                begin
                        head:=pd;
                        if (head<>0)and(mnn<y[i]) then dfs(head);
                end;
                dfs(y[i]);
        end;
end;
begin
        assign(input,'travel.in');reset(input);
        assign(output,'travel.out');rewrite(output);
        read(n,m);
        for i:=1 to m do
        begin
                read(x[i],y[i]);
                x[m+i]:=y[i];
                y[m+i]:=x[i];
        end;
        qsort(1,2*m);
        i:=0;
        while i<2*m do
        begin
                inc(i);
                st[x[i]]:=i;
                while x[i]=x[i+1] do inc(i);
                en[x[i]]:=i;
        end;
        fillchar(bz,sizeof(bz),false);
        fillchar(h,sizeof(h),false);
        if m=n-1 then
        begin
                dg(1);
        end
        else
        if m=n then
        begin
                z:=false;
                zh(1);
                fillchar(bz,sizeof(bz),false);
                //for i:=1 to n do if h[i] then writeln(i);
                dfs(1);
        end;
end.
