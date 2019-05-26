const up=5000;
var
        i,j,k,l,n,m,tot,ans,st,father,zb,yb:longint;
        x,y,answer:array[1..up] of longint;
        tov,next,last:array[1..2*up] of longint;
        son:array[1..up,0..up] of longint;
        flag,h:array[1..up] of boolean;
        bz,dpd:boolean;

procedure qsort(l,r,v:longint);
var
        i,j,k,mid:longint;
begin
        i:=l;
        j:=r;
        mid:=son[v,(i+j) div 2];
        repeat
                while son[v,i]<mid do inc(i);
                while son[v,j]>mid do dec(j);
                if i<=j then
                begin
                        k:=son[v,i];
                        son[v,i]:=son[v,j];
                        son[v,j]:=k;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if i<r then qsort(i,r,v);
        if l<j then qsort(l,j,v);
end;

procedure insert(x,y:longint);
begin
        inc(tot);
        tov[tot]:=y;
        next[tot]:=last[x];
        last[x]:=tot;
end;

procedure dfs1(v,fa:longint);
var
        i,j,k,l:longint;
begin
        i:=last[v];
        while i>0 do
        begin
                if tov[i]<>fa then
                begin
                        inc(son[v,0]);
                        son[v,son[v,0]]:=tov[i];
                end;
                i:=next[i];
        end;
        if son[v,0]>0 then
        qsort(1,son[v,0],v);
        for i:=1 to son[v,0] do
        begin
                inc(ans);
                answer[ans]:=son[v,i];
                dfs1(son[v,i],v);
        end;
end;

procedure dfs2(v,fa:longint);
var
        i,j,k,l:longint;
begin
        i:=last[v];
        flag[v]:=true;
        while i>0 do
        begin
                if (tov[i]<>fa) and (not flag[tov[i]]) then
                begin
                        dfs2(tov[i],v);
                end
                else
                if (tov[i]<>fa) and (flag[tov[i]]=true) then
                begin
                        h[v]:=true;
                        bz:=true;
                        st:=tov[i];
                        break;
                end;
                if bz then
                begin
                        if v=st then
                        begin
                                h[v]:=true;
                                st:=0;
                        end;
                        if st<>0 then
                        begin
                                h[v]:=true;
                        end;
                        break;
                end;
                i:=next[i];
        end;
end;

procedure dfs4(v,fa:longint);
var
        i,j,k,l,x:longint;
begin
        if v=11 then
        j:=j;
        i:=last[v];
        x:=0;
        flag[v]:=false;
        inc(ans);
        answer[ans]:=v;
        while i>0 do
        begin
                if (tov[i]<>fa) and (flag[tov[i]]) then
                begin
                        inc(son[v,0]);
                        son[v,son[v,0]]:=tov[i];
                        if h[tov[i]] then
                        begin
                                x:=tov[i];
                        end;
                end;
                i:=next[i];
        end;
        qsort(1,son[v,0],v);
        for i:=1 to son[v,0] do
        begin
                if son[v,i]<>x then
                begin
                        if son[v,i]=66 then
                        j:=j;
                        inc(ans);
                        answer[ans]:=son[v,i];
                        dfs1(son[v,i],v);
                end
                else
                if (dpd) or ((son[v,i]<=yb) and (son[v,i]=x)) then
                begin
                        dfs4(son[v,i],v);
                end;
        end;
        if (x>yb) and (not dpd) then
        begin
                dpd:=true;
                exit;
        end;
end;

procedure dfs3(v,fa:longint);
var
        i,j,k,l:longint;
        flag:boolean;
begin
        j:=0;
        i:=last[v];
        flag:=true;
        zb:=0;yb:=0;
        while i>0 do
        begin
                if tov[i]<>fa then
                begin
                        inc(son[v,0]);
                        son[v,son[v,0]]:=tov[i];
                        if h[tov[i]] then
                        begin
                                inc(j);
                                if j=2 then flag:=false;
                                if zb<>0 then yb:=tov[i]
                                else zb:=tov[i];
                        end;
                end;
                i:=next[i];
        end;
        if not flag then
        begin
                if zb>yb then
                begin
                        k:=zb;
                        zb:=yb;
                        yb:=k;
                end;
                if son[v,0]>0 then
                qsort(1,son[v,0],v);
                for i:=1 to son[v,0] do
                begin
                        if not h[son[v,i]] then
                        begin
                                inc(ans);
                                answer[ans]:=son[v,i];
                                dfs1(son[v,i],v);
                        end
                        else
                        if son[v,i]=zb then
                        begin
                                dfs4(son[v,i],v);
                        end
                        else
                        if son[v,i]=yb then
                        begin
                                dfs4(son[v,i],v);
                        end;
                end;
                exit;
        end
        else
        begin
                if son[v,0]>0 then
                qsort(1,son[v,0],v);
                for i:=1 to son[v,0] do
                begin
                        inc(ans);
                        answer[ans]:=son[v,i];
                        dfs3(son[v,i],v);
                end;
        end;
end;

begin
        assign(input,'travel.in');reset(input);
        assign(output,'travel.out');rewrite(output);
        readln(n,m);
        for i:=1 to m do
        begin
                readln(x[i],y[i]);
                insert(x[i],y[i]);
                insert(y[i],x[i]);
        end;
        if m=n-1 then
        begin
                ans:=1;
                answer[1]:=1;
                dfs1(1,0);
                for i:=1 to n do
                begin
                        write(answer[i],' ');
                end;
                writeln;
        end
        else
        if m=n then
        begin
                dfs2(1,0);
                ans:=1;
                answer[1]:=1;
                fillchar(flag,sizeof(flag),true);
                dfs3(1,0);
                for i:=1 to n do
                begin
                        write(answer[i],' ');
                end;
                writeln;
        end;
        close(input);close(output);
end.
