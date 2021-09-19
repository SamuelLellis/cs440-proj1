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
        void (*push_front)(Type##_Container* con, Type element);      \
        void (*push_back)(Type##_Container* con, Type element);       \
        void (*pop_front)(Type##_Container* con);                     \
        void (*pop_back)(Type##_Container* con);                      \
        void (*clear)(Type##_Container* con);                         \
    };                                                                \
				                                      \
    int Type##_getSize(Type##_Container* con){                         \
        return con->container_numElements;                             \
    }                                                                  \
                                                                       \
                                                                       \
                                                                       \
                                                                       \
    bool Type##_checkEmpty(Type##_Container* con){     \
        if(con->container_numElements == 0){                  \
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
    }                                                                     \
                                                                          \
                                                                          \
                                                                          \
    Type* dynamicResize(Type##_Container* con){                                                                  \
        Type* newContainer = (Type *) (malloc(sizeof(Type) * (con->container_size * 2)));                       \
        int newArrayIndex = 0;                                                                                  \
        for(int iter = con->container_head; iter < (con->container_size + con->container_head); iter++){        \
          /*  cout << con->Type##_container[(iter%con->container_size)] << " ";*/                               \
            newContainer[newArrayIndex] = con->Type##_container[(iter%con->container_size)];                    \
            newArrayIndex++;                                                                                    \
        }                                                                                                       \
        return newContainer;                                                                                    \
    }                                                                   \
                                                                       \
    void Type##_pushFront(Type##_Container* con, Type element){          \
        if(con->container_size == con->container_numElements){           \
            con->Type##_container = dynamicResize(con);                  \
            con->container_tail = con->container_size - 1;                \
            con->container_size = con->container_size * 2;                \
            con->container_head = 0;                                      \
        }                                                                 \
                                                                          \
        if(con->container_head == -1){                                    \
           con->container_head = 0;                                       \
           con->container_tail = 0;                                       \
        }                                                                 \
                                                                          \
        else if (con->container_head == 0){                               \
            con->container_head = con->container_size - 1;                \
        }                                                                 \
                                                                          \
        else{                                                             \
            con->container_head = con->container_head - 1;                \
        }                                                                 \
                                                                          \
        con->Type##_container[con->container_head] = element;             \
        con->container_numElements++;                                     \
    }                                                                     \
                                                                          \
    void Type##_pushBack(Type##_Container* con, Type element){            \
        if(con->container_size == con->container_numElements){            \
            con->Type##_container = dynamicResize(con);                   \
            con->container_tail = con->container_size - 1;                \
            con->container_size = con->container_size * 2;                \
            con->container_head = 0;                                      \
        }                                                                  \
                                                                          \
        if(con->container_head == -1){                                    \
            con->container_head = 0;                                      \
            con->container_tail = 0;                                      \
        }                                                                 \
                                                                          \
        else if (con->container_tail == con->container_size - 1){         \
            con->container_tail = 0;                                      \
        }                                                                 \
                                                                          \
        else{                                                             \
            con->container_tail = con->container_tail + 1;                \
        }                                                                 \
                                                                          \
        con->Type##_container[con->container_tail] = element;             \
        con->container_numElements++;                                     \
                                                                          \
    }                                                                     \
                                                                          \
    void Type##_popFront(Type##_Container* con){                          \
        if(con->container_numElements == 0){                              \
            return;                                                       \
        }                                                                 \
                                                                          \
        if(con->container_numElements == 1){                              \
            con->container_head = -1;                                     \
            con->container_tail = -1;                                     \
        }                                                                 \
                                                                          \
        else{                                                             \
            if(con->container_head == con->container_size - 1){           \
                con->container_head = 0;                                  \
            }                                                             \
            else{                                                         \
                con->container_head = con->container_head + 1;            \
            }                                                             \
        }                                                                 \
        con->container_numElements = con->container_numElements - 1;      \
    }                                                                     \
                                                                          \
                                                                          \
                                                                          \
    void Type##_popBack(Type##_Container* con){                           \
        if(con->container_numElements == 0){                              \
            return;                                                       \
        }                                                                 \
                                                                          \
        if(con->container_numElements == 1){                              \
            con->container_head = -1;                                     \
            con->container_tail = -1;                                     \
        }                                                                 \
                                                                          \
        else if(con->container_tail == 0){                                \
            con->container_tail = con->container_size - 1;                \
        }                                                                 \
                                                                          \
        else{                                                             \
            con->container_tail = con->container_tail - 1;                \
        }                                                                 \
        con->container_numElements = con->container_numElements - 1;      \
    }                                                                     \
                                                                          \
    void Type##_clearCon(Type##_Container* con){                          \
        con->container_head = -1;                                         \
        con->container_tail = -1;                                         \
        con->container_numElements = 0;                                   \
    }                                                                     \
                                                                          \
                                                                          \
    void Deque_##Type##_ctor(Type##_Container* con, unsigned int (*pFunc)(unsigned int)){       \
        con->container_size = 10;                                                          \
        con->container_numElements = 0;                                                   \
        con->container_head = -1;                                                          \
        con->container_tail = 0;                                                          \
        con->Type##_container = (Type *)(malloc(sizeof(Type) * 10));                      \
        con->size = &Type##_getSize;                                                      \
        con->empty = &Type##_checkEmpty;                                                      \
        con->at = &Type##_indexAt;                                                        \
        con->push_front = &Type##_pushFront;                                               \
        con->push_back = &Type##_pushBack;                                                \
        con->pop_front = &Type##_popFront;                                                \
        con->pop_back = &Type##_popBack;                                                  \
        con->clear = &Type##_clearCon;                                                     \
    };                                                                                    \







#endif 
