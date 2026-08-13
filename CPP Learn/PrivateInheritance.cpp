///*
//============================================================
//PRIVATE INHERITANCE — WHY DOES IT EXIST?
//============================================================
//
//When you write:
//
//    class Derived : private Base
//
//It means:
//
//    - Derived uses Base internally.
//    - But Derived is NOT a Base.
//    - Base public members become private inside Derived.
//
//This models:
//    "implemented-in-terms-of"
//NOT
//    "is-a"
//
//============================================================
//WHEN TO USE PRIVATE INHERITANCE?
//============================================================
//
//When:
//✔ You want to reuse implementation
//✔ You do NOT want polymorphism
//✔ You do NOT want base interface exposed
//✔ You want tighter control
//
//============================================================
//EXAMPLE 1 — PUBLIC INHERITANCE (IS-A)
//============================================================
//*/
//
//#include <iostream>
//
///*
//Base class
//*/
//class Engine
//{
//public:
//    void start() const
//    {
//        std::cout << "Engine started\n";
//    }
//};
//
///*
//Public inheritance (INCORRECT DESIGN)
//Car IS-A Engine ❌ (wrong conceptually)
//*/
//class Car_Public : public Engine
//{
//};
//
///*
//============================================================
//PROBLEM:
//------------------------------------------------------------
//This allows:
//
//    Car_Public car;
//    car.start();   // Works
//
//But logically:
//    Car is NOT an Engine.
//    Car HAS-A Engine.
//
//So public inheritance is conceptually wrong here.
//
//============================================================
//EXAMPLE 2 — PRIVATE INHERITANCE
//============================================================
//*/
//
//class Car_Private : private Engine
//{
//public:
//    void drive()
//    {
//        start();   // allowed internally
//        std::cout << "Car driving\n";
//    }
//};
//
///*
//Now:
//
//- Engine's start() is NOT accessible outside.
//- Car reuses Engine implementation.
//- But Car is NOT treated as Engine.
//*/
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
//    std::cout << "=== Public Inheritance (Bad Design) ===\n";
//
//    Car_Public cp;
//    cp.start();  // ❌ Conceptually wrong exposure
//
//
//    std::cout << "\n=== Private Inheritance (Controlled) ===\n";
//
//    Car_Private c;
//    c.drive();
//
//    // c.start();  // ❌ ERROR (hidden from outside)
//
//    return 0;
//}
//
//
///*
//============================================================
//WHAT JUST HAPPENED?
//============================================================
//
//Private inheritance:
//
//    class Car : private Engine
//
//Means:
//
//    Engine public  → private inside Car
//    Engine protected → private inside Car
//    Engine private → not accessible
//
//So:
//
//✔ Car can use Engine internally
//✘ Outside world cannot treat Car as Engine
//✘ No polymorphism
//
//============================================================
//WHY NOT USE COMPOSITION INSTEAD?
//============================================================
//
//Better modern design:
//
//class Car
//{
//private:
//    Engine m_engine;   // composition (HAS-A)
//};
//
//Composition is usually preferred over private inheritance.
//
//============================================================
//WHEN IS PRIVATE INHERITANCE ACTUALLY USEFUL?
//============================================================
//
//1) When you need access to protected members.
//2) When overriding virtual functions internally.
//3) When you want compile-time relationship but not public exposure.
//4) Rare framework/internal system designs.
//
//============================================================
//IMPORTANT DESIGN RULE
//============================================================
//
//Public inheritance  → IS-A
//Private inheritance → IMPLEMENTED-IN-TERMS-OF
//Composition         → HAS-A
//
//Modern C++ rule:
//Prefer composition over private inheritance.
//
//============================================================
//SUMMARY
//============================================================
//
//We use private inheritance when:
//    - We want implementation reuse
//    - We want to hide base interface
//    - We do NOT want polymorphism
//
//But in most cases:
//    Composition is cleaner.
//
//============================================================
//*/