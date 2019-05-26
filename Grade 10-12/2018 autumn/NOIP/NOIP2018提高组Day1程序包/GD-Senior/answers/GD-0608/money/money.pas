type arr=array[0..1000] of int64;
var
i,j:longint; n,m,t,p,count,now:INT64;
a:arr;    flag:boolean;
b:array[0..1000] of boolean;
ans:array[0..50000] of int64;

procedure swap(var e,r:int64);
 var o:longint;
 begin
  o:=e; e:=r; r:=o;
 end;

procedure sort(l,r: longint);
  var i,j,x,y: longint;
    begin
     i:=l;  j:=r;
     x:=a[(l+r) div 2];
     repeat
      while a[i]>x do inc(i);
      while x>a[j] do dec(j);
      if not(i>j) then
        begin
         swap(a[i],a[j]);
         inc(i);
         j:=j-1;
        end;
     until i>j;
     if l<j then sort(l,j);
     if i<r then sort(i,r);
    end;


procedure dd(k:int64);
 var i,j:longint;  //flag:boolean;
 begin
    if (k=0) and (flag=false) then flag:=true;
    if flag=true then exit;
    for i:=1 to n do
     if (b[i]=true) and (a[i]<>now) then
	 begin
	    if (k mod a[i]=0) and (a[i]<>now) then
               begin
                 //write(now,' ');
                 ans[now]:=ans[now]+1;
                 if ans[now]=1 then dec(count);
                 flag:=true;
                 if flag=true then exit;
               end;
	    if k>=a[i] then
		   begin
		     //b[i]:=false;
		     dd(k-a[i]);
		     //b[i]:=true;
	           end;
	 end;
 end;

begin
assign(input,'money.in');
assign(output,'money.out');
reset(input);
rewrite(output);

readln(t);
for i:=1 to t do
 begin
   fillchar(ans,sizeof(ans),0);
   fillchar(a,sizeof(a),0);
   fillchar(b,sizeof(b),true);
   readln(n);
   for j:=1 to n do read(a[j]); readln;
   sort(1,n);
   count:=n;
   for j:=1 to n do
      begin
       now:=a[j]; flag:=false;
       dd(a[j]);
      end;
   writeln(count);
 end;

close(input);
close(output);
end.
