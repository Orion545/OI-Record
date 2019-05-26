var m,n,i,a,b,now,tot,j,l,k,y:longint;
p:array[1..6000,1..6000] of longint;
ans,mo,total:array[1..10000] of longint;
pp:array[1..10000] of boolean;
ppp:boolean;
procedure dfs(a:longint);
var j:longint;
begin
    pp[a]:=false;
    inc(tot);
    ans[tot]:=a;
    for j:=1 to total[a] do begin
        if (p[a,j]<>0) and pp[p[a,j]] then begin
           dfs(p[a,j]);
        end;
    end;
end;
begin
assign(input,'travel.in');reset(input);
assign(output,'travel.out');rewrite(output);
    readln(n,m);
    for i:=1 to m do begin
        readln(a,b);
        inc(total[a]);
        inc(total[b]);
        p[a,total[a]]:=b;
        p[b,total[b]]:=a;
    end;
    for i:=1 to n do begin
        for j:=1 to total[i]-1 do begin
            for l:=j+1 to total[i] do begin
                if p[i,j]>p[i,l] then begin
                    y:=p[i,j];
                    p[i,j]:=p[i,l];
                    p[i,l]:=y;
                end;
            end;
        end;
    end;
    mo[1]:=n+1;
    if m<>n then begin
       fillchar(pp,sizeof(pp),true);
       dfs(1);
       for j:=1 to n do write(ans[j],' ');
    end;
    if m=n then begin
        for i:=1 to m do begin
            for l:=1 to total[i] do begin
            fillchar(pp,sizeof(pp),true);
            y:=p[i,l];
            p[i,l]:=0;
            tot:=0;
            dfs(1);
            if tot=n then begin
               ppp:=true;
               k:=0;
               while (k<n) do begin
                   inc(k);
                   if ans[k]<mo[k] then begin
                       break;
                   end;
                   if ans[k]>mo[k] then begin
                       ppp:=false;
                       break;
                   end;
               end;
               if ppp then for j:=1 to n do mo[j]:=ans[j];
            end;
            p[i,l]:=y;
            end;
        end;
        for i:=1 to n do write(mo[i],' ');
    end;
    close(input);close(output);

end.
