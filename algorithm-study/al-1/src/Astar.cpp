#include <iostream>
#include <vector>

using namespace std;

/*Astar search算法 */
#if 1
#define COLS 12
#define ROWS 12

struct MyPoint{
    int row;//y
    int col;//x
};
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
    MyPoint endPos={5,10};

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
