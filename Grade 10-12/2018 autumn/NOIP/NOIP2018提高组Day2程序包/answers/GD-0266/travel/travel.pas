var
  n,m,i,j,x,y,s,s2,l,r,min:longint;
  f:array[1..5000,1..5000] of boolean;
  f2:array[1..5000] of boolean;
  a:array[1..5000] of longint;
procedure find(i:longint);
var
  j:longint;
begin
  
  for j:=1 to n do
  
    
    if (f[i,j]) and (f2[j]) then
    begin
      inc(s);
      a[s]:=j; 
     
      f2[j]:=false;
      find(j);
     { f2[j]:=true;
      if s=n then  inc(s2);
      dec(s);  }
    end;
  
end;

begin
assign(input,'travel.in');
assign(output,'travel.out');
reset(input);
rewrite(output);
  read(n,m);
  fillchar(f,sizeof(f),false);
  fillchar(f2,sizeof(f2),true);
  for i:=1 to m do
  begin
    read(x,y);
    f[x,y]:=true;
    f[y,x]:=true;
  end;
  s:=1;  a[1]:=1;  f2[1]:=false;
  find(1);
  //for i:=1 to s2 do
  //begin
    for i:=1 to n do write(a[i],' ');
    //writeln;
 // end;
 close(input); close(output);

end.
