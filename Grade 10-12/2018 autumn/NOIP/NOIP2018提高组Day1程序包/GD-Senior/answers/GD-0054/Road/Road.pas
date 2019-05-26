const
 inf=10001;
var
 n:integer;
 d,d0:integer;
 i:integer;
 min,max,ans:integer;
begin
 assign(input,'road.in');reset(input);
 assign(output,'road.out');rewrite(output);
 readln(n);
 d:=0;
 min:=inf;max:=0;
 ans:=0;
 for i:=1 to n do
  begin
   d0:=d;
   read(d);
   if d<=d0 then begin
                  min:=d;
                 end
            else begin
                  if min<>inf then begin ans:=ans+max-min;min:=inf;end;
                  max:=d;
                 end;
  end;
 writeln(ans+max);
 close(input);close(output);
end.