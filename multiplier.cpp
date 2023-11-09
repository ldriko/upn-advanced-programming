#include <iostream>

using namespace std;

void multiplyAndPrint(int a, int b)
{
    cout << "Result: " << a * b << endl;
}

int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    multiplyAndPrint(2, 3);

    cout << "Result: " << multiply(5, 3) << endl;

    return 0;
}