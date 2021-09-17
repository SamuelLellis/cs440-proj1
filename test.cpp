#include "Deque.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

TEST_MACRO(int)


int main(){

    int_Container test;
    Deque_int_ctor(&test,0);
    test.int_container = (int *)malloc(sizeof(int)*10);
    test.int_container[2] = 6;
    //cout<<test.container_head;
    //cout<<test.container_tail;
    //test.int_container = (int *)malloc(sizeof(int)*50);
    test.container_size = 5;
    //cout<<test.size(&test);
    //cout<<test.empty(&test);
    cout<<test.at(&test,3);
    //cout<<test.container_size;

return 0;

}
