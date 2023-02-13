/*If you're one for imagining, you can imagine that this is a vey powerful
tool for programmers. There are enough similarites in how data can be man-
ipulated that class templates very quickly become standardized tools. I w-
ill discuss one such application of class templates that is very practical
and comes up naturally a lot. Containers. As the name suggests, containers
are storage utilities we can use to store our data in efficient and pract-
ical ways. We have already seen one such STL container, the Vector. We ha-
also saw the linked list (if you did the bonus). What makes containers so
useful is that we always need to store our data and access it readily. c-
ontainers make the storage and accessibility part easy.*/

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <cstdlib>

using namespace std;

/*We do not need to define any classes here, we just need to show you how
they are used. Syntax-wise*/

int main(){
    cout << "######Vectors######" << '\n';
    // the vector, you should already be familair with.
    vector<int> myIntVector;
    for(int i = 0; i < 10; i++){
        myIntVector.push_back(i); // this will add 10 elements to the vector container
    }
    /*The nice thing about vectors is that they are dynamically resized whenever needed.
    Which means that the initial size will start to increase as we add more elements.
    Vectors are also layed out in contiguous arrays in memory which means quick random
    access times, and direct indexing.*/

    // works just like an array would. That is because, it _is_ an array
    for(int i = 0; i < myIntVector.size(); i++){ cout << myIntVector[i] << ' '; } 
    cout << '\n';

    cout << "\n######Lists######" << '\n';
    /* next up i lists, you should also be familiar with lists from last week's lab
    lists are not arrays, they are a series of connected nodes stored in different
    locations in memory. This means that we can't have direct accesses to any element
    we must instead move up to the location from the beginning or "tail" of the list*/
    list<char> myCharList;
    for(int i = 0; i < 15; i++){
        myCharList.push_front('A' + i); // push_front is quicker in lists then push_back
                                        // inversely, push_back is quicker in vectors
    }

    /*We cannot access the list like we would an array or vector, we must use an iterator
    an iterator is essentially a pointer to an element in a container. An iterator can be
    incremented to point at the next element. The syntax for it is:*/

    /*here we initialize the iterator to the beginning of the list*/
    list<char>::iterator myListIterator = myCharList.begin();

    for(; myListIterator != myCharList.end(); myListIterator++){ cout << *myListIterator << ' '; } // notice the order of printing here
    cout << '\n';
    
    cout << "\n######Maps######" << '\n';
    /*Next up is the map. Maps are ways to connect key values to data. Simple example:
    key value is the netid of a student and the stored value is the name of that 
    student. Here's how the syntax looks like*/

    map<string, string> studentList;

    studentList["as12106"] =  "Ahmad Salous";
    studentList["ahb2"] = "Alfred Bloom";
    studentList["mhw1"] = "Mariet Westermann";

    /*we also need iterators */
    map<string, string>::iterator myMapIterator = studentList.begin();

    for(; myMapIterator != studentList.end(); myMapIterator++){ 
        cout << "netid: " << myMapIterator->first << " => "
             << myMapIterator->second << '\n'; // note the order of printing
    } 

    cout << "\n######Stacks######" << '\n';
    /*Finally we have a stack. Stacks are containers that only provide access to the
    last added element, aka the "top" of the stack. To gain access to items added 
    earlier, you must "pop" the top of the stack which means deleting the top element.
    
    Here's the sytnax:*/

    stack<int> numbers;

    for(int i = 0; i < 10; i++){
        numbers.push(i); // pushing 0 to 9
    }

    // now we empty the stack
    // we continue until its empty
    while(!numbers.empty()){
        cout << numbers.top() << ' ';   // read top of stack
        numbers.pop();                  // pop top of stack
    }

    /*What was the order observed here?*/
    /*Maps (and sets which aren't covered here) store everything in ascending order.
    When searching for an item, the search is a binary search and is done in log_2(n)*/
    cout << '\n';
    
    return 0;
}