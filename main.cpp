#include <iostream>

#include "SmartPointer.hpp"

class A {
public:
    A(const int& a, const int& b) : m_a(a), m_b(b) {}
    ~A() {std::cout << __func__ << std::endl;};

    int getA() {
        return m_a;
    }

private:
    int m_a = 0;
    int m_b = 0;

};

int main() {
    
    smart_ptr<int> ptr(new int(4));
    std::cout << *ptr << std::endl;
    
    smart_ptr<int> pt = std::move(ptr);
    std::cout << *pt << std::endl;

    smart_ptr<A> objPtr(new A(6, 5));
    std::cout << objPtr->getA() << std::endl;
    
    return 0;
}