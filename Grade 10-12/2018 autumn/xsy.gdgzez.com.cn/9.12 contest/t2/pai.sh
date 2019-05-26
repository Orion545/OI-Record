while true; do
	./gen > b.in
	python3 BB.py
	./t2 < b.in > my.out
	if diff my.out std.out; then
		printf "ac\n"
	else 
		printf "wa\n"
		exit 0
	fi
done
