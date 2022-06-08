#include <iostream>
using std::cout, std::cin;


int main()
{
    int large, arr[100], size, i;
    cout << "\n Enter Array Size (Max 100): ";
    cin >> size;
    cout << "\n Enter Array Elements : \n";
    for (i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "\n Searching for Largest Number ...\n\n";
    large = arr[0];
    for (i = 0; i < size; i++)
    {
        if (large < arr[i])
        {
            large = arr[i];
        }
    }
    cout << "Largest Number = " << large;
    return 0;
}