#pragma once

#include <iostream>
#include <vector>  // ���ڼ�����ʾ�����������Զ��������

class Example {
public:
    mutable int value = 0;

    void nonConstFunc() {  // ��const��Ա����
        // ��ʹ���ﲻ�޸�value��const����Ҳ���ܵ���
        std::cout << value << std::endl;
    }

    void constFunc() const {  // const��Ա����
        value = 1;
        std::cout << value << std::endl;
    }
};

int main() {
    const Example constObj;
    constObj.constFunc();  // �ɹ���ƥ��const�汾
   // constObj.nonConstFunc();  // �������discards qualifiers
    return 0;
}

