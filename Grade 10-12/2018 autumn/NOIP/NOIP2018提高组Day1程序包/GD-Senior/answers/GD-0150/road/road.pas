var
        a:array[0..100010] of longint;
        b,e,s,c,n,i,j,k,min,max:Longint;
        f:boolean;
        ans:int64;
begin
        assign(input,'road.in');
        reset(input);
        assign(output,'road.out');
        rewrite(output);
        readln(n);
        if n<=1000 then
        begin
        for i:=1 to n do
                read(a[i]);
        c:=0;
        ans:=0;
        while c<n do
        begin
                min:=maxlongint;
                for i:=1 to n do
                        if a[i]>0 then break;
                for j:=i to n do
                begin
                        if a[j]<=0 then break;
                        if a[j]<min then min:=a[j];
                end;
                if a[j]=0 then dec(j);
                for k:=i to j do
                begin
                        a[k]:=a[k]-min;
                        if a[k]=0 then inc(c);
                end;
                ans:=ans+min;
        end;
        end else
        begin
        fillchar(a,sizeof(a),0);
        for i:=1 to n do
                read(a[i]);
        a[0]:=a[1];
        b:=1;
        while (a[b]=a[b-1]) and (b<n) do
                inc(b);
        if a[b]>a[b-1]
                then f:=true
                else f:=false;
        max:=a[b-1];
        ans:=0;
        s:=1;
        e:=b;
        for i:=b+1 to n+1 do
        begin
                if f then
                begin
                        if a[i]>=a[i-1] then max:=a[i] else
                        begin
                                f:=false;
                                e:=i;
                        end;
                end else
                begin
                        if a[i]<=a[i-1] then e:=i else
                        begin
                                b:=i-1;
                                ans:=ans+max-a[e];
                                max:=a[i];
                        end;
                end;
                if i=n+1 then ans:=ans+max;
        end;
        end;
        write(ans);
        close(input);
        close(output);
end.
