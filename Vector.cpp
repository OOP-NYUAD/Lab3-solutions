#include <iostream>
#include "Vector.h"

using namespace std;

int main(){
    Vector<int> myVec;

    myVec.push_back(0);
    myVec.push_back(1);
    myVec.push_back(2);
    myVec.push_back(3);
    for(int i = 0; i < myVec.get_size(); i++){
        cout << myVec.get_element(i) << ' ';
    }
    cout << '\n';
    
    myVec.insert(1, 99);

    for(int i = 0; i < myVec.get_size(); i++){
        cout << myVec.get_element(i) << ' ';
    }
    cout << '\n';

    myVec.delete_at(1);
    myVec.push_front(-1);
    myVec.push_front(-2);
    myVec.push_front(-3);

    for(int i = 0; i < myVec.get_size(); i++){
        cout << myVec.get_element(i) << ' ';
    }
    cout << '\n';

    for(int i = 0; !myVec.empty(); i++){
        if(i%2) myVec.pop_back();
        else myVec.pop_front();

        for(int i = 0; i < myVec.get_size(); i++){
            cout << myVec.get_element(i) << ' ';
        }
        cout << '\n';
    }

    myVec.push_back(99);
    cout << myVec.get_size() << '\n';
    myVec.pop_front();

    return 0;
}