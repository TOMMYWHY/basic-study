#include <iostream>
#include <vector>
#include<queue>
#include <algorithm>
#include <map>

using namespace std;

/*Astar search算法 */
#if 1
#define ZX 10
#define XX 14
#define COLS 12
#define ROWS 12

/*struct compare_F{
    bool operator()
};*/
struct MyPoint{
    int row;//y
    int col;//x
    int h;
    int f;
    int g;
    void setF(){f=g+h;}
   /* bool operator()(MyPoint a,MyPoint b){
        return a.f>b.f;//小顶堆
    }*/
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
    bool operator()(treeNode a,treeNode b){
        return a.pos.f>b.pos.f;//小顶堆
    }
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
/*bool canWalk( vector<MyPoint> expanded_list , MyPoint nextPos,int map[ROWS][COLS]){
    if(nextPos.row>=ROWS|| nextPos.row<0 || nextPos.col>=COLS || nextPos.col<0 )return false;//
    if(map[nextPos.row][nextPos.col]==1)return false;//wall
    if(pathMap[pos.row][pos.col].isFind)return false;//
//    vector<MyPoint>::iterator ret = find(expanded_list.begin(),expanded_list.end(),nextPos);
//    if(find(expanded_list.begin(),expanded_list.end(),nextPos)==expanded_list.begin())
    for(vector<MyPoint>::iterator it=expanded_list.begin();it!=expanded_list.end();it++){
        if(it[0].row==nextPos.row && it[0].col==nextPos.col){
            return false;
        }
    }
    return true;
};*/
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
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << map[i][j]<<",";
        }
        cout <<endl;
    }
    MyPoint beginPos={1,1}; //(1,1)
    MyPoint endPos={4,9};   //(4,9)

//    vector<MyPoint> expanded_list;
//    map<int,MyPoint> expanded_list;
    pathNode pathMap[ROWS][COLS]={0}; //expanded_list
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            pathMap[i][j].val = map[i][j];
        }
    }
    treeNode* pRoot =NULL;
    pRoot =createNode(beginPos.row,beginPos.col);
    pathMap[beginPos.row][beginPos.col].isFind =true;
//    expanded_list.push_back(beginPos);
//    treeNode* pTemp=pRoot;//当前节点，即父节点
    treeNode* robot=pRoot;//当前节点，即父节点
//    treeNode* pTempChild=NULL;//8个方向指针
    treeNode* robot_next_dirc=NULL;//8个方向指针
//    vector<treeNode*>buff;//存放8个方向的具体数据 //todo priorty queue
    priority_queue<treeNode*> enqueued;
    vector<treeNode*>::iterator it;// 遍历所有
    vector<treeNode*>::iterator itMin;// 遍历F最小


    MyPoint tempPos;
    bool isFindEnd= false;
    while(1){
        for (int i = 0; i < 8; i++) {
            tempPos=pRoot->pos;

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
                robot_next_dirc=createNode(tempPos.row,tempPos.col);
                robot_next_dirc->pos.g=tempPos.g;
                robot_next_dirc->pos.h = getH(robot_next_dirc->pos,endPos);
                robot_next_dirc->pos.setF();
                printf("%d : ( %d,%d) g:%d, h:%d, f:%d \n",i+1, robot_next_dirc->pos.row,robot_next_dirc->pos.col,robot_next_dirc->pos.g,robot_next_dirc->pos.h,robot_next_dirc->pos.f);
                robot->child.push_back(robot_next_dirc);
                robot_next_dirc->pParent=robot;
//                buff.push_back(pTempChild);
                enqueued.push(robot_next_dirc);
            }

        }

        treeNode* enqueued_top =enqueued.top();
//        enqueued.pop();
//        cout << enqueued_top->pos.f<<endl;
        map[enqueued_top->pos.row][enqueued_top->pos.col]=8;
//        itMin=buff.begin();
        /*for(it=buff.begin(); it!=buff.end();it++){
            itMin=((*itMin)->pos.f> (*it)->pos.f)?it:itMin; // todo pop min top
        }*/
//        pTemp = * itMin;
        robot=enqueued_top;
//        expanded_list.push_back(robot->pos);
        pathMap[robot->pos.row][robot->pos.col].isFind=true;
//        buff.erase(itMin);
        enqueued.pop();
        if(robot->pos.row==endPos.row && robot->pos.col==endPos.col){
            isFindEnd=true;
            break;
        }
        if(0==enqueued.size())break;
    }

    if(isFindEnd){
        printf("path \n");
       /* while(pTemp){
            printf("(%d，%d)",pTemp->pos.row,pTemp->pos.col);
            pTemp=pTemp->pParent;
        }*/
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                cout << map[i][j]<<",";
            }
            cout <<endl;
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
