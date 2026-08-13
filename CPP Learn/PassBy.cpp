//// ======================================================
//// PASS BY VALUE vs PASS BY REFERENCE
//// Address-Based Demonstration
//// ======================================================
//
//#include <iostream>
//using namespace std;
//
//
//// ======================================================
//// 1. PASS BY VALUE
//// ======================================================
//// A copy of the variable is created.
//// Function works on the copy.
//// Original variable is NOT modified.
////
//
//void passByValue(int x)
//{
//    cout << "\n[Inside passByValue]" << endl;
//    cout << "Value of x        : " << x << endl;
//    cout << "Address of x      : " << &x << endl;
//
//    x = 999;  // modify copy
//
//    cout << "Modified x        : " << x << endl;
//    cout << "Address still same: " << &x << endl;
//}
//
//
//// ======================================================
//// 2. PASS BY REFERENCE
//// ======================================================
//// No copy is created.
//// Function parameter becomes an alias.
//// Both names refer to SAME memory location.
////
//
//void passByReference(int& x)
//{
//    cout << "\n[Inside passByReference]" << endl;
//    cout << "Value of x        : " << x << endl;
//    cout << "Address of x      : " << &x << endl;
//
//    x = 555;  // modifies original
//
//    cout << "Modified x        : " << x << endl;
//    cout << "Address still same: " << &x << endl;
//}
//
//
//// ======================================================
//
//int main()
//{
//    int num = 10;
//
//    cout << "========== ORIGINAL ==========" << endl;
//    cout << "Value of num   : " << num << endl;
//    cout << "Address of num : " << &num << endl;
//
//
//    // ------------------------------
//    // PASS BY VALUE
//    // ------------------------------
//    passByValue(num);
//
//    cout << "\n[Back in main after passByValue]" << endl;
//    cout << "Value of num   : " << num << endl;
//    cout << "Address of num : " << &num << endl;
//
//
//    // ------------------------------
//    // PASS BY REFERENCE
//    // ------------------------------
//    passByReference(num);
//
//    cout << "\n[Back in main after passByReference]" << endl;
//    cout << "Value of num   : " << num << endl;
//    cout << "Address of num : " << &num << endl;
//
//
//    return 0;
//}
//
//
//// ======================================================
//// THEORY SUMMARY
//// ======================================================
////
//// PASS BY VALUE
//// --------------
//// - New memory created
//// - Address inside function is DIFFERENT
//// - Changes do NOT affect original
//// - Slight overhead (copy)
////
//// PASS BY REFERENCE
//// -------------------
//// - No new memory created
//// - Address inside function is SAME
//// - Changes affect original
//// - More efficient for large objects
////
//// Memory view:
////
//// passByValue:
////   main(num @ 1000)
////   function(x @ 2000)   <- copy
////
//// passByReference:
////   main(num @ 1000)
////   function(x @ 1000)   <- alias
////
//// ======================================================