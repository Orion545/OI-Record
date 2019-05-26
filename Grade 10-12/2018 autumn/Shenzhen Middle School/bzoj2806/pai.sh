while true; do
	./gen > gen.in
	./std < gen.in > std.out
	./t1 < gen.in > my.out
	if diff my.out std.out; then
		printf "AC\n"
	else
		printf "WA\n"
		exit 0
	fi
done
