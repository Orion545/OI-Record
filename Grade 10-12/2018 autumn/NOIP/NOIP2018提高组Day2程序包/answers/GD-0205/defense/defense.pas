var
        s:string;
        mx:int64;
        xx,yy:longint;
        n,m,i,j,x,y,tot:longint;
        bz:array[1..100010] of longint;
        a:array[1..100010] of int64;
        f:array[1..100010,0..1] of int64;
        last,tov,next:array[0..200020] of longint;
procedure insert(x,y:longint);
begin
        inc(tot);
        tov[tot]:=y;
        next[tot]:=last[x];
        last[x]:=tot;
end;
function min(x,y:int64):int64;
begin
        if x<y then exit(x) else exit(y);
end;
procedure dg(u,fa:longint);
var
        i:longint;
begin
        i:=last[u];
        while i<>0 do
        begin
                if tov[i]=fa then
                begin
                        i:=next[i];
                        continue;
                end;
                dg(tov[i],u);
                if bz[tov[i]]=0 then
                begin
                        f[u,0]:=mx;
                        f[u,1]:=f[u,1]+f[tov[i],0];
                end
                else
                if bz[tov[i]]=1 then
                begin
                        f[u,0]:=f[u,0]+f[tov[i],1];
                        f[u,1]:=f[u,1]+f[tov[i],1];
                end
                else
                begin
                        f[u,0]:=f[u,0]+f[tov[i],1];
                        f[u,1]:=min(f[tov[i],0],f[tov[i],1])+f[u,1];
                end;
                i:=next[i];
        end;
        f[u,1]:=f[u,1]+a[u];
end;
begin
        assign(input,'defense.in');reset(input);
        assign(output,'defense.out');rewrite(output);
        mx:=maxlongint*maxlongint;
        read(n,m);
        readln(s);
        for i:=1 to n do read(a[i]);
        for i:=1 to n-1 do
        begin
                read(x,y);
                insert(x,y);
                insert(y,x);
        end;
        for i:=1 to n do bz[i]:=-1;
        for i:=1 to m do
        begin
                fillchar(f,sizeof(f),0);
                read(x,xx,y,yy);
                bz[x]:=xx;
                bz[y]:=yy;
                if (xx=0)and(yy=0) then
                begin
                        j:=last[x];
                        while j<>0 do
                        begin
                                if tov[j]=y then break;
                                j:=next[j];
                        end;
                        if tov[j]=y then
                        begin
                                writeln('-1');
                                bz[x]:=-1;
                                bz[y]:=-1;
                                continue;
                        end;
                end;
                dg(1,0);
                if bz[1]=0 then
                begin
                        writeln(f[1,0]);
                end
                else
                if bz[1]=1 then
                begin
                        writeln(f[1,1]);
                end
                else
                begin
                        writeln(min(f[1,1],f[1,0]));
                end;
                bz[x]:=-1;
                bz[y]:=-1;
        end;
        close(input);
        close(output);
end.