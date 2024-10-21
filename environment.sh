#!/bin/bash

################################
# Development Environment Setup
################################

# Get current script directory
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

# Set alias for building from source directory and tests
alias b="python3 ${DIR}/tools/build_current_dir.py"

# Source the pipenv
source env/bin/activate

source .env
