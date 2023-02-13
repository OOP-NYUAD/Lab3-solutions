/*Just like we can have templates for functions to take in data types defined at 
compile-time, we can also do the same for classes. That is, have classes that 
can take in and use multiple kinds of objects, even abstract data types*/

/*We're going to start with the syntax

    template <class T1, class T2, ...> OR template <typename T>
*/
#include <iostream>
#include <string>

using namespace std;

template <class T1>
class myClass{
    T1 myVal;

public:
    myClass(){}         // I don't want to define a default constructor since I don't know what T1 can be
                        // ergo I cannot generalize.
    myClass(T1 val){
        myVal = val;
    }


    /* Here I am defining a print functionality because all fundemental data types in
    cpp are printable. However, if I try to call print for a datatype that isn't
    printable, we'll have a problem*/  
    void print(){
        cout << "Stored value is: " << myVal << '\n';
    }

};

/*We can also define multiple types (this is used in maps as an example)*/
template <class T1, class T2>
class myComplexClass{
    T1 key;
    T2 data;

public:
    myComplexClass(){}
    myComplexClass(T1 k, T2 val){
        key = k;
        data = val;
    }

    void print(){
        cout << "Key value is: " << key << '\n'
             << "Stored value is: " << data << '\n';
    }
};

/*this is the basic syntax for class definition, in order to use this class we use the following syntax*/

int main(){
    // class_name<data_type> variable_name
    myClass<int> intObj(2);
    myClass<char> charObj('A');
    myClass<string> strObj("Some words go here");

    intObj.print();
    charObj.print();
    strObj.print();

    myComplexClass<int, string> simpleMap(0, "zero");

    simpleMap.print();

    return 0;
}