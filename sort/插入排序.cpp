#include <iostream>
#include <vector>

/**
 * 插入排序：
 * - 双层for循环，外层for循环作为标记元素
 * - 内存for循环往前遍历，遇到比标记元素大的元素则左移
 * - 内层for循环后，前面的数组区间范围都是排序好了的
 */
void insertSort(std::vector<int> &arr)
{
    int size = arr.size();
    for (int i = 1; i < size; i++)
    {
        int index = i;
        int value = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[index])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                index = j;
            }
            else
            {
                break;
            }
        }
        std::cout << "i:" << i << " ,index:" << index << std::endl;
        if (index != i)
        {
            arr[index] = value;
        }

        int size = arr.size();
        for (size_t i = 0; i < size; i++)
        {
            std::cout << arr[i] << ",";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> array = {3, 6, 8, 1, 5, 9};
    int size = array.size();
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << ",";
    }
    std::cout << std::endl;
    std::cout << "insertSort" << std::endl;
    insertSort(array);
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << ",";
    }
    return 0;
}