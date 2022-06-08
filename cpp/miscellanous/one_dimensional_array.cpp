#include <iostream>
using std::cout, std::cin;


int main()
{
    int arr[50], num, i;
    cout << "\n How Many Elements You Want to Store into an Array? \n";
    cin >> num;
    cout << "\n Enter " << num << " Elements to Store into an Array : \n";
    for (i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    cout << "\n The Elements in the Array are : \n";
    for (i = 0; i < num; i++)
    {
        cout << arr[i] << "\t";
    }
    return 0;
}