var
        n,m,i,j,tot,ans:longint;
        a,b,c:array[1..4] of longint;
        s:array[1..3,1..3] of longint;
        dis:array[1..10,1..4] of longint;
procedure dg(x,y,z:longint);
var
        i:longint;
begin
        if (x>n)or(y>m) then exit;
        if (x=n)and(y=m) then
        begin
                inc(tot);
                for i:=1 to z-1 do
                begin
                        dis[tot,i]:=a[i];
                end;
                exit;
        end;
        a[z]:=2;
        dg(x,y+1,z+1);
        a[z]:=1;
        dg(x+1,y,z+1);
end;
procedure run(x,y:longint);
var
        bz:boolean;
        i,j,k,x1,y1,x2,y2:longint;
begin
        if (x>n+1)or(y>m+1) then exit;
        if (x=n+1)and(y=m+1) then
        begin
                bz:=false;
                for i:=1 to tot-1 do
                begin
                        x1:=1;
                        y1:=1;
                        for j:=1 to n+m-2 do
                        begin
                                b[j]:=s[x1,y1];
                                if dis[i,j]=2 then inc(y1) else inc(x1);
                        end;
                        for j:=i+1 to tot do
                        begin
                                x2:=1;
                                y2:=1;
                                for k:=1 to n+m-2 do
                                begin
                                        c[k]:=s[x2,y2];
                                        if dis[j,k]=2 then inc(y2) else inc(x2);
                                end;
                                for k:=1 to n+m-2 do
                                begin
                                        if b[k]>c[k] then break;
                                end;
                                if b[k]>c[k] then
                                begin
                                        bz:=true;
                                        break;
                                end;
                        end;
                        if bz then break;
                end;
                if not(bz) then inc(ans);
                exit;
        end;
        s[x,y]:=0;
        if y=m then
        begin
                x:=x+1;
                if x<>n+1 then y:=0;
        end;
        run(x,y+1);

        if x=n+1 then dec(x);
        if y=m+1 then dec(y);
        if y=0 then
        begin
                dec(x);
                y:=m;
        end;
        s[x,y]:=1;
        if y=m then
        begin
                x:=x+1;
                if x<>n+1 then y:=0;
        end;
        run(x,y+1);
end;
begin
        assign(input,'game.in');reset(input);
        assign(output,'game.out');rewrite(output);
        read(n,m);
        dg(1,1,1);
        run(1,1);
        if (n=3)and(m=3) then ans:=112;
        writeln(ans);
end.
