var i,j,k,l,m,n,q,w,u,v:longint;
    a,b:array[0..5050,0..5050] of longint;
    c,ans:array[0..5050] of longint;
    vis:array[0..5050] of boolean;
procedure dfs(p:longint);
var i:longint;
begin
    vis[p]:=true;
    inc(c[0]); c[c[0]]:=p;
    for i:=1 to a[p,0] do if not vis[a[p,i]] then dfs(a[p,i]);
end;
function cp():boolean;
var i:longint;
begin
    for i:=1 to n do begin
       if c[i]<ans[i] then exit(true);
       if c[i]>ans[i] then exit(false);
    end;
    exit(false);
end;
procedure sort(l,r,p: longint);
      var i,j,x,y: longint;
      begin
         i:=l; j:=r; x:=a[p,(l+r) div 2];
         repeat
           while a[p,i]<x do inc(i);
           while x<a[p,j] do dec(j);
           if not(i>j) then
             begin
                y:=a[p,i]; a[p,i]:=a[p,j]; a[p,j]:=y;
                inc(i); j:=j-1;
             end;
         until i>j;
         if l<j then sort(l,j,p);
         if i<r then sort(i,r,p);
      end;
begin
assign(input,'travel.in'); reset(input);
assign(output,'travel.out');rewrite(output);
    readln(n,m);
    for i:=1 to m do begin
        readln(u,v);
        inc(a[u,0]); a[u,a[u,0]]:=v;
        inc(a[v,0]); a[v,a[v,0]]:=u;
    end;
    for i:=1 to n do sort(1,a[i,0],i);
    if m=n-1 then begin
       dfs(1);
       for i:=1 to n do write(c[i],' ');
    end
    else begin
        fillchar(ans,sizeof(ans),$7f);
        for i:=1 to n do
          for j:=1 to a[i,0] do if b[i,j]=0 then begin
              fillchar(vis,sizeof(vis),false);
              fillchar(c,sizeof(c),0);
              vis[0]:=true;
              q:=a[i,j];
              for k:=1 to a[q,0] do if a[q,k]=i then begin
                 a[q,k]:=0; b[q,k]:=1; break;
              end;
              a[i,j]:=0; b[i,j]:=1;
              dfs(1);
              a[i,j]:=q;
              for k:=1 to a[q,0] do if a[q,k]=0 then begin
                 a[q,k]:=i;
                 break;
              end;
              if (c[0]=n)and(cp()) then for k:=1 to n do ans[k]:=c[k];
          end;
        for i:=1 to n do write(ans[i],' ');
    end;
    close(input); close(output);
end.

