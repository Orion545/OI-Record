program D2T1;//by Peter.W.Wany
var     i,j,k,n,m,a,b:longint;
        map:array[0..5001,0..5001]of longint;
        vis:array[0..5001]of boolean;
        last,que,ans:array[0..5001]of longint;
procedure go(x,k:longint;xiao:boolean);
var     i,j:longint;
begin
        if k=n then
        begin
                for i:=1 to n do
                        if ans[i]<>que[i] then
                        begin
                                if ans[i]>que[i] then
                                        ans:=que;
                                break;
                        end;
                exit;

        end;
        for i:=1 to map[x,0] do
        begin
                if (not(vis[map[x,i]]))and((map[x,i]<=ans[k+1])or(xiao))then
                begin
                        vis[map[x,i]]:=true;
                        que[k+1]:=map[x,i];
                        last[map[x,i]]:=x;
                        if (map[x,i]<ans[k+1])or(xiao) then
                                xiao:=true;
                        go(map[x,i],k+1,xiao);
                        vis[map[x,i]]:=false;
                        que[k+1]:=maxlongint;
                        last[map[x,i]]:=0;
                end;
        end;
        i:=x;
        while last[i]<>0 do
        begin
                for j:=1 to map[i,0] do
                begin
                        if (not(vis[map[i,j]]))and((map[i,j]<=ans[k+1])or(xiao))then
                        begin
                                vis[map[i,j]]:=true;
                                que[k+1]:=map[i,j];
                                last[map[i,j]]:=last[i];
                                if (map[i,j]<ans[k+1])or(xiao) then
                                        xiao:=true;
                                go(map[i,j],k+1,xiao);
                                vis[map[i,j]]:=false;
                                que[k+1]:=maxlongint;
                                last[map[i,j]]:=0;
                        end;
                end;
                i:=last[i];
        end;

end;
begin
        assign(input,'travel.in');
        reset(input);
        assign(output,'travel.out');
        rewrite(output);
        readln(n,m);
        for i:=1 to m do
        begin
                readln(a,b);
                inc(map[a,0]);
                map[a,map[a,0]]:=b;
                inc(map[b,0]);
                map[b,map[b,0]]:=a;
        end;
        for i:=1 to n do
                ans[i]:=maxlongint;
        for i:=1 to n do
        begin
                vis[i]:=true;
                que[1]:=i;
                go(i,1,false);
                vis[i]:=false;
                if ans[n]<>maxlongint then
                        break;
        end;
        for i:=1 to n do
                write(ans[i],' ');
        close(input);
        close(output);
end.
