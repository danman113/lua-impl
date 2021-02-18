#!/bin/bash
if command -v brew &> /dev/null; then
    brew install lua
elif command -v apt-get &> /dev/null; then
    sudo apt-get install liblua5.3
fi
# Add windows eventually?