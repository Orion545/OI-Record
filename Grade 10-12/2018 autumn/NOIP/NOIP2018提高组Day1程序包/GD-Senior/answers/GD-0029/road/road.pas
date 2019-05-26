var
  n,i,j,right,left:longint;
  p:array[0..100000]of boolean;
  l,r:array[0..100001]of longint;
  b,wz,a,cost:array[0..100001]of longint;

function max(x,y:longint):longint;
begin
    if x<y then exit(y) else exit(x);
end;

procedure kp(l,r:longint);
var
  i,j,mid,t:longint;
begin
    i:=l; j:=r; mid:=b[(i+j) div 2];
    while i<=j do begin
        while b[i]>mid do inc(i);
        while b[j]<mid do dec(j);
        if i<=j then begin
            t:=b[i]; b[i]:=b[j]; b[j]:=t;
            t:=wz[i]; wz[i]:=wz[j]; wz[j]:=t;
            inc(i); dec(j);
        end;
    end;
    if i<r then kp(i,r);
    if l<j then kp(l,j);
end;

begin
    assign(input,'road.in');reset(input);
    assign(output,'road.out');rewrite(output);
    read(n);
    for i:=1 to n do begin
        read(a[i]);
        l[i]:=i-1; r[i]:=i+1; wz[i]:=i; b[i]:=a[i];
    end;
    l[n+1]:=n; r[0]:=1;
    kp(1,n);
    i:=1;
    while i<=n do begin
        if not p[wz[i]] then begin
            j:=wz[i];
            p[j]:=true;
            while (a[j]>=a[r[j]])and(j<=n) do begin
                p[j]:=true;
                if j<>wz[i] then cost[wz[i]]:=cost[wz[i]]+cost[j];
                j:=r[j];
            end;
            right:=j;

            j:=wz[i];
            while (a[j]>=a[l[j]])and(j>=1) do begin
                p[j]:=true;
                if j<>wz[i] then cost[wz[i]]:=cost[wz[i]]+cost[j];
                j:=l[j];
            end;
            left:=j;

            l[right]:=left; r[left]:=right;

            if a[left]<a[right] then begin
                cost[right]:=cost[right]+cost[wz[i]]+a[wz[i]]-a[right];
                a[wz[i]]:=a[right];
            end
            else begin
                cost[left]:=cost[left]+cost[wz[i]]+a[wz[i]]-a[left];
                a[wz[i]]:=a[left];
            end;
        end;
        inc(i);
    end;
    writeln(max(cost[0],cost[n+1]));
    close(input);close(output);
end.
