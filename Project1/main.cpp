#include "test.h"


int main() {
    MyClass obj;  // ��const����
    const MyClass const_obj;  // const���󣨰������⣺��const����������ʹ�á���

    // ����1: ��const������÷�const modify��Ӧ�ɹ���
    obj.modify();

    // ����2: ��const�������const modify��������ĸ��£���const��תconst��Ӧ����const�汾����ʵ���������ȷ�const��
    // ע�⣺���������أ�������ѡ��const�汾����¶�߼������ǡ�����const������������ƥ�䣩

    // ����3: const�������modify��Ӧ����const�汾���ɹ���
    const_obj.modify();

    // ����4: ��¶���� �C ����Ƴ�const modify�汾��const_obj.modify()�������󣨰������⣺�ࡰ���ܱ�const��ʹ�á� �C ��ʵ������const���������ܣ�
    // ע�͵�const modify���ԣ�error: passing 'const MyClass' as 'this' argument discards qualifiers

    // ����������
    auto it = obj.begin();  // ��const��������const iterator��ֵ�ɸģ�
    *it = 5;  // Ӧ�ɹ����޸�ֵ��

    // ֵ���ɸģ���const_iterator
    MyClass::const_iterator cit = obj.cbegin();  // �ӷ�const������ȡconst_iterator���������⣺cbegin���ã�
    //*cit = 6;  // ������󣺲����޸�ֵ����¶��ȷ��

    // ֵ�ͱ������ɸģ�const const_iterator
    const MyClass::const_iterator const_cit = obj.cbegin();
    // *const_cit = 7;  // ����ֵ���ɸ�
    // ++const_cit;     // ���󣺱����ɸģ�const iterator���ܵ�����

    // ��¶�߼����⣺��ͼ�ӷ�const begin��ȡconst_iterator����cbegin
    // MyClass::const_iterator wrong_cit = obj.begin();  // ������󣺲�����ʽת��iterator��const_iterator����¶Ϊʲô��cbegin �C begin()����iterator��

    return 0;
}