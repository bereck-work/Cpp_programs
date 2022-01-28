#include <iostream>

void main()
{

    int hold;
    int array[5];
    std::cout << "Enter 5 numbers: " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cin >> array[i];
    }
    std::cout << std::endl;
    std::cout << "Orignally entered array by the user is: " << std::endl;

    for (int j = 0; j < 5; j++)
    {
        std::cout << array[j];
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (array[j] > array[j + 1])
            {
                hold = array[j];
                array[j] = array[j + 1];
                array[j + 1] = hold;
            }
        }
    }
    std::cout << "Sorted Array is: " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << array[i] << std::endl;
    }