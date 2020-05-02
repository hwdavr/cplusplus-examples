#include <iostream>
#include <cassert>
#include <cstdint>
#include <vector>
#include <list>
#include <map>

using namespace std;

/// Lambda Expression
/// [ capture clause ] (parameters) -> return-type
/// {
///    definition of method
/// }

void testIntParameter() {
    // int type parameters, return type is skipped
    auto sum = [](int a, int b) {
        return a + b;
    };
    
    cout <<"Sum of two integers: "<< sum(5, 6) << endl;
}

void testGeneralizedLambda() {
    // generalized lambda, return type is skipped
    auto sum = [](auto a, auto b) {
        return a + b;
    };

    cout <<"Sum(5,6) = "<< sum(5, 6) << endl; // sum of two integers

    cout <<"Sum(2.0,6.5) = "<<sum(2.0, 6.5) << endl; // sum of two float numbers

    cout <<"Sum((string(\"SoftwareTesting\"), string(\"help.com\")) ="<< sum(string("SoftwareTesting"), string("help.com")) << endl; // sum of two strings
}

void testCaptureExpression() {
    int one = 1;
    int two = 2;
    
    // Capture by value
    [one, two]() { cout << one << "," << two << endl; }();
    
    // Capture by reference
    [&one, &two]() { one = 2; cout << one << "," << two << endl; }();
}

int main() {

    testIntParameter();
    testGeneralizedLambda();
    testCaptureExpression();
    std::cout << "\nOK\n";

}
