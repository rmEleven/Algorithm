#include <iostream>
#include <vector>

int main()
{
    /* vector::vector */
    std::vector<int> first; // empty vector of ints
    std::cout << "The contents of first are:";
    for (std::vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    std::vector<int> second(4, 5); // four ints with value 5
    std::cout << "The contents of second are:";
    for (std::vector<int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    std::vector<int> third(second.begin(), second.end()); // iterating through second
    std::cout << "The contents of third are:";
    for (std::vector<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    std::vector<int> forth(third); // a copy of third
    std::cout << "The contents of forth are:";
    for (std::vector<int>::iterator it = forth.begin(); it != forth.end(); it++)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    int tmp[] = {1, 2, 3, 4, 5};
    std::vector<int> fifth(tmp, tmp + sizeof(tmp) / sizeof(int));
    std::cout << "The contents of fifth are:";
    for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    std::vector<int> sixth = {1, 2, 3, 4, 5};
    std::cout << "The contents of sixth are:";
    for (int &x : sixth)
        std::cout << ' ' << x;
    std::cout << std::endl;

    std::cout << std::endl;

    /* sequential output */
    std::vector<int> myVector = {1, 2, 3, 4, 5};

    std::cout << "myVector contains:";
    for (auto it = myVector.begin(); it != myVector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    std::cout << "myVector contains:";
    for (auto it = myVector.cbegin(); it != myVector.cend(); it++)
        std::cout << ' ' << *it; // cannot modify *it
    std::cout << std::endl;

    std::cout << std::endl;

    /* reverse output */
    std::cout << "myVector contains:";
    for (auto it = myVector.rbegin(); it != myVector.rend(); it++)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    std::cout << "myVector contains:";
    for (auto it = myVector.crbegin(); it != myVector.crend(); it++)
        std::cout << ' ' << *it; // cannot modify *it
    std::cout << std::endl;

    std::cout << std::endl;

    /* size */

    return 0;
}