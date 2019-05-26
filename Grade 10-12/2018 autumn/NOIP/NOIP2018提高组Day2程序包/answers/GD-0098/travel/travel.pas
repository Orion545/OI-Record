var
        n,m,i,k,tot,len:longint;
        bz,dis:array[0..5000] of boolean;
        c,fuck,dep,data:array[0..5000] of longint;
        x,y,tov,next,last,heap:array[0..10000] of longint;
procedure insert(x,y:longint);
begin
        inc(tot);
        tov[tot]:=y;
        next[tot]:=last[x];
        last[x]:=tot;
end;

procedure qsort(l,r:longint);
var
        i,j,t,m1,m2:longint;
begin
        i:=l;
        j:=r;
        m1:=x[(l+r) shr 1];
        m2:=y[(l+r) shr 1];

        while i<j do
        begin
                while (x[i]<m1) or ((x[i]=m1) and (y[i]>m2)) do inc(i);
                while (x[j]>m1) or ((x[j]=m1) and (y[j]<m2)) do dec(j);

                if i<=j then
                begin
                        t:=x[i]; x[i]:=x[j]; x[j]:=t;
                        t:=y[i]; y[i]:=y[j]; y[j]:=t;

                        inc(i); dec(j);
                end;
        end;

        if i<r then qsort(i,r); if l<j then qsort(l,j);
end;

procedure dg(x:longint);
var
        k:longint;
begin
        dis[x]:=false; inc(len); data[len]:=x;

        k:=last[x];

        while k<>0 do
        begin
                if dis[tov[k]] then dg(tov[k]);

                k:=next[k];
        end;
end;

begin
        assign(input,'travel.in');reset(input);
        assign(output,'travel.out');rewrite(output);
        readln(n,m);

        for i:=1 to m do readln(x[i],y[i]);

        for i:=m+1 to 2*m do
        begin
                x[i]:=y[i-m]; y[i]:=x[i-m];
        end;

        qsort(1,2*m);

        for i:=1 to 2*m do insert(x[i],y[i]);

        fillchar(bz,sizeof(bz),true); fillchar(dis,sizeof(dis),true); dep[1]:=1;

        dg(1);

        for i:=1 to n do write(data[i],' '); writeln;

        close(input);close(output);
end.
