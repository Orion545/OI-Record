const maxn=50010;
var
go,nxt,w : array[1..maxn*2] of longint;
q,head,bz,f,son : array[0..maxn] of longint;
vis : array[1..maxn] of boolean;
n,m,i,j,l,r,mid,u,v,dw,tail,ans : longint;
procedure add(u,v,dw:longint);
begin
        inc(tail);go[tail]:=v;w[tail]:=dw;
        nxt[tail]:=head[u];head[u]:=tail;
end;
procedure yuchuli;
var
l,r,x,i:longint;
        begin
                l:=0;r:=1;q[1]:=1;bz[1]:=0;
                while l<=r do begin
                inc(l);x:=q[l];
                i:=head[x];
                while i<>0 do begin
                        if bz[go[i]]>bz[x]+1 then begin
                        bz[go[i]]:=bz[x]+1;inc(r);q[r]:=go[i];
                        end;
                        i:=nxt[i];
                end;
                end;
        end;
function check(mid:longint):boolean;
var
ans,i,j,x,mi1,mi2,min,k : longint;
        begin
                fillchar(f,sizeof(f),0);ans:=0;
                for k := n downto 1 do begin
                        x:=q[k];
                        //writeln(x,' ',ans);
                        i:=head[x];
                        son[0]:=0;
                        while i<>0 do begin
                        if bz[go[i]]>bz[x] then begin
                        inc(son[0]);son[son[0]]:=go[i];
                        vis[go[i]]:=false;
                        f[go[i]]:=f[go[i]]+w[i]; //write(go[i],' ');
                        if f[go[i]]>=mid then begin
                                vis[go[i]]:=true;inc(ans);
                                if ans=m then exit(true);
                        end;
                        end;
                        i:=nxt[i];
                        end;      // write('son ');

                        repeat
                        min:=maxlongint;mi1:=0;mi2:=0;
                        for i := 1 to son[0]-1 do
                        if not vis[son[i]] then begin
                                for j := i+1 to son[0] do
                                if not vis[son[j]] then begin
                                if (f[son[i]]+f[son[j]]>=mid)and
                                (f[son[i]]+f[son[j]]<min) then begin
                                min:=f[son[i]]+f[son[j]];mi1:=son[i];mi2:=son[j];
                                end;
                                end;
                        end;
                        if min<maxlongint then begin
                                inc(ans);vis[mi1]:=true;vis[mi2]:=true;
                                if ans=m then exit(true);
                        end;
                        //writeln('++: ',mi1,' ',mi2);
                        until min=maxlongint;

                        f[x]:=0;
                        i:=head[x];
                        while i<>0 do begin
                        if (not vis[go[i]])and(f[go[i]]>f[x]) then
                        f[x]:=f[go[i]];
                        i:=nxt[i];
                        end;
                        //writeln(f[x]);
                        if f[x]>=mid then begin
                                f[x]:=0;inc(ans);
                                if ans>=m then exit(true);
                        end;
                end;
                if ans>=m then exit(true);
                exit(false);
        end;
begin
assign(input,'track.in');reset(input);
assign(output,'track.out');rewrite(output);
fillchar(bz,sizeof(bz),$7f);
readln(n,m);
l:=0;r:=0;
for i := 1 to n-1 do begin
        readln(u,v,dw);
        r:=r+dw;
        add(u,v,dw);add(v,u,dw);
end;
yuchuli;
//for i := 1 to n do write(q[i],' ');writeln('q');
ans:=0;
while l<=r do begin
        mid:=(l+r)shr 1;
        if check(mid) then begin
                l:=mid+1;ans:=mid;
        end else r:=mid-1;
end;
write(ans);
close(input);close(output);
end.
