#!/bin/bash

cpp_file="main.cpp"

# Get the first line of the .cpp file
first_line=$(head -n 1 "$cpp_file")

problem_code=$(echo "$first_line" | awk -F'/' '{print $(NF-0)}')

problem_number=$(echo "$first_line" | awk -F'/' '{print $(NF-1)}')

echo ${problem_number}
echo ${problem_code}

# Create a new file with the extracted parts and copy the content of the .cpp file
new_file="${problem_number}${problem_code}.cpp"
echo "$(<"$cpp_file")" > "$new_file"

echo "New file created: $new_file"

# Upload to github
git add ${new_file}
git commit -m "Add ${first_line}"
