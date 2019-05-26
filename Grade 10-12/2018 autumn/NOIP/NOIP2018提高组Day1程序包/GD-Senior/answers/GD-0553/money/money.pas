Var
   T,n,i,j,k,max,m:longint;
   a:array[1..1000] of longint;
   b,been:array[1..100000] of boolean;

procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

Begin
    assign(input,'money.in'); reset(input);
    assign(output,'money.out'); rewrite(output);

    read(T);
    while T>0 do
      begin
          T:=T-1;
          read(n); m:=0;
          for i:=1 to n do read(a[i]);
          sort(1,n);
          fillchar(b,sizeof(b),false);
          max:=a[n];

          for i:=1 to n do
            begin
                if not b[a[i]] then
                  begin
                      fillchar(been,sizeof(been),false);

                      j:=a[i];
                      while j<=max do
                        begin
                            b[j]:=true;
                            been[j]:=true;
                            j:=j+a[i];
                        end;

                      for k:=1 to max do if not been[k] and b[k] then
                        begin
                            been[k]:=true;
                            j:=a[i];
                            while k+j<=max do
                              begin
                                  b[k+j]:=true;
                                  been[k+j]:=true;
                                  j:=j+a[i];
                              end;
                        end;

                      m:=m+1;
                  end;
            end;
          writeln(m);
      end;

    close(input); close(output);
End.