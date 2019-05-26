const maxn=100000;inf=100000000000;
var
go,nxt : array[1..maxn*2] of longint;
p,head,fa : array[1..maxn] of longint;
f,g : array[1..maxn,0..1] of int64;
i,j,n,m,u,u1,v,v1,tail : longint;
bz : boolean;
ans : int64;
typ : string;
procedure add(u,v:longint);
begin
        inc(tail);go[tail]:=v;
        nxt[tail]:=head[u];head[u]:=tail;
end;
procedure dp1(x:longint);
var i:longint;
        begin
        f[x,0]:=0;f[x,1]:=p[x];
        i:=head[x];
        while i<>0 do begin
                if go[i]<>fa[x] then begin
                        fa[go[i]]:=x;dp1(go[i]);
                        f[x,0]:=f[x,0]+f[go[i],1];
                        if f[go[i],1]<f[go[i],0] then
                        f[x,1]:=f[x,1]+f[go[i],1]
                        else f[x,1]:=f[x,1]+f[go[i],0];
                end;
                i:=nxt[i];
        end;
        end;
procedure dp2(x:longint);
var i:longint;
        begin
        g[x,0]:=0;g[x,1]:=p[x];
        i:=head[x];
        while i<>0 do begin
                if go[i]<>fa[x] then begin
                        dp2(go[i]);
                        g[x,0]:=g[x,0]+g[go[i],1];
                        if g[go[i],1]<g[go[i],0] then
                        g[x,1]:=g[x,1]+g[go[i],1]
                        else g[x,1]:=g[x,1]+g[go[i],0];
                        if g[x,0]>inf then g[x,0]:=inf;
                        if g[x,1]>inf then g[x,1]:=inf;
                end;
                i:=nxt[i];
        end;
        if x=u then g[x,1-u1]:=inf
        else if x=v then g[x,1-v1]:=inf;
        end;
begin
assign(input,'defense.in');reset(input);
assign(output,'defense.out');rewrite(output);
        read(n,m); readln(typ);
        for i := 1 to n do read(p[i]);
        for i := 1 to n-1 do begin
        readln(u,v);
        add(u,v);add(v,u);
        end;
        dp1(1);
        //for i := 1 to n do writeln(f[i,0],' ',f[i,1]); writeln('f');

        for i := 1 to m do begin
                readln(u,u1,v,v1);
                bz:=false;
                ans:=inf;
                if (u1+v1=0) then
                begin
                if (fa[u]<>v)and(fa[v]<>u) then bz:=true else ans:=-1;
                end else if u1+v1=2 then begin
                        if (f[u,0]>=f[u,1])and(f[v,0]>=f[v,1]) then
                        begin
                                //writeln('can');
                                ans:=f[1,0];
                                if f[1,1]<f[1,0] then ans:=f[1,1];
                        end else bz:=true;
                end else bz:=true;

                if bz then begin
                fillchar(g,sizeof(g),$7f);
                dp2(1);
                ans:=g[1,0];
                if g[1,1]<g[1,0] then ans:=g[1,1];
                //for j := 1 to n do writeln(g[j,0],' ',g[j,1]);
                //writeln('g');
                end;

                if ans>=inf then ans:=-1;
                writeln(ans);
        end;
close(input);close(output);
end.
