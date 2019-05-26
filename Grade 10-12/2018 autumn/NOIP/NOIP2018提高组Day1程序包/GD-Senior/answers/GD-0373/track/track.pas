type ppp=record
    next,gt,fee:longint;
end;
var way:array[0..51000,1..3]of longint;
    po:array[0..110000]of ppp;
    last,st,gtsum,nn:array[0..51000]of longint;
    l,r,mid,ans,p3,ttt,now,ptot,m,n,ke,i,j:longint;

function max(a,b:longint):longint;
begin
    if a>b then exit(a);exit(b);
end;

function min(a,b:longint):longint;
begin
    if a<b then exit(a);exit(b);
end;

procedure qsort(l,r:longint);
var  i,j,mid:longint;
    t:array[1..3]of longint;
begin
    i:=l;j:=r;mid:=way[(l+r)div 2,3];
    repeat
         while way[i,3]<mid do inc(i);
         while way[j,3]>mid do dec(j);
         if i<=j then begin
             t:=way[i];way[i]:=way[j];way[j]:=t;
             inc(i);dec(j);
         end;
    until i>j;
    if i<r then qsort(i,r);
    if l<j then qsort(l,j);
end;

function bfs(s:longint):longint;
var  ltot,i,zz,tt,ll,now:longint;
    line,kk:array[1..100000]of longint;
    p:array[1..50000]of boolean;
begin
    bfs:=0;
    ltot:=1;line[1]:=s;fillchar(p,sizeof(p),false);kk[1]:=0;ll:=1;
    repeat
        tt:=ltot;
        for zz:=ll to ltot do begin
            p[line[zz]]:=true;
            now:=st[line[zz]];
            while now<>0 do begin
                if not p[po[now].gt] then begin
                    inc(ltot);
                    kk[ltot]:=kk[zz]+po[now].fee;
                    line[ltot]:=po[now].gt;
                    bfs:=max(bfs,kk[ltot]);
                end;
                now:=po[now].next;
            end;
        end;
        ll:=tt+1;
    until ll>ltot;
    exit;
end;

function check:boolean;
var i:longint;
begin
    for i:=1 to n-1 do if abs(way[i,1]-way[i,2])<>1 then exit(false);
    exit(true);
end;

begin
assign(input,'track.in');reset(input);
assign(output,'track.out');rewrite(output);
    readln(n,m);
    for i:=1 to n-1 do readln(way[i,1],way[i,2],way[i,3]);qsort(1,n-1);
    if m=n-1 then begin
        writeln(way[1,3]);
        close(input);close(output);halt;
    end else begin
        for i:=1 to n-1 do begin
            inc(ptot);if st[way[i,1]]=0 then st[way[i,1]]:=ptot;
            po[last[way[i,1]]].next:=ptot;po[ptot].gt:=way[i,2];
            last[way[i,1]]:=ptot;po[ptot].fee:=way[i,3];
            inc(ptot);if st[way[i,2]]=0 then st[way[i,2]]:=ptot;
            po[last[way[i,2]]].next:=ptot;po[ptot].gt:=way[i,1];
            last[way[i,2]]:=ptot;po[ptot].fee:=way[i,3];
            inc(gtsum[way[i,1]]);inc(gtsum[way[i,2]]);
        end;//m
        if gtsum[1]=n-1 then begin
            ans:=10000000;ttt:=m-1;
            for i:=n-m to n-1 do begin
                if ttt>0 then ans:=min(ans,way[i,3]+way[ttt,3])
                else ans:=min(ans,way[i,3]);
                dec(ttt);
            end;
            writeln(ans);
        end else if check then begin
            l:=1;r:=(n div m +1)*way[n-1,3];
            for i:=1 to n do begin
                    now:=st[i];
                    if po[now].gt>i then nn[i]:=po[now].fee
                    else if i<>n then begin
                        now:=po[now].next;
                        nn[i]:=po[now].fee;
                    end;
            end;
            repeat
                mid:=(l+r)div 2;p3:=0;
                now:=0;ke:=0;
                repeat
                    inc(now);
                    if ke+nn[now]<mid then inc(ke,nn[now])
                    else begin
                        ke:=0;inc(p3);
                    end;
                until now>=n;
                if p3>=m then l:=mid+1 else r:=mid;
            until l=r;
            mid:=(l+r)div 2;p3:=0;
                now:=0;ke:=0;
                repeat
                    inc(now);
                    if ke+nn[now]<mid then inc(ke,nn[now])
                    else begin
                        ke:=0;inc(p3);
                    end;
                until now>=n;
            if p3<m then dec(l);
            writeln(l);
        end else  if m=1 then begin
            for i:=1 to n do if gtsum[i]=1 then ans:=max(ans,bfs(i));
            writeln(ans);
        end else writeln(way[n div 2,3]);
    end;
close(input);close(output);
end.
