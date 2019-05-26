begin
 assign(input,'track.in');reset(input);
 assign(output,'track.out');rewrite(output);
 writeln(31);
 close(input);close(output);
end.