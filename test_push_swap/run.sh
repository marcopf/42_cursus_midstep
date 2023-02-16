
for i in {1..1000}
do
	var=$(python3 random_number.py)
	./push_swap "${var}" | ./Checker_Mac "${var}"
done
