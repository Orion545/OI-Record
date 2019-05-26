Var
    n,m,rbq,r1,b1,r2,b2,i,j:longint;
    f:array[1..100050,0..1] of longint;
    a:array[1..100050] of longint;

Begin
    readln(n,m);
    for i:=1 to n do read(a[i]);
    for i:=1 to n-1 do read(rbq,rbq);
    f[1,0]:=0; f[1,1]:=a[1];
    for i:=1 to m do
      begin
          read(r1,b1,r2,b2);
          for i:=1 to n-1 do
            begin
                if (i=r1) and (b1=1) then
                  then begin
                      if (i+1=r2)
                  end;
            end;
      end;
End.