var
        min:boolean;
        n,m,i,x,y,tot,s,k1,k2:longint;
        a,next:array[1..10000] of longint;
        bz:array[1..5000] of boolean;
        f,b,p,last:array[0..5000] of longint;
        son:array[1..5000,0..5000] of longint;
procedure insert(x,y:longint);
begin
        inc(tot);
        a[tot]:=y;
        next[tot]:=last[x];
        last[x]:=tot;
end;
procedure find(k:longint);
var
        x:longint;
begin
        x:=last[k];
        while x<>-1 do
        begin
                if a[x]<>f[k] then
                begin
                        if f[a[x]]=0 then
                        begin
                                f[a[x]]:=k;
                                find(a[x]);
                        end
                        else
                        begin
                                s:=a[x];
                                k1:=f[a[x]];
                                k2:=k;
                        end;
                end;
                x:=next[x];
        end;
end;
procedure qsort(i,j,k:longint);
var
        i1,j1,mid,t:longint;
begin
        i1:=i;
        j1:=j;
        mid:=son[k,(i+j) div 2];
        repeat
                while son[k,i]<mid do inc(i);
                while son[k,j]>mid do dec(j);
                if i<=j then
                begin
                        t:=son[k,i];
                        son[k,i]:=son[k,j];
                        son[k,j]:=t;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if i1<j then qsort(i1,j,k);
        if i<j1 then qsort(i,j1,k);
end;
procedure dg(k:longint);
var
        i,x:longint;
begin
        son[k,0]:=0;
        x:=last[k];
        while x<>-1 do
        begin
                if bz[a[x]] then
                begin
                        if (a[x]=s)and(k=k1) then continue;
                        bz[a[x]]:=false;
                        inc(son[k,0]);
                        son[k,son[k,0]]:=a[x];
                end;
                x:=next[x];
        end;
        if son[k,0]>1 then qsort(1,son[k,0],k);
        for i:=1 to son[k,0] do
        begin
                inc(p[0]);
                p[p[0]]:=son[k,i];
                dg(son[k,i]);
        end;
end;
begin
        assign(input,'travel2.in');
        reset(input);
        assign(output,'travel.out');
        rewrite(output);
        readln(n,m);
        fillchar(last,sizeof(last),255);
        for i:=1 to m do
        begin
                readln(x,y);
                insert(x,y);
                insert(y,x);
        end;
        if m=n-1 then
        begin
                fillchar(bz,sizeof(bz),true);
                bz[1]:=false;
                dg(1);
                write(1,' ');
                for i:=1 to n-1 do write(p[i],' ');
        end
        else
        begin
                find(1);
                fillchar(bz,sizeof(bz),true);
                bz[1]:=false;
                p[0]:=0;
                dg(1);
                b:=p;
                fillchar(bz,sizeof(bz),true);
                bz[1]:=false;
                k1:=k2;
                p[0]:=0;
                dg(1);
                min:=true;
                for i:=1 to n do
                begin
                        if b[i]>p[i] then
                        begin
                                min:=false;
                                break;
                        end;
                end;
                write(1,' ');
                if min then for i:=1 to n do write(b[i],' ') else for i:=1 to n do write(p[i],' ');
        end;
        close(input);
        close(output);
end.
