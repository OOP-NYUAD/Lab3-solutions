/*Create a container list<T> of type Student. Where Student is a 
user defined data type. Student class holds important informati-
on about the Student entity like netID, name, age, and gender. 
Add few instances of Student to list<Student>. Sort the 
list<Student> by student name in ascending or descending order 
using sort method from <algorithm> header. Create a print funct-
ion inside Student and access it via list iterator.*/

#include <list>
#include "Student.h"

using namespace std;

int main(){
    // declare a list of type Student
    list<Student> myList;

    // fill it with some students
    myList.push_front(Student("as12106", "Ahmad Salous", 23));
    myList.push_front(Student("twa2013", "Tuka Alhanai", 35));          // idk how old professor Alhanai is.
    myList.push_front(Student("kr2755", "Wen Rahme", 20));              // also just a guess
    myList.push_front(Student("maa1150", "Muhammad Areeb Ashar", 21));  // I actually asked him.

    // Sort the students using the sort member function list::sort()
    myList.sort();

    // call .print for each object. You will need a list iterator to access the objects
    list<Student>::iterator it;

    for(it = myList.begin(); it != myList.end(); it++){
        (*it).print();
    }

    return 0;
}