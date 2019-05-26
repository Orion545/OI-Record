program travel;
var
        i,j,n,m,d,mad:longint;
        u,v,k,cover:array[1..5000] of integer;
        c:array[1..5000,1..5000] of integer;
        ans:array[1..5000] of integer;

function min(a,b:integer):integer;
begin
        if a<b then exit(a) else exit(b);
end;

function max(a,b:integer):integer;
begin
        if a>b then exit(a) else exit(b);
end;

procedure dfs(x:integer);
var
        i,j:integer;
        e:boolean;
begin
        if (x<ans[d]) or (ans[d]=0) then ans[d]:=x
        else begin ans[mad]:=x; mad:=mad+1; end;
        writeln;
        d:=d+1;
        if d>mad then mad:=d;
        e:=true;
        for i:=1 to k[x] do
                if cover[c[x,i]]=0 then e:=false;
        if e or (d>n) then exit;
        cover[x]:=1;
        for i:=1 to k[x] do
                if cover[c[x,i]]=0 then begin dfs(c[x,i]); d:=d-1; end;
        cover[x]:=0;
end;

begin
        assign(input,'travel.in');reset(input);
        assign(output,'travel.out');rewrite(output);
        read(n,m);
        fillchar(k,sizeof(k),0);
        for i:=1 to m do
        begin
                read(u[i],v[i]);
                inc(k[u[i]]);inc(k[v[i]]);
                c[u[i],k[u[i]]]:=v[i];
                c[v[i],k[v[i]]]:=u[i];
        end;
        ans[1]:=1;d:=1;mad:=1;
        fillchar(cover,sizeof(cover),0);
        dfs(1);
        for i:=1 to n do
                write(ans[i],' ');
        close(input);close(output);
end.