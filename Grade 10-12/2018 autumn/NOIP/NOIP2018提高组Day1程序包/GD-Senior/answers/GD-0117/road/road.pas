var
        ans:int64;
        n,i:longint;
        k:array[0..1] of longint;
        x:array[0..100001] of longint;
        a:array[0..100000,0..1] of longint;
        t:array[0..1,1..400000] of longint;
procedure qsort(i,j:longint);
var
        i1,j1,mid:longint;
begin
        i1:=i;
        j1:=j;
        mid:=a[(i+j) div 2,0];
        repeat
                while a[i,0]<mid do inc(i);
                while a[j,0]>mid do dec(j);
                if i<=j then
                begin
                        a[0]:=a[i];
                        a[i]:=a[j];
                        a[j]:=a[0];
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if i1<j then qsort(i1,j);
        if i<j1 then qsort(i,j1);
end;
function max(a,b:longint):longint;
begin
        if a>b then exit(a) else exit(b);
end;
function min(a,b:longint):longint;
begin
        if a<b then exit(a) else exit(b);
end;
procedure search(l,r,st,en,x,p:longint);
var
        mid:longint;
begin
        if (l=st)and(r=en) then
        begin
                if p=0 then k[0]:=max(k[0],t[0,x])
                else k[1]:=min(k[1],t[1,x]);
        end
        else
        begin
                mid:=(l+r) div 2;
                if en<=mid then search(l,mid,st,en,2*x,p)
                else if st>mid then search(mid+1,r,st,en,2*x+1,p)
                else
                begin
                        search(l,mid,st,mid,2*x,p);
                        search(mid+1,r,mid+1,en,2*x+1,p);
                end;
        end;
end;
procedure change(l,r,x,p:longint);
var
        mid:longint;
begin
        if l=r then
        begin
                t[0,x]:=p;
                t[1,x]:=p;
        end
        else
        begin
                mid:=(l+r) div 2;
                if p<=mid then change(l,mid,2*x,p)
                else change(mid+1,r,2*x+1,p);
                t[0,x]:=max(t[0,2*x],t[0,2*x+1]);
                t[1,x]:=min(t[1,2*x],t[1,2*x+1]);
        end;
end;
begin
        assign(input,'road.in');
        reset(input);
        assign(output,'road.out');
        rewrite(output);
        readln(n);
        for i:=1 to n do
        begin
                read(x[i]);
                a[i,0]:=x[i];
                a[i,1]:=i;
        end;
        qsort(1,n);
        fillchar(t[1],sizeof(t[1]),10);
        for i:=1 to n do
        begin
                k[0]:=0;
                k[1]:=168430090;
                if a[i,1]>1 then search(1,n,1,a[i,1]-1,1,0);
                if a[i,1]<n then search(1,n,a[i,1]+1,n,1,1);
                if k[1]=168430090 then k[1]:=n+1;
                if (x[k[0]]<>a[i,0])or(x[k[1]]<>a[i,1]) then ans:=ans+a[i,0]-max(x[k[0]],x[k[1]]);
                change(1,n,1,a[i,1]);
        end;
        writeln(ans);
        close(input);
        close(output);
end.
