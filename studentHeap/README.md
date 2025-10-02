# Code Documentation for studentHeap

```mermaid
classDiagram

    class Address {    
        - string street
        - string city
        - string state
        - int zip

        + Address(string street, string city, string state, int zip)
        + string getStreet()
        + string getCity()
        + string getState()
        + int getZip()
    }

    class Date {
        - int month
        - int day
        - int year

        + Date(int month, int day, int year)
        + int getMonth()
        + int getDay()
        + int getYear()
    }

    class Student {
        - string firstName
        - string lastName
        - Address address
        - Date birthday
        - Date expectedGradDate
        - int creditHoursComplete
    }

    Student o-- Address
    Student o-- Date

```
