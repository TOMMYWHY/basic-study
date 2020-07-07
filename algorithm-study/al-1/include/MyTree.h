//
// Created by Tommy on 2020/7/7.
//

#ifndef ALGORITHM1_MYTREE_H
#define ALGORITHM1_MYTREE_H
#include <string.h>
template<class T>
class MyTree{
    T data;
    MyTree* pParent;
    MyTree* pPeer;
    MyTree* pChild;
public:
    MyTree();
    ~MyTree();
    void insertNode(const T& data, bool isChild=true);

};

template<class T>
MyTree<T>::MyTree() {
    pParent=pPeer=pChild= NULL;
}

template<class T>
MyTree<T>::~MyTree() {}

template<class T>
void MyTree<T>::insertNode(const T &data, bool isChild) {
    MyTree* pNew=new MyTree;
    memset(pNew,0,sizeof(MyTree));
    pNew->data=data;
    if(isChild){

    }else{}
}


#endif //ALGORITHM1_MYTREE_H
