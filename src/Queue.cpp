#include "Queue.hpp"
#include "hidden.hpp"

#include <iostream>
#include <string>

/**
 * Print hidden PI value
*/
void ppi() 
{
    Queue<int> q;

    q.push(1);
    q.push(2);

    std::cout << std::to_string(q.pop()) << std::endl;
    std::cout << std::to_string(BIGPI) << std::endl;
}
