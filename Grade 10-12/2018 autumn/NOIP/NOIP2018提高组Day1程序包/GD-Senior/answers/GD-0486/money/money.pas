var i,j,k,n,t,xh,yy,answer,now,tot,totl,ccf:longint;
    p:boolean;
    a:array[0..101] of longint;
    use,answ:array[0..2500000] of boolean;
    jly:array[0..2500001] of longint;
procedure getmax(lzk:longint);
var now,i,xx:longint;
begin
    for i:=1 to lzk do use[i]:=false;
    totl:=0;
    for i:=1 to n do begin
        now:=1;
        xx:=0;
        ccf:=0;
        use[lzk+1]:=true;
        use[lzk+2]:=true;
        use[0]:=true;
        while now*a[i]+xx<=lzk do begin
            while xx<=lzk do begin
                while not use[xx] do inc(xx);
                if now*a[i]+xx<=lzk then begin
                    inc(ccf);
                    jly[ccf]:=now*a[i]+xx;
                end else xx:=lzk;
                inc(xx);
            end;
            inc(now);
            xx:=0;
        end;
        for j:=1 to ccf do use[jly[j]]:=true;
    end;
    {for i:=1 to n do if use[i] then begin
        inc(totl);
        sz[totl]:=i;      //totl quanjubianliang
    end;  }
end;
begin
assign(input,'money.in');reset(input);
assign(output,'money.out');rewrite(output);
    read(t);
    for xh:=1 to t do begin
        answer:=0;
        tot:=0;
        read(n);
        p:=false;
        for i:=1 to n do begin
            read(a[i]);
            inc(tot,a[i]);
            if a[i]=1 then p:=true;
        end;
        if (p) or (n=1) then writeln('1')
        else begin
            //sort(1,n);
            getmax(tot);
            for i:=1 to tot do answ[i]:=false;
            for j:=1 to tot do begin
                if (use[j]) and (not answ[j]) then begin
                    now:=1;
                    yy:=0;
                    ccf:=0;
                    answ[0]:=true;
                    answ[tot+1]:=true;
                    answ[tot+2]:=true;
                    while now*j+yy<=tot do begin
                        while yy<=tot do begin
                            while not answ[yy] do inc(yy);
                            if now*j+yy<=tot then begin
                               inc(ccf);
                               jly[ccf]:=now*j+yy;
                            end else yy:=tot;
                            inc(yy);
                        end;
                        inc(now);
                        yy:=0;
                    end;
                    for k:=1 to ccf do answ[jly[k]]:=true;
                    inc(answer);
                end;
            end;
            writeln(answer);
        end;
    end;
close(input);close(output);
end.
