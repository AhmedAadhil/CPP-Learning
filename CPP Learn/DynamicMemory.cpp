//// ============================================================
//// DYNAMIC MEMORY IN C++ (C++20)
//// Understanding: Heap, new, delete
//// ============================================================
//
//#include <iostream>
//using namespace std;
//
//
//// ============================================================
//// 1️⃣ WHAT IS DYNAMIC MEMORY?
//// ============================================================
////
//// There are two main memory areas:
////
//// 1. Stack  -> automatic variables (fast, limited)
//// 2. Heap   -> manual allocation (dynamic memory)
////
//// "new" allocates memory on the HEAP.
//// "delete" frees it.
////
//// ============================================================
//
//
//// ------------------------------------------------------------
//// STACK EXAMPLE
//// ------------------------------------------------------------
//void stackExample()
//{
//    int number = 10;   // stored on stack
//
//    cout << "\n--- STACK EXAMPLE ---\n";
//    cout << "Value   : " << number << endl;
//    cout << "Address : " << &number << endl;
//
//    // Automatically destroyed when function ends
//}
//
//
//// ------------------------------------------------------------
//// HEAP EXAMPLE (Single variable)
//// ------------------------------------------------------------
//void heapExample()
//{
//    cout << "\n--- HEAP EXAMPLE (Single int) ---\n";
//
//    int* pNumber = new int;   // allocate 4 bytes on heap
//
//    *pNumber = 100;           // assign value
//
//    cout << "Value on heap        : " << *pNumber << endl;
//    cout << "Heap address stored  : " << pNumber << endl;
//    cout << "Address of pointer   : " << &pNumber << endl;
//
//    delete pNumber;           // free heap memory
//
//    pNumber = nullptr;        // prevent dangling pointer
//}
//
//
//// ------------------------------------------------------------
//// HEAP ARRAY EXAMPLE
//// ------------------------------------------------------------
//void heapArrayExample()
//{
//    cout << "\n--- HEAP ARRAY EXAMPLE ---\n";
//
//    int size = 3;
//
//    int* pArray = new int[size];   // dynamic array
//
//    for (int i = 0; i < size; i++)
//    {
//        pArray[i] = (i + 1) * 10;
//    }
//
//    for (int i = 0; i < size; i++)
//    {
//        cout << "pArray[" << i << "] = "
//            << pArray[i]
//            << " | Address: "
//            << &pArray[i] << endl;
//    }
//
//    delete[] pArray;   // IMPORTANT: delete[] for arrays
//
//    pArray = nullptr;
//}
//
//
//// ============================================================
//// 2️⃣ WHAT DOES "new" ACTUALLY DO?
//// ============================================================
////
//// When you write:
////
////     int* p = new int;
////
//// It does 3 things:
////
//// 1. Allocates memory on heap
//// 2. Returns address of that memory
//// 3. Assigns that address to pointer
////
//// If allocation fails -> throws std::bad_alloc
////
//// ============================================================
//
//
//// ============================================================
//// 3️⃣ COMMON MISTAKES
//// ============================================================
////
//// ❌ Forgetting delete -> MEMORY LEAK
////
//// ❌ Using delete instead of delete[] for arrays
////
//// ❌ Dereferencing after delete (dangling pointer)
////
//// ❌ Not initializing pointer
////
//// ============================================================
//
//
//int main()
//{
//    stackExample();
//    heapExample();
//    heapArrayExample();
//
//    return 0;
//}