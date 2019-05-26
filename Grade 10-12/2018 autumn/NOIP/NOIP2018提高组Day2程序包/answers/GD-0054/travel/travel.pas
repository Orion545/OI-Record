const
 filename='Travel';
 t=true;
 f=false;
 inf=5001;
var
 n,m:integer;
 i,j:integer;
 map:array[1..5000,1..5000]of boolean;
 visited:array[1..5000]of integer;
 a,b:integer;
 ring,ringmin:integer;

 function findring(pos,count:integer):integer;
  var
   i,j:integer;
   tt:integer;
  begin
   for i:=1 to count do
   if pos=visited[i]then begin visited[count+1]:=i;exit(count+1);end;
   findring:=0;
   for i:=1 to n do
   if map[pos,i]then begin
                      map[pos,i]:=f;map[i,pos]:=f;
                      visited[count]:=pos;
                      tt:=findring(i,count+1);
                      if tt<>0 then begin map[pos,i]:=t;map[i,pos]:=t;exit(tt);end;
                      visited[count]:=0;
                      map[pos,i]:=t;map[i,pos]:=t;
                     end;
  end;
 function max(a,b:integer):integer;
  begin
   if a>b then exit(a)
          else exit(b);
  end;
 procedure ans(pos:integer);
  var
   i:integer;
  begin
   write(pos,' ');
   for i:=1 to n do
   if map[pos,i]then begin map[pos,i]:=f;map[i,pos]:=f;ans(i);end;
  end;

begin
 //file
 assign(input,filename+'.in');reset(input);
 assign(output,filename+'.out');rewrite(output);
 //init
 readln(n,m);
 for i:=1 to n do visited[i]:=0;
 for i:=1 to n do for j:=1 to n do map[i,j]:=f;
 ringmin:=inf;
 for i:=1 to m do
  begin
   readln(a,b);
   map[a,b]:=t;map[b,a]:=t;
  end;
 //main
   //finding if there is a ring
 ring:=findring(1,1);
 if ring<>0 then begin//if ringed then find for min and delele(min,max(l,r)).
                  for i:=ring-2 downto 1 do
                   begin               //finding for min...
                    if visited[ring]=visited[i]then break;
                    if ringmin>visited[i]then ringmin:=visited[i];
                   end;                //min found.then delete(min,max(l,r)).
                  map[visited[ring],max(visited[ring-1],visited[i+1])]:=f;
                  map[max(visited[ring-1],visited[i+1]),visited[ring]]:=f;
                 end;//then search.
   //no rings now.
 if ringmin=inf then ringmin:=1;
   //get answer
 ans(1);
 //file
 close(input);close(output);
end.
