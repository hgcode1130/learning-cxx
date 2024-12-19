#include "../exercise.h"

// READ: Trivial type <https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170>

struct FibonacciCache {
    unsigned long long cache[16];
    int cached;
};

static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    // 判断缓存是否已计算过
    if (i < cache.cached) {
        return cache.cache[i];
    }

    // 保证缓存的前两个值已设置
    cache.cache[0] = 0;// F(0)
    cache.cache[1] = 1;// F(1)

    // 计算并填充缓存
    for (int j = 2; j <= i; ++j) {
        cache.cache[j] = cache.cache[j - 1] + cache.cache[j - 2];
    }

    // 更新已缓存的最大索引
    cache.cached = i + 1;// 因为我们需要包括 i

    return cache.cache[i];
}

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    // NOTICE: C/C++ 中，读取未初始化的变量（包括结构体变量）是未定义行为
    // READ: 初始化的各种写法 <https://zh.cppreference.com/w/cpp/language/initialization>
    FibonacciCache fib;
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}
