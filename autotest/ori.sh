FILES=/mnt/c/COMP20007Project1/sample_input/orientation-*-in.txt
for input in $FILES
do
	echo "Testing $input.."
	../cmake-build-debug/COMP20007Project1 -o < $input 
done
