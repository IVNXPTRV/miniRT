#!/bin/bash



# Check if a folder is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <folder>"
  exit 1
fi

FOLDER="$1"

# Check if folder exists
if [ ! -d "$FOLDER" ]; then
  echo "Error: '$FOLDER' is not a directory"
  exit 1
fi

# Get basename of folder to check if it is "error"
BASENAME=$(basename "$FOLDER")

if [ "$BASENAME" = "error" ]; then
   chmod -r "./error/nopermission.rt"
   CMDS=(
     "./miniRT ./error/nonexistingfile.rt"
     "./miniRT ./error/"
     "./miniRT ./arg1.rt ./arg2.rt"
     "./miniRT"
     "./miniRT ./error/nopermission.rt"
   )
   for CMD in "${CMDS[@]}"; do
      echo -e "Running valgrind on $CMD \n"
      valgrind --track-fds=yes --leak-check=full -q $CMD &
      PID1=$!
      echo -e "Press Enter to close and open next, or 'q' to quit...\n"
      read -r -n1 KEY
      echo

      kill $PID1 2>/dev/null
      wait $PID1 2>/dev/null

      if [ "$KEY" = "q" ]; then
        echo "Exiting."
        break
      fi

   done
fi

for FILE in "$FOLDER"/*; do
  if [ -f "$FILE" ]; then
    if [ "$BASENAME" = "error" ]; then
      echo -e "Running valgrind on: $FILE\n"
      valgrind --track-fds=yes --leak-check=full -q ./miniRT "$FILE" &
      PID1=$!
    else
      echo -e "Opening: $FILE\n"
      ./miniRT "$FILE" &
      PID1=$!
    fi
      echo -e "Press Enter to close and open next, or 'q' to quit...\n"
      read -r -n1 KEY
      echo

      kill $PID1 2>/dev/null
      wait $PID1 2>/dev/null

      if [ "$KEY" = "q" ]; then
        echo "Exiting."
        break
      fi
    fi
done

echo "All scenes are shown. Exiting..."
