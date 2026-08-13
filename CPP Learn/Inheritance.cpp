///*
//============================================================
//INHERITANCE IN C++ (C++20)
//Base Class | Derived Class | Access Control
//Overriding | virtual | override | final
//Memory Model | Constructor Order
//============================================================
//
//------------------------------------------------------------
//1) WHAT IS INHERITANCE?
//------------------------------------------------------------
//
//Inheritance allows a class (Derived)
//to acquire properties and behavior of another class (Base).
//
//Purpose:
//✔ Code reuse
//✔ Polymorphism
//✔ Logical hierarchy modeling
//
//Syntax:
//
//class Derived : access_specifier Base
//{
//};
//
//============================================================
//2) BASE CLASS
//============================================================
//*/
//
//#include <iostream>
//#include <string>
//
///*
//------------------------------------------------------------
//Base Class
//------------------------------------------------------------
//*/
//
//class Animal
//{
//protected:
//    std::string m_name;
//
//public:
//    Animal(const std::string& name)
//        : m_name(name)
//    {
//        std::cout << "Animal constructor\n";
//    }
//
//    void eat() const
//    {
//        std::cout << m_name << " is eating\n";
//    }
//
//    virtual void speak() const
//    {
//        std::cout << "Animal makes sound\n";
//    }
//
//    virtual ~Animal()
//    {
//        std::cout << "Animal destructor\n";
//    }
//};
//
//
///*
//============================================================
//3) DERIVED CLASS
//============================================================
//*/
//
//class Dog : public Animal
//{
//private:
//    int m_age;
//
//public:
//    Dog(const std::string& name, int age)
//        : Animal(name), m_age(age)   // Base constructor call
//    {
//        std::cout << "Dog constructor\n";
//    }
//
//    /*
//    Overriding base function
//    */
//    void speak() const override
//    {
//        std::cout << m_name << " says Woof\n";
//    }
//
//    void fetch() const
//    {
//        std::cout << m_name << " is fetching\n";
//    }
//
//    ~Dog()
//    {
//        std::cout << "Dog destructor\n";
//    }
//};
//
//
///*
//============================================================
//4) ACCESS MODES IN INHERITANCE
//============================================================
//
//class Derived : public Base
//class Derived : protected Base
//class Derived : private Base
//
//Public inheritance (most common):
//    Base public    -> public
//    Base protected -> protected
//    Base private   -> NOT accessible
//
//Protected inheritance:
//    Base public    -> protected
//    Base protected -> protected
//
//Private inheritance:
//    Base public    -> private
//    Base protected -> private
//
//============================================================
//5) MAIN
//============================================================
//*/
//
//int main()
//{
//    std::cout << "=== Direct Object ===\n";
//    Dog d("Buddy", 3);
//
//    d.eat();       // inherited
//    d.speak();     // overridden
//    d.fetch();     // own method
//
//
//    std::cout << "\n=== Base Pointer (Polymorphism) ===\n";
//
//    Animal* ptr = new Dog("Rocky", 5);
//
//    ptr->eat();    // base method
//    ptr->speak();  // derived method (virtual dispatch)
//
//    delete ptr;    // IMPORTANT: virtual destructor required
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
//1) MEMORY MODEL
//------------------------------------------------------------
//Derived object layout:
//
//[ Base part ]
//[ Derived part ]
//
//Dog object contains:
//    Animal members
//    Dog members
//
//============================================================
//
//2) CONSTRUCTOR ORDER
//------------------------------------------------------------
//Creation order:
//    Base constructor
//    Derived constructor
//
//Destruction order:
//    Derived destructor
//    Base destructor
//
//============================================================
//
//3) VIRTUAL FUNCTION
//------------------------------------------------------------
//If base function is NOT virtual:
//
//    Animal* ptr = new Dog();
//    ptr->speak();   // calls Animal::speak()
//
//If virtual:
//    Calls Dog::speak()
//
//virtual enables runtime polymorphism.
//
//============================================================
//
//4) override KEYWORD
//------------------------------------------------------------
//Best practice:
//
//    void speak() const override;
//
//Ensures:
//✔ Function matches base signature
//✔ Compiler error if mismatch
//
//============================================================
//
//5) FINAL KEYWORD
//------------------------------------------------------------
//Prevents further overriding:
//
//    void speak() const final;
//
//Prevents further inheritance:
//
//    class Dog final : public Animal
//
//============================================================
//
//6) WHY VIRTUAL DESTRUCTOR?
//------------------------------------------------------------
//If deleting via base pointer:
//
//    Animal* ptr = new Dog();
//    delete ptr;
//
//Without virtual destructor:
//    Only base destructor runs (dangerous).
//
//============================================================
//
//7) IS-A RELATIONSHIP
//------------------------------------------------------------
//Use inheritance only if:
//
//    Dog IS-A Animal   ✔
//    Car IS-A Engine   ✘
//
//Inheritance models hierarchy, not composition.
//
//============================================================
//SUMMARY
//============================================================
//
//Base class → General behavior
//Derived class → Specialized behavior
//virtual → runtime polymorphism
//override → safety
//public inheritance → most common
//virtual destructor → mandatory for polymorphic base
//
//============================================================
//*/