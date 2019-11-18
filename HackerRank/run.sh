filename=$1
extension=".cpp"
FILE=$filename$extension

if [ -f "$FILE" ]; then
    g++ -o output.out $FILE
    ./output.out
else
	echo "$filename does not exist"
fi