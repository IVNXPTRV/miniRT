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

# Loop through all files in the folder
for FILE in "$FOLDER"/*; do
  if [ -f "$FILE" ]; then
    echo -e "Opening: $FILE\n"

    ./miniRT "$FILE" &
    PID1=$!

    ./examples/jack/minirt "$FILE" &
    PID2=$!

    ./examples/gun/miniRT "$FILE" &
    PID3=$!

    echo -e "Press Enter to close and open next, or 'q' to quit...\n"
    read -r -n1 KEY
    echo 

    # Kill the processes if they are still running
    kill $PID1 $PID2 $PID3 2>/dev/null
    wait $PID1 $PID2 $PID3 2>/dev/null

    if [ "$KEY" = "q" ]; then
      echo "Exiting."
      break
    fi
  fi
done

echo "All scenes are showed. Exiting..."
