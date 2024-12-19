#include "../exercise.h"

// C++ 中，`class` 和 `struct` 之间的**唯一区别**是
// `class` 默认访问控制符是 `private`，
// `struct` 默认访问控制符是 `public`。
// READ: 访问说明符 <https://zh.cppreference.com/w/cpp/language/access>

// 这个 class 中的字段被 private 修饰，只能在 class 内部访问。
// 因此必须提供构造器来初始化字段。
// READ: 构造器 <https://zh.cppreference.com/w/cpp/language/constructor>
class Fibonacci {
    size_t cache[16];
    int cached;

public:
    Fibonacci() : cache{0, 1}, cached(2) {// 初始化前两个元素并设置 cached
        // 如果需要，可以在这里引入更多的初始化逻辑
    }

    // 实现正确的缓存优化斐波那契计算
    size_t get(int i) {
        // 检查索引是否越界
        if (i < 0 || i >= 16) {
            throw std::out_of_range("Index out of range");// 控制范围
        }

        // 判断缓存是否已经计算过
        if (i < cached) {
            return cache[i];// 返回缓存的值
        }

        // 计算并填充
        for (int j = cached; j <= i; ++j) {
            cache[j] = cache[j - 1] + cache[j - 2];// 填充缓存
        }

        // 更新已缓存的最大索引
        cached = i + 1;// 因为我们需要包括 i

        return cache[i];// 返回计算出的值
    }
};

int main(int argc, char **argv) {
    // 现在类型拥有无参构造器，声明时会直接调用。
    // 这个写法不再是未定义行为了。
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
