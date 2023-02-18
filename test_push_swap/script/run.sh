
for i in {1..10}
do
	var=$(python3 random_number.py)
	./push_swap "${var}" > test.txt
       echo $var	
	cat test.txt | ./Checker_Mac "${var}"
	cat test.txt | wc -l
done
for i in {1..10}
do
	var=$(python3 random_number1-100.py)
	./push_swap "${var}" > test.txt
	cat test.txt | ./Checker_Mac "${var}"
	cat test.txt | wc -l
	
done
