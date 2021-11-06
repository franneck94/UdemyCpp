#include <iostream>
#include <memory>
#include <string>

class ScopeTest
{
public:
    ScopeTest(const std::string &name) : m_name(name)
    {
        std::cout << "Constructor: " << m_name << std::endl;
    }

    ~ScopeTest()
    {
        std::cout << "Destructor:" << m_name << std::endl;
    }

    void test()
    {
        std::cout << "Val: " << m_name << std::endl;
    }

    std::weak_ptr<ScopeTest> m_partner;

private:
    std::string m_name;
};

// Shared Pointer: besitzen ein Reference counting System
void f1()
{
    auto t = std::make_shared<ScopeTest>("t1");
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
    ScopeTest *t3 = new ScopeTest("t3");
    t3->test();
}

// Weak Pointer: erhöht den Reference Counter eines Shared Pointer NICHT
void f3()
{
    auto t4 = std::make_shared<ScopeTest>("t4");
    std::cout << "Count t4: " << t4.use_count() << std::endl;
    auto t5 = std::make_shared<ScopeTest>("t5");
    std::cout << "Count t5: " << t5.use_count() << std::endl;

    t4->m_partner = t5;
    std::cout << "Count t5: " << t5.use_count() << std::endl;
    t5->m_partner = t4;
    std::cout << "Count t4: " << t4.use_count() << std::endl;
}

void f4(std::shared_ptr<ScopeTest> t5)
{
    auto shared_t5_partner = t5->m_partner.lock();
    shared_t5_partner->test();
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
