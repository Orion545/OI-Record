type
        edge=record
                x,y,v,l:longint;
        end;
var
        e:array[0..110000] of edge;
        a,f,l,d:array[0..110000] of longint;
        n,m,i,j,k,t:longint;
        x,y,v,ans:longint;
procedure add(x,y,v,i:longint);
begin
        e[i].x:=x;
        e[i].y:=y;
        e[i].v:=v;
        e[i].l:=l[x];
        l[x]:=i;
end;
procedure qsort(l,r:longint);
var
        i,j,mid,t:longint;
begin
        i:=l;j:=r;
        mid:=f[(l+r) div 2];
        repeat
                while f[i]>mid do inc(i);
                while f[j]<mid do dec(j);
                if i<=j then
                begin
                        t:=f[i];
                        f[i]:=f[j];
                        f[j]:=t;
                        t:=d[i];
                        d[i]:=d[j];
                        d[j]:=t;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if j>l then qsort(l,j);
        if i<r then qsort(i,r);
end;
begin
        assign(input,'track.in');reset(input);
        assign(output,'track.out');rewrite(output);
        read(n,m);
        for i := 1 to n-1 do
        begin
                read(x,y,v);
                add(x,y,v,i*2-1);
                add(y,x,v,i*2);
                f[i]:=v;
                d[i]:=i;
        end;
        qsort(1,n-1);
        ans:=maxlongint;
        for i := 1 to m do
        begin
                if ans>f[i]+f[m*2-i+1] then ans:=f[i]+f[m*2-i+1];
        end;
        writeln(ans);
        close(input);close(output);
end.
