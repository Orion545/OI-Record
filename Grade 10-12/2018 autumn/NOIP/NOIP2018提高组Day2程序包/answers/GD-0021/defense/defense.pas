var
        i,j,k,l,n,m,tot,a,b,xx,yy:longint;
        val,flag:array[0..100000] of int64;
        x,y:array[1..100000] of longint;
        tov,next,last:array[1..200000] of longint;
        f:array[1..100000,0..1] of int64;
        s:string;
        qj:boolean;
function min(x,y:longint):longint;
begin
        if x<y then exit(x);
        exit(y);
end;
procedure insert(x,y:longint);
begin
        inc(tot);
        tov[tot]:=y;
        next[tot]:=last[x];
        last[x]:=tot;
end;
procedure dfs(v,fa:longint);
var
        i,j,k,l:longint;
begin
        f[v,0]:=0;
        f[v,1]:=val[v];
        i:=last[v];
        while i>0 do
        begin
                if tov[i]<>fa then
                begin
                        dfs(tov[i],v);
                        if not qj then exit;
                        if flag[tov[i]]>-1 then
                        begin
                                if flag[tov[i]]=0 then
                                begin
                                        f[v,0]:=maxlongint;
                                        f[v,1]:=f[v,1]+f[tov[i],0];
                                        if flag[v]=0 then
                                        begin
                                                qj:=false;
                                                exit;
                                        end;
                                end;
                                if flag[tov[i]]=1 then
                                begin
                                        f[v,0]:=f[v,0]+f[tov[i],1];
                                        f[v,1]:=f[v,1]+f[tov[i],1];
                                end;
                        end
                        else
                        begin
                                if f[v,0]<>maxlongint then
                                begin
                                        f[v,0]:=f[v,0]+f[tov[i],1];
                                end;
                                f[v,1]:=f[v,1]+min(f[tov[i],0],f[tov[i],1]);
                        end;
                end;
                i:=next[i];
        end;
end;
begin
        assign(input,'defense.in');reset(input);
        assign(output,'defense.out');rewrite(output);
        read(n,m);
        readln(s);
        for i:=1 to n do
        begin
                read(val[i]);
                flag[i]:=-1;
        end;
        for i:=1 to n-1 do
        begin
                readln(x[i],y[i]);
                insert(x[i],y[i]);
                insert(y[i],x[i]);
        end;
        for i:=1 to m do
        begin
                flag[b]:=-1;flag[a]:=-1;
                readln(a,xx,b,yy);
                flag[b]:=yy;flag[a]:=xx;
                qj:=true;
                dfs(1,0);
                if not qj then writeln(-1)
                else
                writeln(min(f[1,0],f[1,1]));
        end;
        close(input);close(output);
end.
