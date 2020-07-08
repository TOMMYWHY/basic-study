#include <iostream>
#include "iostream"
#include "mpi.h"

using namespace std;

#if 01
int main(int argc,char** argv){
    MPI_Init(NULL,NULL);
    int world_size;
    MPI_Comm_rank(MPI_COMM_WORLD,&world_size);
    cout <<"word_size: "<<world_size <<endl;
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    cout <<"world_rank: "<<world_rank <<endl;

    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
    cout <<"processor_name: "<<processor_name <<endl;


    printf("Hello world from processor %s, rank %d out of %d processors\n", processor_name, world_rank, world_size);
    MPI_Finalize();

    printf("xxxx");
    return 0;
}
#endif

/*=env done=*/
#if 0
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