# Code Documentation for studentHeap

```mermaid
classDiagram

    class Address {    
        - string street
        - string city
        - string state
        - string zip

        + Address()
        + void init(string street, string city, string state, string zip)
        + void printAddress()
    }

    class Date {
        - int month
        - int day
        - int year

        + Date()
        + void init(string date)
        + void printDate()
    }

    class Student {
        - string firstName
        - string lastName
        - Address* address
        - Date* birthday
        - Date* expectedGradDate
        - int creditHoursComplete

        + Student()
        + ~Student()
        + void init(string studentString)
        + void printStudent()
        + string getLastFirst() 
    }

    Student o-- Address
    Student o-- Date

```

# Documentation of Algorithm
Just a quick note, I am breaking up certain features of the algorithm—such as creating the vector of all the students from the file—into their own functions. This is partially for readability, but also because I simply think it makes sense.

## main Function
This is the main algorithm of the program, containing the list of students, as well as the interface for the user.
### Algorithm for main()
    Create the vector containing the students using the readStudentFile() function

## loadStudents Function
This is the function that reads the students.csv file and adds all the student objects to a vector.
### Algorithm for loadStudents()
Create a vector of student pointers called studentList
Create an inputFileStream called inFile, which will be used for reading the students.csv file
Create a string called currentLine, which will be used to initialize each student in the vector
Open the students.csv file via inFile
Loop through every line in students.csv, setting currentLine to match the currently accessed line in the file, while also doing the following for each line:
    Create a new student object on the heap, saving the pointer to it in a variable called currentStudent
    Call init on currentStudent, using currentLine as the string for the initialization
    Add the pointer to currentStudent to the end of the studentList vector
After the loop is finished, return studentList

## printStudents Function
This function prints the students vector to the console
### Parameters for printStudents()
A vector of Student pointers (likely the vector created from students.csv), which will be referred to as students
### Algorithm for printStudents()
Loop through each Student in the students vector, doing the following:
    Call printStudent() on the current Student in the loop
    Print a horizontal line to the console to clearly seperate students on viewing
