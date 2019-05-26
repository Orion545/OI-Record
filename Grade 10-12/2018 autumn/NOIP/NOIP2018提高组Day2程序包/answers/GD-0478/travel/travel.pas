type
        edge=record
                y,next:longint;
        end;
var
        f,g,l,v:array[0..10020] of longint;
        a:array[0..10020] of edge;
        n,m,i,j,x,y:longint;
procedure add(x,y,i:longint);
begin
        a[i].y:=y;
        a[i].next:=l[x];
        l[x]:=i;
end;
procedure dfs(x,fr,k:longint);
var
        i,y:longint;
begin
        if v[x]=0 then
        begin
                f[k]:=x;
                g[x]:=fr;
                v[x]:=1;
        end;
        i:=l[x];y:=n+1;
        if k=n then exit;
        while i<>0 do
        begin
                if (v[a[i].y]=0)and(y>a[i].y) then y:=a[i].y;
                i:=a[i].next;
        end;
        if y=n+1 then dfs(g[x],x,k)
        else dfs(y,x,k+1);
end;
begin
        assign(input,'travel.in');reset(input);
        assign(output,'travel.out');rewrite(output);
        read(n,m);
        fillchar(f,sizeof(f),0);
        fillchar(v,sizeof(v),0);
        for i := 1 to m do
        begin
                read(x,y);
                add(x,y,i*2-1);
                add(y,x,i*2);
        end;
        f[1]:=1;
        dfs(1,1,1);
        for i := 1 to n do
                write(f[i],' ');
        close(input);close(output);
end.
