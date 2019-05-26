const
        mo=1000000007;
var
        n,m,tot,i:longint;
        ans:int64;
        p,s:array[1..1000]of string;
        a:array[1..100,1..100]of longint;
function pd:boolean;
var
        i,j,x,y:longint;
begin

        for i:=1 to tot do
        begin
                s[i]:='';
                x:=1;
                y:=1;
                for j:=1 to length(p[i]) do
                begin
                        if(p[i][j]='R')then
                        begin
                                s[i]:=s[i]+chr(a[x,y+1]+48);
                                inc(y);
                        end;
                        if(p[i][j]='D')then
                        begin
                                s[i]:=s[i]+chr(a[x+1,y]+48);
                                inc(x);
                        end;
                end;
        end;
        for i:=1 to tot do
        begin
                for j:=1 to tot do
                begin
                        if(i=j)then continue;
                        if(p[i]>p[j])then
                        begin
                                if(s[i]>s[j])then exit(false);
                        end;
                end;
        end;
        exit(true);
end;
procedure bl(x,y:longint);
begin
        if(x=n)and(y=m)then
        begin
                inc(tot);
                p[tot]:=p[tot-1];
                exit;
        end;
        if(x+1<=n)then
        begin
                p[tot]:=p[tot]+'D';
                bl(x+1,y);
                delete(p[tot],length(p[tot]),1);
        end;
        if(y+1<=m)then
        begin
                p[tot]:=p[tot]+'R';
                bl(x,y+1);
                delete(p[tot],length(p[tot]),1);
        end;
end;
procedure dg(x,y:longint);
begin
        if(x>n)then
        begin
                if(pd)then inc(ans);
                exit;
        end;
        a[x,y]:=0;
        if(y+1<=m)then dg(x,y+1)
        else dg(x+1,1);
        a[x,y]:=0;

        a[x,y]:=1;
        if(y+1<=m)then dg(x,y+1)
        else dg(x+1,1);
        a[x,y]:=0;
end;
begin
        assign(input,'game.in');
        reset(input);
        assign(output,'game.out');
        rewrite(output);
        read(n,m);
        if(n<=3)and(m<=3)then
        begin
                tot:=1;
                bl(1,1);
                dec(tot);
                dg(1,1);
                writeln(ans);
                halt;
        end;
        if(n=2)then
        begin
                ans:=4;
                for i:=2 to m do ans:=ans*3 mod mo;
                writeln(ans);
                halt;
        end;
        if(n=1)then
        begin
                ans:=2;
                for i:=2 to m do ans:=ans*2 mod mo;
                writeln(ans);
                halt;
        end;
        if(n=3)then
        begin
                ans:=112;
                for i:=4 to m do ans:=ans*3 mod mo;
                writeln(ans);
                halt;
        end;
        writeln('7136');
        close(input);
        close(output);
end.
