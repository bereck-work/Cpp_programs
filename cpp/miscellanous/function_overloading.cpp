#include <iostream>
using std::cout;

// function with float type parameter
float absolute(float var){
    if (var < 0.0)
        var = -var;
    return var;
}

// function with int type parameter
int absolute(int var) {
     if (var < 0)
         var = -var;
    return var;
}

int main() {

    // call function with int type parameter
    cout << "Absolute value of -5 = " << absolute(-5) << "\n";

    // call function with float type parameter
    cout << "Absolute value of 5.5 = " << absolute(5.5f) << "\n";
    return 0;
}
