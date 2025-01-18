#include <iostream>
#include <list>
#include "node.h"
int main(int argc, char const *argv[])
{
    //     std::list<int> nums = {1, 2, 3, 4};
    //     for (std::list<int>::iterator it=nums.begin(); it != nums.end(); it++)
    //     {

    //         std::cout << "value: " << *it << "    " << std::endl;
    //         std::cout << "iterator address: " << &it << "    " << std::endl;
    //         std::cout << "element address: " << &(*it) << "     " << std::endl;
    //     }
    int a[] = {3, 7, 9, 15, 20};
    int b[] = {10,20,30,40,50};
    int n = sizeof(a) / sizeof(a[0]);
    node *head;
    node *head2;
    head2 = head2->create_linked(b, n);
    head = head->create_linked(a, n);
    head->isLoop();
    return 0;
}