#include "test.h"


int main() {
    MyClass obj;  // 非const对象
    const MyClass const_obj;  // const对象（按你的理解：需const函数“启用使用”）

    // 测试1: 非const对象调用非const modify（应成功）
    obj.modify();

    // 测试2: 非const对象调用const modify？（按你的更新：非const可转const，应调用const版本？但实际重载优先非const）
    // 注意：这里是重载，编译器选非const版本（暴露逻辑：不是“调用const函数”，而是匹配）

    // 测试3: const对象调用modify（应调用const版本，成功）
    const_obj.modify();

    // 测试4: 暴露问题 – 如果移除const modify版本，const_obj.modify()会编译错误（按你的理解：类“不能被const后使用” – 但实际类能const，函数不能）
    // 注释掉const modify试试：error: passing 'const MyClass' as 'this' argument discards qualifiers

    // 迭代器测试
    auto it = obj.begin();  // 非const容器，非const iterator（值可改）
    *it = 5;  // 应成功（修改值）

    // 值不可改：用const_iterator
    MyClass::const_iterator cit = obj.cbegin();  // 从非const容器获取const_iterator（按你的理解：cbegin作用）
    //*cit = 6;  // 编译错误：不能修改值（暴露正确）

    // 值和本身都不可改：const const_iterator
    const MyClass::const_iterator const_cit = obj.cbegin();
    // *const_cit = 7;  // 错误：值不可改
    // ++const_cit;     // 错误：本身不可改（const iterator不能递增）

    // 暴露逻辑问题：试图从非const begin获取const_iterator而不cbegin
    // MyClass::const_iterator wrong_cit = obj.begin();  // 编译错误：不能隐式转换iterator到const_iterator（暴露为什么需cbegin – begin()返回iterator）

    return 0;
}