var i,j,k,l,m,n,q,w,tot,mx,nw,u,v:longint;
    dep,a,ne,st,wt:array[0..100000] of longint;
    vis:array[1..100000] of boolean;
procedure add(p,o,y:longint);
begin
    inc(tot); a[tot]:=o; ne[tot]:=st[p]; st[p]:=tot; wt[tot]:=y;
end;
procedure dfs(p,dp:longint);
var i,j:longint;
begin
   dep[p]:=dp; vis[p]:=true;
   j:=st[p];
   while ne[j]<>-1 do begin
       if not vis[a[j]] then dfs(a[j],dp+wt[j]);
        j:=ne[j];
   end;
end;
begin
assign(input,'track.in');reset(input);
assign(output,'track.out');rewrite(output);
   readln(n,m);
   for i:=0 to n do ne[i]:=-1;
   for i:=1 to n-1 do begin
       readln(u,v,w);
       add(u,v,w); add(v,u,w);
   end;
   dfs(1,0);
   fillchar(vis,sizeof(vis),false);
   for i:=1 to n do if dep[i]>mx then begin
      mx:=dep[i]; nw:=i;
   end;
   fillchar(dep,sizeof(dep),0);
   dfs(nw,0);
   mx:=0;
   for i:=1 to n do if dep[i]>mx then mx:=dep[i];
   writeln(mx);
   close(input); close(output);
end.
