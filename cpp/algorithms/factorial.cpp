#include <iostream>
using std::cin, std::cout;

int factorial(int n)
// This function returns the nth factorial number using recursion.
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cout << "Enter a number for factorial: " << "\n";
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n) << "\n";
    return 0;
}
