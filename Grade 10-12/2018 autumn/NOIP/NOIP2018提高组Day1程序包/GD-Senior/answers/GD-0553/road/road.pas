Var
    n,i,ans:longint;
    a:array[0..1001000] of longint;
    t,p:boolean;

Begin
    assign(input,'road.in'); reset(input);
    assign(output,'road.out'); rewrite(output);

    readln(n);
    for i:=1 to n do read(a[i]);
    ans:=0;
    t:=true;
    a[0]:=0; a[n+1]:=0;

    for i:=0 to n do
      begin
          if t then
            begin
                if a[i]>a[i+1] then
                  begin
                      ans:=ans+a[i];
                      t:=false;
                      p:=false;
                      continue;
                  end;
            end;

          if not t then
            begin
                if a[i]<a[i+1] then
                  begin
                      ans:=ans-a[i];
                      t:=true;
                  end;
            end;
      end;

    writeln(ans);
    close(input); close(output);
End.