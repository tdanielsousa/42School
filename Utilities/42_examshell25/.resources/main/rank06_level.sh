#!/bin/bash
source colors.sh

rank=$1

base_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Set question array for rank06
qsub=(mini_db mini_serv)

# Shuffle questions manually
shuffle_array() {
    local i tmp size max rand
    size=${#qsub[*]}
    max=$(( 32768 / size * size ))

    for ((i = size - 1; i > 0; i--)); do
        while (( (rand = RANDOM) >= max )); do :; done
        rand=$(( rand % (i + 1) ))
        tmp=${qsub[i]}
        qsub[i]=${qsub[rand]}
        qsub[rand]=$tmp
    done
    shuffled=("${qsub[@]}")
}

shuffle_array
num=${#shuffled[@]}
i=0
mkdir -p "$base_dir/../../rendu"

while true; do
    current_subject="${shuffled[$i]}"
    subject_dir="$base_dir/../$rank/$current_subject"
    
    # Check if subject directory exists
    if [ ! -d "$subject_dir" ]; then
        echo -e "${RED}Error: Subject directory not found: $subject_dir${RESET}"
        exit 1
    fi
    
    cd "$subject_dir" || {
        echo -e "${RED}Error: Cannot change to subject directory${RESET}"
        exit 1
    }
    
    mkdir -p "$base_dir/../../rendu/$current_subject"

    # Create question files if needed
    if [[ "$current_subject" == "mini_db" ]]; then
        touch "$base_dir/../../rendu/$current_subject/mini_db.cpp"
        touch "$base_dir/../../rendu/$current_subject/mini_db.hpp"
    elif [[ "$current_subject" == "mini_serv" ]]; then
        touch "$base_dir/../../rendu/$current_subject/mini_serv.c"
    fi

    # Read subject question
    if [ ! -f "sub.txt" ]; then
        echo -e "${RED}Error: sub.txt not found in $subject_dir${RESET}"
        exit 1
    fi
    
    subject=$(cat sub.txt)

    # Check if all questions are completed
    if [ $i -ge $num ]; then
        clear
        echo "These questions are completed."
        echo "=============================================="
        read -rp "${GREEN}${BOLD}Please press enter for return to the menu.${RESET}" enterx
        sleep 2
        cd ../../main
        bash menu.sh
        exit
    fi

    # Inner loop for testing or navigating
    while true; do
        clear
        echo -e "${WHITE}$subject${RESET}"
        echo
        echo "Please type 'test' to test code, 'next' for next or 'exit' for exit."
        echo
        read -rp "/>" input
        case $input in
            next)
                i=$((i+1))
                break
                ;;
            test)
                clear
                if [ -f "./tester.sh" ]; then
                    ./tester.sh &
                    pid=$!
                    slept=0

                    while [ $slept -lt 10 ] && kill -0 $pid 2>/dev/null; do
                        sleep 1
                        slept=$((slept+1))
                    done

                    if kill -0 $pid 2>/dev/null; then
                        echo "$(tput setaf 1)$(tput bold)TIMEOUT$(tput sgr 0)"
                        echo "It can be because of infinite loop ∞"
                        echo "Please check your code or just try again."
                        kill $pid 2>/dev/null
                    fi
                else
                    echo "No tester.sh found. Please test manually."
                fi

                echo "=============================================="
                read -rp "${GREEN}${BOLD}Please press enter to continue your practice.${RESET}" enter
                break
                ;;
            menu)
                cd ../../../../
                if [ -d rendu ]; then
                    mkdir -p trace
                    cp -r rendu "trace/rendu_backup_$(date +%s)"
                    rm -rf rendu
                fi
                cd .resources/main
                bash menu.sh
                exit
                ;;
            exit)
                cd ../../../../
                if [ -d rendu ]; then
                    mkdir -p trace
                    cp -r rendu "trace/rendu_backup_$(date +%s)"
                    rm -rf rendu
                fi
                exit 1
                ;;
            *)
                echo "Please type 'test' to test code, 'next' for next or 'exit' to quit."
                ;;
        esac
    done
done
