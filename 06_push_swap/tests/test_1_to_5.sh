#!/bin/bash

NAME_PUSHSWAP="./push_swap"
NAME_CHECKER_OWN="./checker"
NAME_CHECKER_42="./checker_linux"

limit_2=5
limit_3=5
limit_4=12
limit_5=12

green="\e[32m"
red="\e[31m"
reset="\e[0m"

combinations_2=(
	"0 1"
	"1 0"
)

combinations_3=(
	"0 1 2"
    "0 2 1"
    "1 0 2"
    "1 2 0"
    "2 0 1"
    "2 1 0"
)

combinations_4=(
    "0 1 2 3"
    "0 1 3 2"
    "0 2 1 3"
    "0 2 3 1"
    "0 3 1 2"
    "0 3 2 1"
    "1 0 2 3"
    "1 0 3 2"
    "1 2 0 3"
    "1 2 3 0"
    "1 3 0 2"
    "1 3 2 0"
    "2 0 1 3"
    "2 0 3 1"
    "2 1 0 3"
    "2 1 3 0"
    "2 3 0 1"
    "2 3 1 0"
    "3 0 1 2"
    "3 0 2 1"
    "3 1 0 2"
    "3 1 2 0"
    "3 2 0 1"
    "3 2 1 0"
)

combinations_5=(
    "0 1 2 3 4"
    "0 1 2 4 3"
    "0 1 3 2 4"
    "0 1 3 4 2"
    "0 1 4 2 3"
    "0 1 4 3 2"
    "0 2 1 3 4"
    "0 2 1 4 3"
    "0 2 3 1 4"
    "0 2 3 4 1"
    "0 2 4 1 3"
    "0 2 4 3 1"
    "0 3 1 2 4"
    "0 3 1 4 2"
    "0 3 2 1 4"
    "0 3 2 4 1"
    "0 3 4 1 2"
    "0 3 4 2 1"
    "0 4 1 2 3"
    "0 4 1 3 2"
    "0 4 2 1 3"
    "0 4 2 3 1"
    "0 4 3 1 2"
    "0 4 3 2 1"
    "1 0 2 3 4"
    "1 0 2 4 3"
    "1 0 3 2 4"
    "1 0 3 4 2"
    "1 0 4 2 3"
    "1 0 4 3 2"
    "1 2 0 3 4"
    "1 2 0 4 3"
    "1 2 3 0 4"
    "1 2 3 4 0"
    "1 2 4 0 3"
    "1 2 4 3 0"
    "1 3 0 2 4"
    "1 3 0 4 2"
    "1 3 2 0 4"
    "1 3 2 4 0"
    "1 3 4 0 2"
    "1 3 4 2 0"
    "1 4 0 2 3"
    "1 4 0 3 2"
    "1 4 2 0 3"
    "1 4 2 3 0"
    "1 4 3 0 2"
    "1 4 3 2 0"
    "2 0 1 3 4"
    "2 0 1 4 3"
    "2 0 3 1 4"
    "2 0 3 4 1"
    "2 0 4 1 3"
    "2 0 4 3 1"
    "2 1 0 3 4"
    "2 1 0 4 3"
    "2 1 3 0 4"
    "2 1 3 4 0"
    "2 1 4 0 3"
    "2 1 4 3 0"
    "2 3 0 1 4"
    "2 3 0 4 1"
    "2 3 1 0 4"
    "2 3 1 4 0"
    "2 3 4 0 1"
    "2 3 4 1 0"
    "2 4 0 1 3"
    "2 4 0 3 1"
    "2 4 1 0 3"
    "2 4 1 3 0"
    "2 4 3 0 1"
    "2 4 3 1 0"
    "3 0 1 2 4"
    "3 0 1 4 2"
    "3 0 2 1 4"
    "3 0 2 4 1"
    "3 0 4 1 2"
    "3 0 4 2 1"
    "3 1 0 2 4"
    "3 1 0 4 2"
    "3 1 2 0 4"
    "3 1 2 4 0"
    "3 1 4 0 2"
    "3 1 4 2 0"
    "3 2 0 1 4"
    "3 2 0 4 1"
    "3 2 1 0 4"
    "3 2 1 4 0"
    "3 2 4 0 1"
    "3 2 4 1 0"
    "3 4 0 1 2"
    "3 4 0 2 1"
    "3 4 1 0 2"
    "3 4 1 2 0"
    "3 4 2 0 1"
    "3 4 2 1 0"
    "4 0 1 2 3"
    "4 0 1 3 2"
    "4 0 2 1 3"
    "4 0 2 3 1"
    "4 0 3 1 2"
    "4 0 3 2 1"
    "4 1 0 2 3"
    "4 1 0 3 2"
    "4 1 2 0 3"
    "4 1 2 3 0"
    "4 1 3 0 2"
    "4 1 3 2 0"
    "4 2 0 1 3"
    "4 2 0 3 1"
    "4 2 1 0 3"
    "4 2 1 3 0"
    "4 2 3 0 1"
    "4 2 3 1 0"
    "4 3 0 1 2"
    "4 3 0 2 1"
    "4 3 1 0 2"
    "4 3 1 2 0"
    "4 3 2 0 1"
    "4 3 2 1 0"
)

for ((N=2; N<=5; N++)); do

	cur_comb="combinations_$N[@]"
	cur_limit="limit_$N"

	echo -e "\n$N NUMBERS | LIMIT: ${!cur_limit}\n---------------------"
	for comb in "${!cur_comb}"; do
	    count_actions=$($NAME_PUSHSWAP $comb | wc -l)
		res_checker_42=$($NAME_PUSHSWAP $comb | $NAME_CHECKER_42 $comb)
		res_checker_own=$($NAME_PUSHSWAP $comb | $NAME_CHECKER_OWN $comb)

	#check if limit is fine
			if [[ $count_actions -le ${!cur_limit} ]]; then
				echo -ne "$comb -> | count: ${green}$(printf "%02d" "$count_actions")${reset}"
			else
				echo -ne "${red}$comb -> $count_actions${reset}"
			fi

	#check if 42 checker is fine
			if [[ $res_checker_42 == "OK" ]]; then
				echo -ne " | 42 checker: ${green}OK${reset}"
			else
				echo -ne " | 42 checker: ${red}KO${reset}"
			fi

	#check if own checker is fine
			if [[ $res_checker_own == $res_checker_42 ]]; then
				echo -e " | own checker is working?: ${green}YES${reset}"
			else
				echo -e " | own checker is working?: ${red}NO${reset}"
			fi
	done
done