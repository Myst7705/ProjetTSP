#!/bin/bash
PROJECT_DIR="$(dirname "$(realpath "$0")")"

# Generate docs
doxygen "$PROJECT_DIR/Doxyfile"

# Define the correct output file path
HTML_FILE="$PROJECT_DIR/doc/html/index.html"

# Check if the file exists
if [ -f "$HTML_FILE" ]; then
    explorer.exe "$(wslpath -w "$HTML_FILE")"
else
    echo "❌ Documentation not found at $HTML_FILE"
    echo "Check your Doxyfile's OUTPUT_DIRECTORY setting."
fi
