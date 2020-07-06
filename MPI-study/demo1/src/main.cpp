#include <iostream>
#include "iostream"

#include "mpi.h"

#if 0
int main(){
    printf("xxxx");
    return 0;
}
#endif

#if 1
int main(int argc, char** argv){
    //初始化MPI环境
    MPI_Init(NULL, NULL);

    //获取进程数
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    //获取进程的等级
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    //获取进程的名字
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    //打印helloworld
    printf("Hello world from processor %s, rank %d out of %d processors\n",processor_name, world_rank, world_size);

    //关闭MPI环境
    MPI_Finalize();
}
#endif