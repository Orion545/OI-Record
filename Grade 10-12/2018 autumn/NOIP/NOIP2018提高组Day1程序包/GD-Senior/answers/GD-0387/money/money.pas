program money;
var
        a:array[1..100] of integer;
        n,t,i,j,ans,te,k:integer;

procedure kp(l,r:integer);
var
        mid,i,j,t:integer;
begin
        if l>=r then exit;
        i:=l;j:=r;mid:=a[(l+r) div 2];
        repeat
                while a[i]<mid do inc(i);
                while a[j]>mid do dec(j);
                if i<=j then
                        begin
                                t:=a[i];a[i]:=a[j];a[j]:=t;
                                inc(i);dec(j);
                        end;
        until i>j;
        kp(l,j);
        kp(i,r);
end;

begin
        assign(input,'money.in');reset(input);
        assign(output,'money.out');rewrite(output);
        readln(t);
        for i:=1 to t do
                begin
                        readln(n);
                        ans:=n;
                        for j:=1 to n do
                                read(a[j]);
                        readln;
                        kp(1,n);
                        if n=2 then
                                if (a[2] mod a[1]=0) then ans:=ans-1;
                        if n=3 then
                                begin
                                        if a[2] mod a[1]=0 then
                                                begin a[2]:=0;ans:=ans-1;end;
                                        if a[3] mod a[1]=0 then
                                                begin a[3]:=0;ans:=ans-1;end;
                                        if (a[2]<>0) and (a[3]<>0) then
                                                if a[3] mod a[2]=0 then
                                                        begin a[3]:=0;ans:=ans-1;end;
                                        while (a[3]>a[2]) and (a[2]<>0) do
                                                begin
                                                        a[3]:=a[3]-a[2];
                                                        if a[3] mod a[1]=0 then
                                                                begin
                                                                        ans:=ans-1;
                                                                        break;
                                                                end;
                                                end;
                                end;
                        if n>=4 then begin
                                for j:=1 to n-1 do
                                        if a[j]=0 then
                                                ans:=ans-1
                                        else
                                        for k:=j+1 to n do
                                                if a[k] mod a[j]=0 then
                                                        a[k]:=0;
                                if a[n]=0 then
                                        ans:=ans-1;
                                kp(1,n);
                                for j:=1 to ans do
                                        a[j]:=a[n-ans+j];
                                if ans=3 then
                                begin
                                        while (a[3]>a[2]) and (a[2]<>0) do
                                                begin
                                                        a[3]:=a[3]-a[2];
                                                        if a[3] mod a[1]=0 then
                                                                begin
                                                                        ans:=ans-1;
                                                                        break;
                                                                end;
                                                end;
                                end;
                        end;
                        writeln(ans);
                end;
        close(input);close(output);
end.