Var
    n,m,i,tot,a,b,now:longint;
    able,been:array[1..5050] of boolean;
    ok:array[1..5050,1..5050] of boolean;
    pre:array[1..5050] of longint;
    p:boolean;

Procedure dfs(x:longint);
Var
    i,t:longint;
  Begin
      write(x,' ');
      begin
          for i:=1 to n do if ok[x,i] and not able[i] then
            begin
                able[i]:=true;
                dfs(i);
            end;
      end;
  End;

Procedure Cut(a,b,c:longint);

    Function min(a,b:longint):longint;
      begin
          if a<b then exit(a) else exit(b);
      end;
    Function max(a,b:longint):longint;
      begin
          if a>b then exit(a) else exit(b);
      end;

  Begin
      if (a<c) and (b<c) then
        begin
            ok[min(a,b),c]:=false;
            ok[c,min(a,b)]:=false;
        end;
      if (min(a,b)<c) and (max(a,b)>c) then
        begin
            ok[max(a,b),c]:=false;
            ok[c,max(a,b)]:=false;
        end;
      if (a>c) and (b>c) then
        begin
            ok[max(a,b),c]:=false;
            ok[c,max(a,b)]:=false;
        end;
  End;

Begin
    assign(input,'travel.in'); reset(input);
    assign(output,'travel.out'); rewrite(output);

    read(n,m);
    tot:=0;
    fillchar(able,sizeof(able),0);
    fillchar(been,sizeof(been),0);
    fillchar(pre,sizeof(pre),0);
    fillchar(ok,sizeof(ok),0);

    for i:=1 to m do
      begin
          read(a,b);
          ok[a,b]:=true;
          ok[b,a]:=true;
      end;

    if m=n then
      begin
          able[1]:=true;
          p:=true;
          while p do
            begin
                for i:=1 to n do if able[i] and not been[i] then
                  begin
                      now:=i;
                      been[now]:=true;
                      break;
                  end;
                for i:=1 to n do
                  begin
                      if ok[now,i] and able[i] and not been[i] then
                        begin
                            cut(pre[i],now,i);
                            p:=false;
                            break;
                        end;
                      if ok[now,i] and not able[i] then
                        begin
                            able[i]:=true;
                            pre[i]:=now;
                        end;
                  end;
            end;
      end;

    fillchar(able,sizeof(able),0);
    fillchar(been,sizeof(been),0);
    able[1]:=true;
    dfs(1);

    close(input); close(output);
End.