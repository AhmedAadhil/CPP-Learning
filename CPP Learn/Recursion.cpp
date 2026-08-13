//// ======================================================
//// RECURSION IN C++
//// Example: Factorial
//// ======================================================
//
//#include <iostream>
//using namespace std;
//
///*
//--------------------------------------------------------
//RECURSION THEORY (Compact + Important Points)
//--------------------------------------------------------
//
//1) Recursion = A function calling itself.
//2) Must have:
//      - Base Case      (stopping condition)
//      - Recursive Case (self-call reducing problem size)
//3) Each recursive call creates a new stack frame.
//4) If no proper base case -> Stack Overflow.
//
//Factorial Definition:
//
//    n! = n × (n-1)!
//    0! = 1  (Base Case)
//
//Call Stack Flow Example for factorial(4):
//
//    factorial(4)
//        4 * factorial(3)
//            3 * factorial(2)
//                2 * factorial(1)
//                    1 * factorial(0)
//                        return 1
//
//    Then stack unwinds:
//        1
//        2 * 1 = 2
//        3 * 2 = 6
//        4 * 6 = 24
//
//*/
//
//
//// -------------------------------
//// Recursive Function
//// -------------------------------
//long long factorial(int n)
//{
//    // Base Case (Termination Condition)
//    if (n == 0 || n == 1)
//        return 1;
//
//    // Recursive Case
//    return n * factorial(n - 1);
//}
//
//
//// -------------------------------
//// Optional: Input Validation Wrapper
//// -------------------------------
//long long factorialSafe(int n)
//{
//    if (n < 0)	
//    {
//        cout << "Factorial not defined for negative numbers.\n";
//        return -1;
//    }
//
//    return factorial(n);
//}
//
//
//// -------------------------------
//// Main
//// -------------------------------
//int main()
//{
//    int number;
//
//    cout << "Enter a number: ";
//    cin >> number;
//
//    long long result = factorialSafe(number);
//
//    if (result != -1)
//        cout << "Factorial of " << number << " is " << result << endl;
//
//    return 0;
//}
//
//
///*
//--------------------------------------------------------
//IMPORTANT NOTES (Advanced Awareness)
//--------------------------------------------------------
//
//1) Time Complexity:
//      O(n)
//
//2) Space Complexity:
//      O(n)  (due to call stack)
//
//3) Stack Frame Contains:
//      - Parameter n
//      - Return address
//      - Local variables
//
//4) Risk:
//      Large n → Stack overflow
//
//5) Practical Limit:
//      ~10^4 recursive depth (depends on system)
//
//6) Iterative alternative avoids stack growth.
//
//--------------------------------------------------------
//When To Use Recursion?
//--------------------------------------------------------
//
//- Tree traversal
//- Graph DFS
//- Divide and conquer (Merge Sort, Quick Sort)
//- Backtracking
//- Mathematical recurrence relations
//
//--------------------------------------------------------
//*/