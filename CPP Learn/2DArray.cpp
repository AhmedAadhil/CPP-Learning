//// ==========================================
//// 2D Arrays in C++
//// Declaration, Definition, Size Calculation
//// Square & Non-Square Matrices
//// ==========================================
//
//#include <iostream>
//using namespace std;
//
//
//// ==========================================
//// 1. DECLARATION SYNTAX
//// ==========================================
//
//// type name[rows][columns];
//// Note  : rows are not mandatory but columns are mandatory during declaration.
//
//int matrix1[3][3];     // Square matrix (3x3)
//int matrix2[2][4];     // Non-square matrix (2x4)
//
//
//// ==========================================
//// 2. DEFINITION WITH INITIALIZATION
//// ==========================================
//
//int squareMatrix[3][3] = {
//    {1, 2, 3},
//    {4, 5, 6},
//    {7, 8, 9}
//};
//
//int rectangularMatrix[2][4] = {
//    {1, 2, 3, 4},
//    {5, 6, 7, 8}
//};
//
//
//// ==========================================
//// 3. MEMORY LAYOUT (IMPORTANT)
//// ==========================================
//
//// 2D arrays are stored in ROW-MAJOR ORDER
//// Meaning:
//// Row 0 → all columns
//// Row 1 → all columns
//// Row 2 → all columns
////
//// Memory sequence for squareMatrix:
////
//// 1 2 3 4 5 6 7 8 9
////
//// Not column-wise.
//
//
//// ==========================================
//// 4. SIZE CALCULATIONS
//// ==========================================
//
//int main()
//{
//    cout << "===== SIZE CALCULATIONS =====\n\n";
//
//    // ---- Square Matrix ----
//    cout << "Square Matrix (3x3)\n";
//    cout << "Total size in bytes: "
//        << sizeof(squareMatrix) << endl;
//
//    cout << "Size of one row: "
//        << sizeof(squareMatrix[0]) << endl;
//
//    cout << "Number of rows: "
//        << sizeof(squareMatrix) / sizeof(squareMatrix[0]) << endl;
//
//    cout << "Number of columns: "
//        << sizeof(squareMatrix[0]) / sizeof(squareMatrix[0][0]) << endl;
//
//
//    cout << "\n-----------------------------\n\n";
//
//
//    // ---- Non-Square Matrix ----
//    cout << "Rectangular Matrix (2x4)\n";
//    cout << "Total size in bytes: "
//        << sizeof(rectangularMatrix) << endl;
//
//    cout << "Size of one row: "
//        << sizeof(rectangularMatrix[0]) << endl;
//
//    cout << "Number of rows: "
//        << sizeof(rectangularMatrix) / sizeof(rectangularMatrix[0]) << endl;
//
//    cout << "Number of columns: "
//        << sizeof(rectangularMatrix[0]) / sizeof(rectangularMatrix[0][0]) << endl;
//
//
//    return 0;
//}
//
//
//// ==========================================
//// 5. FORMULAS (IMPORTANT FOR INTERVIEWS)
//// ==========================================
//
//// If type is int (4 bytes typical):
////
//// Square (n x n):
//// Total elements = n * n
//// Total bytes = n * n * sizeof(int)
////
//// Rectangular (r x c):
//// Total elements = r * c
//// Total bytes = r * c * sizeof(int)
////
//// Rows = sizeof(array) / sizeof(array[0])
//// Columns = sizeof(array[0]) / sizeof(array[0][0])
//
//
//// ==========================================
//// 6. KEY WARNINGS
//// ==========================================
//
//// 1. Columns MUST be specified in function parameters.
////    int arr[][3]  -> OK
////    int arr[][]   -> ERROR
////
//// 2. sizeof works only in SAME SCOPE.
////    If passed to function, it decays to pointer.
////
//// 3. Out-of-bounds access = Undefined Behavior.
////    No automatic bounds checking.
////
//// 4. All dimensions must be compile-time constants
////    (unless using dynamic allocation).
