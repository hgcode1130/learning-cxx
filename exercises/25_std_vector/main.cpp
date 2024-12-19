#include "../exercise.h"
#include <cstring>
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    {
        std::vector<int> vec{1, 2, 3, 4, 5};
        ASSERT(vec.size() == 5, "Fill in the correct value.");                        // 大小应为 5
        ASSERT(sizeof(vec) == sizeof(std::vector<int>), "Fill in the correct value.");// sizeof 为 std::vector<int> 的大小
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");// 使用 data() 获取指针
    }
    {
        std::vector<double> vec{1, 2, 3, 4, 5};
        {
            ASSERT(vec.size() == 5, "Fill in the correct value.");                           // 大小应为 5
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value.");// sizeof 为 std::vector<double> 的大小
            double ans[]{1, 2, 3, 4, 5};
            ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");// 使用 data() 获取指针
        }
        {
            vec.push_back(6);
            ASSERT(vec.size() == 6, "Fill in the correct value.");                           // 大小应为 6
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value.");// sizeof 为 std::vector<double> 的大小
            vec.pop_back();
            ASSERT(vec.size() == 5, "Fill in the correct value.");                           // 大小应回到 5
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value.");// sizeof 为 std::vector<double> 的大小
        }
        {
            vec[4] = 6;                                       // 设置最后一个元素为 6
            ASSERT(vec[0] == 1, "Fill in the correct value.");// 第 0 个元素应为 1
            ASSERT(vec[1] == 2, "Fill in the correct value.");// 第 1 个元素应为 2
            ASSERT(vec[2] == 3, "Fill in the correct value.");// 第 2 个元素应为 3
            ASSERT(vec[3] == 4, "Fill in the correct value.");// 第 3 个元素应为 4
            ASSERT(vec[4] == 6, "Fill in the correct value.");// 第 4 个元素应为 6
        }
        {
            // THINK: `std::vector` 插入删除的时间复杂度是什么？
            vec.insert(vec.begin() + 1, 1.5);                                                     // 在索引 1 插入 1.5
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 3, 4, 6}), "Make this assertion pass.");// 检查向量内容
            vec.erase(vec.begin() + 3);                                                           // 删除索引 3 的元素
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 4, 6}), "Make this assertion pass.");   // 检查向量内容
        }
        {
            vec.shrink_to_fit();                                      // 调整容量以适应当前大小
            ASSERT(vec.capacity() == 5, "Fill in the correct value.");// 容量应为 5
            vec.clear();                                              // 清空向量
            ASSERT(vec.empty(), "`vec` is empty now.");               // 应为空
            ASSERT(vec.size() == 0, "Fill in the correct value.");    // 大小应为 0
            ASSERT(vec.capacity() == 5, "Fill in the correct value.");// 容量在清空后仍应为 5
        }
    }
    {
        std::vector<char> vec(48, 'z');                                                // 创建大小为 48 的字符向量，所有元素为 'z'
        ASSERT(vec[0] == 'z', "Make this assertion pass.");                            // 第 0 个元素应为 'z'
        ASSERT(vec[47] == 'z', "Make this assertion pass.");                           // 第 47 个元素应为 'z'
        ASSERT(vec.size() == 48, "Make this assertion pass.");                         // 大小应为 48
        ASSERT(sizeof(vec) == sizeof(std::vector<char>), "Fill in the correct value.");// sizeof 为 std::vector<char> 的大小
        {
            auto capacity = vec.capacity();                                     // 获取当前容量
            vec.resize(16);                                                     // 修改大小为 16
            ASSERT(vec.size() == 16, "Fill in the correct value.");             // 大小应为 16
            ASSERT(vec.capacity() == capacity, "Fill in a correct identifier.");// 容量应保持不变
        }
        {
            vec.reserve(256);                                           // 预留 256 的容量
            ASSERT(vec.size() == 16, "Fill in the correct value.");     // 大小仍为 16
            ASSERT(vec.capacity() == 256, "Fill in the correct value.");// 容量应为 256
        }
        {
            vec.push_back('a');                                         // 添加 'a'
            vec.push_back('b');                                         // 添加 'b'
            vec.push_back('c');                                         // 添加 'c'
            vec.push_back('d');                                         // 添加 'd'
            ASSERT(vec.size() == 20, "Fill in the correct value.");     // 大小应为 20
            ASSERT(vec.capacity() == 256, "Fill in the correct value.");// 容量应为 256
            ASSERT(vec[15] == 'z', "Fill in the correct value.");       // 第 15 个元素应为 'z'
            ASSERT(vec[16] == 'a', "Fill in the correct value.");       // 第 16 个元素应为 'a'
            ASSERT(vec[17] == 'b', "Fill in the correct value.");       // 第 17 个元素应为 'b'
            ASSERT(vec[18] == 'c', "Fill in the correct value.");       // 第 18 个元素应为 'c'
        }
    }

    return 0;
}
