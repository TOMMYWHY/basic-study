//
// Created by Tommy on 2020/7/7.
//

#ifndef ALGORITHM1_MYSTACK_H
#define ALGORITHM1_MYSTACK_H
#include <stddef.h>
template<class T>
class MyStack{
    T* pBuff;
    size_t capacity;
    size_t len;
public:
    MyStack(){pBuff=NULL;capacity=len=0;}
    ~MyStack(){if(pBuff) delete [] pBuff; pBuff=NULL; capacity=NULL;}

    void push(const T&data){
        if (len>=capacity){
            capacity=capacity+(((capacity>>1)>1)?(capacity>>1):1);
            T* pNew =new T[capacity];
            if(pBuff){
                memcpy(pNew,pBuff,sizeof(T)*len);
                delete [] pBuff;
            }
            pBuff=pNew;
        }
        pBuff[len++]=data;
    };
    void pop(void){
        len--;
    };

    T getTop(void){
        return pBuff[len-1];
    };
    bool isEmpty(void){
        return (len==0);
    };
};

#endif //ALGORITHM1_MYSTACK_H
