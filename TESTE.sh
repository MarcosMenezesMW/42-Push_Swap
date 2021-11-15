#!/bin/sh

echo "Testing with 3 numbers"
ARG=$(python test.py 3 | tr [] " " | tr , " ")
echo $ARG
echo "Number of Movements"
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

echo "Testing with 5 numbers"
ARG=$(python test.py 5 | tr [] " " | tr , " ")
echo $ARG
echo "Number of Movements"
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

echo "Testing with 100 numbers"
ARG=$(python test.py 100 | tr [] " " | tr , " ")
echo $ARG
echo "Number of Movements"
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

echo "Testing with 500 numbers"
ARG=$(python test.py 500 | tr [] " " | tr , " ")
echo $ARG
echo "Number of Movements"
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

echo "Testing with 1000 numbers"
ARG=$(python test.py 1000 | tr [] " " | tr , " ")
echo $ARG
echo "Number of Movements"
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG
