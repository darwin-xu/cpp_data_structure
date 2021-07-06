#include <iostream>

int main()
{
    int  i;
    int* j = 0;
    int* k = &i;

    std::cout << i << " " << j << " " << k << std::endl;

    *k = 123; // 改动k所指向的地址(i)的数据

    k = (int*)567;  // 改动k所指向的地址

    *k = 567; // 改动k所指向的地址(unknown)的数据

    std::cout << i << " " << j << " " << k << std::endl;

    std::cout << i << std::endl;

    return 0;
}
