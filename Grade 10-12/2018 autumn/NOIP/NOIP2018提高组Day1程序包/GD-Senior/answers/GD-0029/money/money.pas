var
  t,l,n,i,j,tot,max:longint;
  f:array[-30000..30000]of longint;
  a:array[0..30000]of longint;
begin
    assign(input,'money.in');reset(input);
    assign(output,'money.out');rewrite(output);
    read(t);
    for l:=1 to t do begin
        read(n);
        fillchar(f,sizeof(f),0);
        max:=0;
        for i:=1 to n do begin
            read(a[i]);
            f[a[i]]:=1;
            if max<=a[i] then max:=a[i];
        end;
        for i:=1 to max do
          for j:=1 to n do if f[i-a[j]]>=1 then f[i]:=2;
        tot:=0;
        for i:=1 to n do if f[a[i]]>1 then inc(tot);
        writeln(n-tot);
    end;
    close(input);close(output);
end.
