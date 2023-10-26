# Algorithms and data structures 1
This repository serves as a comprehensive collection of code and projects related to the "Algorithms and data structures 1" course offered at the ISRM and FRI programs of University of Ljubljana.


## Folder structure
```
.
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
    Holds weekly source code from our lectures and some Jupyter Notebook files as 
- `revision`:
    Solved old exams and midterms

## Setup 
Each program can be tested using the following sequence of commands:

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

