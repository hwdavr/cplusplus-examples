#include <iostream>
#include <cassert>
#include <cstdint>
#include <vector>
#include <list>
#include <map>

using namespace std;
/// The example refer from: https://eli.thegreenplace.net/2014/variadic-templates-in-c/

/// Test adder
template<typename T>
T adder(T v) {
  return v;
}

template<typename T, typename... Args>
T adder(T first, Args... args) {
  return first + adder(args...);  // recursively add new argument
}

void testAdder() {
    long sum = adder(1, 2, 3, 8, 7);
    cout << "Sum: " << sum;
    
    string s1 = "x", s2 = "aa", s3 = "bb", s4 = "yy";
    string ssum = adder(s1, s2, s3, s4);
    cout << "\nSsum: " << ssum;
}

/// Test pair comparer
template<typename T>
bool pair_comparer(T a, T b) {
  // In real-world code, we wouldn't compare floating point values like
  // this. It would make sense to specialize this function for floating
  // point types to use approximate comparison.
  return a == b;
}

template<typename T, typename... Args>
bool pair_comparer(T a, T b, Args... args) {
  return a == b && pair_comparer(args...);  // recursively compare arguments in pairs
}

void testComparer() {
    bool result = pair_comparer(1.5, 1.5, 2, 2, 6, 6);
    assert(result);
}

/// Print container
template <template <typename, typename> class ContainerType,
          typename ValueType,
          typename AllocType>
void print_container(const ContainerType<ValueType, AllocType>& c) {
  for (const auto& v : c) {
    cout << v << ' ';
  }
  cout << '\n';
}

void testPrintContainer() {
    cout << '\n';
    vector<double> vd{3.14, 8.1, 3.2, 1.0};
    print_container(vd);

    list<int> li{1, 2, 3, 5};
    print_container(li);
}

int main() {

    testAdder();
    testComparer();
    testPrintContainer();
    std::cout << "\nOK\n";

}
