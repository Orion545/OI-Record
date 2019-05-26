var
        n,m,i,j,k,l,x,y,z,tot,max,min,wz:longint;
        a,last,next,tov,bz,len,b:array[0..1000] of longint;
procedure add(x,y,z:longint);
begin
        inc(tot);
        next[tot]:=last[x];
        len[tot]:=z;
        tov[tot]:=y;
        last[x]:=tot;
end;
procedure dg(x,ans:longint);
var
        i,j,k,l:longint;
begin
        if ans>max then max:=ans;
        l:=last[x];
        while l<>0 do
        begin
                if bz[tov[l]]=0 then
                begin
                        bz[x]:=1;
                        bz[tov[l]]:=1;
                        dg(tov[l],ans+len[l]);
                        bz[x]:=0;
                        bz[tov[l]]:=0;
                end;
                l:=next[l];
        end;
end;
begin
        assign(input,'track.in');reset(input);
        assign(output,'track.out');rewrite(output);
        readln(n,m);
        for i:=1 to n-1 do
        begin
                readln(x,y,z);
                inc(b[x]);
                inc(b[y]);
                add(x,y,z);
                add(y,x,z);
        end;
        min:=maxlongint;
        for i:=1 to n do
        begin
                if b[i]<min then
                begin
                        min:=b[i];
                        wz:=i;
                end;
        end;
        dg(wz,0);
        writeln(max);
        close(input);close(output);
end.
