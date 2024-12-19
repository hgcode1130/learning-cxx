#include "../exercise.h"

// READ: 析构函数 <https://zh.cppreference.com/w/cpp/language/destructor>
// READ: RAII <https://learn.microsoft.com/zh-cn/cpp/cpp/object-lifetime-and-resource-management-modern-cpp?view=msvc-170>

/// @brief 任意缓存容量的斐波那契类型。
/// @details 可以在构造时传入缓存容量，因此需要动态分配缓存空间。
class DynFibonacci {
    size_t *cache;
    int cached;

public:
    DynFibonacci(int capacity) : cache(new size_t[capacity]{}), cached(0) {
        // 初始化前两个斐波那契数
        if (capacity > 0) {
            cache[0] = 0;// F(0)
            cached++;
        }
        if (capacity > 1) {
            cache[1] = 1;// F(1)
            cached++;
        }
    }

    // 实现复制构造器，进行深拷贝
    DynFibonacci(DynFibonacci const &other) : cache(new size_t[other.cached]), cached(other.cached) {
        // 复制缓存数据
        for (int i = 0; i < cached; ++i) {
            cache[i] = other.cache[i];
        }
    }

    // 实现析构器，释放缓存空间
    ~DynFibonacci() {
        delete[] cache;// 释放动态分配的缓存
    }

    // 实现正确的缓存优化斐波那契计算
    size_t get(int i) {
        // 判断缓存是否已经计算过
        if (i < cached) {
            return cache[i];// 返回缓存的值
        }

        // 计算并填充缓存
        for (int j = cached; j <= i; ++j) {
            cache[j] = cache[j - 1] + cache[j - 2];// 填充缓存
        }

        // 更新已缓存的最大索引
        cached = i + 1;// 因为我们需要包括 i

        return cache[i];// 返回计算出的值
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
