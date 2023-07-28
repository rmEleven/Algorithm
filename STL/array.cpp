#include <iostream>
#include <array>

int main()
{
    std::array<int, 5> myArray = {1, 2, 3, 4, 5};

    /* sequential output */
    std::cout << "myArray contains:";
    for (auto it = myArray.begin(); it != myArray.end(); it++)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    std::cout << "myArray contains:";
    for (auto it = myArray.cbegin(); it != myArray.cend(); it++)
        std::cout << ' ' << *it; // cannot modify *it
    std::cout << std::endl;

    std::cout << std::endl;

    /* reverse output */
    std::cout << "myArray contains:";
    for (auto it = myArray.rbegin(); it != myArray.rend(); it++)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    std::cout << "myArray contains:";
    for (auto it = myArray.crbegin(); it != myArray.crend(); it++)
        std::cout << ' ' << *it; // cannot modify *it
    std::cout << std::endl;

    std::cout << std::endl;

    /* size */
    std::cout << "size of myArray: " << myArray.size() << std::endl;
    std::cout << "max size of myArray: " << myArray.max_size() << std::endl;
    std::cout << "sizeof(myArray): " << sizeof(myArray) << std::endl;

    std::cout << std::endl;

    /* empty */
    std::array<int, 0> first;
    std::array<int, 5> second;
    std::cout << "first " << (first.empty() ? "is empty" : "is not empty") << std::endl;
    std::cout << "second " << (second.empty() ? "is empty" : "is not empty") << std::endl;

    std::cout << std::endl;

    /* index */
    // do not check boundaries
    std::cout << "myArray contains:";
    for (int i = 0; i < 5; i++)
        std::cout << ' ' << myArray[i];
    std::cout << std::endl;

    // check boundaries
    std::cout << "myArray contains:";
    for (int i = 0; i < 5; i++)
        std::cout << ' ' << myArray.at(i);
    std::cout << std::endl;

    std::cout << std::endl;

    /* reference */
    std::cout << "front is " << myArray.front() << std::endl;
    std::cout << "back is " << myArray.back() << std::endl;

    std::cout << std::endl;

    /* data */
    int *ptr = myArray.data();
    std::cout << "myArray contains:";
    for (int i = 0; i < 5; i++)
        std::cout << ' ' << *(ptr + i);
    std::cout << std::endl;

    std::cout << std::endl;

    /* fill */
    std::array<int, 5> filled;
    filled.fill(100);
    std::cout << "filled contains:";
    for (int &x : filled)
        std::cout << ' ' << x;
    std::cout << std::endl;

    std::cout << std::endl;

    /* swap */
    std::array<int, 5> X = {1, 2, 3, 4, 5};
    std::array<int, 5> Y = {10, 20, 30, 40, 50};

    std::cout << "before:" << std::endl;
    std::cout << "X:";
    for (int &x : X)
        std::cout << ' ' << x;
    std::cout << std::endl;
    std::cout << "Y:";
    for (int &y : Y)
        std::cout << ' ' << y;
    std::cout << std::endl;

    X.swap(Y);

    std::cout << "after:" << std::endl;
    std::cout << "X:";
    for (int &x : X)
        std::cout << ' ' << x;
    std::cout << std::endl;
    std::cout << "Y:";
    for (int &y : Y)
        std::cout << ' ' << y;
    std::cout << std::endl;

    std::cout << std::endl;

    /* get<index> */
    int tmp = std::get<0>(myArray);
    std::get<0>(myArray) = std::get<1>(myArray);
    std::get<1>(myArray) = tmp;

    std::cout << "myArray contains:";
    for (int &x : myArray)
        std::cout << ' ' << x;
    std::cout << std::endl;

    std::cout << std::endl;

    return 0;
}