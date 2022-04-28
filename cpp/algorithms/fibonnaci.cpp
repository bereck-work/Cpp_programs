#include <iostream>
using std::cout, std::endl, std::cin;


int fibonacci(int n)
// This function returns the nth Fibonacci number, using recursion.
{

    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

// Main program
int main(){
    int a = 0;
    cout << "Enter a number that you want to find Fibonacci of: " << endl;
    cin >> a;
    cout << fibonacci(a) << endl;
    return 0;
}
