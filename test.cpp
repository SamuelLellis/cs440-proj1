#include "Deque.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

TEST_MACRO(int)


int main(){

    int_Container test;
    Deque_int_ctor(&test,0);
    //test.int_container = (int *)malloc(sizeof(int)*10);
    test.int_container[2] = 6;
    //cout<<test.container_head;
    //cout<<test.container_tail;
    //test.int_container = (int *)malloc(sizeof(int)*50);
    //test.container_size = 5;
    //cout<<test.size(&test);
    //cout<<test.empty(&test);
    //cout<<test.at(&test,13);
    //test.container_numElements = 10;
    test.push_front(&test, 9);
    test.push_front(&test,8);
    test.push_front(&test,7);
    test.push_front(&test,6);
    test.push_front(&test,5);
    test.push_front(&test,4);
    test.push_front(&test,3);
    test.push_front(&test,2);
    test.push_front(&test,1);
    test.push_front(&test,0);
    //cout <<"No head?\n";
    //cout << test.container_tail << "\n";
    test.push_front(&test,68);
    test.push_front(&test,67);
    test.push_front(&test,66);
    test.push_front(&test,65);
    test.push_front(&test,64);
    test.push_front(&test,63);
    test.push_front(&test,62);
    test.push_front(&test,61);
    test.push_front(&test,60);
    test.push_front(&test,59);
    //test.push_front(&test,58);
    for(int i = 0; i < test.container_size; i++){
         cout<<test.at(&test,i) << "\n";
    }
    cout <<"\n";
    cout <<test.container_tail << "\n";
    cout << test.container_head << "\n";
    cout<<test.container_numElements << "\n";

return 0;

}
