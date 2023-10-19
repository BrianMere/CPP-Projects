#include "Queue.hpp"
#include <iostream>//

// TEST CODE!!!

int main()
{
    

    Queue<int> q;

    q.push(1);
    q.push(2);
    q.push(1);

    std::cout << std::to_string(q.pop()) << std::endl;

    Queue<std::string> r;

    r.push("Test");
    r.push("This");
    r.push("Out");

    std::cout << r.pop() << std::endl;


    exit(0);
}