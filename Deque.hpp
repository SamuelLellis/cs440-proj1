//File Created
#ifndef CONTAINER
#define CONTAINER

#include<iostream>
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

using namespace std;


#define Deque_DEFINE(Type)                                                                                      \
    struct Deque_##Type;                                                                                        \
    struct Deque_##Type##_Iterator {                                                                            \
        Deque_##Type* container;                                                                                \
        int iter;                                                                                               \
        void(*inc)(Deque_##Type##_Iterator* iter);                                                              \
        void(*dec)(Deque_##Type##_Iterator* iter);                                                              \
        Type&(*deref)(Deque_##Type##_Iterator* iter);                                                           \
    };                                                                                                          \
    struct Deque_##Type{                                                                                        \
	/*const*/ char *type_name;                                                                              \
        Type * Type##_container;                                                                                \
        size_t container_size;                                                                                     \
        int container_numElements;                                                                              \
        int container_head;                                                                                     \
        int container_tail;                                                                                     \
        size_t (*size)(Deque_##Type* con);                                                                         \
        bool (*empty)(Deque_##Type* con);                                                                       \
        Type& (*at)(Deque_##Type* con, int index);                                                              \
        void (*push_front)(Deque_##Type* con, Type element);                                                    \
        void (*push_back)(Deque_##Type* con, Type element);                                                     \
        void (*pop_front)(Deque_##Type* con);                                                                   \
        void (*pop_back)(Deque_##Type* con);                                                                    \
        void (*clear)(Deque_##Type* con);                                                                       \
        Type& (*front)(Deque_##Type* con);                                                                      \
        Type& (*back)(Deque_##Type* con);                                                                       \
        void (*dtor)(Deque_##Type* con);                                                                        \
        Deque_##Type##_Iterator(*begin)(Deque_##Type* con);                                                     \
        Deque_##Type##_Iterator(*end)(Deque_##Type* con);                                                       \
        bool (*less_than)(const Type& a, const Type& b);                                                        \
        void (*sort)(Deque_##Type* con, Deque_##Type##_Iterator a, Deque_##Type##_Iterator);                    \
    };                                                                                                          \
				                                                                                \
    size_t Type##_getSize(Deque_##Type* con){                                                                      \
        return con->container_numElements;                                                                      \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
                                                                                                                \
                                                                                                                \
    bool Type##_checkEmpty(Deque_##Type* con){                                                                  \
        if(con->container_numElements == 0){                                                                    \
            return false;                                                                                       \
        }                                                                                                       \
        return true;                                                                                            \
    }                                                                                                           \
                                                                                                                \
    Type& Type##_indexAt(Deque_##Type* con, int index){                                                         \
        return con->Type##_container[(index + con->container_head) % con->container_size];                      \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
                                                                                                                \
    Type* dynamicResize(Deque_##Type* con){                                                                     \
        Type* newContainer = (Type *) (malloc(sizeof(Type) * (con->container_size * 2)));                       \
        int newArrayIndex = 0;                                                                                  \
        for(int iter = con->container_head; iter < ((int)con->container_size + con->container_head); iter++){        \
          /*  cout << con->Type##_container[(iter%con->container_size)] << " ";*/                               \
            newContainer[newArrayIndex] = con->Type##_container[(iter%con->container_size)];                    \
            newArrayIndex++;                                                                                    \
        }                                                                                                       \
        return newContainer;                                                                                    \
    }                                                                                                           \
                                                                                                                \
    void Type##_pushFront(Deque_##Type* con, Type element){              \
        if((int)con->container_size == con->container_numElements){           \
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
    void Type##_pushBack(Deque_##Type* con, Type element){            \
        if((int)con->container_size == con->container_numElements){            \
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
        else if (con->container_tail == (int)con->container_size - 1){         \
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
    void Type##_popFront(Deque_##Type* con){                          \
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
            if(con->container_head == (int)con->container_size - 1){           \
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
    void Type##_popBack(Deque_##Type* con){                               \
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
    void Type##_clearCon(Deque_##Type* con){                              \
        con->container_head = -1;                                         \
        con->container_tail = -1;                                         \
        con->container_numElements = 0;                                   \
    }                                                                     \
                                                                          \
    Type& Type##_getFront(Deque_##Type* con){                             \
        return con->Type##_container[con->container_head];                \
    }                                                                     \
                                                                          \
    Type& Type##_getBack(Deque_##Type* con){                              \
        return con->Type##_container[con->container_tail];                \
    }                                                                     \
                                                                          \
    void Type##_dtorDeque(Deque_##Type* con){                             \
        free(con->Type##_container);                                      \
    }                                                                     \
                                                                          \
                                                                          \
                                                                          \
                                                                           \
    void Type##_Iterator_inc(Deque_##Type##_Iterator* iterator){           \
        iterator->iter = iterator->iter + 1;                               \
                                                                           \
    }                                                                      \
                                                                           \
    void Type##_Iterator_dec(Deque_##Type##_Iterator* iterator){           \
       iterator->iter = iterator->iter - 1;                                \
    }                                                                      \
                                                                           \
    Type& Type##_Iterator_deref(Deque_##Type##_Iterator* iterator){                            \
        return iterator->container->at(iterator->container, iterator->iter);          \
    }                                                                                 \
                                                                                      \
   Deque_##Type##_Iterator Type##_iter_begin(Deque_##Type* con){                     \
        Deque_##Type##_Iterator dequeIter;                                            \
        dequeIter.iter = con->container_head;                                        \
        dequeIter.inc = &Type##_Iterator_inc;                                        \
        dequeIter.dec = &Type##_Iterator_dec;                                        \
	return dequeIter;                                                             \
    }                                                                                 \
                                                                                      \
    Deque_##Type##_Iterator Type##_iter_end(Deque_##Type* con){                       \
        Deque_##Type##_Iterator dequeIter;                                            \
        dequeIter.iter = con->container_tail+1;                                      \
        dequeIter.inc = &Type##_Iterator_inc;                                         \
        dequeIter.dec = &Type##_Iterator_dec;                                         \
	return dequeIter;                                                             \
    }                                                                                 \
                                                                                      \
    int Type##_qsortCompare(const void * a, const void * b, void * context){                                              \
        Deque_##Type* con = (Deque_##Type*)context;                                                                       \
        Type* element1 = (Type*)a;                                                                                        \
        Type* element2 = (Type*)b;                                                                                        \
                                                                                                                          \
        bool lessThan = con->less_than(*element1,*element2);                                                              \
        bool greaterThan = con->less_than(*element2, *element1);                                                          \
                                                                                                                          \
        if(lessThan){                                                                                                     \
            return -1;                                                                                                    \
        }                                                                                                                 \
        if(greaterThan){                                                                                                  \
            return 1;                                                                                                     \
        }                                                                                                                 \
        return 0;                                                                                                         \
                                                                                                                          \
    }                                                                                                                     \
                                                                                                                          \
    void Type##_sortIter(Deque_##Type* con, Deque_##Type##_Iterator iter1, Deque_##Type##_Iterator iter2){                \
        Type * sortVals;                                                                                                  \
        sortVals = (Type *)(malloc(sizeof(Type) * (iter2.iter - iter1.iter)));                                            \
                                                                                                                          \
        int fillArr = 0;                                                                                                  \
        for(int iter = iter1.iter; iter < (iter2.iter - iter1.iter); iter++){                                             \
            sortVals[fillArr] = con->at(con,iter);                                                                        \
            fillArr++;                                                                                                    \
        }                                                                                                                 \
                                                                                                                          \
                                                                                                                         \
                                                                                                                          \
        qsort_r(sortVals, (iter2.iter - iter1.iter), sizeof(Type), Type##_qsortCompare, con);                              \
                                                                                                                          \
        int getArr = 0;                                                                                                   \
        for(int iterFill = iter1.iter; iterFill < (iter2.iter - iter1.iter); iterFill++){                                          \
            con->Type##_container[iterFill] = sortVals[getArr];                                                               \
            getArr++;                                                                                                     \
        }                                                                                                                  \
    }                                                                                                                     \
                                                                                                                          \
    bool Deque_##Type##_equal(Deque_##Type con1, Deque_##Type con2){                                                      \
        if(con1.container_numElements != con2.container_numElements){                                                   \
            return 0;                                                                                                     \
        }                                                                                                                 \
                                                                                                                          \
        for(int iter = 0; iter < (int)con1.container_size; iter++){                                                      \
            if( !(con1.less_than(  (con1.at(&con1,iter))  , (con2.at(&con2,iter)))) && !(con2.less_than((con2.at(&con2,iter)),(con1.at(&con1,iter))))){         \
                return 0;                                                                                                 \
            }                                                                                                             \
        }                                                                                                                 \
                                                                                                                          \
        return 1;                                                                                                         \
    }                                                                                                                     \
                                                                                                                          \
    bool Deque_##Type##_Iterator_equal(Deque_##Type##_Iterator iter1, Deque_##Type##_Iterator iter2){                     \
        if(iter1.iter == iter2.iter){                                                                                   \
            return 1;                                                                                                     \
        }                                                                                                                 \
        return 0;                                                                                                         \
    }                                                                                                                     \
                                                                                                                          \
    void Deque_##Type##_ctor(Deque_##Type* con, bool(*pFunc)(const Type&, const Type&)){       \
	con->type_name = {0};                                                                  \
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
        con->front = &Type##_getFront;                                                     \
        con->back = &Type##_getBack;                                                      \
        con->dtor =&Type##_dtorDeque;                                                     \
        con->begin = &Type##_iter_begin;                                                  \
        con->end = &Type##_iter_end;                                                      \
        con->less_than = pFunc;                                                          \
    }                                                                                    \







#endif 
