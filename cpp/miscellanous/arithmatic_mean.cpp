#include <iostream>
using std::cin, std::cout;

int main()
{
    int num, i, arr[50], sum = 0;
    cout << "\n How Many Numbers You Want to Enter? \n";
    cin >> num;
    cout << "\n Enter " << num << " Numbers : \n";
    for (i = 0; i < num; i++)
    {
        cin >> arr[i];
        sum = sum + arr[i];
    }
    int armean = sum / num;
    cout << "\n Arithmetic Mean = " << armean;
    return 0;
}