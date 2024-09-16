#!/bin/bash

# ----- Static Variables ----- #
directory="c++"
output_file="README.md"
repo_url="https://github.com/Calvinjmin/Interview_Questions/blob/main/C%2B%2B"

# ----- C++ Directory ----- #

echo "### C++ Files" > "$output_file"
echo "" >> "$output_file"

# Sub Directories
categories=("Array" "Two_Pointer" "Sliding_Window" "Backtracking" "Greedy" "Dynamic_Programming" "Graph" "Math" "Hash_Table" "Heap" "Trees" "Binary_Search" "Linked_Lists")

relative_path() {
    local target="$1"
    local base="$2"
    local path="${target#${base}/}"
    echo "$path"
}

# Grab desc. of file off the first line, trim the comment characters
trim_description() {
    local description="$1"
    echo "${description:2}"
}

# Start of README.md
{
    echo "# Interview Questions"
    echo "The purpose of this repo is to keep track of key algorithms/solutions for common Leetcode questions. Furthermore, there will be solutions in multiple languages to show the versatility of my coding abilities."
    echo "## Languages"
    echo "### C++ Files"
} > "$output_file"

for category in "${categories[@]}"; do
    echo "#### $category" >> "$output_file"
    echo "" >> "$output_file"
    echo "| File Name | Description |" >> "$output_file"
    echo "|---|---|" >> "$output_file"

    for file in "$directory/$category"/*; do
        if [[ -f "$file" ]]; then
            filename=$(basename "$file")
            filepath=$(echo "$file" | sed "s|$directory/||") # Remove the base directory
            url_encoded_filepath=$(echo "$filepath" | sed 's/ /%20/g') # URL encode spaces
            url="$repo_url/$filepath"
            description=$(head -n 1 "$file") 
            description=$(trim_description "$description") 
            description=${description//|/\\|} 
            echo "| [$filename]($url) | $description |" >> "$output_file"
        fi
    done

    echo "" >> "$output_file"
done


## Conclusion
{
    echo "---"
    echo "### Resources"
    echo "Link to HackerRank - [Hackerank](https://www.hackerrank.com/) <br />"
    echo "Link to Leetcode - [Leetcode](https://leetcode.com/) <br />"
    echo "Calvin Min | 2024"
} >> "$output_file"

echo "Markdown file created: $output_file"
