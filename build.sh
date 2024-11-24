#!/bin/bash

# build.sh - A script to delete and rebuild the app during development.

set -e 

print_info() {
    echo -e "[INFO] $1"
}

print_warning() {
    echo -e "[WARNING] $1"
}

print_error() {
    echo -e "[ERROR] $1"
}

if [ ! -f "setup.py" ]; then
    print_error "setup.py not found, cd into ./pyatium"
    exit 1
fi

print_info "Uninstalling pyatium..."
pip uninstall -y pyatium || print_warning "pyatium is not installed."


print_info "Removing build directories and artifacts..."
rm -rf build/ dist/ *.egg-info/ pyatium/_backend.* __pycache__/ .pytest_cache/ .mypy_cache/ *.pyc cython_debug/


print_info "Removing CMake build artifacts..."
rm -rf CMakeFiles/ CMakeCache.txt Makefile cmake_install.cmake


print_info "Removing generated stub files and type hints..."
rm -f pyatium/_backend.pyi pyatium/py.typed


print_info "Removing additional temporary and cache files..."
find . -type f \( -name "*.log" -o -name "*.tmp" -o -name "*.temp" -o -name "*~" -o -name "*.bak" -o -name "*.swp" \) -delete


print_info "Reinstalling pyatium..."
pip install . || { print_error "pip install failed."; exit 1; }


print_info "Regenerating stub files using pybind11-stubgen..."
pybind11-stubgen pyatium._backend || { print_error "Failed to generate stub files."; exit 1; }


print_info "Moving generated stub files to the package directory..."
mv stubs/pyatium/_backend.pyi pyatium/_backend.pyi

rm -rf stubs/

print_info "Creating 'py.typed' marker file..."
touch pyatium/py.typed

print_info "Cleanup and rebuild completed successfully."