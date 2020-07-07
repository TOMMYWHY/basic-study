#include <iostream>
#include <vector>

using namespace std;

/*BFS（Breath First Search）广度优先搜索
 * 树结构，可以找到最短路线
 *
 * todo err....
 * */
#if 01
#define COLS 10
#define ROWS 10
enum direct{p_up,p_right,p_down,p_left};
struct MyPoint{
    int row;//y
    int col;//x
};
struct pathNode{
    int val;
    direct dir;
    bool isFind;
};
struct treeNode{
    MyPoint pos;
    vector<treeNode*> child;
    treeNode* pParent;
};

treeNode* createNode(int row,int col){
    treeNode * pNew= new treeNode;
    memset(pNew,0,sizeof(treeNode));
    pNew->pos.row=row;
    pNew->pos.col=col;
    return pNew;
}
bool canWalk(pathNode pathMap[ROWS][COLS],MyPoint pos){
    if(pathMap[pos.row][pos.col].isFind)return false;//
    if(pathMap[pos.row][pos.col].val)return false;//wall

    return true;
}
int main(){

    int map[ROWS][COLS]={
            {1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,1,0,1,1,1,1},
            {1,0,1,0,1,0,0,0,0,1},
            {1,0,0,0,1,0,1,1,0,1},
            {1,0,1,0,1,0,0,0,0,1},
            {1,0,1,0,1,0,1,1,0,1},
            {1,0,1,0,0,0,1,1,0,1},
            {1,0,1,0,1,0,1,1,0,1},
            {1,0,0,0,1,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1}
    };
    pathNode pathMap[ROWS][COLS]={0};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            pathMap[i][j].val = map[i][j];
        }
    }
    MyPoint beginPos={1,1};
    MyPoint endPos={8,8};
    treeNode * pRoot = NULL;
    pRoot=createNode(beginPos.row,beginPos.col);
    pathMap[beginPos.row][beginPos.col].isFind=true;
    MyPoint temPo;
    vector<treeNode*> buff; //current tree layers
    buff.push_back(pRoot);
    treeNode * tempNode =NULL;
    vector<treeNode*> nextBuff; //
    bool flag = false;
    while(flag!=true){
        for (int i = 0; i < buff.size(); i++) {
            for (int j = 0; j < 4; j++) {
                temPo=buff[i]->pos;
                switch (j) {
                    case p_up:temPo.row--;break;
                    case p_down:temPo.row++;break;
                    case p_left:temPo.col--;break;
                    case p_right:temPo.col++;break;
                }
                if(canWalk(pathMap,temPo)){
                    pathMap[temPo.row][temPo.col].isFind=true;
                    tempNode = createNode(temPo.row,temPo.col);
                    buff[i]->child.push_back(tempNode);
                    tempNode->pParent=buff[i];
                    nextBuff.push_back(tempNode);
                    cout <<"temPo:"<<temPo.row << ","<< temPo.col<<endl;
                    if(temPo.row==endPos.row && temPo.col==endPos.col){
                        flag=true;
                        printf("flag");
                    }
                    if(flag) break;
                }
            }
            if(flag)break;
        }
        if(flag)break;
        if(nextBuff.size()==0)
            break;
        buff=nextBuff;//next tree layer
    }

    if(flag){
        cout <<"path:"<<endl;
        while(tempNode){
            cout <<"("<<tempNode->pos.row <<","<<tempNode->pos.col<<")"<<endl;
            tempNode=tempNode->pParent;
        }
    }
//    printf("aaa");
    return 0;
}
#endif

/*DFS 深度优先搜索算法*/
#if 00

#include "MyStack.h"

enum direct{p_up,p_right,p_down,p_left};
struct pathNode{
    int val;
    direct dir;
    bool isFind;
};
struct MyPoint{
    int row;//y
    int col;//x
};
void printMap(int map[8][8],MyPoint pos){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(i==pos.row && j==pos.col){
                printf(" * ");
            }else if(map[i][j]==1){
                printf(" | ");
            }else{
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}
int main() {

    int map[8][8]={
            {1,1,1,1,1,1,1,1},
            {1,0,1,0,0,0,0,1},
            {1,0,1,0,1,0,1,1},
            {1,0,1,0,1,0,1,1},
            {1,0,1,0,1,0,0,1},
            {1,0,1,0,1,0,1,1},
            {1,0,0,0,1,0,0,1},
            {1,1,1,1,1,1,1,1}
    };
    pathNode pathMap[8][8]={0};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            pathMap[i][j].val = map[i][j];
        }
    }

    MyPoint beginPos={1,1};
    MyPoint endPos={6,6};
    MyStack<MyPoint> stack;
    pathMap[beginPos.row][beginPos.col].isFind=true;
    stack.push(beginPos);
    MyPoint currentPos = beginPos;
    MyPoint searchPos;
    bool flag = false;
    while(flag==false){
        searchPos = currentPos;
        switch (pathMap[currentPos.row][currentPos.col].dir) {
            case p_up:
                searchPos.row--; // 假设 向上 为通路
                pathMap[currentPos.row][currentPos.col].dir = p_right;
                if(pathMap[searchPos.row][searchPos.col].isFind!=true&&pathMap[searchPos.row][searchPos.col].val !=1){
                    currentPos=searchPos;
                    pathMap[currentPos.row][currentPos.col].isFind=true;
                    stack.push(currentPos);
                }
                break;

            case p_right:
                searchPos.col++; // 假设 向上 为通路
                pathMap[currentPos.row][currentPos.col].dir = p_down;
                if(pathMap[searchPos.row][searchPos.col].isFind!=true&&pathMap[searchPos.row][searchPos.col].val !=1){
                    currentPos=searchPos;
                    pathMap[currentPos.row][currentPos.col].isFind=true;
                    stack.push(currentPos);
                }
                break;

            case p_down:
                searchPos.row++; // 假设 向上 为通路
                pathMap[currentPos.row][currentPos.col].dir = p_left;
                if(pathMap[searchPos.row][searchPos.col].isFind!=true&&pathMap[searchPos.row][searchPos.col].val !=1){
                    currentPos=searchPos;
                    pathMap[currentPos.row][currentPos.col].isFind=true;
                    stack.push(currentPos);
                }
                break;

            case p_left:
                searchPos.col--; // 假设 向上 为通路
//                pathMap[currentPos.row][currentPos.col].dir = p_right;
                if(pathMap[searchPos.row][searchPos.col].isFind!=true&&pathMap[searchPos.row][searchPos.col].val !=1){
                    currentPos=searchPos;
                    pathMap[currentPos.row][currentPos.col].isFind=true;
                    stack.push(currentPos);
                }else{
                    stack.pop();
                    currentPos=stack.getTop();
                }
                break;
        }
        printMap(map,currentPos);
        if(currentPos.row==endPos.row && currentPos.col==endPos.col){
            flag = true;
            break;
        }
        if(stack.isEmpty()){
            break;
        }
    }
    if(flag ==true){
        cout << " The end:"<<endl;
        while(!stack.isEmpty()){
            printf("(%d,%d)\n",stack.getTop().row,stack.getTop().col);
            stack.pop();
        }
    }



    return 0;
}
#endif


/* N-tree */
#if 0

#include "MyTree.h"
int main() {
//    std::cout << "Hello, World!" << std::endl;
    MyTree<int>tree;
    return 0;
}
#endif
