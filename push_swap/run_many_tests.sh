#!/bin/bash
LIMIT=12
MAX_OPS=0
MAX_ARG=0
TOTAL=0
BOLD=$(tput bold)
LIGHT_GREEN='\033[1;32m'
PURPLE='\033[0;35m'
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'

echo "25 Tests Commencing.."
for i in {1..25}
do
	ARG=$(sh GenRandNums.sh)
	echo "${PURPLE}Trial: $i${NC}"
	printf "Number of operations needed: " 
	NUM=$(./push_swap $ARG | wc -l)
	TOTAL=$((TOTAL+$NUM))
	if [[ "$NUM" -gt $MAX_OPS ]] 
	then
		MAX_OPS=$NUM	
		MAX_ARG=$ARG
	fi
	if [[ "$NUM" -gt 12 ]] 
	then
		echo "${RED}Your program took $NUM operations; The limit is $LIMIT!${NC}"
		echo "Here's the Arg: $ARG"
		continue
	fi	
	echo "${BOLD}${BLUE}$NUM${NC}"
	printf "Checker: "
	RES=$(./push_swap $ARG | ./checker $ARG)
	if [ "$RES" == "OK" ]
	then
		echo ${LIGHT_GREEN}"SUCCESS for Trial $i!${NC}"
	elif [ "$RES" == "KO" ]
	then
		echo ${RED}"FAILURE for Trial $i!${NC}"
	fi
	echo "------------------------------"
done
echo "--------------------------------"
echo "Avg operations: ${PURPLE}$((TOTAL/25))${NC}"
echo "Max num of operations: ${PURPLE}$((MAX_OPS))${NC}"
echo "Max arg: ${PURPLE}$MAX_ARG${NC}"
