/*The bonus (2 marks) is implementing a template class Vector. Vectors
are dynamically resized arrays. They expand when more elements are ad-
ded automatically. Vectors have the follownig properties:
    1. They are initially empty (starting size is zero)
    2. The first element to be inserted into a vector makes its size 1
    3. Everytime you exceed the vector's capacity, it redoubles its capacity
        > e.g. if the vector has the capacity of 4, and there are 4 elements inside
        then you attempt to insert another element, its capaicty becomes 8.
    4. Resizing works by:
        a. making another dynamic array with double the capaicty
        b. copying contents of old array into new array
        c. deleting / deallocating old memory

The member methods needed for the Vector class are defined below.
Note this needs to be a TEMPLATE CLASS
*/

using namespace std;

template <class T>
class Vector{
private:
    T *array;
    u_int size;
    u_int cap;

    // copy function to transfer array to bigger one
    // also doubles capacity
    void copy(){
        T *temp = new T[cap*2];
        for(int i = 0; i < size; i++){
            temp[i] = this->array[i]; 
        }

        delete[] this->array;
        this->array = temp;
        cap *= 2;
    }

public:
    // default constructor can be used to initialize variables
    // you don't need to define a non-default constructor
    Vector(){
        this->size    = 0;
        this->cap     = 0;
        this->array   = nullptr;
    }  

    void push_back(const T &data){ // appends an element to the end of the vector
        if(array == nullptr){
            this->size = 1;
            this->cap  = 1;
            this->array = new T(data);
            return;
        }

        if(size == cap) copy();
        
        this->array[this->size++] = data;
    }

    void push_front(const T &data){ // appends an element to the beginning/start of the vector
        if(array == nullptr){
            this->size = 1;
            this->cap  = 1;            
            this->array = new T(data);
            return;
        }  

        if(this->size == this->cap) copy();

        for(int i = this->size + 1; i > 0; i--)
            this->array[i] = this->array[i-1]; // shift everything to the right
        
        this->array[0] = data;
        this->size++;
    }

    void insert(const int index, const T &data){ // places the element at the given index and shifts everything to the right of it
        if(index > size || index < 0){
            cout << "Specified index exceeds bounds of array\n";
            return;
        }

        if(array == nullptr){
            this->size = this->cap = 1;
            this->array = new T(data);
            return;
        }  

        if(this->size == this->cap) copy();

        for(int i = this->size + 1; i > index; i--)
            this->array[i] = this->array[i-1]; // shift everything to the right from the inserted point

        this->array[index] = data;
        this->size++;
    }

    int get_size() const { return size; }
    bool empty() const { return size == 0; }

    T get_element(const int index) const{ // returns the element at the specified index
        if(index > size || index < 0){
            cout << "Specified index exceeds bounds of array\n";
            exit(-1);
        }

        return this->array[index];
    }

    void pop_back(){ // removes the last element
        if(empty()){
            cout << "Vector is empty\n";
            return;
        }
        else
            this->size--;
    }

    void pop_front(){ // removes the first element and shifts everything back
        if(empty()){
            cout << "Vector is empty\n";
            return;
        }

        for(int i = 0; i < size - 1; i++){
            this->array[i] = this->array[i+1];
        }
        this->size--;
    }

    void delete_at(int index){ // removes the element at the specified index and shifts everything back
        if(index > size || index < 0){
            cout << "Specified index exceeds bounds of array\n";
            return;
        }

        if(empty()){
            cout << "Vector is empty\n";
            return;
        }

        for(int i = index; i < this->size - 1; i++)
            this->array[i] = this->array[i+1]; // shift everything to the right from the inserted point

        this->size--;
    }

    ~Vector(){ // cleanup goes here
        delete[] this->array;
    }
};