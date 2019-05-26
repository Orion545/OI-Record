var
  n,m,a,b,x,y,i,j,ii:longint;
  c:string;
  v,vv:array[0..100000]of longint;
  tp:array[0..100000]of boolean;
  f:array[0..100000,0..1]of int64;
       {
procedure dfs(k:longint);
var
  i,ans1:longint;
begin
    for i:=1 to b[k,0] do if not p[i] then begin
        p[i]:=true;
        dfs(b[k,i]);
    end;
    ans1:=0;
    for i:=1 to b[k,0] do begin
        ans1:=ans1+p[i];
    end;
    if p[k]<p[i] then
end;    }

function min(x,y:int64):int64;
begin
    if x<y then exit(x) else exit(y);
end;

begin
    assign(input,'defense.in');reset(input);
    assign(output,'defense.out');rewrite(output);
    readln(c);
    val(copy(c,1,pos(' ',c)-1),n);
    delete(c,1,pos(' ',c));
    val(copy(c,1,pos(' ',c)-1),m);
    delete(c,1,pos(' ',c));
    if c[1]='A' then begin
        for i:=1 to n do read(vv[i]);
        v:=vv;
        for i:=1 to n-1 do read(x,y);
        for i:=1 to m do begin
            read(a,x,b,y);
            if (x=y)and(x=0)and(abs(a-b)=1) then begin
                writeln(-1);
                continue;
            end;
            if (x=0) then v[a]:=maxlongint;
            if (y=0) then v[b]:=maxlongint;
            if x=1 then tp[a]:=true;
            if y=1 then tp[b]:=true;
            for ii:=1 to n do begin
                f[ii,1]:=maxlongint div 3;
                f[ii,0]:=maxlongint div 3;
            end;
            f[1,1]:=v[1];
            f[1,0]:=0;
            for j:=2 to n do begin
                f[j,1]:=min(f[j-1,0],f[j-1,1])+v[j];
                if not tp[j] then f[j,0]:=f[j-1,1];
            end;
            writeln(min(f[n,0],f[n,1]));
            if x=1 then tp[a]:=false;
            if y=1 then tp[b]:=false;
            if (x=0) then v[a]:=vv[a];
            if (y=0) then v[b]:=vv[b];
        end;
    {for i:=1 to n-1 do begin
        read(x,y);
        inc(b[x,0]);
        b[x,b[x,0]]:=y;
        inc(b[y,0]);
        b[y,b[y,0]]:=x;
    end;
    p[1]:=true;
    dfs(1);}
    end;
    close(input);close(output);
end.
