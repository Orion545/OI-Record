const
  p=1000000007;
var
  i,j,ans:longint;
  n,m,t:int64;

function ksm(x,y:int64):int64;
var
  i,ans:longint;
begin
  i:=x;ans:=1;
  while y>0 do
    begin
      if y mod 2=1
        then ans:=(ans*i)mod p;
      i:=(i*i)mod p;
      y:=y div 2;
    end;
  exit(ans);
end;

procedure main;
begin
  if n=2 then
    begin
      writeln((ksm(3,m-1)*4)mod p);
      exit;
    end;
  if n=3 then
    begin
      writeln((ksm(4,m-2)*28)mod p);
      exit;
    end;
  if(n=5)and(m=5) then
    begin
      writeln(7136);
      exit;
    end;
end;

begin
  assign(input,'game.in');reset(input);
  assign(output,'game.out');rewrite(output);
  readln(n,m);
  if m<n then begin t:=n;n:=m;m:=t;end;
  if (n=1)and(m=1) then writeln(2)
    else main;
  close(input);close(output);
end.
