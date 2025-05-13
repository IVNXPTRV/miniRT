#!/bin/bash

# Courtesy of ChatGPT

GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m"

TESTS="$(cd "$(dirname "$0")/../" && pwd)/tests"
TEST_LIST="$TESTS/test_list.txt"
BIN="$(cd "$(dirname "$0")/../" && pwd)/miniRT"

USE_VALGRIND=0
VERBOSE=0
ONLY_WRONG=0
FILTER=""

OK=0
KO=0
i=1

# ──────── 🔧 Argument Handling ──────── #

for arg in "$@"; do
    if [[ "$arg" == "--help" || "$arg" == "-h" ]]; then
        echo "Usage: ./test.sh [-h | --help] [-v | --verbose] [-o | --only-wrong] [-g | --valgrind] [filter]"
        exit 0
    elif [[ "$arg" == "--verbose" || "$arg" == "-v" ]]; then
        VERBOSE=1
    elif [[ "$arg" == "--only-wrong" || "$arg" == "-o" ]]; then
        ONLY_WRONG=1
    elif [[ "$arg" == "--valgrind" || "$arg" == "-g" ]]; then
        USE_VALGRIND=1
    else
        FILTER="$arg"  # Assume any other arg is a filter pattern
    fi
done

# ──────── ✅ Core Functions ──────── #

print_result() {
    local index=$1
    local path=$2
    local result=$3
    local expected=$4
    local output=$5

    if [[ "$result" == "OK" ]]; then
        echo -e "$index. $path ${GREEN}OK${NC}"
        if [[ $VERBOSE -eq 1 ]]; then
            echo -e "$output"
            echo "------------------------------------------"
        fi
    else
        echo -e "$index. $path ${RED}KO${NC}"
        echo -e "> Expected:\n$expected"
        echo -e "> Got:\n$output"
        echo "------------------------------------------"
    fi
}

run_test() {
    local filepath=$1
    local expected=$2
    local output

    if [[ $USE_VALGRIND -eq 1 ]]; then
        valgrind_output=$(valgrind --leak-check=full --error-exitcode=42 $BIN "$TESTS/$filepath" --parse-only 2>&1)
        output="$valgrind_output"
    else
        output=$($BIN "$TESTS/$filepath" --parse-only 2>&1)
    fi
    
    if echo "$output" | grep -q "$expected"; then
        ((OK++))
        if [[ $ONLY_WRONG -eq 0 ]]; then
            print_result "$i" "$filepath" "OK" "$expected" "$output"
        fi
    else
        ((KO++))
        print_result "$i" "$filepath" "KO" "$expected" "$output"
    fi
}

# ──────── 🚀 Test Runner ──────── #

while IFS="|" read -r filepath expected; do
    if [[ "$filepath" =~ ^# ]]; then
        echo -e "\n$filepath"
        continue
    fi
    if [[ -z "$filepath" ]]; then
        continue
    fi
    if [[ -n "$FILTER" && "$filepath" != *"$FILTER"* ]]; then
        continue  # Skip if filter doesn't match filepath
    fi
    if [[ ! -f "$TESTS/$filepath" ]]; then
        echo -e "$filepath ${RED}FILE NOT FOUND${NC}"
        continue
    fi
    run_test "$filepath" "$expected"
    ((i++))
done < "$TEST_LIST"

# ──────── 🧾 Summary ──────── #

echo
if [[ KO -eq 0 ]]; then
    echo -e "${GREEN}All $OK cases pass! OK! 😆${NC}"
else
    echo -e "${RED}Some test(s) failed. 🥲${NC}"
    echo
    echo -e "${GREEN}OK${NC}: $OK"
    echo -e "${RED}KO${NC}: $KO"
fi
echo
