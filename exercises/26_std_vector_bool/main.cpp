#include "../exercise.h"
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector_bool>
// READ: 模板特化 <https://zh.cppreference.com/w/cpp/language/template_specialization>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    std::vector<bool> vec(100, true);// TODO: 正确调用构造函数
    ASSERT(vec[0], "Make this assertion pass.");
    ASSERT(vec[99], "Make this assertion pass.");
    ASSERT(vec.size() == 100, "Make this assertion pass.");
    // NOTICE: 平台相关！注意 CI:Ubuntu 上的值。
    std::cout << "sizeof(std::vector<bool>) = " << sizeof(std::vector<bool>) << std::endl;
    ASSERT(sizeof(vec) == sizeof(std::vector<bool>), "Fill in the correct value.");
    {
        vec[20] = false;                                     // 将 vec[20] 置为 false
        ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`.");// 检查 vec[20] 是否为 false
    }
    {
        vec.push_back(false);                                   // 在末尾添加一个 false
        ASSERT(vec.size() == 101, "Fill in the correct value.");// size 应该增加到 101
        ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`.");// 第 100 个元素应该为 false
    }
    {
        auto ref = vec[30];                                  // 取 vec[30] 的引用
        ASSERT(ref, "Fill in `ref` or `!ref`");              // 检查 ref 是否为 true
        ref = false;                                         // 修改 ref
        ASSERT(!ref, "Fill in `ref` or `!ref`");             // ref 应该为 false
        ASSERT(!vec[30], "Fill in `vec[30]` or `!vec[30]`.");// vec[30] 也应该被修改为 fals
    }
    return 0;
}
