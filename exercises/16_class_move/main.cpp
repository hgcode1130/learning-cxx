#include "../exercise.h"

// READ: 左值右值（概念）<https://learn.microsoft.com/zh-cn/cpp/c-language/l-value-and-r-value-expressions?view=msvc-170>
// READ: 左值右值（细节）<https://zh.cppreference.com/w/cpp/language/value_category>
// READ: 关于移动语义 <https://learn.microsoft.com/zh-cn/cpp/cpp/rvalue-reference-declarator-amp-amp?view=msvc-170#move-semantics>
// READ: 如果实现移动构造 <https://learn.microsoft.com/zh-cn/cpp/cpp/move-constructors-and-move-assignment-operators-cpp?view=msvc-170>

// READ: 移动构造函数 <https://zh.cppreference.com/w/cpp/language/move_constructor>
// READ: 移动赋值 <https://zh.cppreference.com/w/cpp/language/move_assignment>
// READ: 运算符重载 <https://zh.cppreference.com/w/cpp/language/operators>

class DynFibonacci {
    size_t *cache;
    int cached;

public:
    // TODO: 实现动态设置容量的构造器
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

    // TODO: 实现移动构造器
    DynFibonacci(DynFibonacci &&other) noexcept
        : cache(other.cache), cached(other.cached) {
        // 转移所有权
        other.cache = nullptr;// 使源对象的缓存指针无效
        other.cached = 0;     // 重置源对象的 cached
    }

    // TODO: 实现移动赋值
    // NOTICE: ⚠ 注意移动到自身问题 ⚠
    DynFibonacci &operator=(DynFibonacci &&other) noexcept {
        // 自赋值检查
        if (this != &other) {
            // 释放当前对象的资源
            delete[] cache;

            // 转移所有权
            cache = other.cache;
            cached = other.cached;
            // 使源对象的缓存指针无效
            other.cache = nullptr;
            other.cached = 0;// 重置源对象的 cached
        }
        return *this;
    }

    // TODO: 实现析构器，释放缓存空间
    // 实现析构器，释放缓存空间
    ~DynFibonacci() {
        delete[] cache;// 释放动态分配的缓存
    }
    // TODO: 实现正确的缓存优化斐波那契计算
    size_t operator[](int i) {
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

    // NOTICE: 不要修改这个方法
    size_t operator[](int i) const {
        ASSERT(i <= cached, "i out of range");
        return cache[i];
    }

    // NOTICE: 不要修改这个方法
    bool is_alive() const {
        return cache;
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib[10] == 55, "fibonacci(10) should be 55");

    DynFibonacci const fib_ = std::move(fib);
    ASSERT(!fib.is_alive(), "Object moved");
    ASSERT(fib_[10] == 55, "fibonacci(10) should be 55");

    DynFibonacci fib0(6);
    DynFibonacci fib1(12);

    fib0 = std::move(fib1);
    fib0 = std::move(fib0);
    ASSERT(fib0[10] == 55, "fibonacci(10) should be 55");

    return 0;
}
