#include <iostream>

using namespace std;

const double *f1(const double *ar, int n);

const double *f2(const double *ar, int n);

const double *f3(const double *ar, int n);

int main()
{
    cout << "Hello world!" << endl;


    // 1.Pointer to a function
    const double *(*p1)(const double *, int) = f1;

    // Using array
    double av[3] = {1112.3, 2223.4, 3334.5};
    // Address
    cout << "val's address: " << p1(av, 10) << endl;
    // Value
    cout << "val's value: " << *p1(av, 10) << endl;

    // Using variable
    const double val = 10;
    // Address
    cout << "val's address: " << p1(&val, 10) << endl;
    // Value
    cout << "val's value: " << *p1(&val, 10) << endl;
    cout << "------------------" << endl;

    // auto
    // const double *(*p2)(const double *, int) = p1;
    auto p2 = p1;
    // Address
    cout << "val's address: " << p2(&val, 10) << endl;
    // Value
    cout << "val's value: " << *p2(&val, 10) << endl;
    /*
    val's address: 0x61fee0
    val's value: 10
    ------------------
    val's address: 0x61fee0
    val's value: 10
    */
    cout << "--------------------------------------------" << endl;


    // 2.Array of pointer
    const double *(*pa1[3])(const double *, int) = {f1, f2, f3};

    int index = -1;
    while(++index < 3){
        // Address
        // cout << "val's address: " << (*(pa1 + index))(&val, 10) << endl;
        cout << "val's address: " << pa1[index](&val, 10) << endl;
        // Value
        // cout << "val's address: " << *(*(pa1 + index))(&val, 10) << endl;
        cout << "val's value: " << *pa1[index](&val, 10) << endl;
    }
    cout << "------------------" << endl;

    // const double *(**pa2)(const double *, int) = pa1;
    auto pa2 = pa1;
    index = -1;
    while(++index < 3){
        // Address
        // cout << "val's address: " << (*(pa1 + index))(&val, 10) << endl;
        cout << "val's address: " << pa1[index](&val, 10) << endl;
        // Value
        // cout << "val's address: " << *(*(pa1 + index))(&val, 10) << endl;
        cout << "val's value: " << *pa1[index](&val, 10) << endl;
    }
    /*
    val's address: 0x61fee0
    val's value: 10
    val's address: 0x61fee0
    val's value: 10
    val's address: 0x61fee0
    val's value: 10
    ------------------
    val's address: 0x61fee0
    val's value: 10
    val's address: 0x61fee0
    val's value: 10
    val's address: 0x61fee0
    val's value: 10
    */
    cout << "--------------------------------------------" << endl;


    // 3.Pointer of pointer to a function
    const double *(*(*pp)[3])(const double *, int) = &pa1;
    index = -1;
    while(++index < 3){
        // Address
        // cout << "val's address: " << (*(pa1 + index))(&val, 10) << endl;
        cout << "val's address: " << (*pp)[index](&val, 10) << endl;
        // Using double * receive
        const double * temp = (*pp)[index](&val, 10);
        cout << "val's address: " << *temp << endl;

        // Value
        // cout << "val's address: " << *(*(pa1 + index))(&val, 10) << endl;
        cout << "val's value: " << *(*pp)[index](&val, 10) << endl;
        // Using double receive
        const double temp1 = *(*pp)[index](&val, 10);
        cout << "val's address: " << temp1 << endl;
    }
    cout << "------------------" << endl;
    return 0;
}

const double *f1(const double *ar, int n){
    // cout << "f1" << endl;
    return ar;
}
const double *f2(const double *ar, int n){
    // cout << "f2" << endl;
    return ar;
}
const double *f3(const double *ar, int n){
    // cout << "f3" << endl;
    return ar;
}


