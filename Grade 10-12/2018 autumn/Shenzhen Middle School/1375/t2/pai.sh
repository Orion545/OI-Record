while true; do
	./gen > in.in
	./t2 < in.in > my.out
	./tt2 < in.in > std.out
	if diff my.out std.out; then
		printf "AC\n"
	else 
		printf "WA\n"
		exit 0
	fi
done
