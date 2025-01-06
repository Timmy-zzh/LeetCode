#include <iostream>
#include <vector>

/**
 * 选择排序
 * - 两层for循环，每层for循环都找到最小元素，并进行交换
 */
void selectSort(std::vector<int> arr)
{
    int size = arr.size();
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            // 判断是否比minIndex元素小，更小则标记
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> array = {3, 6, 8, 1, 5, 9};
    return 0;
}