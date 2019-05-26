type
        edge=record
                x,y,next:longint;
        end;
        litt=array[0..20] of longint;
var
        e:array[0..200020] of edge;
        c,l,d,lf:array[0..100020] of longint;
        sh1:litt;
        f,g:array[0..100020] of int64;
        n,m,i,j,k,a,x,b,y:longint;
        s,p:string;
        ans:int64;
procedure add(x,y,i:longint);
begin
        e[i].x:=x;
        e[i].y:=y;
        e[i].next:=l[x];
        l[x]:=i;
end;
function min(a,b:int64):int64;
begin
        if a<b then exit(a) else exit(b);
end;
procedure dfs(x,fr:longint);
var
        i,y,k:longint;
        mn:int64;
begin
        d[x]:=fr;
        i:=l[x];
        mn:=g[100001];
        while i<>0 do
        begin
                if d[e[i].y]=0 then
                begin
                        lf[x]:=1;
                        dfs(e[i].y,x);
                        mn:=min(mn,f[e[i].y]);
                end;
                i:=e[i].next;
        end;
        if lf[x]=0 then
        begin
                f[x]:=c[x];
                g[x]:=0;
        end else
        begin

        end;
end;
procedure try(xx,fl:longint;sh:litt);
var
        i,k:longint;
        sum:int64;
begin
        if xx>n then
        begin
                for i := 1 to (n-1)*2 do
                        if (sh[e[i].x]=0)and(sh[e[i].y]=0) then exit;
                sum:=0;
                for i := 1 to n do
                        if sh[i]=1 then sum:=sum+c[i];
                if ans>sum then ans:=sum;
                exit;
        end;
        sh[xx]:=fl;
        if (xx=x)and(a=1) then sh[xx]:=1;
        if (xx=x)and(a=0) then sh[xx]:=0;
        if (xx=y)and(b=1) then sh[xx]:=1;
        if (xx=y)and(b=0) then sh[xx]:=0;
        try(xx+1,1,sh);
        try(xx+1,0,sh);
end;
begin
        assign(input,'defense.in');reset(input);
        assign(output,'defense.out');rewrite(output);
        readln(s);
        i:=pos(' ',s);
        p:=copy(s,1,i-1);
        delete(s,1,i);
        val(p,n);
        i:=pos(' ',s);
        p:=copy(s,1,i-1);
        delete(s,1,i);
        val(p,m);
        for i := 1 to n do
                read(c[i]);
        for i := 1 to n-1 do
        begin
                read(x,y);
                add(x,y,i*2-1);
                add(y,x,i*2);
        end;
        if s[1]='A' then
        begin
                fillchar(f,sizeof(f),$7f);f[0]:=0;
                fillchar(g,sizeof(g),$7f);g[0]:=0;
                while m>0 do
                begin
                        read(x,a,y,b);
                        if (abs(x-y)=1)and(a=0)and(b=0) then writeln('-1')
                        else
                        begin
                                for i := 1 to n do
                                begin
                                        f[i]:=min(f[i-1]+c[i],g[i-1]+c[i]);
                                        g[i]:=f[i-1];
                                        if (i=x)and(a=1) then g[i]:=g[n+1];
                                        if (i=x)and(a=0) then f[i]:=f[n+1];
                                        if (i=y)and(b=1) then g[i]:=g[n+1];
                                        if (i=y)and(b=0) then f[i]:=f[n+1];
                                end;
                                writeln(min(f[n],g[n]));
                        end;
                        dec(m);
                end;
        end else if n<30 then
        begin
                fillchar(f,sizeof(f),$7f);f[0]:=0;
                fillchar(g,sizeof(g),$7f);g[0]:=0;
                fillchar(lf,sizeof(lf),0);
                while m>0 do
                begin
                        read(x,a,y,b);
                                j:=0;
                                i:=l[x];
                                repeat
                                        if e[i].y=y then j:=1;
                                        i:=e[i].next;
                                until (i=0)or(j=1);
                        if (j=1)and(a=0)and(b=0) then
                        begin
                                if j=1 then writeln('-1');
                        end else
                        begin
                                ans:=g[100001];
                                fillchar(sh1,sizeof(sh1),0);
                                try(1,0,sh1);
                                try(1,1,sh1);
                                writeln(ans);
                        end;
                        dec(m);
                end;
        end else
        begin
                fillchar(f,sizeof(f),$7f);f[0]:=0;
                fillchar(g,sizeof(g),$7f);g[0]:=0;
                fillchar(lf,sizeof(lf),0);
                while m>0 do
                begin
                        read(x,a,y,b);
                                j:=0;
                                i:=l[x];
                                repeat
                                        if e[i].y=y then j:=1;
                                        i:=e[i].next;
                                until (i=0)or(j=1);
                        if (j=1)and(a=0)and(b=0) then
                        begin
                                if j=1 then writeln('-1');
                        end else
                        begin
                                dfs(1,1);
                        end;
                        dec(m);
                end;
        end;
        close(input);close(output);
end.

