var
        f:array[0..5000,0..5000] of boolean;
        a:array[0..5000,0..5000] of longint;
        b:array[0..10000] of longint;
        o:array[0..10000] of boolean;
        s,e,n,m,i,j,x,y,ans,min:longint;
begin
        assign(input,'travel.in');
        reset(input);
        assign(output,'travel.out');
        rewrite(output);
        readln(n,m);
        fillchar(f,sizeof(f),0);
        fillchar(a,sizeof(a),0);
        fillchar(o,sizeof(o),1);
        for i:=1 to m do
        begin
                readln(x,y);
                f[x,y]:=true;
                f[y,x]:=true;
                inc(a[x,0]);
                a[x,a[x,0]]:=y;
                inc(a[y,0]);
                a[y,a[y,0]]:=x;
        end;
        o[1]:=false;
        ans:=1;
        s:=1;
        e:=e;
        b[1]:=1;
        while ans<n do
        begin
                min:=maxlongint;
                for i:=1 to ans do
                        for j:=1 to a[b[i],0] do
                                if (a[b[i],j]<min) and (o[a[b[i],j]]) then
                                begin
                                        min:=a[b[i],j];
                                        o[a[b[i],j]]:=false;
                                end;
                inc(ans);
                b[ans]:=min;
        end;
        for i:=1 to n do
                write(b[i],' ');
        close(input);
        close(output);
end.
