#include <iostream>
#include <list>


using namespace std;

struct A {
    int x = 4;

    A() {
        cout << "A()" << endl;
    }

    A(A &&a) {
        cout << "A(A&&)" << endl;
    }

    ~A() {
        cout << "~A()" << endl;
    }
};

int main() {
    A a = std::move(A());
    cout << a.x;
//    A *a = new(temp) A;
//    cout<<*((int*)temp)<<endl;
//    for (int i = 0; i < 1000; i++)
//        temp[i] = '0';
//    A *array = new A[3];
//    for (int i = 0; i < 1000; i++)
//        if (temp[i] != '0')
//            cout << i << ": " << temp[i] << endl;
//    cout << endl;
//    delete[] array;
    return 0;
}