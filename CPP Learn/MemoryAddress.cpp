//// =====================================================
//// MEMORY ADDRESS IN C++
//// Detailed Theory + Practical Demonstration
//// =====================================================
//
//#include <iostream>
//using namespace std;
//
//
//// =====================================================
//// 1. BASIC ADDRESS OPERATOR
//// =====================================================
////
//// &  -> Address-of operator
//// *  -> Dereference operator
////
//
//void basicAddressDemo()
//{
//    int x = 10;
//
//    cout << "Value of x      : " << x << endl;
//    cout << "Address of x    : " << &x << endl;
//
//    int* ptr = &x;  // pointer storing address of x
//
//    cout << "Value inside ptr (address): " << ptr << endl;
//    cout << "Dereferenced ptr (*ptr)  : " << *ptr << endl;
//}
//
//
//// =====================================================
//// 2. MEMORY IS BYTE ADDRESSABLE
//// =====================================================
////
//// Every variable occupies memory.
//// Each byte has a unique address.
////
//// int typically = 4 bytes
//// char = 1 byte
////
//
//void sizeAndAddressDemo()
//{
//    int a = 100;
//    char b = 'A';
//    double d = 3.14;
//
//    cout << "\n--- Size Information ---\n";
//    cout << "sizeof(int)    : " << sizeof(a) << endl;
//    cout << "sizeof(char)   : " << sizeof(b) << endl;
//    cout << "sizeof(double) : " << sizeof(d) << endl;
//
//    cout << "\n--- Addresses ---\n";
//    cout << "Address of a : " << &a << endl;
//    cout << "Address of b : " << static_cast<void*>(&b) << endl;
//    cout << "Address of d : " << &d << endl;
//}
//
//
//// =====================================================
//// 3. ARRAY MEMORY CONTINUITY
//// =====================================================
////
//// Arrays are stored in contiguous memory.
//// Elements are placed sequentially.
////
//
//void arrayMemoryDemo()
//{
//    int arr[4] = { 10, 20, 30, 40 };
//
//    cout << "\n--- Array Addresses ---\n";
//
//    for (int i = 0; i < 4; i++)
//    {
//        cout << "arr[" << i << "] = "
//            << arr[i]
//            << " | Address: "
//            << &arr[i]
//            << endl;
//    }
//
//    cout << "\nBase address (arr)      : " << arr << endl;
//    cout << "Address of first element: " << &arr[0] << endl;
//}
//
//
//// =====================================================
//// 4. POINTER ARITHMETIC
//// =====================================================
////
//// If int = 4 bytes
//// ptr + 1 moves 4 bytes forward
////
//// It moves by sizeof(type), not 1 byte.
////
//
//void pointerArithmeticDemo()
//{
//    int arr[3] = { 5, 10, 15 };
//
//    int* p = arr;   // same as &arr[0]
//
//    cout << "\n--- Pointer Arithmetic ---\n";
//
//    cout << "p       : " << p << endl;
//    cout << "p + 1   : " << p + 1 << endl;
//    cout << "p + 2   : " << p + 2 << endl;
//
//    cout << "*p      : " << *p << endl;
//    cout << "*(p+1)  : " << *(p + 1) << endl;
//    cout << "*(p+2)  : " << *(p + 2) << endl;
//}
//
//
//// =====================================================
//// 5. STACK MEMORY THEORY
//// =====================================================
////
//// Local variables live in STACK memory.
////
//// Characteristics:
//// - Automatically managed
//// - LIFO (Last In First Out)
//// - Fast allocation/deallocation
//// - Limited size
////
//
//void stackDemo()
//{
//    int a = 1;
//    int b = 2;
//    int c = 3;
//
//    cout << "\n--- Stack Addresses ---\n";
//    cout << "a: " << &a << endl;
//    cout << "b: " << &b << endl;
//    cout << "c: " << &c << endl;
//
//    // Notice addresses are usually close to each other
//}
//
//
//// =====================================================
//// 6. IMPORTANT THEORY
//// =====================================================
////
//// 1. Every variable occupies memory.
//// 2. Memory is byte-addressable.
//// 3. & gives memory address.
//// 4. Pointer stores address.
//// 5. * dereferences pointer.
//// 6. Arrays are contiguous.
//// 7. Pointer arithmetic scales by sizeof(type).
//// 8. Local variables -> stack.
//// 9. Dynamic memory -> heap (using new/delete).
////
//
//
//// =====================================================
//
//int main()
//{
//    basicAddressDemo();
//    sizeAndAddressDemo();
//    arrayMemoryDemo();
//    pointerArithmeticDemo();
//    stackDemo();
//
//    return 0;
//}