#include <iostream>
using std::cin, std::cout, std::endl;

int factorial(int n)
// This function returns the nth factorial number using recursion.
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main(){
    int n;
    cout << "Enter a number for factorial: " << endl;
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}
