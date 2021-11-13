#include <iostream>
#include <vector>
#include <functional>
#include <numeric>
// #include <execution>

using namespace std;

vector<int> a{1, 1, 2, 3, 4};
vector<int> b{5, 4, 2, 3, 1};

void DemoInnerProduct()
{
    int r1 = inner_product(a.begin(), a.end(), b.begin(), 0);
    cout << "Inner product of a and b: " << r1 << '\n';
 
    int r2 = inner_product(a.begin(), a.end(), b.begin(), 0,
                                plus<>(), equal_to<>());
    cout << "Number of pairwise matches between a and b: " <<  r2 << '\n';
}

void TransformReduce1()
{
    vector<double> xvalues(10007, 1.0), yvalues(10007, 1.0);
 
    /*double result = transform_reduce(
        execution::par,
        xvalues.begin(), xvalues.end(),
        yvalues.begin(), 0.0
    );
    cout << result << '\n';
    */
}

void TransformReduce2()
{
  //transform(a.begin(), a.end(), b.begin(), 0, plus<>(), multiplies<>());
    string s("hello");
    transform(s.begin(), s.end(), s.begin(),
                    [](unsigned char c) -> unsigned char { return toupper(c); });

    vector<size_t> ordinals;
    transform(s.begin(), s.end(), back_inserter(ordinals),
                    [](unsigned char c) -> size_t { return c; });

    cout << s << ':';
    for (auto ord : ordinals)
        cout << ' ' << ord;

    transform(ordinals.cbegin(), ordinals.cend(), ordinals.cbegin(),
                    ordinals.begin(), plus<>{});

    cout << '\n';
    for (auto ord : ordinals) {
        cout << ord << ' ';
    }
    cout << '\n';
}
}

int main()
{
    DemoInnerProduct();

    TransformReduce1();
    TransformReduce2();

}