//File Created
#ifndef CONTAINER
#define CONTAINER

#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;


#define TEST_MACRO(Type)                                             \
    struct Type##_Container{                                         \
        Type * Type##_container;                                     \
        int container_size;                                          \
        int container_numElements;                                   \
        int container_head;                                          \
        int container_tail;                                          \
        int (*size)(Type##_Container* con);                          \
        bool (*empty)(Type##_Container* con);                       \
        Type (*at)(Type##_Container* con, int index);                \
    };                                                                \
				                                      \
    int Type##_getSize(Type##_Container* con){                         \
        return con->container_size;                                    \
    }                                                                  \
                                                                       \
                                                                       \
                                                                       \
                                                                       \
    bool Type##_checkEmpty(Type##_Container* con){     \
        if(con->container_size == 0){                  \
            return false;                             \
        }                                             \
        return true;                                  \
    }                                                 \
                                                      \
    Type Type##_indexAt(Type##_Container* con, int index){             \
        if(!(con->container_size <= index)){                              \
            for(int iter = 0; iter < con->container_size; iter++){        \
                if(iter == index){                                        \
                    return con->Type##_container[iter];                   \
                }                                                         \
            }                                                             \
        }                                                                 \
        return 0;                                                         \
    }                                                                   \
                                                                       \
                                                                       \
                                                                       \
                                                      \
    void Deque_##Type##_ctor(Type##_Container* con, unsigned int (*pFunc)(unsigned int)){       \
        con->container_size = 0;                                                          \
        con->container_numElements = 0;                                                   \
        con->container_head = 0;                                                          \
        con->container_tail = 0;                                                          \
        con->size = &Type##_getSize;                                                      \
        con->empty = &Type##_checkEmpty;                                                      \
        con->at = &Type##_indexAt;                                                        \
    };                                                                                    \







#endif 
