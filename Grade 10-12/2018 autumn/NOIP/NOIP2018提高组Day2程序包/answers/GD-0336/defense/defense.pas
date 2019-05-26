var
        b:array[1..2000,0..200]of longint;
        bz:array[1..2000]of longint;
        f:array[1..2000,0..1]of int64;
        p,fa:array[1..2000]of longint;
        i,j,n,m,k,l,o,aa,bb,x,y:longint;
        ans:int64;
        sa:string;
function max(x,y:int64):int64;begin if x>y then exit(x) else exit(y);end;
function min(x,y:int64):int64;begin if x<y then exit(x) else exit(y);end;
procedure dg(x:longint);
var
        i,k,v:longint;
        e:int64;
begin
        for i:=1 to b[x,0] do
        begin
                v:=b[x,i];
                if v=fa[x] then continue;
                fa[v]:=x;
                dg(v);
        end;
        if (b[x,0]=1)and(x<>1) then
        begin
                if bz[x]<>1 then f[x,0]:=0;
                if bz[x]<>0 then f[x,1]:=p[x];
                exit;
        end;
        if bz[x]<>0 then f[x,1]:=p[x];
        for i:=1 to b[x,0] do
        begin
                v:=b[x,i];
                if v=fa[x] then continue;
                if bz[x]<>1 then
                begin
                        e:=0;
                        for k:=1 to b[x,0] do
                        begin
                                if b[x,k]=fa[x] then continue;
                                if k<>i then e:=e+min(f[b[x,k],0],f[b[x,k],1]) else e:=e+f[b[x,k],1];
                        end;
                        if e<>0 then
                        f[x,0]:=min(f[x,0],e);
                end;
                if bz[x]<>0 then f[x,1]:=f[x,1]+min(f[v,0],f[v,1]);
        end;
        if bz[x]=0 then f[x,1]:=maxlongint*maxlongint div 100;
        if bz[x]=1 then f[x,0]:=maxlongint*maxlongint div 100;
end;
begin
        assign(input,'defense.in');reset(input);
        assign(output,'defense.out');rewrite(output);
        readln(n,m,sa);
        for i:=1 to n do read(p[i]);
        for i:=1 to n-1 do
        begin
                read(o,l);
                inc(b[o,0]);
                b[o,b[o,0]]:=l;
                inc(b[l,0]);
                b[l,b[l,0]]:=o;
        end;
        while m>0 do
        begin
                m:=m-1;
                read(aa,x,bb,y);
                fillchar(bz,sizeof(bz),255);
                fillchar(f,sizeof(f),100);
                if x=0 then bz[aa]:=0 else bz[aa]:=1;
                if y=0 then bz[bb]:=0 else bz[bb]:=1;
                dg(1);
                ans:=maxlongint div 2*maxlongint;
                if bz[1]<>1 then ans:=min(ans,f[1,0]);
                if bz[1]<>0 then ans:=min(ans,f[1,1]);
                if ans>maxlongint then ans:=-1;
                writeln(ans);
        end;
        close(input);close(output);
end.
