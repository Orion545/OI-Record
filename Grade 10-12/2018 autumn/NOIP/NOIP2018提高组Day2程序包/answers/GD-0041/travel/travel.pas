const maxn=5000;
var a:array[0..maxn,0..maxn]of boolean;
    b:array[0..maxn]of boolean;
    back,ans:array[0..maxn]of longint;
    n,m,i,x,y,tot:longint;

function find(x,y:longint):boolean;//x==>y
begin
    if a[x,y] then begin
        back[y]:=x;
        exit(true);
    end;
    if back[x]=0 then exit(false);
    exit(find(back[x],y));
end;

function dfs(x:longint):boolean;
var i:longint;
begin
    b[x]:=false;
    inc(tot);
    ans[tot]:=x;
    if tot=n then exit(true);
    for i:=1 to n do
        if b[i] then
            if find(x,i) then
                if dfs(i) then exit(true);
    dec(tot);
    b[x]:=true;
    back[x]:=0;
    exit(false);
end;

procedure print(x:longint);
var i:longint;
begin
    write(x,' ');
    for i:=1 to n do
        if a[x,i] and(back[x]<>i)then begin
            back[i]:=x;
            print(i);
        end;
end;

begin
    assign(input,'travel.in');reset(input);
    assign(output,'travel.out');rewrite(output);
    fillchar(a,sizeof(a),false);
    fillchar(b,sizeof(b),true);
    readln(n,m);
    for i:=1 to m do begin
        readln(x,y);
        a[x,y]:=true;
        a[y,x]:=true;
    end;
    if n=m then begin
        dfs(1);
        for i:=1 to n do write(ans[i],' ');
    end else print(1);
    close(input);close(output);
end.
