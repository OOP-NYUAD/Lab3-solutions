/*As the title might suggest, we can't just overload any operator and expect smooth operation
for all class templates. Eventually, and depending on our usage of our class templates, we migh
encounter run-time errors when we're trying to overload an opeartor that does not work for a 
given data type and then try to use that operator on that data type. Let's give an example*/

#include <iostream>

using namespace std;

template <class T1>
class myClass{
    T1 myVal;

public:
    myClass(){}
    myClass(T1 val){
        myVal = val;
    }

    T1 getVal(){ return myVal; }

    /*here I am attempting to overload the left shift operator
    if I am working with integers, I will be alright, if I try 
    to left shift doubles or floats, I will run into problems*/
    myClass<T1> operator <<(const myClass<T1> &obj){ 
        return myClass(this->myVal << obj.myVal);
    }
};

int main(){
    myClass<int> intObj1(2), intObj2(3);
    cout << (intObj1 << intObj2).getVal() << '\n'; // this should work fine

    myClass<float> floatObj1(2.2), floatObj2(1.5);
    cout << (floatObj1 << floatObj2).getVal() << '\n'; // what about this?

    /* Two questions:
        > Will my code compile?
        > Will it run just fine from start to finish?
        > What is the expected output?

    Try to compile this file and run it (if it compiles).
    */

   /*You also need to be aware of this when passing abstract data types (class objects)
   as typenames to a template class since different classes have different methods*/

   return 0;
}