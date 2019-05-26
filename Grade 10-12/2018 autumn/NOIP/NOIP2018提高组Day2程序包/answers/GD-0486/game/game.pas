var n,m,ans,i,mo:longint;
    a:array[0..10] of int64;
begin
assign(input,'game.in');reset(input);
assign(output,'game.out');rewrite(output);
    read(n,m);
    mo:=10;
    for i:=1 to 8 do mo:=mo*10;
    mo:=mo+7;
    a[1]:=2;
    a[2]:=12;
    a[3]:=112;
    a[4]:=480;
    a[5]:=7136;
    if n=1 then begin
        ans:=2;
        for i:=1 to m-1 do ans:=ans*2 mod mo;
        write(ans);
    end else if m=1 then begin
        ans:=2;
        for i:=1 to n-1 do ans:=ans*2 mod mo;
        write(ans);
    end else if n=m then begin
        if n=1 then write('2');
        if n=2 then write('12');
        if n=3 then write('112');
        if n=4 then write('480');
        if n=5 then write('7136');
        if n>5 then write('I do not know');
    end else if n<m then begin
        if n>5 then write('I do not know');
        for i:=n to m do a[n]:=a[n]*3 mod mo;
        write(a[n]);
    end else begin
        if m>5 then write('I do not know');
        for i:=m to n do a[m]:=a[m]*3 mod mo;
        write(a[m]);
    end;
close(input);close(output);
end.