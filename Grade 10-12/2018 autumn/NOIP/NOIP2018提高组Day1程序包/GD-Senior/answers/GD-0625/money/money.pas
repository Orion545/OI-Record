var
        t,n,i,j,ans,no:longint;
        p:boolean;
        a:array[1..100]of longint;
procedure dfs(x:longint);
var
        i:longint;
begin
        if x=a[no] then p:=true;
        if p then exit;
        if x>a[no] then exit;
        for i:=1 to n do
        if i<>no then dfs(x+a[i]);
end;
begin
        assign(input,'money.in');
        assign(output,'money.out');
        reset(input);
        rewrite(output);
        readln(t);
        for i:=1 to t do begin
                readln(n);
                for j:=1 to n do read(a[j]);
                for j:=1 to n do begin
                        p:=false;
                        no:=j;
                        dfs(0);
                        if p=true then inc(ans);
                end;
                writeln(n-ans);
                ans:=0;
        end;
        close(input);
        close(output);
end.