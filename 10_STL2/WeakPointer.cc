#include <iostream>
#include <memory>
#include <string>

class ScopeTest
{
public:
    ScopeTest(int val) : m_val(val)
    {
        std::cout << "Constructor: " << m_val << '\n';
    }

    ~ScopeTest()
    {
        std::cout << "Destructor:" << m_val << '\n';
    }

    void test()
    {
        std::cout << "Val: " << m_val << '\n';
    }

    std::weak_ptr<ScopeTest> m_partner;
    int m_val;
};

// Shared Pointer: besitzen ein Reference counting System
void f1()
{
    auto t = std::make_shared<ScopeTest>(1);
    t->test();

    std::cout << "Count: " << t.use_count() << '\n';

    {
        auto t2 = t;
        t2->test();

        std::cout << "Count: " << t.use_count() << '\n';
    }

    std::cout << "Count: " << t.use_count() << '\n';
}

void f2()
{
    auto *t3 = new ScopeTest(10);
    t3->test();
}

// Weak Pointer: erhöht den Reference Counter eines Shared Pointer NICHT
void f3()
{
    auto t4 = std::make_shared<ScopeTest>(11);
    std::cout << "Count t4: " << t4.use_count() << '\n';
    auto t5 = std::make_shared<ScopeTest>(12);
    std::cout << "Count t5: " << t5.use_count() << '\n';

    t4->m_partner = t5;
    std::cout << "Count t5: " << t5.use_count() << '\n';
    t5->m_partner = t4;
    std::cout << "Count t4: " << t4.use_count() << '\n';

    if (!t4->m_partner.expired())
    {
        auto t4_partner_shard = t4->m_partner.lock();
        std::cout << t4_partner_shard->m_val << '\n';
        std::cout << "Count t5: " << t5.use_count() << '\n';
    }
}

int main()
{
    f1();
    std::cout << '\n';
    f2();
    std::cout << '\n';
    f3();

    return 0;
}
