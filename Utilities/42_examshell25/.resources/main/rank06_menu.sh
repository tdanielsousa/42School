#!/bin/bash
source colors.sh

clear
printf "${CYAN}%s${RESET}\n" "╔═══════════════════════════════════════════════════════════╗"
printf "${BLUE}%s${GREEN}%s${BLUE}%s${RESET}\n" "║" "            📄 EXAM RANK 06 - MODE SELECTION            " "║"
printf "${CYAN}%s${RESET}\n" "╚═══════════════════════════════════════════════════════════╝"
printf "${YELLOW}${BOLD}%s${RESET}\n" "1. Level Mode"
printf "${YELLOW}${BOLD}%s${RESET}\n" "2. Real Exam Mode"
printf "${YELLOW}${BOLD}%s${RESET}\n" "3. Back to Main Menu"
printf "${GREEN}${BOLD}Enter your choice (1-3): ${RESET}"
read rank06_opt
case $rank06_opt in
    1)
        bash rank06_level.sh rank06
        ;;
    2)
        bash rank06.sh
        ;;
    3)
        bash intro.sh
        ;;
    *)
        echo "Invalid choice. Please enter 1, 2, or 3."
        sleep 1
        bash rank06_menu.sh
        ;;
esac
