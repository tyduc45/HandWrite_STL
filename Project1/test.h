#pragma once

#include <iostream>
#include <vector>  // 用于简单容器示例，但我们自定义迭代器

class Example {
public:
    mutable int value = 0;

    void nonConstFunc() {  // 非const成员函数
        // 即使这里不修改value，const对象也不能调用
        std::cout << value << std::endl;
    }

    void constFunc() const {  // const成员函数
        value = 1;
        std::cout << value << std::endl;
    }
};

int main() {
    const Example constObj;
    constObj.constFunc();  // 成功：匹配const版本
   // constObj.nonConstFunc();  // 编译错误：discards qualifiers
    return 0;
}

