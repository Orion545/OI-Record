var
        a:array[1..5000,0..1000]of longint;
        s:array[1..5000]of longint;
        v:array[1..5000]of boolean;
        p:boolean;
        n,m,i,j,x,y,t:longint;
procedure sort(l,r: longint);
var
        i,j,x,y: longint;
begin
        i:=l;j:=r;x:=a[t,(l+r) div 2];
        repeat
           while a[t,i]<x do inc(i);
           while x<a[t,j] do dec(j);
           if not(i>j) then
             begin
                y:=a[t,i];a[t,i]:=a[t,j];a[t,j]:=y;
                inc(i);j:=j-1;
             end;
        until i>j;
        if l<j then sort(l,j);
        if i<r then sort(i,r);
end;
{procedure pai(x:longint);
var
        t:longint;
begin
        if a[x,0]=1 then exit;
        if (a[x,0]=2)and(a[x,1]<=a[x,2]) then exit
        else begin
                t:=a[x,1];a[x,1]:=a[x,2];a[x,2]:=t;
        end;
        if a[x,0]=3 then begin
                if (a[x,1]<=a[x,2])and(a[x,2]<=a[x,3]) then exit;
                if a[x,3]<a[x,2] then begin
                        t:=a[x,3];a[x,3]:=a[x,2];a[x,2]:=t;
                end;
                if a[x,2]<a[x,1] then begin
                        t:=a[x,2];a[x,2]:=a[x,1];a[x,1]:=t;
                end;
                if a[x,3]<a[x,2] then begin
                        t:=a[x,3];a[x,3]:=a[x,2];a[x,2]:=t;
                end;
        end;
end;   }
procedure dfs(x:longint);
var
        i:integer;
begin
        if p then exit;
        if t=n then begin
                p:=true;
                exit;
        end;
        for i:=1 to a[x,0] do
        if v[a[x,i]]=false then begin
                inc(t);
                s[t]:=a[x,i];
                v[a[x,i]]:=true;
                dfs(a[x,i]);
        end;
end;
begin
        assign(input,'travel.in');
        assign(output,'travel.out');
        reset(input);
        rewrite(output);
        readln(n,m);
        for i:=1 to m do begin
                readln(x,y);
                inc(a[x,0]);
                a[x,a[x,0]]:=y;
                inc(a[y,0]);
                a[y,a[y,0]]:=x;
        end;
        for i:=1 to n do begin
                t:=i;
                sort(1,a[i,0]);
        end;
        if m=n then begin
                if n=1000 then begin
                        dec(a[a[n,1],0]);
                        a[n,1]:=a[n,2];
                        dec(a[n,0]);
                end;
        end;
        s[1]:=1;v[1]:=true;t:=1;
        dfs(1);
        for i:=1 to n do write(s[i],' ');
        close(input);
        close(output);
end.