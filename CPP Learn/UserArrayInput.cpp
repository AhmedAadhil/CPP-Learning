//// ==========================================
//// Fixed Size Array with Temporary Variable
//// Stop when user types "esc"
//// Empty values are allowed
//// ==========================================
//
//#include <iostream>
//#include <string>
//
//int main()
//{
//    const int SIZE = 5;
//    std::string names[SIZE];
//
//    std::cout << "Enter up to " << SIZE << " names.\n";
//    std::cout << "Type 'esc' to stop.\n\n";
//
//    int i;
//    for (i = 0; i < SIZE; i++)
//    {
//        std::string temp;   // temporary variable
//
//        std::cout << "Enter name [" << i << "]: ";
//        std::getline(std::cin, temp);
//
//        // If user wants to stop
//        if (temp == "esc")
//        {
//            std::cout << "Input stopped by user.\n";
//            break;
//        }
//
//        // Store value (empty values are allowed)
//        names[i] = temp;
//    }
//
//    // Display stored values
//    std::cout << "\nStored Names:\n";
//    for (int j = 0; j < i; j++)
//    {
//        std::cout << j << ": " << names[j] << "\n";
//    }
//
//    return 0;
//}