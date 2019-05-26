var
        i,j,k,l,r,n,m,mid,pd1,pd2,pd3,tot:longint;
        x,y,z,jl:array[1..100000] of longint;
        f:array[1..50000,1..2] of longint;
        tov,next,last,val:array[1..200000] of longint;
procedure insert(x,y,z:longint);
begin
        inc(tot);
        tov[tot]:=y;
        val[tot]:=z;
        next[tot]:=last[x];
        last[x]:=tot;
end;
function max(x,y:longint):longint;
begin
        if x>y then exit(x);exit(y);
end;
procedure dp1(v,fa:longint);
var
        i,j,k,l,st,rd:longint;
begin
        st:=0;
        rd:=0;
        i:=last[v];
        while i>0 do
        begin
                if tov[i]<>fa then
                begin
                        dp1(tov[i],v);
                        if f[tov[i],1]+val[i]>st then
                        begin
                                rd:=st;
                                st:=f[tov[i],1]+val[i];
                        end
                        else
                        if (f[tov[i],1]+val[i]>rd) and (f[tov[i],1]+val[i]<=st) then
                        begin
                                rd:=f[tov[i],1]+val[i];
                        end;
                end;
                i:=next[i];
        end;
        f[v,1]:=st;f[v,2]:=rd;
end;
procedure qsortz(l,r:longint);
var
        i,j,k,mid:longint;
begin
        i:=l;j:=r;
        mid:=z[(l+r) div 2];
        repeat
                while z[i]<mid do inc(i);
                while z[j]>mid do dec(j);
                if i<=j then
                begin
                        k:=z[i];
                        z[i]:=z[j];
                        z[j]:=k;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if i<r then qsortz(i,r);
        if l<j then qsortz(l,j);
end;
function pd(x:longint):boolean;
var
        i,j,k,l:longint;
begin
        j:=0;
        k:=0;
        for i:=1 to n-1 do
        begin
                k:=k+z[i];
                if k>=x then
                begin
                        k:=0;
                        inc(j);
                end;
        end;
        if j>=m then exit(true);
        exit(false);
end;
begin
        assign(input,'track.in');reset(input);
        assign(output,'track.out');rewrite(output);
        readln(n,m);
        for i:=1 to n-1 do
        begin
                readln(x[i],y[i],z[i]);
                insert(x[i],y[i],z[i]);
                insert(y[i],x[i],z[i]);
                pd2:=max(pd2,x[i]);
                if y[i]<>x[i]+1 then
                begin
                        pd3:=1;
                end;
        end;
        if m=1 then
        begin
                dp1(1,0);
                writeln(f[1,1]+f[1,2]);
        end
        else
        if pd2=1 then
        begin
                qsortz(1,n-1);
                j:=0;
                for i:=n-1 downto n-m do
                begin
                        inc(j);
                        jl[j]:=z[i];
                end;
                j:=m+1;
                for i:=n-m-1 downto 1 do
                begin
                        dec(j);
                        if j=0 then break;
                        jl[j]:=jl[j]+z[i];
                end;
                pd2:=maxlongint;
                for i:=1 to m do
                begin
                        if pd2>jl[i] then
                        begin
                                pd2:=jl[i];
                        end;
                end;
                writeln(pd2);
        end
        else
        if pd3=0 then
        begin
                l:=0;
                r:=500000000;
                while l<=r do
                begin
                        mid:=(l+r) div 2;
                        if pd(mid) then
                        begin
                                l:=mid+1;
                                pd3:=mid;
                        end
                        else
                        begin
                                r:=mid-1;
                        end;
                end;
                writeln(pd3);
        end;
        close(input);close(output);
end.
