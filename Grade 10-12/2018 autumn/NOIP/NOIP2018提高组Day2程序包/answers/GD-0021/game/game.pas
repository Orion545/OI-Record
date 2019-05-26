var
        mo:int64=1000000007;
        ans,op:int64;
        i,j,k,l,n,m,my:longint;
        c:array[1..1000,1..8000] of int64;
        mi:array[1..1000010] of int64;
        ans1,ans2:array[1..1000010] of int64;
        bh:array[1..1000010,1..2] of longint;
        map,p:array[1..1000,1..1000] of longint;
        fx:array[0..1000,1..10000] of longint;
        kk:array[1..10000] of longint;
        lx:array[0..10000,1..2] of longint;
procedure dfs(x:longint);
var
        i,j,k,l:longint;
begin
        if x>n*m then
        begin
                k:=0;
                fillchar(kk,sizeof(kk),0);
                for i:=1 to c[n*2-1,m] do
                begin
                        for j:=1 to n+m-1 do
                        begin
                                kk[i]:=kk[i]*10+map[bh[fx[i,j],1],bh[fx[i,j],2]];
                        end;
                end;
                for i:=1 to c[n*2-1,m] do
                begin
                        for j:=i+1 to c[n*2-1,m] do
                        begin
                                if kk[i]<kk[j] then k:=1;
                        end;
                end;
                if k=0 then
                begin
                        inc(ans);
                end;
        end
        else
        begin
                dfs(x+1);
                map[bh[x,1],bh[x,2]]:=1;
                dfs(x+1);
                map[bh[x,1],bh[x,2]]:=0;
        end;
end;
procedure dfs1(x,y:longint);
var
        i,j,k,l:longint;
begin
        if (x=n) and (y=m) then
        begin
                inc(my);
                fx[my,1]:=1;
                for i:=2 to lx[0,1]+1 do
                begin
                        fx[my,i]:=p[lx[i-1,1],lx[i-1,2]];
                end;
        end
        else
        begin
                if x<n then
                begin
                        inc(lx[0,1]);
                        lx[lx[0,1],1]:=x+1;
                        lx[lx[0,1],2]:=y;
                        dfs1(x+1,y);
                        dec(lx[0,1]);
                end;
                if y<m then
                begin
                        inc(lx[0,1]);
                        lx[lx[0,1],1]:=x;
                        lx[lx[0,1],2]:=y+1;
                        dfs1(x,y+1);
                        dec(lx[0,1]);
                end;
        end;
end;
begin
        assign(input,'game.in');reset(input);
        assign(output,'game.out');rewrite(output);
        readln(n,m);
        c[1,1]:=1;
        c[2,1]:=1;
        c[2,2]:=1;
        for i:=3 to 100 do
        begin
                if i>100 then j:=100
                else j:=i;
                c[i,1]:=1;
                c[i,j]:=1;
                for k:=2 to j-1 do
                begin
                        c[i,k]:=(c[i-1,k-1]+c[i-1,k]) mod mo;
                end;
        end;
        k:=0;
        if n=2 then
        begin
                ans:=1;
                for i:=1 to m*2 do
                begin
                        ans:=(ans*2) mod mo;
                end;
                writeln(ans);
        end
        else
        if (n=3) and (m>5) then
        begin
                ans:=1;
                op:=15;
                for j:=6 to m do
                begin
                        op:=(op+3) mod mo;
                end;
                for i:=1 to op do
                begin
                        ans:=(ans*2) mod mo;
                end;
                writeln(ans);
        end
        else
        begin
                k:=0;
                my:=0;
                for i:=1 to n do
                begin
                        for j:=1 to m do
                        begin
                                inc(k);
                                bh[k,1]:=i;
                                bh[k,2]:=j;
                                p[i,j]:=k;
                        end;
                end;
                ans:=0;
                dfs1(1,1);
                dfs(1);
                writeln(ans);
        end;
        close(input);close(output);
end.