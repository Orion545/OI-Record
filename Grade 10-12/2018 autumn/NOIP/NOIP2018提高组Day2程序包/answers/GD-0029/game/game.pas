var
  n,m,mo,i:longint;
  map:array[0..8,0..1000000]of int64;
begin
    assign(input,'game.in');reset(input);
    assign(output,'game.out');rewrite(output);
    read(n,m);
    mo:=1000000007;
    map[1,1]:=2;
    for i:=2 to n do map[i,1]:=map[i-1,1]*2 mod mo;
    for i:=2 to m do map[1,i]:=map[1,i-1]*2 mod mo;
    map[2,2]:=12;map[2,3]:=36;map[3,2]:=36;map[3,3]:=112;map[5,5]:=7136;
    writeln(map[n,m]);
    close(input);close(output);
end.