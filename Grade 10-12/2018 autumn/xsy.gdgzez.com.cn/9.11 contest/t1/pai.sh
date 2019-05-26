while true; do
	./gen > data.in
	./std < data.in > std.out
	./t1 < data.in > my.out
	if diff std.out my.out; then
		printf "AC\n"
	else
		printf "WA\n"
		exit 0
	fi
done
