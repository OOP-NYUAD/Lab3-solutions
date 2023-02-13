/*Write a template class “HetrogenousPair” that can hold a pair 
of values of different types. Define constructors, two mutator 
and two accessor methods:
    - set_first_value() 
    - set_second_value() 
    - get_first_value()
    - get_second_value() 
in the template class HetrogenousPair*/
#include <iostream>
#include <string>

using namespace std;

class HetrogenousPair{

};

int main(){
    HetrogenousPair<int, string> obj1(0, "a string");
    HetrogenousPair<string, string> obj2("first", "second");

    obj1.set_first_value(2);
    obj2.set_second_value("third");

    cout << obj1.get_first_value() << '\n';
    cout << obj2.get_second_value() << '\n';

    return 0;
}