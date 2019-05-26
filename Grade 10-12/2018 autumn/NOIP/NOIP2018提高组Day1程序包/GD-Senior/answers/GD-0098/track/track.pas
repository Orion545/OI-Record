var
        data1,data2:boolean;
        n,m,i,l,r,mid,x,y,z,tot,ans,answ,ppp:longint;
        c,dis:array[0..50000] of longint;
        tov,cos,next,last:array[0..100000] of longint;
procedure insert(x,y,z:longint);
begin
        inc(tot);
        tov[tot]:=y;
        cos[tot]:=z;
        next[tot]:=last[x];
        last[x]:=tot;
end;

procedure dg(x,q:longint);
var
        k:longint;
begin
        k:=last[x];

        while k<>0 do
        begin
                if tov[k]<>q then
                begin
                        dis[tov[k]]:=dis[x]+cos[k];

                        if dis[tov[k]]>ans then
                        begin
                                ans:=dis[tov[k]]; answ:=tov[k];
                        end;

                        dg(tov[k],x);
                end;

                k:=next[k];
        end;
end;

procedure qsort(l,r:longint);
var
        i,j,t,mid:longint;
begin
        i:=l;
        j:=r;
        mid:=c[(l+r) shr 1];

        while i<j do
        begin
                while c[i]<mid do inc(i);
                while c[j]>mid do dec(j);

                if i<=j then
                begin
                        t:=c[i]; c[i]:=c[j]; c[j]:=t;

                        inc(i); dec(j);
                end;
        end;

        if i<r then qsort(i,r); if l<j then qsort(l,j);
end;

function check(x:longint):boolean;
var
        i,now,now1:longint;
begin
        now1:=0; now:=0;

        for i:=1 to n-1 do
        begin
                inc(now,c[i]);

                if now>=x then
                begin
                        inc(now1); now:=0;
                end;
        end;

        if now1>=m then exit(true) else exit(false);
end;
begin
        assign(input,'track.in');reset(input);
        assign(output,'track.out');rewrite(output);

        readln(n,m);

        data1:=true; data2:=true;

        for i:=1 to n-1 do
        begin
                readln(x,y,z); if x<>1 then data1:=false; c[i]:=z;  if y<>x+1 then data2:=false;

                insert(x,y,z); insert(y,x,z);
        end;

        if m=1 then
        begin
                dg(1,0); fillchar(dis,sizeof(dis),0); dg(answ,0);

                writeln(ans); halt;
        end;

        if data1 then
        begin
                qsort(1,n-1);

                l:=n-m-1; r:=n-m; ans:=maxlongint;

                for i:=r to n-1 do
                begin
                        ppp:=0; if l>0 then ppp:=c[l];

                        if c[i]+ppp<ans then ans:=c[i]+ppp;

                        dec(l);
                end;

                writeln(ans); halt;
        end;

        if data2 then
        begin
                l:=1; r:=maxlongint-1;

                while l+1<r do
                begin
                        mid:=(l+r) shr 1;

                        if check(mid) then l:=mid else r:=mid-1;
                end;

                if check(r) then writeln(r) else writeln(l);

                halt;
        end;

        close(input);close(output);
end.
