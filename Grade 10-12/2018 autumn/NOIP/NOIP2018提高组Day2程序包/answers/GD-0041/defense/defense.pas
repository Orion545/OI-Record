const INF=1800000000;
      maxn=100005;
type line=record
         nxt,val:longint;
     end;
var map:array[0..4*maxn]of line;
    f,tmp:array[0..maxn,0..2]of longint;
    val,dfn,fa:array[0..maxn]of longint;
    b:array[0..maxn]of boolean;
    n,m,i,j,x,y,p,q,p_x,q_y,cnt,min_G,tot_map,G:longint;
    s:string;

function min(i,j:longint):longint;
begin
    if i<j then exit(i) else exit(j);
end;
procedure add(x,y:longint);
begin
    inc(tot_map);
    map[tot_map].val:=y;
    map[map[x].val].nxt:=tot_map;
    map[x].val:=tot_map;
end;

procedure find_dfs(x:longint);
var i,tmp,cnt_max,cnt_min:longint;
begin
    inc(cnt);
    dfn[x]:=cnt;
    tmp:=cnt;
    cnt_max:=0;
    cnt_min:=maxlongint;
    i:=x;
    while map[i].nxt<>0 do begin
        i:=map[i].nxt;
        if dfn[map[i].val]<>0 then continue;
        find_dfs(map[i].val);
        if cnt-tmp>cnt_max then cnt_max:=cnt-tmp;
        if cnt-tmp<cnt_min then cnt_min:=cnt-tmp;
        tmp:=cnt;
    end;
    if n-cnt+dfn[x]>cnt_max then cnt_max:=n-cnt+dfn[x];
    if n-cnt+dfn[x]<cnt_min then cnt_min:=n-cnt+dfn[x];
    if cnt_max=cnt_min then cnt_min:=0;
    if cnt_max-cnt_min<min_G then begin
        min_G:=cnt_max-cnt_min;
        G:=x;
    end;
end;

procedure make_dfs(x:longint);
var i,j,dec_min,sum_1,sum_2:longint;
begin
    i:=x;
    dec_min:=INF;
    sum_1:=0;
    sum_2:=0;
    while map[i].nxt<>0 do begin
        i:=map[i].nxt;
        j:=map[i].val;
        if fa[x]=j then continue;
        fa[j]:=x;
        make_dfs(j);
        inc(sum_1,f[j,1]);
        inc(sum_2,f[j,2]);
        if f[j,0]-f[j,1]<dec_min then dec_min:=f[j,0]-f[j,1];
    end;
    f[x,0]:=val[x]+sum_2;
    f[x,1]:=min(sum_1+dec_min,f[x,0]);
    f[x,2]:=min(sum_1,f[x,1]);
end;


procedure dfs(x:longint);
var i,j,dec_min,sum_1,sum_2,ask:longint;
begin
    if b[x] then begin
        tmp[x]:=f[x];
        exit;
    end;
    i:=x;
    dec_min:=INF;
    sum_1:=0;
    sum_2:=0;
    while map[i].nxt<>0 do begin
        i:=map[i].nxt;
        j:=map[i].val;
        if fa[x]=j then continue;
        dfs(j);
        inc(sum_1,tmp[j,1]);
        inc(sum_2,tmp[j,2]);
        if tmp[j,0]-tmp[j,1]<dec_min then dec_min:=tmp[j,0]-tmp[j,1];
    end;
    ask:=-1;
    if x=p then ask:=p_x;
    if x=q then ask:=q_y;
    if ask=-1 then begin
        tmp[x,0]:=val[x]+sum_2;
        tmp[x,1]:=min(sum_1+dec_min,tmp[x,0]);
        tmp[x,2]:=min(sum_1,tmp[x,1]);
    end else if ask=0 then begin
        tmp[x,0]:=INF;
        tmp[x,1]:=sum_1+dec_min;
        tmp[x,2]:=min(sum_1,tmp[x,1]);
    end else begin
        tmp[x,0]:=val[x]+sum_2;
        tmp[x,1]:=tmp[x,0];
        tmp[x,2]:=tmp[x,0];
    end;
end;

begin
    assign(input,'defense.in');reset(input);
    assign(output,'defense.out');rewrite(output);
    readln(n,m,s);
    for i:=1 to n do read(val[i]);
    tot_map:=n;
    for i:=1 to n do map[i].val:=i;
    for i:=1 to n-1 do begin
        readln(x,y);
        add(x,y);
        add(y,x);
    end;
    min_G:=maxlongint;
    find_dfs(1);
    make_dfs(G);
    for i:=1 to m do begin
        readln(p,p_x,q,q_y);
        if((fa[p]=q)or(fa[q]=p))and(p_x+q_y=0)then begin
            writeln(-1);
            continue;
        end;
        fillchar(b,sizeof(b),true);
        j:=p;
        while j<>0 do begin
            b[j]:=false;
            j:=fa[j];
        end;
        j:=q;
        while j<>0 do begin
            b[j]:=false;
            j:=fa[j];
        end;
        dfs(G);
        writeln(tmp[G,1]);
    end;
    close(input);close(output);
end.
