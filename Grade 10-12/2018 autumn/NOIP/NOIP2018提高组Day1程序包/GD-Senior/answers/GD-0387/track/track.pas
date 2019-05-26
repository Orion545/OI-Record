program track;
var
        n,m,i,j,x,y,c,max:longint;
        a,b:array[1..20000,1..20000] of integer;
        k:array[1..50000] of integer;
        d:array[1..50000] of integer;

procedure kp(l,r:integer);
var
        mid,i,j,t:integer;
begin
        if l>=r then exit;
        i:=l;j:=r;mid:=d[(l+r) div 2];
        repeat
                while d[i]<mid do inc(i);
                while d[j]>mid do dec(j);
                if i<=j then
                        begin
                                t:=d[i];d[i]:=d[j];d[j]:=t;
                                inc(i);dec(j);
                        end;
        until i>j;
        kp(l,j);
        kp(i,r);
end;

begin
        assign(input,'track.in');reset(input);
        assign(output,'track.out');rewrite(output);
        read(n,m);max:=0;c:=1;
        fillchar(k,sizeof(k),0);
        for i:=1 to n-1 do
        begin
                read(x,y,d[i]);
                inc(k[x]);inc(k[y]);
                if (x<=20000) and (y<=20000) then begin
                        a[x,k[x]]:=y;
                        a[y,k[y]]:=x;
                        b[x,y]:=d[i];
                end;
        end;
        kp(1,n-1);
        if k[1]=n-1 then
                write(d[n-m])
        else write(d[n-1]+d[n-2]);
        close(input);close(output);
end.