# Algorithms and data structures 1
This repository serves as a comprehensive collection of code and projects related to the "Algorithms and data structures 1" course offered at the ISRM and FRI programs of University of Ljubljana.

## Folder structure
```
|
├── home_work
├── challanges
├── lectures
├── README.md
└── ...
```

- `home_work`:
    Home work assignments for the year 2023/24
- `challanges`:
    Nonobligatory challanges that were posted by our professor
- `lectures`:
    Holds weekly source code from our lectures and Jupyter Notebook files that serve as curriculum notes

## Setup 
Each program can be tested using the following sequence of terminal commands:

```cpp
g++ -std=c++20 -o FileName FileName.cpp 
./FileName < test.in > test.res

// Runtime check
time ./FileName < test.in > test.res
```

You can also run the program manually using the following sequence of commands:

```cpp
g++ -std=c++20 -o FileName FileName.cpp 
./FileName
```

Every task with a working makefile and test units can be tested using the following sequence of commands (the provided makefile might not be fully compatible with the test cases included in certain directories):
```cpp
gcc -o FileName FileName.cpp
export name=FileName
make test
```
