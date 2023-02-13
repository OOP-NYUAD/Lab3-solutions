/*We are discussing a couple of uses for the const keywork.
In class methods, you can have constant member functions t-
hat do not alter any member variable. For example, it is g-
ood to declare *all* getter functions as constant member f-
unctions. This is because getters are supposed to retrieve
and mediate access to values, not change anything about th-
em. Here's the syntax and a couple of uses for const*/

#include <iostream>
#include <string>

using namespace std;

class myClass{
    int var1, var2;
    string var3;

public:
    myClass(int v1 = 0, int v2 = 0, string v3 = ""){
        var1 = v1;
        var2 = v2;
        var3 = v3;
    }

    int getVar1() const{
        // Notice that this next line (commented out) will result in an error
        // var1 = 2;
        return var1; 
    }

    int getVar2(){
        return var2;
    }

    // let's make a copy constructor to demonstrate a common use of constant member
    // functions
    myClass(const myClass &obj){
        this->var1 = obj.getVar1();
        // this->var2 = obj.getVar2();  // here, an error is encountered as getVar2() 
                                        //is not a constant class method however, obj
                                        // is declared as a constant value so any me-
                                        // mber functions used must be constant.
        this->var3 = obj.var3;          // of course this is all kinda useless since
                                        // we can directly refer to our objects.

    }
};