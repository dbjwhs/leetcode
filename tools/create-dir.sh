#!/bin/bash

# Check if input is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 \"your directory name\""
    exit 1
fi

# Take input, replace dots with hyphens and remove spaces
DIR_PATH="../$(echo "$1" | tr '.' '-' | tr -d ' ')"

# Create the directory
mkdir -p "$DIR_PATH"

# Copy template files
cp main.cpp $DIR_PATH
cp CMakeLists.txt $DIR_PATH

echo "Directory: $DIR_NAME created and initialized"