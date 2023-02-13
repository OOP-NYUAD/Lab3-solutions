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

template <class T1, class T2>
class HetrogenousPair{
    T1 first;
    T2 second;

public:
    HetrogenousPair(){}
    HetrogenousPair(T1 first, T2 second){
        this->first = first;
        this->second = second;
    }

    void set_first_value(T1 val){
        first = val;
    }

    void set_second_value(T2 val){
        second = val;
    }

    T1 get_first_value() const{ return first; }
    T2 get_second_value() const{ return second; }
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