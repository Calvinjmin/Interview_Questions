#!/bin/bash

# ----- Static Variables ----- #
cpp_directory="c++"
python_directory="python"
output_file="README.md"
repo_url="https://github.com/Calvinjmin/Interview_Questions/blob/main"

# ----- Function to Extract Relative Path ----- #
relative_path() {
    local target="$1"
    local base="$2"
    local path="${target#${base}/}"
    echo "$path"
}

# ----- Function to Trim Description ----- #
trim_description() {
    local description="$1"
    echo "${description:2}"
}

# ----- Initialize README.md ----- #
{
    echo "# Interview Questions"
    echo "The purpose of this repo is to keep track of key algorithms/solutions for common Leetcode questions. Furthermore, there will be solutions in multiple languages to show the versatility of my coding abilities."
    echo "## Languages"
    echo "### C++ Files"
} > "$output_file"

# ----- C++ Categories ----- #
cpp_categories=("Array" "Two_Pointer" "Sliding_Window" "Backtracking" "Greedy" 
    "Dynamic_Programming" "Graph" "Math" "Hash_Table" "Heap" "Trees" "Prefix_Tree" "Sets" "Stacks" "Binary_Search" "Matrix" "Linked_Lists")

for category in "${cpp_categories[@]}"; do
    echo "#### $category" >> "$output_file"
    echo "" >> "$output_file"
    echo "| File Name | Description |" >> "$output_file"
    echo "|---|---|" >> "$output_file"

    for file in "$cpp_directory/$category"/*; do
        if [[ -f "$file" ]]; then
            filename=$(basename "$file")
            filepath=$(relative_path "$file" "$cpp_directory")
            url_encoded_filepath=$(echo "$filepath" | sed 's/ /%20/g') # URL encode spaces
            url="$repo_url/C%2B%2B/$url_encoded_filepath"
            description=$(head -n 1 "$file")
            description=$(trim_description "$description")
            description=${description//|/\\|}
            echo "| [$filename]($url) | $description |" >> "$output_file"
        fi
    done

    echo "" >> "$output_file"
done

# ----- Python Section ----- #
echo "### Python Files" >> "$output_file"
echo "" >> "$output_file"

python_categories=("Backtracking" "Greedy" "Dynamic_Programming")

# Modify the trim_description function to handle Python comments
trim_description() {
    local description="$1"
    echo "${description:2}" # This will trim either // or # based on the file format
}

for category in "${python_categories[@]}"; do
    echo "#### $category" >> "$output_file"
    echo "" >> "$output_file"
    echo "| File Name | Description |" >> "$output_file"
    echo "|---|---|" >> "$output_file"

    for file in "$python_directory/$category"/*; do
        if [[ -f "$file" ]]; then
            filename=$(basename "$file")
            filepath=$(relative_path "$file" "$python_directory")
            url_encoded_filepath=$(echo "$filepath" | sed 's/ /%20/g') # URL encode spaces
            url="$repo_url/Python/$url_encoded_filepath"
            description=$(head -n 1 "$file")
            description=$(trim_description "$description") # Trim '#' from Python comments
            description=${description//|/\\|}
            echo "| [$filename]($url) | $description |" >> "$output_file"
        fi
    done

    echo "" >> "$output_file"
done

# ----- Conclusion ----- #
{
    echo "---"
    echo "### Resources"
    echo "Link to HackerRank - [Hackerank](https://www.hackerrank.com/) <br />"
    echo "Link to Leetcode - [Leetcode](https://leetcode.com/) <br />"
    echo "Calvin Min | 2024"
} >> "$output_file"

echo "Markdown file created: $output_file"

