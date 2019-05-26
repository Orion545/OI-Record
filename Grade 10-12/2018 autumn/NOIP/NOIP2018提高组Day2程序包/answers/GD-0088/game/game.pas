var
        n,m,i,j,k,l,num,bz,ans:longint;
        a,bzz:array[0..100,0..100] of longint;
        s,s1:array[0..1000000] of ansistring;
        f:array[0..8,0..100000] of longint;
        fx:array[1..4,1..2] of longint=((1,0),(0,1),(0,-1),(-1,0));
        st:ansistring;
procedure dg(x,y:longint;t:ansistring);
begin
        if (x=n)and(y=m) then
        begin
                inc(num);
                s[num]:=t;
        end
        else
        begin
                if x+1<=n then dg(x+1,y,t+'D');
                if y+1<=m then dg(x,y+1,t+'R');
        end;
end;
procedure hhl(x,y:longint);
var
        i,j,k:longint;
begin
        i:=1;
        j:=1;
        st:=st+chr(a[i,j]+48);
        for k:=1 to length(s[i]) do
        begin
                if s[i][k]='D' then inc(i) else inc(j);
                st:=st+chr(a[i,j]+48);
        end;
end;
procedure js(x,y:longint);
var
        i,j,k,l,bz,xx,yy:longint;
begin
        if (x=n)and(y=m) then
        begin
                st:='';
                for i:=1 to num do
                begin
                        st:='';
                        hhl(1,1);
                        s1[i]:=st;
                end;
                bz:=1;
                for i:=1 to num do
                begin
                        writeln(s[i],' ',s1[i]);
                end;
                writeln;
                for i:=1 to num-1 do
                begin
                        for j:=i+1 to num do
                        if (s[i]<=s[j])or(s1[i]>s1[j]) then
                        begin
                                bz:=0;
                                break;
                        end;
                end;
                if bz=1 then inc(ans);
        end
        else
        begin
                for i:=1 to 4 do
                begin
                        xx:=x+fx[i,1];
                        yy:=y+fx[i,2];
                        if (xx<=n)and(yy<=m)and(xx>0)and(yy>0)and(bzz[xx,yy]=0) then
                        begin
                                bzz[xx,yy]:=1;
                                a[xx,yy]:=1;
                                js(xx,yy);
                                a[xx,yy]:=0;
                                js(xx,yy);
                                bzz[xx,yy]:=0;
                        end;
                end;
        end;
end;
begin
        assign(input,'game.in');reset(input);
        assign(output,'game.out');rewrite(output);
        readln(n,m);
        f[1,1]:=2;f[2,1]:=4;f[3,1]:=8;
        f[1,2]:=4;f[2,2]:=12;f[3,2]:=36;
        f[1,3]:=8;f[2,3]:=36;f[3,3]:=112;
        {for i:=4 to n do
        begin
                for j:=4 to m do
                        f[i,j]:=2*(f[i-1,j]+f[i,j-1]-f[i-1,j-1]);
        end;    }
        writeln(f[n,m]);
        close(input);close(output);

end.
