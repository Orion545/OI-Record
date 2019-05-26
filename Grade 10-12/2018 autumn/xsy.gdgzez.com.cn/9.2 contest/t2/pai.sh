while true; do
	./gen > gen.in
	./t2 < gen.in > my.out
	./brute < gen.in > std.out
	if diff my.out std.out; then
		printf "AC\n"
	else
		printf "WA\n"
		exit 0
	fi
done
