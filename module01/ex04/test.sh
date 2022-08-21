#!/bin/bash

if ! [[ $1 ]] || ! [[ $2 ]] || ! [[ $3 ]]; then
  echo "needs 3 args"
else
  bin/loser_sed "$1" "$2" "$3"

  if [ "$2" == '$' ]; then
    arg1='\$'
  else
    arg1="$2"
  fi
  if [ "$3" == '$' ]; then
    arg2='\$'
  else
    arg2="$3"
  fi

  sed s/"$arg1"/"$arg2"/gi "$1" > "$1".sed
  echo "Written changes to: '$1.sed'"
  if [[ $(diff "$1".replace "$1".sed) != "" ]]; then
    echo "diff found.. check '$1.replace' and '$1.sed'"
  else
    echo "no diff between '$1.replace' and '$1.sed' !"
  fi
fi

