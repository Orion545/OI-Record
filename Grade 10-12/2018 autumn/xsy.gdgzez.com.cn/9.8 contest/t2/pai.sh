while true; do
	./gen > data.in
	./t22 < data.in > my.out
	./std < data.in > std.out
	if diff std.out my.out;then
		printf "AC\n"
	else
		printf "WA\n"
		exit 0
	fi
done
