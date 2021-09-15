//File Created
#ifndef CONTAINER
#define CONTAINER

#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;


#define TEST_MACRO(Type)  \
    struct Type##_Container{  \
        Type * Type##_container;    \
        int container_size;  \
        int container_head;   \
        int container_tail;    \
        }; \
				\
    int Type##_getSize(Type##_Container con){                    \
        return con.container_size;               \
    }					\








#endif 
