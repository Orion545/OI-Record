program defense;
var
        n,m,a,b,x,y,i,j,k,ans,max,min:longint;
        type1:string;
        p,u,v,d:array[0..100000] of longint;
        q:array[1..100000] of integer;
        c:array[1..100000,1..2000] of longint;
        yn:boolean;

begin
        assign(input,'defense.in');reset(input);
        assign(output,'defense.out');rewrite(output);
        read(n,m,type1);
        for i:=1 to n do
                read(p[i]);
        fillchar(d,sizeof(d),0);
        for i:=1 to n-1 do
                begin
                        read(u[i],v[i]);
                        inc(d[u[i]]);inc(d[v[i]]);
                        c[u[i],d[u[i]]]:=v[i];
                        c[v[i],d[v[i]]]:=u[i];
                end;
        for i:=1 to m do
                begin
                        read(a,x,b,y);
                        fillchar(q,sizeof(q),1);
                        q[a]:=x;
                        q[b]:=y;
                        for j:=1 to n do
                                if q[j]=1 then
                                        for k:=1 to d[j] do
                                                q[c[u[j],k]]:=0;
                        for j:=1 to n do
                                begin
                                        if q[j]=0 then
                                        begin
                                                yn:=true;max:=0;d[0]:=0;
                                                for k:=1 to d[j] do
                                                begin
                                                        if q[c[u[j],k]]=1 then
                                                                yn:=false;
                                                        if (d[c[u[j],k]]>d[max]) and (q[c[u[j],k]]<>0) then max:=c[u[j],k];
                                                        if (d[c[u[j],k]]=d[max]) and (q[c[u[j],k]]<>0) then
                                                                if p[max]>p[c[u[j],k]] then max:=c[u[j],k];
                                                end;
                                                if max<>0 then
                                                        if yn then q[max]:=1;
                                        end;
                                        if (q[j]<>1) and (q[j]<>0) then
                                        begin
                                                yn:=true;min:=c[u[j],1];
                                                for k:=1 to d[j] do
                                                begin
                                                        if q[c[u[j],k]]=1 then
                                                                yn:=false;
                                                        if p[c[u[j],k]]<p[min] then min:=c[u[j],k];
                                                end;
                                                if yn then
                                                        q[min]:=1;
                                        end;
                                end;
                        for j:=1 to n do
                        begin
                                yn:=true;
                                for k:=1 to d[j] do
                                        begin
                                                if q[c[j,k]]=1 then
                                                        yn:=false;
                                        end;
                                if yn then exit;
                        end;
                        ans:=0;
                        if yn then writeln(-1)
                        else
                        begin
                                for j:=1 to n do
                                        if q[j]=1 then ans:=ans+p[j];
                                writeln(ans);
                        end;
                end;
        close(input);close(output);
end.