const maxn=5005;
var
bz : array[1..maxn,1..maxn] of boolean;
go,nxt : array[1..maxn*2] of longint;
vis : array[1..maxn] of boolean;
head,d,ans,u,v : array[0..maxn] of longint;
i,j,n,m,tail : longint;

procedure dfs(x,fa:longint);
var i:longint;
        begin
        inc(d[0]);d[d[0]]:=x;vis[x]:=true;
        for i := 1 to n do
        if bz[x,i] and (not vis[i]) then dfs(i,x);
        end;
begin
assign(input,'travel.in');reset(input);
assign(output,'travel.out');rewrite(output);
readln(n,m);
for i := 1 to m do begin
        readln(u[i],v[i]);
        bz[u[i],v[i]]:=true;bz[v[i],u[i]]:=true;
end;


if m=n-1 then begin
        d[0]:=0;
        dfs(1,0);
        for i := 1 to n do write(d[i],' ');
end
else begin
        ans[1]:=maxlongint;
        for i := 1 to m do begin
                bz[u[i],v[i]]:=false;bz[v[i],u[i]]:=false;
                d[0]:=0;
                fillchar(vis,sizeof(vis),0);
                dfs(1,0);
                bz[u[i],v[i]]:=true;bz[v[i],u[i]]:=true;
                for j := 1 to n do
                if d[j]<>ans[j] then break;
                if (d[0]=n) and (d[j]<ans[j]) then ans:=d;
                //writeln(': ',i);
        end;
        for i := 1 to n do write(ans[i],' ');
end;
close(input);close(output);
end.
