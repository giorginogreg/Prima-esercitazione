#include <iostream> // simile alla Forward declaration
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Hello World!" << endl;    
    cout <<  "What's your name?"  << endl;    

    string name;
    cin >> name;
    cout << "Hello " << name  << "!" << endl;   


    // Reference example
    int val = 10;
    int* address_val = &val;

    // I can dereference a pointer, not a REFERENCE!
    cout << "Value of val: " << *address_val  << endl;   

    // Pointer can change their location address, while references CAN'T

    int& val_pointer = val; // Initialization mandatory on creation.
    
    // null pointer example
    // Class null_pointer = nullptr;

    // Aliases (using T = Y) = typedef
    using intero = int;
    typedef int intero;

    // Decltype
    // It deduces the value type but doesn't evaluate it (example for functions)

    int a = 1;
    int b = 2;
    swap(a, b);
    cout << "Value of A and B are " << to_string(a) << " | " << to_string(b) << endl;

    return 0;
}

// Example of function with parameters passed by reference.
void swap(int& v1, int& v2) {
    int tmp = v2;
    v2 = v1;
    v1 = tmp;
}
