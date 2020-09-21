# Takes 2 args - Folder Name to create and number of test cases files to create.
# copies the template c program to the newly created folder.

foldername=$1
noTestCases=$2
mkdir $foldername

cp template.cpp $foldername/sol.cpp

cd $foldername
echo $(pwd)

for ((i=0; i<$2; i++)); do
  touch in$i.txt
  touch out$i.txt
done

# $SHELL