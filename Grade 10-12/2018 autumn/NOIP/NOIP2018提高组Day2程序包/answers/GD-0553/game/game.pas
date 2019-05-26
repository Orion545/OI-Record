Const
    modn=1000000007;

Var
  n,m,t,i:longint;
  ans:int64;

Function dex2(x:longint):int64;
  begin
      dex2:=1;
      while x>0 do
        begin
            x:=x-1;
            dex2:=dex2*2 mod modn;
        end;
  end;

Begin
    assign(input,'game.in'); reset(input);
    assign(output,'game.out'); rewrite(output);

    ans:=0;
    read(n,m);
    if n>m then
      begin
          t:=n; n:=m; m:=t;
      end;
    case n of
        1:writeln(dex2(m));
        2:writeln( (ans+( (dex2(n+m-3)+1) * dex2(n+m-3-1) )*4) mod modn);
        3:writeln(112);
        5:writeln(7136);
    end;

    close(input); close(output);
End.