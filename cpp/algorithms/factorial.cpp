#include <iostream>

// Recursive factorial program
int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main(){
    int n;
    std::cout << "Enter a number for factorial: " << std::endl;
    std::cin >> n;
    std::cout << "Factorial of " << n << " is " << factorial(n) << std::endl;
    return 0;
}