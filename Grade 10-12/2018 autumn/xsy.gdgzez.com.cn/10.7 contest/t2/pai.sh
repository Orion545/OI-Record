while true; do
	./gen > data.in
	./t2 < data.in > my.out
	./std < data.in > std.out
	if diff my.out std.out; then
		printf "AC\n"
	else
		printf "WA\n"
		exit 0
	fi
done
