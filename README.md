# C++ Student GradeBook

A small C++ console application that loads student records from a text file and performs basic grade-book operations.

## Features

- Loads student names, IDs, and scores from a text file
- Displays all student records
- Adds a student to the grade book
- Deletes a student using their ID
- Sorts students by score
- Uses a Singleton class design
- Uses vectors, tuples, file input, iterators, and a lambda expression

## Technologies and Concepts

- C++20
- Visual Studio
- Object-oriented programming
- Singleton design pattern
- `std::vector`
- `std::tuple`
- File input with `std::ifstream`
- Sorting with `std::sort`
- Lambda expressions

## Project Structure

```text
cpp-student-gradebook/
├── ConsoleApplication4/
│   ├── ConsoleApplication4.cpp
│   ├── ConsoleApplication4.vcxproj
│   ├── ConsoleApplication4.vcxproj.filters
│   └── Firstdata.txt
├── ConsoleApplication4.slnx
├── .gitignore
└── README.md
```

## Input File Format

The `Firstdata.txt` file stores one student per line:

```text
Name ID Score
```

Example:

```text
Wei 1 75.5
Ming 2 55.0
Liang 3 82.0
```

## How to Run in Visual Studio

1. Download or clone this repository.
2. Open `ConsoleApplication4.slnx` in Visual Studio.
3. Make sure `Firstdata.txt` is available in the project directory.
4. Build the solution.
5. Run the application.

## Program Operations

The current program automatically:

1. Loads records from `Firstdata.txt`
2. Prints the student list
3. Adds a student
4. Deletes the student with ID `2`
5. Sorts the students by score
6. Prints the updated list after each operation

## What I Practised

Through this project, I practised:

- Creating and using a class
- Restricting object creation with the Singleton pattern
- Storing related data in tuples
- Managing a collection using a vector
- Reading structured data from a file
- Searching and deleting with iterators
- Sorting data using a custom lambda comparator

## Planned Improvements

- [ ] Add an interactive menu
- [ ] Prevent duplicate student IDs
- [ ] Validate scores so they stay between 0 and 100
- [ ] Save updated records back to the file
- [ ] Search for a student by ID
- [ ] Sort scores in ascending or descending order
- [ ] Replace tuples with a `Student` structure for clearer code
- [ ] Add automated tests

## Author

**Samar Hajjaji**

Third-year Computer Science and Technology student at NJUPT.

- GitHub: [SAMARHAJJAJI](https://github.com/SAMARHAJJAJI)
