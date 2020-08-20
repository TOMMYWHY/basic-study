//
// Created by Tommy on 2020/8/20.
//

#ifndef ALGORITHM1_TREENODE_H
#define ALGORITHM1_TREENODE_H
#include <vector>
using namespace std;

struct MyPoint{
    int row;//y
    int col;//x
    int h;
    int f;
    int g;
    void setF(){f=g+h;}
};

enum direct{Up,Right,Down,Left,l_up,l_down,r_up,r_down};

struct pathNode{
    int val;
//    direct dir;
    bool isFind;
};

class TreeNode {
public:
    MyPoint pos;
    vector<TreeNode> child;
    TreeNode* pParent;
    TreeNode();
    TreeNode(int row,int col);
};


#endif //ALGORITHM1_TREENODE_H
