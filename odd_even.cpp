#include <iostream>

using namespace std;

bool isEven(int x)
{
    return x % 2 == 0;
}

void printOddEven(int number)
{
    if (isEven(number))
        cout << number << " is even" << endl;
    else
        cout << number << " is odd" << endl;
}

void findOddEven(int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printOddEven(numbers[i]);
    }
}

int main()
{
    int size = 5;
    int numbers[size] = {1, 2, 3, 4, 5};

    findOddEven(numbers, size);
}