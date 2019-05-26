program travel;
type
        jh=record
        x,y,next:longint; end;
var
        s:array [0..10010] of jh;
        last,vis,ans:array [0..5005] of longint;
        i,n,m,x,y,tot,lans:longint;
procedure add(x,y:longint);
begin
        tot:=tot+1;
        s[tot].x:=x;
        s[tot].y:=y;
        s[tot].next:=last[x];
        last[x]:=tot;
end;

procedure dfs(x:longint);
var
        a:array [0..5005] of longint;
        i,j,l,temp:longint;
begin
        vis[x]:=1;
        fillchar(a,sizeof(a),0);
        l:=0;
        lans:=lans+1;
        ans[lans]:=x;

        i:=last[x];
        while i<>0 do
        begin
                j:=s[i].y;
                if vis[j]=0 then
                begin
                        l:=l+1;
                        a[l]:=j;
                end;
                i:=s[i].next;
        end;
        for i:=1 to l do
          for j:=i+1 to l do
            if a[i]>a[j] then
            begin
                temp:=a[i];
                a[i]:=a[j];
                a[j]:=temp;
            end;
        for i:=1 to l do
          if vis[a[i]]=0 then dfs(a[i]);
end;

begin
        assign(input,'travel.in');
        assign(output,'travel.out');
        reset(input);
        rewrite(output);

        readln(n,m);
        for i:=1 to m do
        begin
                readln(x,y);
                add(x,y);
                add(y,x);
        end;
        fillchar(vis,sizeof(vis),0);
        dfs(1);
        for i:=1 to n do
          write(ans[i],' ');
        writeln;
        close(input);
        close(output);
end.