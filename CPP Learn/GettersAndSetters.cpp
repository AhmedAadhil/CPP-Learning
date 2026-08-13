///*
//============================================================
//GETTERS & SETTERS (ABSTRACTION IN C++)
//Private Members | Controlled Access | Encapsulation
//============================================================
//
//------------------------------------------------------------
//1) WHY PRIVATE MEMBERS?
//------------------------------------------------------------
//
//If members are public:
//    - Anyone can modify them.
//    - No validation possible.
//    - Object can enter invalid state.
//
//If members are private:
//    - Cannot be accessed directly from outside.
//    - Forces controlled access.
//    - Protects invariants.
//
//This is called ENCAPSULATION.
//
//Abstraction:
//    - Hide internal implementation.
//    - Expose only necessary interface.
//
//============================================================
//EXAMPLE 1 — PUBLIC MEMBERS (BAD DESIGN)
//============================================================
//*/
//
//#include <iostream>
//#include <string>
//
//class BankAccount_Public
//{
//public:
//    std::string owner;
//    double balance;
//};
//
///*
//Problem:
//User can directly modify balance without rules.
//*/
//
//
///*
//============================================================
//EXAMPLE 2 — PRIVATE MEMBERS (PROTECTED)
//============================================================
//*/
//
//class BankAccount
//{
//private:
//    std::string m_owner;
//    double m_balance;
//
//public:
//
//    // Constructor
//    BankAccount(const std::string& owner, double balance)
//        : m_owner(owner), m_balance(balance)
//    {
//    }
//
//    /*
//    --------------------------------------------------------
//    GETTER
//    --------------------------------------------------------
//    - Used to READ private data.
//    - Does NOT modify object.
//    - Should be marked const.
//    */
//    double getBalance() const
//    {
//        return m_balance;
//    }
//
//    std::string getOwner() const
//    {
//        return m_owner;
//    }
//
//    /*
//    --------------------------------------------------------
//    SETTER
//    --------------------------------------------------------
//    - Used to MODIFY private data.
//    - Allows validation.
//    - Protects object state.
//    */
//    void setBalance(double newBalance)
//    {
//        if (newBalance >= 0)   // validation rule
//        {
//            m_balance = newBalance;
//        }
//        else
//        {
//            std::cout << "Invalid balance. Cannot be negative.\n";
//        }
//    }
//
//    /*
//    Controlled behavior instead of raw modification
//    */
//    void deposit(double amount)
//    {
//        if (amount > 0)
//        {
//            m_balance += amount;
//        }
//    }
//
//    void withdraw(double amount)
//    {
//        if (amount > 0 && amount <= m_balance)
//        {
//            m_balance -= amount;
//        }
//        else
//        {
//            std::cout << "Invalid withdrawal.\n";
//        }
//    }
//};
//
//
///*
//============================================================
//MAIN
//============================================================
//*/
//
//int main()
//{
//    std::cout << "=== Public Member Example (Unsafe) ===\n";
//
//    BankAccount_Public acc1;
//    acc1.owner = "UserA";
//    acc1.balance = 1000;
//
//    acc1.balance = -5000;   // ❌ No restriction
//    std::cout << "Balance modified directly: "
//        << acc1.balance << "\n";
//
//
//    std::cout << "\n=== Private Member Example (Safe) ===\n";
//
//    BankAccount acc2("UserB", 1000);
//
//    // acc2.m_balance = -5000;  // ❌ ERROR (private, not accessible)
//
//    std::cout << "Initial Balance: "
//        << acc2.getBalance() << "\n";
//
//    acc2.setBalance(-5000);   // validation prevents corruption
//    std::cout << "After invalid set: "
//        << acc2.getBalance() << "\n";
//
//    acc2.deposit(500);
//    std::cout << "After deposit: "
//        << acc2.getBalance() << "\n";
//
//    acc2.withdraw(200);
//    std::cout << "After withdrawal: "
//        << acc2.getBalance() << "\n";
//
//    return 0;
//}
//
//
///*
//============================================================
//DETAILED THEORY
//============================================================
//
//1) PRIVATE MEMBERS
//-------------------
//- Cannot be accessed directly outside the class.
//- Enforced at compile time.
//- Protects internal representation.
//
//2) GETTER
//----------
//- Provides read-only access.
//- Should be const.
//- Returns value (or const reference if heavy object).
//
//Example:
//    int getValue() const;
//
//3) SETTER
//----------
//- Provides controlled write access.
//- Should validate inputs.
//- Can reject invalid data.
//
//4) ABSTRACTION
//---------------
//User sees:
//
//    account.deposit(500);
//    account.getBalance();
//
//User does NOT see:
//    how balance is stored
//    validation rules
//    internal representation
//
//Internal logic can change without affecting users.
//
//5) WHY NOT MAKE EVERYTHING PUBLIC?
//
//If public:
//    - No validation
//    - No control
//    - Hard to debug
//    - Breaks invariants
//    - Poor OOP design
//
//6) BEST PRACTICE
//
//✔ Keep data private
//✔ Expose behavior through public functions
//✔ Use const correctness
//✔ Avoid unnecessary setters
//✔ Prefer behavior functions (deposit, withdraw)
//  over raw setBalance()
//
//============================================================
//IMPORTANT WARNING
//============================================================
//
//Do NOT blindly create getters/setters for everything.
//That defeats abstraction.
//
//Bad design:
//    class with private data + trivial getters/setters
//    but no real control logic.
//
//Good design:
//    expose meaningful operations.
//
//============================================================
//SUMMARY
//============================================================
//
//Private → Protects data
//Getter  → Controlled read access
//Setter  → Controlled write access
//Abstraction → Hide implementation, expose interface
//
//This is core OOP principle.
//
//============================================================
//*/