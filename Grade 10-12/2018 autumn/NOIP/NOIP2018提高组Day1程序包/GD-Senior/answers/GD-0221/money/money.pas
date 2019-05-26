var i,j,k,l,m,n,q,w,t,tot:longint;
    a,b,vis:array[0..60000] of longint;
 procedure sort(l,r: longint);
      var i,j,x,y: longint;
      begin
         i:=l; j:=r; x:=a[(l+r) div 2];
         repeat
           while a[i]<x do inc(i);
           while x<a[j] do dec(j);
           if not(i>j) then
             begin
                y:=a[i]; a[i]:=a[j]; a[j]:=y;
                inc(i); j:=j-1;
             end;
         until i>j;
         if l<j then sort(l,j);
         if i<r then sort(i,r);
      end;
begin
assign(input,'money.in');reset(input);
assign(output,'money.out');rewrite(output);
    readln(t);
    while t>0 do begin
       dec(t);
       fillchar(vis,sizeof(vis),0);
       fillchar(b,sizeof(b),0);
       fillchar(a,sizeof(a),0);
       tot:=0;
       vis[0]:=1;
       readln(n);
       for i:=1 to n do read(a[i]);
       sort(1,n);
       for i:=1 to n do if a[i]<>a[i-1] then begin
          inc(b[0]);
          b[b[0]]:=a[i];
       end;
       readln;
       for i:=1 to b[0] do
           for j:=b[i] to 25000 do if vis[j-b[i]]<>0 then inc(vis[j]);
       for i:=1 to b[0] do if vis[b[i]]=1 then inc(tot);
       writeln(tot);
    end;
    close(input); close(output);
end.


