#include "Deque.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

TEST_MACRO(int)


int main(){

    int_Container test;
    Deque_int_ctor(&test,0);
    //test.int_container = (int *)malloc(sizeof(int)*10);
    //test.int_container[2] = 6;
    //cout<<test.container_head;
    //cout<<test.container_tail;
    //test.int_container = (int *)malloc(sizeof(int)*50);
    //test.container_size = 5;
    //cout<<test.size(&test);
    //cout<<test.empty(&test);
    //cout<<test.at(&test,13);
    //test.container_numElements = 10;
    test.push_back(&test, 1);
    test.push_front(&test,2);
    test.push_back(&test,3);
    test.pop_front(&test);
    test.pop_back(&test);
    //test.push_front(&test,69);
    //test.pop_back(&test);
    //test.pop_front(&test);
    //test.pop_front(&test);
    //test.push_front(&test,50);
    //test.push_back(&test,6);
    //test.push_back(&test,5);
    //test.push_front(&test,4);
    //test.push_front(&test,3);
    //test.push_back(&test,2);
    //test.push_front(&test,1);
    //test.push_back(&test,0); 
    //cout <<"No head?\n";
    //cout << test.container_tail << "\n";
    //test.push_back(&test,68);
    //test.push_back(&test,67);
   /* test.push_back(&test,66);
    test.push_back(&test,65);
    test.push_back(&test,64);
    test.push_back(&test,63);
    test.push_back(&test,62);
    test.push_back(&test,61);
    test.push_back(&test,60);
    test.push_back(&test,59);
    test.push_back(&test,58); */
    for(int i = 0; i < test.container_size; i++){
         cout<<test.at(&test,i) << "\n";
    }
    cout <<"\n";
    cout <<test.container_tail << "\n";
    cout << test.container_head << "\n";
    cout<<test.container_numElements << "\n";

return 0;

}
