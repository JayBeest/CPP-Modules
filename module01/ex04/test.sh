#!/bin/bash

if ! [[ $1 ]] || ! [[ $2 ]] || ! [[ $3 ]]; then
  echo "needs 3 args"
else
  bin/loser_sed "$1" "$2" "$3"
  sed s/"$2"/"$3"/g "$1" > "$1".sed
  diff "$1".replace "$1".sed
fi

