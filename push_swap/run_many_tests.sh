for i in {1..10}
do
	ARG=$(sh GenRandNums.sh)
	echo "Random numbers stored in ARG for Trial $i"
	echo "Number of operations needed: "
	./push_swap $ARG | wc -l
	echo "Checker: "
	./push_swap $ARG | ./checker $ARG
done
