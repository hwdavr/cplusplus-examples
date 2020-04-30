#include <memory>
#include <iostream>
#include <cassert>

using namespace std;

struct C {

    double val;

    C(int a, int b) : val(a + b) {}
    C(double x) : val(x * 10) {}

    virtual ~C() {};

};

struct D : public C {

    D() : C(1, 0) {};

};

void test() {

    unique_ptr<int> r(new int(1));
    if (r) {
        assert(*r == 1);
    }
    int *ptr = r.release();  // r release control and return raw pointer
    r.reset(new int(2));  // r points to new object

    unique_ptr<int> p(ptr);  // p is point to original ptr, value is 1
    std::cout << "p points to int " << *p.get() << endl;
    
    assert(p.get() == ptr);
    assert(*p.get() == 1);

    unique_ptr<int> q = std::move(r);  // move r to q
    assert(*q == 2);

    auto f = make_unique<C>(1, 1);  // val = 2.
    auto g = make_unique<C>(10.);   // val = 100.
    f.swap(g);

    assert(f->val == 100.);
    assert(g->val == 2.);

    auto d = make_unique<D>();  // val = 1.
    unique_ptr<C> c(std::move(d));
    assert(c->val == 1.);

}

int main() {

    test();
    std::cout << "OK\n";

}
