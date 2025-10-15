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

## Main Function
This is the main algorithm of the program, containing the list of students, as well as the interface for the user.
### Algorithm for Main()
    Create the vector containing the students using the readStudentFile() function
