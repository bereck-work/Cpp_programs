#include <iostream>
#include <cmath>
using std::cin, std::cout;

int main() {

  float a, b, c, x1, x2, discriminant, realPart, imaginaryPart;
  cout << "Enter coefficients a, b and c: ";
  cin >> a >> b >> c;
  discriminant = b*b - 4*a*c;

  if (discriminant > 0) {
    x1 = (-b + sqrt(discriminant)) / (2*a);
    x2 = (-b - sqrt(discriminant)) / (2*a);
    cout << "Roots are real and different." << "\n";
    cout << "x1 = " << x1 << "\n";
    cout << "x2 = " << x2 << "\n";
  }

  else if (discriminant == 0) {
    cout << "Roots are real and same." << "\n";
    x1 = -b/(2*a);
    cout << "x1 = x2 =" << x1 << "\n";
  }

  else {
    realPart = -b/(2*a);
    imaginaryPart =sqrt(-discriminant)/(2*a);
    cout << "Roots are complex and different."  << "\n";
    cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << "\n";
    cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << "\n";
  }

  return 0;
}
