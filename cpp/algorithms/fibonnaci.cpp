#include <iostream>
using namespace std;


int fib(int n)
{

    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int main(){
    int a = 0;
    cout << "Enter a number that you want to find Fibonacci of: " << endl;
    cin >> a;
    cout << fib(a) << endl;
    return 0;
}