#!/bin/bash

# Check if input is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 \"your directory name\""
    exit 1
fi

# Take input, replace dots with hyphens and remove spaces
DIR_NAME=$(echo "$1" | tr '.' '-' | tr -d ' ')

# Create the directory
mkdir -p "$DIR_NAME"

echo "Directory created: $DIR_NAME"