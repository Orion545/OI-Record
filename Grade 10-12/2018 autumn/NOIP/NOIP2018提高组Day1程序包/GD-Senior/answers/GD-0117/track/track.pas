var
        ans:int64;
        n,m,i,x,y,v,tot:longint;
        a:array[1..100000,0..1] of longint;
        next:array[1..100000] of longint;
        last:array[1..50000] of longint;
        f:array[1..50000] of int64;
        bz:array[1..50000] of boolean;
procedure insert(x,y,v:longint);
begin
        inc(tot);
        a[tot,0]:=y;
        a[tot,1]:=v;
        next[tot]:=last[x];
        last[x]:=tot;
end;
function max(a,b:int64):int64;
begin
        if a>b then exit(a) else exit(b);
end;
procedure dg(k:longint);
var
        x:longint;
        m1,m2:longint;
begin
        x:=last[k];
        m1:=0; m2:=0;
        while x<>-1 do
        begin
                if bz[a[x,0]] then
                begin
                        bz[a[x,0]]:=false;
                        dg(a[x,0]);
                        if f[a[x,0]]+a[x,1]>m1 then
                        begin
                                m2:=m1;
                                m1:=f[a[x,0]]+a[x,1];
                        end
                        else if f[a[x,0]]+a[x,1]>m2 then m2:=f[a[x,0]]+a[x,1];
                end;
                x:=next[x];
        end;
        f[k]:=m1;
        ans:=max(ans,max(f[k],m1+m2));
end;
begin
        assign(input,'track.in');
        reset(input);
        assign(output,'track.out');
        rewrite(output);
        readln(n);
        fillchar(last,sizeof(last),255);
        for i:=1 to n-1 do
        begin
                readln(x,y,v);
                insert(x,y,v);
                insert(y,x,v);
        end;
        fillchar(bz,sizeof(bz),true);
        bz[1]:=false;
        dg(1);
        writeln(ans);
        close(input);
        close(output);
end.