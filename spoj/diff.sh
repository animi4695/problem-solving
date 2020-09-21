#!/bin/bash
cd $1
echo $(pwd)
mainoutfiles=(`ls out*.txt`)

yourfiles=(`ls yout*.txt`)

echo "Hello"
echo "" > testcases.txt;
for ((i=0; i<${#mainoutfiles[@]}; i++)); do
  if cmp -s -- "out$i.txt" "yout$i.txt"; then
    echo "out$i.txt Test Case PASSED" >> testcases.txt
  else
    echo "out$i.txt Test Case FAILED" >> testcases.txt
  fi
  # diff -s out$i.txt yout$i.txt
  # if [ $? -eq 0 ]; then
  #   echo "out$i.txt Test Case Passed"
  # else
  #   echo "out$i.txt Test Case Failed"
  # fi
done

# $SHELL

# echo $cmd
# eval $cmd
# cd ..