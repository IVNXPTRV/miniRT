#!/bin/bash



# Check if a folder is provided
if [ -z "$1" ]; then
  FOLDERS=(
    "./scenes/basic/"
    "./scenes/nice/"
    "./scenes/other/"
    "./scenes/error/"
  )
else
  FOLDERS=("$1")
fi

TARGET="./scenes/error/"

found=false
for folder in "${FOLDERS[@]}"; do
  if [[ "$folder" == "$TARGET" ]]; then
    found=true
    break
  fi
done

if $found; then
   touch "./scenes/error/nopermission.rt"
   chmod -r "./scenes/error/nopermission.rt"
   CMDS=(
     "./miniRT ./scenes/error/nonexistingfile.rt"
     "./miniRT ./scenes/error/"
     "./miniRT ./arg1.rt ./arg2.rt"
     "./miniRT"
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

for FOLDER in "${FOLDERS[@]}"; do
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
done
rm  "./scenes/error/nopermission.rt"
echo "All scenes are shown. Exiting..."
