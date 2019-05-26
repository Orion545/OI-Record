var
        can:boolean;
        s,t:string;
        n,m,k,q,i,j,x,ans,sum:longint;
        b:array[1..10] of longint;
        a:array[1..10,0..1] of longint;
        c:array[1..10,0..3] of longint;
        bz:array[1..10] of longint;
function min(a,b:longint):longint;
begin
        if a<b then exit(a) else exit(b);
end;
begin
        assign(input,'defense.in');
        reset(input);
        assign(output,'defense.out');
        rewrite(output);
        readln(s);
        k:=pos(' ',s);
        t:=copy(s,1,k-1);
        val(t,n);
        delete(s,1,k);
        k:=pos(' ',s);
        t:=copy(s,1,k-1);
        val(t,m);
        for i:=1 to n do read(b[i]);
        for i:=1 to n-1 do readln(a[i,0],a[i,1]);
        for i:=1 to m do readln(c[i,0],c[i,1],c[i,2],c[i,3]);
        for q:=1 to m do
        begin
                ans:=maxlongint;
                for i:=1 to (1 shl n)-1 do
                begin
                        fillchar(bz,sizeof(bz),0);
                        x:=i; j:=1; sum:=0;
                        while x<>0 do
                        begin
                                if x mod 2=1 then
                                begin
                                        bz[j]:=1;
                                        sum:=sum+b[j];
                                end;
                                inc(j);
                                x:=x div 2;
                        end;
                        can:=true;
                        for j:=1 to n-1 do
                                if (bz[a[j,0]]=0)and(bz[a[j,1]]=0) then
                                begin
                                        can:=false;
                                        break;
                                end;
                        if (can)and(bz[c[q,0]]=c[q,1])and(bz[c[q,2]]=c[q,3]) then ans:=min(ans,sum);
                end;
                if ans=maxlongint then writeln(-1) else writeln(ans);
        end;
        close(input);
        close(output);
end.