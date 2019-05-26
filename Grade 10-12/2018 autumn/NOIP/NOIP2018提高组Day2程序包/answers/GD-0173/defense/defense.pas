var
        n,m,i,j,x,y,pd,pd1,js,ans:longint;
        xx,l,num:char;
        a,tov,next,last,f,bz:array[1..100010] of longint;
function min(x1,y1:longint):longint;
begin
        if x1<y1 then exit(x1)
        else
                exit(y1);
end;
procedure ins(x1,y1:longint);
begin
        inc(js);
        tov[js]:=y1;
        next[js]:=last[x1];
        last[x1]:=js;
end;
procedure suan;
var
        k:longint;
begin
        for k:=1 to n-1 do
        begin
                if (bz[k]=2) and (bz[k+1]=2) then
                begin
                        ans:=-1;
                        exit;
                end;
                f[k]:=maxlongint div 3;
        end;
        f[n]:=maxlongint div 3;
        f[1]:=a[1];
        if bz[1]=1 then f[2]:=a[2]+a[1]
        else
                f[2]:=a[2];
        for k:=3 to n do
        begin
                if (bz[k-1]=0) and (bz[k-2]=0) then
                begin
                        f[k]:=min(f[k-1],f[k-2])+a[k];
                end
                else
                begin
                        if (bz[k-1]=2) or (bz[k-2]=2) then
                        begin
                                if bz[k-1]=2 then f[k]:=f[k-2]+a[k]
                                else
                                        f[k]:=f[k-1]+a[k];
                        end
                        else
                        if (bz[k-1]=1) and (bz[k-2]=1) then f[k]:=f[k-1]+a[k]
                        else
                        begin
                                if bz[k-1]=1 then f[k]:=f[k-1]+a[k]
                                else
                                        f[k]:=f[k-2]+a[k];
                        end;
                end;
        end;
        ans:=min(f[n],f[n-1]);
end;
begin
        assign(input,'defense.in');reset(input);
        assign(output,'defense.out');rewrite(output);
        read(n,m);
        readln(xx,l,num);
        for i:=1 to n do
        begin
                read(a[i]);
                bz[i]:=0;
        end;
        for i:=1 to n-1 do
        begin
                read(x,y);
                ins(x,y);
                ins(y,x);
        end;
        for i:=1 to m do
        begin
                read(x,pd,y,pd1);
                if pd=1 then bz[x]:=1
                else
                        bz[x]:=2;
                if pd1=1 then bz[y]:=1
                else
                        bz[y]:=2;
                if l='A' then
                begin
                        suan;
                        writeln(ans);
                end;
                bz[x]:=0;
                bz[y]:=0;
        end;
        close(input);
        close(output);
end.
