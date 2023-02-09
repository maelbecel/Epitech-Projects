BOLD=" "
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
    $2 > /dev/null
    retrn=$?
    if [ "$retrn" != "$4" ]; then
        FAILED=$((FAILED+1))
        BLOC_FAILED=$((BLOC_FAILED+1))
        echo -e "$BOLD$RED        [KO]$DEFAULT Bad return, need '$4' but have '$retrn'"
    else
        RES=$($2)
        if [ "$RES" = "$3" ]; then
            PASSED=$((PASSED+1))
            BLOC_PASSED=$((BLOC_PASSED+1))
            echo -e "$BOLD$GREEN        [OK]$DEFAULT Test PASSED"
        else
            FAILED=$((FAILED+1))
            BLOC_FAILED=$((BLOC_FAILED+1))
            echo -e "$BOLD$RED        [KO]$DEFAULT Bad output, need '$3' but have '$RES'"
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

BANNEDSRC=$(cat solver/src/* generator/src/*  | grep -e ' printf(' -e ' strlen(' -e ' strcat(')
BANNEDLIB=$(cat lib/my/*  | grep -e ' printf(' -e ' strlen(' -e ' strcat(')
echo -e "\n ========================"
echo -e "$ORANGE$BOLD$UNDERLINE"
echo -e "Banned functions:$DEFAULT\n"
if [ -z "$BANNEDSRC" ] && [ -z "$BANNEDLIB" ]; then
    echo -e "$BOLD$GREEN\c"
    echo -e "No banned function used$DEFAULT"
else
    print_banned "src"
    print_banned "lib/my"
fi
echo -e "\n ========================\n"

############# Tests ##########

bloc Solver
    mouli "20x20" "./solver/solver 20x20.txt" \
"ooooo***************
*X*XoXXXXXXXXXXXXXXX
*X*Xooooo**********X
*XXX*X*XoXXX*X*X*X*X
***X*X*Xo**X*X*X*X*X
*XXX*XXXoXXXXX*XXXXX
***X***XoooooX*****X
*XXX*XXX*XXXoXXX*XXX
***X***X***Xo**X***X
*X*X*XXX*X*XoXXX*X*X
*X*X***X*X*XoooX*X*X
*X*X*XXXXX*X*XoX*X*X
*X*X*****X*X*XoX*X*X
*XXXXXXX*X*XXXoXXXXX
*******X*X***Xo****X
*X*XXXXX*X*XXXoXXXXX
*X*****X*X***XoooooX
*X*XXXXX*X*XXX*X*XoX
*X*****X*X***X*X*XoX
*XXXXXXXXXXXXXXXXXoo" 0

    mouli "50x10" "./solver/solver 50x10.txt" \
"ooooooooooooooooooooooooo*************************
*XXXXXXXXXXX*XXXXXXXXX*XoXXXXXXXXXXXXX*X*X*X*X*X*X
***********X*********X*XoooooooooooooX*X*X*X*X*X*X
*XXXXX*X*XXXXXXX*X*X*XXXXXXX*X*X*XXXoXXX*XXX*X*XXX
*****X*X*******X*X*X*******X*X*X***XoooX***X*X***X
*X*XXXXX*X*X*XXXXX*XXX*X*X*X*X*XXXXXXXoXXXXXXX*XXX
*X*****X*X*X*****X***X*X*X*X*X*******XoooooooX***X
*XXXXXXXXX*XXXXXXX*XXXXXXXXX*XXX*X*XXXXX*X*XoXXXXX
*********X*******X*********X***X*X*****X*X*XoooooX
*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXoo" 0


mouli "100x30" "./solver/solver 100x30.txt" \
"ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo*********************
*X*XXX*X*X*XXXXX*XXXXXXXXXXX*XXXXXXXXX*X*XXXXXXXXX*XXX*X*X*XXX*XXX*XXXXX*X*X*XoXXXXX*X*X*X*X*X*XXXXX
*X***X*X*X*****X***********X*********X*X*********X***X*X*X***X***X*****X*X*X*Xo****X*X*X*X*X*X*****X
*XXX*XXX*XXX*XXX*X*X*XXX*XXXXXXX*XXXXX*X*X*XXX*XXXXX*XXXXXXX*X*XXXXXXXXX*XXXXXoXXXXXXX*X*X*XXX*X*XXX
***X***X***X***X*X*X***X*******X*****X*X*X***X*****X*******X*X*********X*****Xo******X*X*X***X*X***X
*X*XXXXX*X*X*X*XXX*XXX*X*X*XXXXX*XXXXXXX*X*X*XXX*X*X*X*X*X*XXX*X*X*XXX*XXXXX*XoXXXXX*XXX*XXXXX*XXX*X
*X*****X*X*X*X***X***X*X*X*****X*******X*X*X***X*X*X*X*X*X***X*X*X***X*****X*Xo****X***X*****X***X*X
*XXX*XXX*XXXXX*XXXXX*X*XXX*X*X*X*XXXXX*X*XXX*X*X*X*X*XXX*XXXXXXX*X*X*X*XXXXXXXoX*XXX*XXX*X*XXX*X*X*X
***X***X*****X*****X*X***X*X*X*X*****X*X***X*X*X*X*X***X*******X*X*X*X*******XoX***X***X*X***X*X*X*X
*X*XXXXX*X*XXX*XXXXXXXXX*XXXXX*X*X*XXXXX*XXX*X*X*X*X*XXXXX*XXX*X*XXXXXXXXX*XXXoXXXXXXXXX*X*XXX*X*X*X
*X*****X*X***X*********X*****X*X*X*****X***X*X*X*X*X*****X***X*X*********X***Xooo******X*X***X*X*X*X
*X*XXX*X*XXX*XXX*XXXXXXXXX*X*X*XXXXX*X*X*XXXXXXX*X*X*XXX*X*XXX*XXX*X*XXXXX*X*XXXoX*XXXXX*XXX*XXXXX*X
*X***X*X***X***X*********X*X*X*****X*X*X*******X*X*X***X*X***X***X*X*****X*X***XoX*****X***X*****X*X
*XXX*XXX*X*XXX*X*XXXXXXXXX*X*XXXXXXX*X*XXX*X*X*XXX*XXXXXXX*X*X*XXX*XXX*X*X*X*X*XoXXX*XXXXX*XXXXXXXXX
***X***X*X***X*X*********X*X*******X*X***X*X*X***X*******X*X*X***X***X*X*X*X*X*XoooX*****X*********X
*X*XXXXX*X*XXX*X*X*X*X*X*X*X*X*X*X*X*X*XXX*X*XXX*XXXXXXX*X*X*XXXXXXX*XXXXXXXXXXXXXoXXX*X*XXX*X*X*X*X
*X*****X*X***X*X*X*X*X*X*X*X*X*X*X*X*X***X*X***X*******X*X*X*******X*************XoooX*X***X*X*X*X*X
*XXXXX*X*XXX*XXX*X*XXX*X*X*XXX*X*X*X*XXX*XXXXXXXXXXXXXXXXXXX*X*X*XXX*X*X*X*XXX*XXX*XoXXXXXXXXXXXXXXX
*****X*X***X***X*X***X*X*X***X*X*X*X***X*******************X*X*X***X*X*X*X***X***X*Xooooooooo******X
*XXXXX*XXX*XXX*X*XXXXX*XXXXXXXXXXXXX*X*XXXXX*XXX*XXX*XXX*XXXXXXXXX*XXX*X*X*X*X*XXXXX*X*X*XXXoXXX*X*X
*****X***X***X*X*****X*************X*X*****X***X***X***X*********X***X*X*X*X*X*****X*X*X***Xo**X*X*X
*XXXXXXX*XXXXX*X*XXX*XXX*XXXXXXXXX*X*XXX*XXX*XXX*X*X*X*XXXXX*X*X*XXXXXXX*X*XXX*X*XXX*X*X*XXXoXXXXX*X
*******X*****X*X***X***X*********X*X***X***X***X*X*X*X*****X*X*X*******X*X***X*X***X*X*X***Xooo**X*X
*X*XXX*XXXXX*XXXXXXX*XXXXXXX*XXX*X*XXXXXXXXXXXXX*XXX*X*XXX*X*XXX*XXX*XXXXX*X*X*X*XXX*XXX*X*X*XoXXX*X
*X***X*****X*******X*******X***X*X*************X***X*X***X*X***X***X*****X*X*X*X***X***X*X*X*XoooX*X
*X*XXX*XXXXX*XXXXXXXXXXX*XXXXX*X*X*XXXXX*XXX*X*X*X*XXXXX*X*XXXXX*X*X*XXX*X*X*XXXXX*XXXXXXX*X*X*XoXXX
*X***X*****X***********X*****X*X*X*****X***X*X*X*X*****X*X*****X*X*X***X*X*X*****X*******X*X*X*XoooX
*X*X*XXXXX*XXX*XXXXX*X*X*X*XXX*XXXXX*XXX*XXXXXXXXXXXXXXXXXXX*X*X*X*XXXXX*X*XXX*XXXXX*XXXXXXX*X*X*XoX
*X*X*****X***X*****X*X*X*X***X*****X***X*******************X*X*X*X*****X*X***X*****X*******X*X*X*XoX
*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXoo" 0
end

############# Display #########

displayres
