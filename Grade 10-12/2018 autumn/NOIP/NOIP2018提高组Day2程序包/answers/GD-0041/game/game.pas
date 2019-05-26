const p=1000000007;
var a:array[0..10]of longint;
    n,m,max,ans:longint;
    b:boolean;


function pow(x,k:longint):longint;
var tmp:longint;
begin
    if k=1 then exit(x);
    tmp:=pow(x,k shr 1);
    tmp:=(tmp*tmp)mod p;
    if odd(k) then tmp:=(tmp*x)mod p;
    exit(tmp);
end;



procedure up(x:longint);
begin
    if x=0 then b:=true;
    inc(a[x]);
    if a[x]=1 shl m then begin
        a[x]:=0;
        up(x-1);
    end;
end;

function dfs(x,y,num:longint):boolean;
begin
    if(x=m)and(y=n)then begin
        if num>=max then begin
            max:=num;
            exit(true);
        end else exit(false);
    end;
    if x<m then
        if not dfs(x+1,y,num*2+(a[y]and(1 shl (m-x-1)))shr (m-x-1))
                then exit(false);
    if y<n then
        if not dfs(x,y+1,num*2+(a[y+1]and(1 shl (m-x)))shr (m-x))
                then exit(false);
    exit(true);
end;

begin
    assign(input,'game.in');reset(input);
    assign(output,'game.out');rewrite(output);
    readln(n,m);
    if(n<=5)and(m<=5)then begin
    b:=false;
    repeat
        max:=0;
        if dfs(1,1,0) then inc(ans);
        up(n);
    until b;
    writeln(ans);
    end;
    if n=2 then writeln((4*pow(3,m-1))mod p);
    if n=3 then writeln((112*pow(3,m-3))mod p);
    close(input);close(output);
end.
