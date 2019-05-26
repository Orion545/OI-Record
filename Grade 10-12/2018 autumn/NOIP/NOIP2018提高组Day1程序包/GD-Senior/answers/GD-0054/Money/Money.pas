const
 inf=25001;
var
 T:integer;//20
 n:integer;//100
 a:array[1..100]of integer;//25000
 i,j,k:integer;
 ans:integer;
 procedure bubble;
  var
   i,j,k,min,t:integer;
  begin
   for i:=1 to n do
    begin
     min:=i;
     for j:=i+1 to n do
     if a[j]<a[min]then min:=j;
     t:=a[min];
     a[min]:=a[i];
     a[i]:=t;
     for j:=i+1 to n do
     if(a[j]mod a[i])=0 then a[j]:=inf;
    end;
  end;
 function check(x,pos:integer):boolean;
  var
   i:integer;
  begin
   if x<=a[1]then exit(true);
   check:=true;
   for i:=1 to pos-1 do
   if(x mod a[i]=0)then exit(false);
   for i:=1 to pos-1 do
   check:=check and check(x-a[i],pos);
  end;
begin
 assign(input,'money.in');reset(input);
 assign(output,'money.out');rewrite(output);
 readln(T);
 for i:=1 to T do
  begin
   ans:=2;
   readln(n);
   if n=1 then begin writeln(n);readln(n);continue;end;
   for j:=1 to n do
   read(a[j]);
   bubble;
   for j:=n downto 1 do
   if a[j]<>inf then break;
   n:=j;
   for j:=3 to n do
   if a[j]>(a[1]*a[2]-a[1]-a[2])then break;
   if a[n]>(a[1]*a[2]-a[1]-a[2])then n:=j-1;
   if n<3 then begin writeln(n);continue;end;
   for j:=3 to n do
   if check(a[j],j) then inc(ans);
   writeln(ans);
  end;
 close(input);close(output);
end.