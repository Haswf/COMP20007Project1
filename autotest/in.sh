FILES=/mnt/c/COMP20007Project1/sample_input/inside-hull-*-in.txt
for input in $FILES
do
	echo "Testing $input.."
	../cmake-build-debug/COMP20007Project1 -i < $input 
done
