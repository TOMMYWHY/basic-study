#include "hello_CV_1.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    hello_cv_1::HelloCv_1 helloCv_1_;
    cout << helloCv_1_.getMsgsContent("hello cmake") <<endl;

    return 0;
}
