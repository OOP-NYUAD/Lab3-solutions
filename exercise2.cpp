/*Create a container vector<T> of type Account from the 
previous lab. Where Account is a user defined data type 
and contains relevant bank account information. Add few 
instances of Account to vector<Account>. Sort the cont-
ainer vector<Account> by account balance in ascending 
order*/

#include "Account.h"
#include <vector>
#include <cstdlib>

using namespace std;

int main(){
    // declare a vector of type Account
    vector<Account> myVec;

    // fill it with some accounts
    for(int i = 0; i < 10; i++){
        myVec.push_back((double) (rand() % 1000));
    }

    // sort the accounts in ascending order of account balance
    for(int i = 0; i < myVec.size(); i++){
        int index = i;
        float minVal = myVec[i].getBalance();
        for(int x = i + 1; x < myVec.size(); x++){
            if(myVec[x].getBalance() < minVal){
                index = x;
                minVal = myVec[x].getBalance();
            }
        }

        if(i != index){
            Account temp = myVec[i];
            myVec[i] = myVec[index];
            myVec[index] = temp;
        }
    }

    // call .print() for each object in the, now sorted, container
    for(int i = 0; i < myVec.size(); i++){
        myVec[i].print();
    }

    return 0;
}
