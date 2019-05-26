Var
   head,next,x,y,v,c:array[1..100010] of longint;
   n,m,i,tot,a,b,l,r,start,ans,mid,now:longint;
   p:array[1..100010] of boolean;
   ErFenable:boolean;

Procedure dfs(x,now:longint);
var
   i:longint;
Begin
    p[x]:=true;
    i:=head[x];
    while i<>0 do
      begin
          if not p[y[i]] then dfs(y[i],now+v[i]);
          i:=next[i];
      end;
    if now>ans then
      begin
          ans:=now;
          start:=x;
      end;
    p[x]:=false;
End;


Begin
    assign(input,'track.in'); reset(input);
    assign(output,'track.out'); rewrite(output);

    read(n,m);
    fillchar(head,sizeof(head),0);
    tot:=0; ErFenable:=true;
    for i:=1 to n-1 do
      begin
          read(a,b,l);

          if a+1<>b then ErFenable:=false;
          c[a]:=l;

          tot:=tot+1;
          x[tot]:=a; y[tot]:=b; v[tot]:=l;
          next[tot]:=head[a]; head[a]:=tot;

          tot:=tot+1;
          x[tot]:=b; y[tot]:=a; v[tot]:=l;
          next[tot]:=head[b]; head[b]:=tot;
      end;
    if m=1 then
      begin
          start:=1; ans:=0;
          fillchar(p,sizeof(p),false);

          dfs(start,0);

          dfs(start,0);

          writeln(ans);
      end;

    if ErFenable then
      begin
          l:=1; r:=maxlongint div 2;
          while l<r do
            begin
                mid:=(l+r) div 2;
                tot:=0;
                now:=0;
                for i:=1 to n-1 do
                  begin
                      tot:=tot+c[i];
                      if tot>=mid then
                        begin
                            tot:=0;
                            now:=now+1;
                        end;
                  end;
                if now>=m then l:=mid;
                if now<m then r:=mid;
                if l+1=r then
                  begin
                      writeln(l);
                      break;
                  end;
            end;
      end;

    close(input); close(output);
End.
