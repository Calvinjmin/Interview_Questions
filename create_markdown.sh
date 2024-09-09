#!/bin/bash

directory="c++"
output_file="dynamic_file_hierarchy_table.md"

# ----- C++ Directory ----- #

echo "### C++ Files" > "$output_file"
echo "" >> "$output_file"

# Sub Directories
categories=("Array" "Dynamic_Programming" "Graph" "Greedy" "Hash_Table" "Heap" "Trees")

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

for category in "${categories[@]}"; do
    echo "#### $category" >> "$output_file"
    echo "" >> "$output_file"
    echo "| File Name | Description |" >> "$output_file"
    echo "|---|---|" >> "$output_file"

    for file in "$directory/$category"/*; do
        if [[ -f "$file" ]]; then
            filename=$(basename "$file")
            filepath="$directory/$category/$filename" 
            description=$(head -n 1 "$file") 
            description=$(trim_description "$description") 
            description=${description//|/\\|} 
            echo "| [\`$filename\`](./$filepath) | $description |" >> "$output_file"
        fi
    done

    echo "" >> "$output_file"
done

echo "" >> "$output_file"
echo "Markdown file created: $output_file"
