var
        ch1,ch2:char;
        n,m,x,y,x1,y1,x2,y2,i,j,tot:longint;
        a,c:array[0..100000] of longint;
        f:array[0..100000,0..1] of int64;
        tov,next,last:array[0..200000] of longint;
procedure insert(x,y:longint);
begin
        inc(tot);
        tov[tot]:=y;
        next[tot]:=last[x];
        last[x]:=tot;
end;

function min(var x,y:int64):int64;
begin
        if x<y then exit(x) else exit(y);
end;

procedure dg(x,q:longint);
var
        k:longint;
begin
        if c[x]=-1 then
        begin
                f[x,1]:=maxlongint*maxint;
                f[x,0]:=0;
        end;

        if c[x]=1 then
        begin
                f[x,0]:=maxlongint*maxint;
                f[x,1]:=a[x];
        end;

        if c[x]=0 then
        begin
                f[x,0]:=0;
                f[x,1]:=a[x];
        end;

        k:=last[x];

        while k<>0 do
        begin
                if tov[k]<>q then
                begin
                        dg(tov[k],x);

                        f[x,0]:=f[x,0]+f[tov[k],1];
                        f[x,1]:=f[x,1]+min(f[tov[k],1],f[tov[k],0]);
                end;

                k:=next[k];
        end;
end;
begin
        assign(input,'defense.in');reset(input);
        assign(output,'defense.out');rewrite(output);

        read(n,m); read(ch1); readln(ch1,ch2);

        for i:=1 to n do read(a[i]);

        for i:=1 to n-1 do
        begin
                readln(x,y);

                insert(x,y); insert(y,x);
        end;

        while m>0 do
        begin
                readln(x1,x2,y1,y2);

                if x2=0 then c[x1]:=-1 else c[x1]:=1;
                if y2=0 then c[y1]:=-1 else c[y2]:=1;

                dg(1,0);

                c[x1]:=0; c[y1]:=0;

                if min(f[1,0],f[1,1])>maxlongint*maxint then writeln(-1) else writeln(min(f[1,0],f[1,1]));

                dec(m);
        end;

        close(input);close(output);
end.
