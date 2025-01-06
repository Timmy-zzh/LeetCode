#include <iostream>
#include <vector>
// #include "../utils/Print.h"

/**
 * 冒泡排序实现：
 * 1、两层for循环，外层for循环，每次循环之后，都会将元素中最大元素上升到数组末尾，就像冒泡泡一样
 * 2、内层for循环，控制循环的前后两个元素的大小，并将大的元素，通过交换，移动后后面
 */
void bubbleSort(std::vector<int> array)
{
    int size = array.size();

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                // 交换
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> array = {3, 6, 8, 1, 5, 9};
    // printArr(array);
    bubbleSort(array);
    // printArr(array);

    return 0;
}