#include <iostream>
#include <memory>

class ScopeTest
{
public:
    ScopeTest(int val) : m_val(val)
    {
        std::cout << "Constructor: " << m_val << std::endl;
    }

    ~ScopeTest()
    {
        std::cout << "Destructor!" << std::endl;
    }

    void test()
    {
        std::cout << m_val << std::endl;
    }

    std::shared_ptr<ScopeTest> m_partner;

private:
    int m_val;
};

// Shared Pointer: besitzen ein Reference counting System
void f1()
{
    auto t = std::make_shared<ScopeTest>(10);
    t->test();

    std::cout << "Count: " << t.use_count() << std::endl;

    {
        auto t2 = t;
        t2->test();

        std::cout << "Count: " << t.use_count() << std::endl;
    }

    std::cout << "Count: " << t.use_count() << std::endl;
}

void f2()
{
    ScopeTest *t3 = new ScopeTest(10);
    t3->test();
}

void f3()
{
    auto t4 = std::make_shared<ScopeTest>(10);
    std::cout << "Count t4: " << t4.use_count() << std::endl;
    auto t5 = std::make_shared<ScopeTest>(10);
    std::cout << "Count t5: " << t5.use_count() << std::endl;

    t4->m_partner = t5;
    std::cout << "Count t5: " << t5.use_count() << std::endl;
    t5->m_partner = t4;
    std::cout << "Count t4: " << t4.use_count() << std::endl;
}

int main()
{
    f1();
    std::cout << std::endl;
    f2();
    std::cout << std::endl;
    f3();

    return 0;
}
