const mo:int64=1000000007;
var n2:array[0..1000]of longint;
    ans:int64;
    n,m,i,k,u,use,j:longint;

procedure dfs(no,l,la,p:longint);
var  i1,j1,i,j:longint;
     tt:int64;
begin
    if p=1 then begin
        tt:=1;
        for i:=no to m do tt:=(tt*n2[n])mod mo;
        ans:=(ans+tt)mod mo;
        exit;
    end;
    if no=m+1 then begin
        if p=1 then inc(ans);
        exit;
    end;
    for i:=0 to n2[n]-1 do begin
        i1:=i;j1:=l;
        for j:=1 to n do begin
            if (i1 mod 2)<(j1 mod 2) then begin
                dfs(no+1,i,j,1);break;
            end else if (i1 mod 2)=(j1 mod 2) then dfs(no+1,i,j,0)
             else break;
            i1:=i1 div 2;j1:=j1 div 2;
        end;
    end;
end;

begin
assign(input,'game.in');reset(input);
assign(output,'game.out');rewrite(output);
    readln(n,m);n2[0]:=1;
    for i:=1 to n do n2[i]:=(n2[i-1]*2)mod mo;
    for i:=0 to n2[n]-1 do
    for j:=1 to n do dfs(2,i,j,0);
    writeln(ans);
close(input);close(output);
end.
