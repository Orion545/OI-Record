var
        n,m,i,j,x,y,l,r:longint;
        ans:int64;
        kongge,ch,ch1:char;
        a:array[1..10000]of longint;
        bz:array[1..100]of boolean;
        map:array[1..1000,1..1000]of boolean;
function pd:boolean;
var
        i,j:longint;
begin
        for i:=1 to n do
        begin
                for j:=1 to n do
                begin
                        if(map[i,j])then
                        begin
                                if(bz[i]=false)and(bz[j]=false)then exit(false);
                        end;
                end;
        end;
        exit(true);
end;
procedure dg(t:longint;sum:int64);
begin
        if(t>n)then
        begin
                if(pd)then
                begin
                        if(ans>sum)then ans:=sum;
                end;
                exit;
        end;
        if(t=l)or(t=r)then
        begin
                if(t=l)then
                begin
                        if(x=0)then
                        begin
                                bz[t]:=false;
                                dg(t+1,sum);
                                bz[t]:=false;
                        end
                        else
                        begin
                                bz[t]:=true;
                                dg(t+1,sum+a[t]);
                                bz[t]:=false;
                        end;
                end
                else
                begin
                        if(y=0)then
                        begin
                                bz[t]:=false;
                                dg(t+1,sum);
                                bz[t]:=false;
                        end
                        else
                        begin
                                bz[t]:=true;
                                dg(t+1,sum+a[t]);
                                bz[t]:=false;
                        end;
                end;
        end
        else
        begin
                bz[t]:=true;
                dg(t+1,sum+a[t]);
                bz[t]:=false;
                bz[t]:=false;
                dg(t+1,sum);
                bz[t]:=false;
        end;
end;
begin
        assign(input,'defense.in');
        reset(input);
        assign(output,'defense.out');
        rewrite(output);
        read(n,m,kongge,ch,ch1);
        readln;
        for i:=1 to n do read(a[i]);
        for i:=1 to n-1 do
        begin
                read(x,y);
                map[x,y]:=true;
                map[y,x]:=true;
        end;
        for i:=1 to m do
        begin
                read(l,x,r,y);
                ans:=maxlongint;
                fillchar(bz,sizeof(bz),false);
                dg(1,0);
                if(ans<>maxlongint)then writeln(ans)
                else writeln('-1');
        end;
        close(input);
        close(output);
end.
