program travel;
var a,b:array[1..10050] of longint;
    c,d:array[1..10050] of longint;
    i,x,y,z,n,m,zz,j,k,t:longint;
    ans:array[1..10050] of longint;
    vis:array[1..10050] of boolean;

procedure qs(l,r:longint);
var i,j,t,x:longint;
begin
    i:=l;
    j:=r;
    x:=a[(i+j) div 2];
    repeat
        while a[i]<x do inc(i);
        while x<a[j] do dec(j);
        if i<=j then
        begin
            t:=a[i];a[i]:=a[j];a[j]:=t;
            t:=b[i];b[i]:=b[j];b[j]:=t;
            inc(i);
            dec(j);
        end;
    until i>j;
    if i<r then qs(i,r);
    if l<j then qs(l,j);
end;

procedure print;
var i:longint;
begin
    for i:=1 to n-1 do write(ans[i],' ');writeln(ans[n]);
end;

procedure dfs(x:longint);
var i:longint;
begin
    if zz=n then begin print;halt; end;
    for i:=c[x] to d[x] do
        if vis[b[i]]=false then
        begin
            vis[b[i]]:=true;
            inc(zz);
            ans[zz]:=b[i];
            dfs(b[i]);
        end;
end;

begin
    assign(input,'travel.in');reset(input);
    assign(output,'travel.out');rewrite(output);
    readln(n,m);
    z:=0;
    for i:=1 to m do
    begin
        readln(x,y);
        inc(z);a[z]:=x;b[z]:=y;
        inc(z);a[z]:=y;b[z]:=x;
    end;
    qs(1,z);
    fillchar(c,sizeof(c),0);
    c[1]:=1;d[n]:=z;
    for i:=2 to z do
        if a[i]<>a[i-1] then
        begin
            if c[a[i-1]]<i-1 then
            begin
                for j:=c[a[i-1]] to i-2 do
                    for k:=j+1 to i-1 do
                    if b[j]>b[k] then
                    begin
                        t:=b[j];
                        b[j]:=b[k];
                        b[k]:=t;
                    end;
            end;
            d[a[i-1]]:=i-1;
            c[a[i]]:=i;
        end;
    if c[n]<d[n] then
    begin
        for j:=c[n] to d[n]-1 do
            for k:=j+1 to d[n] do
            if b[j]>b[k] then
            begin
                t:=b[j];
                b[j]:=b[k];
                b[k]:=t;
            end;
    end;
    fillchar(vis,sizeof(vis),false);
    vis[1]:=true;
    fillchar(ans,sizeof(ans),0);
    ans[1]:=1;zz:=1;
    dfs(1);
    close(input);close(output);
end.
