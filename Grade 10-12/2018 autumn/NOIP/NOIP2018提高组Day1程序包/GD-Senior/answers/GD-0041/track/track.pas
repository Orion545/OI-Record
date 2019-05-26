const maxn=50005;
type line=record
         nxt,pnt,val:longint;
     end;
var map:array[1..4*maxn]of line;
    f:array[0..maxn,false..true]of longint;
    a,b,dep:array[0..maxn]of longint;
    n,m,i,j,x,y,z,l,r,mid,cnt,sum,ans,tot_map:longint;
    p,q:boolean;

procedure add(x,y,z:longint);//x==>y with z
begin
    inc(tot_map);
    map[tot_map].pnt:=y;
    map[tot_map].val:=z;
    map[map[x].val].nxt:=tot_map;
    map[x].val:=tot_map;
end;

procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
    i:=l;
    j:=r;
    x:=a[(l+r) div 2];
    repeat
        while a[i]<x do inc(i);
        while x<a[j] do dec(j);
        if not(i>j) then begin
            y:=a[i];
            a[i]:=a[j];
            a[j]:=y;
            inc(i);
            dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
end;

procedure update(var i:longint;j:longint);//update max
begin
    if j>i then i:=j;
end;

//p:
//false:dont need to connect up root
//true:need
function dfs(x:longint;p:boolean):longint;
var max,fir,sec,tmp,i:longint;
begin
    if f[x,p]=-1 then begin
        if p then begin
            max:=0;
            i:=x;
            while map[i].nxt<>0 do begin
                i:=map[i].nxt;
                if dep[map[i].pnt]=0 then dep[map[i].pnt]:=dep[x]+1;
                if dep[map[i].pnt]<dep[x] then continue;
                update(max,dfs(map[i].pnt,true)+map[i].val);
            end;
            f[x,p]:=max;
        end else begin
            max:=0;
            fir:=0;
            sec:=0;
            i:=x;
            while map[i].nxt<>0 do begin
                i:=map[i].nxt;
                if dep[map[i].pnt]=0 then dep[map[i].pnt]:=dep[x]+1;
                if dep[map[i].pnt]<dep[x] then continue;
                update(max,dfs(map[i].pnt,false));
                tmp:=dfs(map[i].pnt,true)+map[i].val;
                if tmp>fir then begin
                    sec:=fir;
                    fir:=tmp;
                end else if tmp>sec then sec:=tmp;
            end;
            if fir+sec>max then f[x,p]:=fir+sec else f[x,p]:=max;
        end;
    end;
    exit(f[x,p]);
end;

begin
    assign(input,'track.in');reset(input);
    assign(output,'track.out');rewrite(output);
    read(n,m);
    tot_map:=n;
    for i:=1 to n do map[i].val:=i;
    p:=true;//ai=1
    q:=true;//bi=ai+1
    for i:=1 to n-1 do begin
        read(x,y,z);
        add(x,y,z);
        add(y,x,z);
        if(x<>1)and(y<>1)then p:=false else a[i]:=z;
        if abs(x-y)<>1 then q:=false else begin
            b[(x+y)div 2]:=z;//a[x]:x==>x+1
            inc(sum,z);
        end;
    end;
    if p then begin
        sort(1,n-1);
        l:=a[1];
        r:=a[n-1]+a[n-2];
        while l<r do begin
            mid:=(l+r)div 2+1;
            cnt:=0;
            i:=0;
            j:=n-1;
            while(i<j)and(cnt<m)do begin
                while a[i]+a[j]<mid do inc(i);
                if i<j then begin
                    if i<>0 then inc(i);
                    dec(j);
                    inc(cnt);
                end;
            end;
            if cnt=m then l:=mid else r:=mid-1;
        end;
        ans:=l;
    end else if q then begin
        l:=1;
        r:=sum div m;
        while l<r do begin
            mid:=(l+r)div 2+1;
            cnt:=0;
            sum:=0;
            for i:=1 to n-1 do begin
                inc(sum,b[i]);
                if sum>=mid then begin
                    inc(cnt);
                    if cnt=m then break;
                    sum:=0;
                end;
            end;
            if cnt=m then l:=mid else r:=mid-1;
        end;
        ans:=l;
    end else if m=1 then begin
        fillchar(f,sizeof(f),255);
        dep[1]:=1;
        ans:=dfs(1,false);
    end;
    writeln(ans);
    close(input);close(output);
end.
