filename=$1
extension=".cpp"
FILE=$filename$extension

if [[ "$filename" == *"$extension"* ]]; then
  FILE=$filename
fi

if [ -f "$FILE" ]; then
    g++ -o output.out $FILE
    ./output.out
else
	echo "$filename does not exist"
fi