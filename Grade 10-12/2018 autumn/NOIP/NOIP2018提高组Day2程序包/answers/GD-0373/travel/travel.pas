var p:array[1..5000,1..5000]of boolean;
    q,ir:array[1..5000]of boolean;
    i,m,x,y,n,sss,r1,r2,k,rn:longint;
    cc:boolean;

procedure getr(now,fa:longint);
var i:longint;
begin
    q[now]:=true;
    for i:=1 to n do if p[now,i] then begin
        if i<>fa then begin
            if q[i] then begin
                sss:=i;ir[now]:=true;
                exit;
            end;
            getr(i,now);
            if ir[i] then begin
                if now <>sss then ir[now]:=true;
                exit;
            end;
            exit;
        end;
    end;
end;

procedure dfs(now:longint);
var i:longint;
begin
    if not q[now] then write(now,' ');q[now]:=true;
    if (r1=6000)and(ir[now]) then begin
        for i:=1 to n do if (p[now,i])and(ir[i]) then begin
            if r2<>6000 then r1:=i
            else r2:=i;
        end;
    end;
    if (r1<=5000)and(ir[now]) then begin
        for i:=1 to n do if (p[now,i])and(not q[i]) then begin
            if (rn<=i)and(rn<r2) then begin
                rn:=5999;
                dfs(1);
            end;
            if r2<=i then begin
               k:=r2;r2:=5999;
               dfs(k);
            end;
            if r1<=i then begin
                k:=r1;r1:=5999;
                dfs(k);
            end;
            if rn<=i then begin
                rn:=5999;
                dfs(1);
            end;
            if not q[i] then dfs(i);
        end;
    end else begin
        for i:=1 to n do if (p[now,i])and(not q[i]) then dfs(i);
    end;
end;


begin
assign(input,'travel.in');reset(input);
assign(output,'trave.out');rewrite(output);
    readln(n,m);
    for i:=1 to m do begin
        readln(x,y);if p[x,y] then begin
            cc:=true;ir[x]:=true;ir[y]:=true;sss:=1;
        end;
        p[x,y]:=true;p[y,x]:=true;
    end;
    r1:=6000;r2:=6000;
    if m=n then begin
        if not cc then getr(1,0);fillchar(q,sizeof(q),false);ir[sss]:=true;rn:=6000;
        if ir[1] then begin
            for i:=2 to n do if p[1,i] then begin
                if ir[i] then begin
                    if r2=6000 then r2:=i
                    else r1:=i;
                end else if rn=6000 then rn:=i;
            end;
        end ;
        dfs(1);
    end else dfs(1);
close(input);close(output);
end.
