#include "ArrayList.hpp"
#include <string>
#include <iostream>

int main()
{
    int arr [3] = {1,2,3};
    ArrayList<int> l(arr, 3);

    std::cout << "List: " << l << std::endl;

    float arr2 [5] = {1.2f, -1.2f, 2.1f, 0.2f, 0.0f};
    ArrayList<float> l2(arr2, 5);

    std::cout << "List: " << l2 << std::endl;

    std::string s_arr [7] = {"This", "is", "some", "text"};
    ArrayList<std::string> l3(s_arr, 7);

    std::cout << "List: " << l3 << std::endl;

    std::cout << std::to_string(l[1]) << std::endl;
    std::cout << std::to_string(l2[1]) << std::endl;

    l[2] = 300;
    std::cout << l << std::endl;

    std::cout << std::to_string(l.pop(2)) << std::endl;
    std::cout << "List: " << l << std::endl;

}