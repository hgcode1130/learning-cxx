#include "../exercise.h"
#include <array>
#include <cstring>

// READ: std::array <https://zh.cppreference.com/w/cpp/container/array>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    {
        std::array<int, 5> arr{{1, 2, 3, 4, 5}};
        ASSERT(arr.size() == 5, "Fill in the correct value.");               // 数组大小为 5
        ASSERT(sizeof(arr) == 5 * sizeof(int), "Fill in the correct value.");// sizeof(arr) = 5 * sizeof(int)
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(arr.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");// 比较内存块
    }
    {
        std::array<double, 8> arr;
        ASSERT(arr.size() == 8, "Fill in the correct value.");                  // 数组大小为 8
        ASSERT(sizeof(arr) == 8 * sizeof(double), "Fill in the correct value.");// sizeof(arr) = 8 * sizeof(double)
    }
    {
        std::array<char, 21> arr{"Hello, InfiniTensor!"};
        ASSERT(arr.size() == 21, "Fill in the correct value.");                                    // 数组大小为 21
        ASSERT(sizeof(arr) == 21, "Fill in the correct value.");                                   // sizeof(arr) = 21
        ASSERT(std::strcmp(arr.data(), "Hello, InfiniTensor!") == 0, "Fill in the correct value.");// 比较字符串
    }
    return 0;
}
