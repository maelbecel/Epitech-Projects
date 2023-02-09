BOLD="\e[1m"
UNDERLINE="\e[4m"
DEFAULT="\e[0m"
PURPLE="\e[49;36m"
GREEN="\e[49;92m"
RED="\e[49;91m"
ORANGE="\e[49;93m"

print_banned() {
    for file in "$1"/* ; do
        if [[ ! -z $(grep -in ' printf(' $file) ]]; then
            echo -e "$RED$BOLD[$file\c"
            grep -in ' printf(' $file | awk -F: '{printf ":L"$1"]"}'
            echo -e "$DEFAULT$BOLD : printf() function banned.$DEFAULT"
        fi
        if [[ ! -z $(grep -in ' strlen(' $file) ]]; then
            echo -e "$RED$BOLD[$file\c"
            grep -in ' strlen(' $file | awk -F: '{printf ":L"$1"]"}'
            echo -e "$DEFAULT$BOLD : strlen() function banned.$DEFAULT"
        fi
        if [[ ! -z $(grep -in ' strcat(' $file) ]]; then
            echo -e "$RED$BOLD[$file\c"
            grep -in ' strcat(' $file | awk -F: '{printf ":L"$1"]"}'
            echo -e "$DEFAULT$BOLD : strcat() function banned.$DEFAULT"
        fi
    done
}

showbar() {
    have=$1
    on=$2
    len=$3

    percentage=$((have*100/on))
    valid=$((percentage*len/100))
    invalid=$((len-valid))
    echo -e " $GREEN\c"
    perl -E "print '█' x $valid"
    echo -e "$DEFAULT$RED\c"
    perl -E "print '█' x $invalid"
    echo -e " $DEFAULT$BOLD$percentage$DEFAULT%"
}

bloc() {
    echo -e " $ORANGE$BOLD$UNDERLINE$1$DEFAULT\n"
}

end() {
    echo ""
    echo -e " \c"
    showbar $BLOC_PASSED $BLOC_TOTAL 20
    echo -e "\n ========================\n"
    BLOC_TOTAL=0
    BLOC_PASSED=0
    BLOC_FAILED=0
}

mouli() {
    TOTAL=$((TOTAL+1))
    BLOC_TOTAL=$((BLOC_TOTAL+1))
    echo -e "$BOLD    Test $BLOC_TOTAL :'$1' $DEFAULT"
    $3 > /dev/null
    retrn=$?
    if [ "$retrn" != "$5" ]; then
        FAILED=$((FAILED+1))
        BLOC_FAILED=$((BLOC_FAILED+1))
        echo -e "$BOLD$RED        [KO]$DEFAULT Bad return, need '$5' but have '$retrn'"
    else
        RES=$2
        # RES=$(echo '' | ./pushswap_checker 6 5 2)
        if [ "$RES" = "$4" ]; then
            PASSED=$((PASSED+1))
            BLOC_PASSED=$((BLOC_PASSED+1))
            echo -e "$BOLD$GREEN        [OK]$DEFAULT Test PASSED"
        else
            FAILED=$((FAILED+1))
            BLOC_FAILED=$((BLOC_FAILED+1))
            echo -e "$BOLD$RED        [KO]$DEFAULT Bad output, need '$4' but have '$RES'"
        fi
    fi
    echo ""
}

displayres() {
    showbar $PASSED $TOTAL 33
    echo  ""
    echo -e "$PURPLE TOTAL $BOLD$TOTAL$DEFAULT |$GREEN PASSED $BOLD$PASSED$DEFAULT |$RED FAILED $BOLD$FAILED$DEFAULT"
    echo -e "$BOLD ====================================$DEFAULT"
}

############# INIT ##########

TOTAL=0
PASSED=0
FAILED=0

BLOC_TOTAL=0
BLOC_PASSED=0
BLOC_FAILED=0

make re > /dev/null
make clean > /dev/null

if [ "$1" = "-n" ]; then
    NORME=$(normez -i)
    echo -e "\n ========================"
    echo -e "$ORANGE$BOLD$UNDERLINE"
    echo -e "Norme:$DEFAULT\n"
    if [ -z "$NORME" ]; then
        echo -e "$BOLD$GREEN\c"
        echo -e "No faults$DEFAULT"
    else
        normez -i
    fi
fi

if [ "$1" = "-b" ]; then
    echo -e "\n ========================"
    echo -e "$ORANGE$BOLD$UNDERLINE"
    echo -e "Norme:$DEFAULT\n"
    bubulle -ii -ic -f
fi

echo -e "\n ======================== \n"

############# Tests ##########

# mouli TestName ActualResult Command NeededResult Return

bloc "Basic command"
    mouli "sa" "$(echo 'sa' | ./pushswap_checker 2 1 3)" 'echo "sa" | ./pushswap_checker 2 1 3' "OK" 0
    mouli "sb" "$(echo 'sb' | ./pushswap_checker 1 2 3)" 'echo "sb" | ./pushswap_checker 1 2 3' "OK" 0
    mouli "sc" "$(echo 'sc' | ./pushswap_checker 2 1 3)" 'echo "sc" | ./pushswap_checker 2 1 3' "OK" 0
    mouli "pa" "$(echo 'pb pa' | ./pushswap_checker 1 2 3)" 'echo "pb pa" | ./pushswap_checker 1 2 3' "OK" 0
    mouli "pb" "$(echo 'pb pa' | ./pushswap_checker 1 2 3)" 'echo "pb pa" | ./pushswap_checker 1 2 3' "OK" 0
    mouli "ra" "$(echo 'ra' | ./pushswap_checker 3 1 2)" 'echo "ra" | ./pushswap_checker 3 1 2' "OK" 0
    mouli "rb" "$(echo 'rb' | ./pushswap_checker 1 2 3)" 'echo "rb" | ./pushswap_checker 1 2 3' "OK" 0
    mouli "rr" "$(echo 'rr' | ./pushswap_checker 3 1 2)" 'echo "rr" | ./pushswap_checker 3 1 2' "OK" 0
    mouli "rra" "$(echo 'rra' | ./pushswap_checker 2 3 1)" 'echo "rra" | ./pushswap_checker 2 3 1' "OK" 0
    mouli "rrb" "$(echo 'rrb' | ./pushswap_checker 1 2 3)" 'echo "rrb" | ./pushswap_checker 1 2 3' "OK" 0
    mouli "rrr" "$(echo 'rrr' | ./pushswap_checker 2 3 1)" 'echo "rrr" | ./pushswap_checker 2 3 1' "OK" 0
end

bloc "Invalid Test"
    mouli "Empty List" "$(echo '' | ./pushswap_checker 6 5 2)" 'echo "pa" | ./pushswap_checker 6 5 2' "KO" 0
    mouli "Bad Order" "$(echo 'pa sa' | ./pushswap_checker 6 5 2)" 'echo "pa" | ./pushswap_checker 6 5 2' "KO" 0
    mouli "Not Empty List B" "$(echo 'pb' | ./pushswap_checker 6 5 2)" 'echo "pa" | ./pushswap_checker 6 5 2' "KO" 0
end

bloc "Error Test"
    mouli "Bad Operator" "$(echo 'bangarang ' | ./pushswap_checker 6 5 2)" 'echo "bangarang" | ./pushswap_checker 6 5 2' "" 0
    mouli "Bad Number" "$(echo 'pa pb' | ./pushswap_checker "six" 5 2)" 'echo "bangarang" | ./pushswap_checker "six" 5 2' "" 0
end



############# Display #########

displayres
