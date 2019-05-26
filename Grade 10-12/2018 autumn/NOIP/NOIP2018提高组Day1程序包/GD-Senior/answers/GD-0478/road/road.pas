var
        a,d,b,f:array[-10..100020] of longint;
        n,i,j,k,s,m:longint;
        sum:int64;
procedure qsort(l,r:longint);
var
        i,j,mid,t:longint;
begin
        i:=l;j:=r;
        mid:=b[(l+r) div 2];
        repeat
                while b[i]<mid do inc(i);
                while b[j]>mid do dec(j);
                if i<=j then
                begin
                        t:=b[i];
                        b[i]:=b[j];
                        b[j]:=t;
                        t:=d[i];
                        d[i]:=d[j];
                        d[j]:=t;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if j>l then qsort(l,j);
        if i<r then qsort(i,r);
end;
begin
        assign(input,'road.in');reset(input);
        assign(output,'road.out');rewrite(output);
        read(n);
        for i := 1 to n do
        begin
                read(a[i]);
                b[i]:=a[i];
                d[i]:=i;
        end;
        qsort(1,n);
        s:=1;sum:=0;i:=1;m:=0;
        fillchar(f,sizeof(f),0);f[0]:=1;f[n+1]:=1;
        while i<=n do
        begin
                j:=i;
                while b[j]=b[i] do inc(j);j:=j-1;
                sum:=sum+s*(b[i]-m);
                m:=b[i];
                for k := i to j do
                begin
                        if (f[d[k]-1]=0)and(f[d[k]+1]=0) then inc(s);
                        f[d[k]]:=1;
                        if (f[d[k]-1]=1)and(f[d[k]+1]=1) then dec(s);
                end;
                i:=j+1;
        end;
        writeln(sum);
        //for i := 1 to n do write(b[i],' ');
        close(input);
        close(output);
end.
