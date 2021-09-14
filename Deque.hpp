//File Created
#ifndef CONTAINER
#define CONTAINER

#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

#define test_macro(Type){ \
    struct Type##_Container{  \
        Type * Type##_container = (Type *)(malloc(sizeof(Type)*10));    \
        int Type##_container_size;  \
        int Type##_container_head;   \
        int Type##_container_tail;    \
    };                   \
        int getSize(Type##_Container con) \
        {   \
            return (sizeof(con.Type##_container))/(sizeof(con.Type##_container[0])); \
        }                   \
}                        \








#endif 
