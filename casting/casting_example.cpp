#include <memory>
#include <iostream>
#include <cassert>
#include <cstdint>

using namespace std;

struct Calculator {

    double val;

    Calculator(int a, int b) : val(a + b) {}
    Calculator(double x) : val(x * 10) {}

    virtual ~Calculator() {};

};

struct Derived : public Calculator {

    Derived() : Calculator(1, 0) {};

};

struct car
{
    int doors;
    int height;
    int length;
    float weight;
};

int64_t create_car()
{
    car *c = new car;
    return reinterpret_cast<int64_t>(c);  // cast pointer to int
}

int64_t get_car_doors(int64_t car_id)
{
    car *c = reinterpret_cast<car*>(car_id);  // cast back int to pointer
    return c->doors;
}

void destroy_car(int64_t car_id)
{
    car *c = reinterpret_cast<car*>(car_id);  // cast back int to pointer
    delete c;
}


void test() {
    int value0 = 0;
    int* pValue0 = &value0;
    // implicit cast: casting any pointer to void pointer
    void* pVoid = pValue0;
    assert(pVoid != nullptr);
    
    // const_cast
    const int *pVALUE = &value0;
    int* pValue1 = const_cast<int *>(pVALUE);  // From const pointer to non-const pointer
    assert(*pValue1 == 0);
    cout << "value 0: " << *pValue1 << endl;
    
    // static_cast
    double dValue = 1.12;
    int value1 = static_cast<int>(dValue);   // Force casting double to int
    assert(value1 == 1);
    cout << "value 1: " << value1 << endl;
    
    int* pValue2 = static_cast<int*>(pVoid);  // From void pointer to int pointer
    cout << "value 2: " << *pValue2 << endl;
    
    // dynamic_cast
    Calculator* cal = new Derived;
    Derived *derived = dynamic_cast<Derived*>(cal);  // From base to derived class
    assert(cal == derived);
    assert(derived->val == 1);
    
    // reinterpret_cast: can cast from different type of pointers
    double *dptr = reinterpret_cast<double*>(pValue0);  // Cast int pointer to to double pointer
    cout << "Double value: " << *dptr << endl;
}

int main() {

    test();
    std::cout << "OK\n";

}
