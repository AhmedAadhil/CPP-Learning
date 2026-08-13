//// ==========================================
//// topic: range-based for loop (for-each)
//// ==========================================
//
//#include <iostream>
//#include <string>
//
//int main() {
//
//    std::string names[] = { "alice", "bob", "charlie" };
//
//    // ------------------------------------------
//    // value copy (creates copy every iteration)
//    // ------------------------------------------
//    for (std::string name : names) {
//        std::cout << name << "\n";
//    }
//
//    // ------------------------------------------
//    // using const reference (recommended)
//    // ------------------------------------------
//    for (const std::string& name : names) {
//        std::cout << name << "\n";
//    }
//
//    // ------------------------------------------
//    // modifying elements
//    // ------------------------------------------
//    for (std::string& name : names) {
//        name += "!";
//    }
//
//    /*
//    ------------------------------------------
//    using auto (modern c++ style)
//    ------------------------------------------
//
//    for (const auto& name : names) {
//        std::cout << name << "\n";
//    }
//
//    - auto deduces std::string
//    - const prevents modification
//    - & avoids copy
//    - this is the most professional pattern:
//          for (const auto& elem : container)
//    */
//
//    return 0;
//}