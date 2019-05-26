var
        mid,r,i,j,k,l,n,m,ans:longint;
        f,deep:array[0..100000] of longint;
        total:array[0..100000] of longint;
        a:array[0..100000,1..3] of longint;
        star:array[0..200000,1..3] of longint;
        went,last:array[0..200000] of longint;
        bj:boolean;
function max(a,b:longint):longint;
begin
        if (a>b) then
                exit(a);
        exit(b);
end;
function min(a,b:longint):longint;
begin
        if (a<b) then
                exit(a);
        exit(b);
end;
procedure kp(l,r:longint);
var
        i,j,mid:longint;
begin
        i:=l;
        j:=r;
        mid:=a[(l+r) div 2,3];
        repeat
                while (a[i,3]>mid) do inc(i);
                while (a[j,3]<mid) do dec(j);
                if (i<=j) then
                begin
                        a[0]:=a[i];
                        a[i]:=a[j];
                        a[j]:=a[0];
                        inc(i);
                        dec(j);
                end;
        until(i>j);
        if (i<r) then kp(i,r);
        if (l<j) then kp(l,j);
end;
procedure make(x,a,b,c:longint);
begin
        star[x,1]:=a;
        star[x,2]:=b;
        star[x,3]:=c;
        went[x]:=last[a];
        last[a]:=x;
end;
procedure dg(x,t:longint);
var
        i:longint;
begin
        deep[x]:=t;
        i:=last[x];
        while (i>0) do
        begin
                if (deep[star[i,2]]=0) then
                begin
                        dg(star[i,2],t+1);
                        ans:=max(ans,f[x]+f[star[i,2]]+star[i,3]);
                        f[x]:=max(f[x],star[i,3]+f[star[i,2]]);
                end;
                i:=went[i];
        end;
end;
procedure dg2(x,t:longint);
var
        i:longint;
begin
        deep[x]:=t;
        i:=last[x];
        while (i>0) do
        begin
                if (deep[star[i,2]]=0) then
                begin
                        f[star[i,2]]:=f[x]+star[i,3];
                        dg(star[i,2],t+1);
                end;
                i:=went[i];
        end;
end;
function pd(x,t,s:longint):boolean;
begin
        if (t=m) then
                exit(true);
        if (t=n) then
                exit(false);
        if (f[x]-f[s]>=mid) then
                exit(pd(x+1,t+1,x));
        exit(pd(x+1,t,s));
end;
begin
        assign(input,'track.in');reset(input);
        assign(output,'track.out');rewrite(output);
        fillchar(f,sizeof(f),0);
        readln(n,m);
        bj:=true;
        for i:=1 to n-1 do
        begin
                readln(a[i,1],a[i,2],a[i,3]);
                inc(total[a[i,1]]);
                inc(total[a[i,2]]);
                if (a[i,1]+1<>a[i,2]) and (a[i,2]+1<>a[i,1]) then
                        bj:=false;
        end;
        if (total[1]=n-1) then
        begin
                kp(1,n-1);
                for i:=1 to m do
                        f[i]:=a[i,3];
                r:=m;
                for i:=m+1 to min(n,m+m) do
                        inc(f[2*m-i+1],a[i,3]);
                ans:=maxlongint;
                for i:=1 to m do
                        ans:=min(ans,f[i]);
                writeln(ans);
                close(input);
                close(output);
                halt;
        end;
        if (m=1) then
        begin
                for i:=1 to n-1 do
                begin
                        make(i*2,a[i,1],a[i,2],a[i,3]);
                        make(i*2+1,a[i,2],a[i,1],star[i,3]);
                end;
                ans:=0;
                dg(1,1);
                writeln(ans);
                close(input);
                close(output);
                halt;
        end;
        if (bj) then
        begin
                dg2(1,1);
                l:=0;
                r:=f[n];
                f[0]:=0;
                while (l<=r) do
                begin
                        mid:=(l+r) div 2;
                        if (pd(1,0,0)) then
                        begin
                                l:=mid+1;
                                ans:=mid;
                        end
                        else
                                r:=mid-1;
                end;
                writeln(ans);
                close(input);
                close(output);
        end;
        close(input);
        close(output);
end.
