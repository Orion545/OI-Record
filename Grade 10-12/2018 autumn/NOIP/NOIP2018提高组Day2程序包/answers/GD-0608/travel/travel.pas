//CCF MAKES ME SAD
type arr=array[0..5000] of longint;
var
n,m,i,j,k,t,p,ans,count:longint;
flag:boolean;
a:array[0..5000,0..1000] of longint;
num:array[0..5000] of boolean;
minn,cd,x,y,rd:arr;
b:array[0..5000] of boolean;

procedure swap(var e,r:longint);
 var o:longint;
 begin
  o:=e; e:=r; r:=o;
 end;

procedure sort(l,r: longint; var a,b:arr);
var i,j,x,y: longint;
  begin
  i:=l; j:=r; x:=a[(l+r) div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if (not(i>j)) or ((b[j]<b[i]) and (a[i]=a[j]))then
      begin
        swap(a[i],a[j]);
        if (b[i]>b[j]) and (a[i]=a[j]) then swap(b[i],b[j]);
        inc(i);
        j:=j-1;
      end;
    until i>j;
    if l<j then sort(l,j,a,b);
    if i<r then sort(i,r,a,b);
   end;

function min(e,r:longint):longint;
 begin
  if e<r then exit(e) else exit(r);
 end;

procedure dd(t,count,fa:longint);
 var i,j,famin,sonmin,k:longint;
 begin
 {  if count=n-1 then begin writeln(t); inc(count); exit; end
    else begin
          write(t,' ');
          inc(count);
    end;               }
    if count>n-1 then exit;
    if count=n-1 then
      begin
      //  for i:=1 to n do if b[i]=true then begin write(t,' ');(i);  end;
        if flag=true then writeln(t);
        close(input) ;
        close(output);
        halt;
      end else begin write(t,' ');  end;
   sonmin:=maxlongint;
   for i:=1 to a[t,0] do
     begin
       if b[a[t,i]]=true then sonmin:=min(sonmin,a[t,i]);
       if (rd[a[t,i]]=1) and (b[a[t,i]]=true) and (cd[t]<=2) then
          begin b[a[t,i]]:=false; dd(a[t,i],count+1,t);  end;
     end;
   famin:=maxlongint;
   for j:=1 to a[fa,0] do
     begin
      if b[a[fa,j]]=true then famin:=min(famin,a[fa,j]);
     { if (rd[a[fa,j]]=1) and (b[a[fa,j]]=true) then
        begin b[a[fa,j]]:=false; dd(a[fa,j],count+1,fa); end; }
     end;
   if sonmin>famin then begin b[famin]:=false; k:=famin; dd(famin,count+1,fa); {b[k]:=true;} end;
   for i:=1 to a[t,0] do
    begin

      if b[a[t,i]]=true then
       begin
        b[a[t,i]]:=false;
        dd(a[t,i],count+1,t);
       // b[a[t,i]]:=true;
       end;
   end;
 end;
begin
assign(input,'travel.in');
assign(output,'travel.out');
reset(input);
rewrite(output);

flag:=true;
fillchar(minn,sizeof(minn),$7f);
fillchar(b,sizeof(b),true);
readln(n,m);
for i:=1 to m do readln(x[i],y[i]);
sort(1,m,x,y);
for i:=1 to m do
 begin
  // readln(x[i],y[i]);
   inc(cd[x[i]]);
   inc(cd[y[i]]);
   inc(rd[x[i]]);
   inc(rd[y[i]]);
   inc(a[x[i],0]);
   a[x[i],a[x[i],0]]:=y[i];
  // minn[x]:=min(minn[x],y) ;
   inc(a[y[i],0]);
   a[y[i],a[y[i],0]]:=x[i];
  // minn[y]:=min(minn[y],y);
 end;
{for i:=1 to m do write(x[i],' ');
writeln;
for i:=1 to m do write(y[i],' '); }
for i:=1 to 5000 do
  if cd[i]<>0 then
    begin
      b[i]:=false;
      dd(i,1,0);
      break;
    end;

close(input);
close(output);
end.
