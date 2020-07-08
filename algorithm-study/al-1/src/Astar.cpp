#include <iostream>
#include <vector>

using namespace std;

/*Astar search算法 */
#if 1
#define ZX 10
#define XX 14
#define COLS 12
#define ROWS 12

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

struct treeNode{
    MyPoint pos;
    vector<treeNode*> child;
    treeNode* pParent;
};

//treeNode * createNode(const MyPoint& point )
treeNode * createNode(int row,int col)
{
    treeNode* pNew= new treeNode;
    memset(pNew,0,sizeof(treeNode));
    pNew->pos.row=row;
    pNew->pos.col=col;
    return pNew;
}
bool canWalk(pathNode pathMap[ROWS][COLS], MyPoint pos){
    if(pos.row>=ROWS|| pos.row<0 || pos.col>=COLS || pos.col<0 )return false;//
    if(pathMap[pos.row][pos.col].isFind)return false;//
    if(pathMap[pos.row][pos.col].val)return false;//wall
    return true;
};
int getH(MyPoint& currentPos,MyPoint& endPos){
    int x =( currentPos.col > endPos.col)?(currentPos.col-endPos.col):(endPos.col-currentPos.col);
    int y =( currentPos.row > endPos.row)?(currentPos.row-endPos.row):(endPos.row-currentPos.row);
    return  (x+y)*ZX;
}

int main() {

    int map[ROWS][COLS]={
            {0,0,0,0,1,0,0,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0,0,0},
    };

    MyPoint beginPos={1,1};
    MyPoint endPos={4,9};

    pathNode pathMap[ROWS][COLS]={0};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            pathMap[i][j].val = map[i][j];
        }
    }
    treeNode* pRoot =NULL;
    pRoot =createNode(beginPos.row,beginPos.col);
    pathMap[beginPos.row][beginPos.col].isFind =true;
    treeNode* pTemp=pRoot;//当前节点，即父节点
    treeNode* pTempChild=NULL;//8个方向指针
    vector<treeNode*>buff;//存放8个方向的具体数据
    vector<treeNode*>::iterator it;// 遍历所有
    vector<treeNode*>::iterator itMin;// 遍历F最小


    MyPoint tempPos;
    bool isFindEnd= false;
    while(1){
        for (int i = 0; i < 8; i++) {
            tempPos=pTemp->pos;

            switch (i) {
                case Up:
                    tempPos.row--;
                    tempPos.g+=ZX;
                    break;
                case Down:
                    tempPos.row++;
                    tempPos.g+=ZX;
                    break;
                case Left:
                    tempPos.col--;
                    tempPos.g+=ZX;
                    break;
                case Right:
                    tempPos.col++;
                    tempPos.g+=ZX;
                    break;
                case l_up:
                    tempPos.row--;
                    tempPos.col--;
                    tempPos.g+=XX;
                    break;
                case l_down:
                    tempPos.row++;
                    tempPos.col--;
                    tempPos.g+=XX;
                    break;
                case r_up:
                    tempPos.row--;
                    tempPos.col++;
                    tempPos.g+=XX;
                    break;
                case r_down:
                    tempPos.row++;
                    tempPos.col++;
                    tempPos.g+=XX;
                    break;
            }
            if(canWalk(pathMap,tempPos)){
                pTempChild=createNode(tempPos.row,tempPos.col);
                pTempChild->pos.g=tempPos.g;
                pTempChild->pos.h = getH(pTempChild->pos,endPos);
                pTempChild->pos.setF();
                printf("%d : ( %d,%d) g:%d, h:%d, f:%d \n",i+1, pTempChild->pos.row,pTempChild->pos.col,pTempChild->pos.g,pTempChild->pos.h,pTempChild->pos.f);
                pTemp->child.push_back(pTempChild);
                pTempChild->pParent=pTemp;
                buff.push_back(pTempChild);
            }

        }

        itMin=buff.begin();
        for(it=buff.begin(); it!=buff.end();it++){
            itMin=((*itMin)->pos.f> (*it)->pos.f)?it:itMin;
        }
        pTemp = * itMin;
        pathMap[pTemp->pos.row][pTemp->pos.col].isFind=true;
        buff.erase(itMin);
        if(pTemp->pos.row==endPos.row && pTemp->pos.col==endPos.col){
            isFindEnd=true;
            break;
        }
        if(0==buff.size())break;
    }

    if(isFindEnd){
        printf("path \n");
        while(pTemp){
            printf("(%d，%d)",pTemp->pos.row,pTemp->pos.col);
            pTemp=pTemp->pParent;
        }
        printf("\n");
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
