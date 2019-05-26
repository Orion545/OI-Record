var p:array[0..25000]of boolean;
    num:array[1..100]of longint;
    sss,i,ans,n,now,ma,t,mi,j:longint;

procedure qsort(l,r:longint);
var  i,j,mid,t:longint;
begin
    i:=l;j:=r;mid:=num[(l+r)div 2];
    repeat
         while num[i]<mid do inc(i);
         while num[j]>mid do dec(j);
         if i<=j then begin
             t:=num[i];num[i]:=num[j];num[j]:=t;
             inc(i);dec(j);
         end;
    until i>j;
    if i<r then qsort(i,r);
    if l<j then qsort(l,j);
end;

function find(a:longint):boolean;
var i:longint;
begin
    for i:=mi to a div 2 do if (p[i])and(p[a-i]) then exit(true);
    exit(false);
end;


begin
assign(input,'money.in');reset(input);
assign(output,'money.out');rewrite(output);
    readln(t);
for sss:=1 to t do begin
    readln(n);
    for i:=1 to n do read(num[i]);
    qsort(1,n);fillchar(p,sizeof(p),false);
    mi:=num[1];ma:=num[n];ans:=0;p[0]:=true;
    for i:=1 to n do if not find(num[i]) then begin
        now:=num[i];inc(ans);
        while now<=ma do begin
            p[now]:=true;
            inc(now,num[i]);
        end;
        for j:=num[i]+1 to ma do if (not p[j])and(find(j)) then begin
            now:=j;
            while now<=ma do begin
                p[now]:=true;inc(now,j);
            end;
        end;
    end else begin
        p[num[i]]:=true;
        if (2*num[i]<=ma)and(not p[2*num[i]]) then begin
            now:=2*num[i];
            while now<=ma do begin
                p[now]:=true;
                inc(now,num[i]);
            end;
        end;
    end;
    writeln(ans);
end;
close(input);close(output);
end.
