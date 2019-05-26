var
        b:array[1..5000,0..100]of longint;
        ans,ans1,fa,bz:array[1..5000]of longint;
        i,j,n,m,k,l,o,p,pd:longint;
procedure swap(var x,y:longint);var z:longint;begin z:=x;x:=y;y:=z;end;
procedure kp(l,r,e:longint);
var
        i,j,o:longint;
begin
        i:=l;
        j:=r;
        o:=b[e,i];
        repeat
                while b[e,i]<o do i:=i+1;
                while b[e,j]>o do j:=j-1;
                if i<=j then
                begin
                        swap(b[e,i],b[e,j]);
                        i:=i+1;j:=j-1;
                end;
        until i>=j;
        if i<r then kp(i,r,e);
        if l<j then kp(l,j,e);
end;
procedure haha2(x:longint);
var
        v,i:longint;
begin
        bz[x]:=1;
        for i:=1 to b[x,0] do
        begin
                v:=b[x,i];
                if v=fa[x] then continue;
                if (v<>fa[x])and(bz[v]=1) then
                begin
                        o:=x;
                        p:=v;
                        exit;
                end;
                fa[v]:=x;
                haha2(v);
        end;
end;
procedure haha1(x:longint);
var
        v,i:longint;
begin
        bz[x]:=1;
        k:=k+1;
        ans[k]:=x;
        for i:=1 to b[x,0] do
        begin
                v:=b[x,i];
                if bz[v]=1 then continue;
                haha1(v);
        end;
end;
procedure dg(x:longint);
var
        v,i:longint;
begin
        bz[x]:=1;
        k:=k+1;
        ans[k]:=x;
        for i:=1 to b[x,0] do
        begin
                v:=b[x,i];
                if (bz[v]=1) then continue;
                dg(v);
        end;
end;
begin
        assign(input,'travel.in');reset(input);
        assign(output,'travel.out');rewrite(output);
        read(n,m);
        for i:=1 to m do
        begin
                read(o,p);
                inc(b[o,0]);
                b[o,b[o,0]]:=p;
                inc(b[p,0]);
                b[p,b[p,0]]:=o;
        end;
        for i:=1 to n do if b[i,0]>2 then kp(1,b[i,0],i);
        if m=n-1 then
        begin
                haha1(1);
                for i:=1 to k-1 do write(ans[i],' ');
                writeln(ans[k]);
        end
        else
        begin
                haha2(1);
                fillchar(bz,sizeof(bz),0);
                dg(1);
                for i:=1 to k-1 do write(ans[i],' ');
                writeln(ans[k]);
        end;
        close(input);close(output);
end.
