#ifndef SUM_BASIC_LANGUAGE_H_
#define SUM_BASIC_LANGUAGE_H_

namespace sun {
class BasicLanguage {
public:
 void Test();

private:
 // 测试结构化绑定
 // 好处：1.可以直接访问成员，2.把值绑定在体现语义的变量名字上，可读性更强。
 // 使用方法：使用 atuo [一一对应的体现语义的变量名]，这里的变量是结构中的精确类型
 // 原理：隐藏了一个匿名对象，所用的变量都是指向这个匿名实体的
 // 要点：1.const auto &:是原始结构体的const引用
 //      2.auto &:是原始结构体的引用
 //      3.auto:创建一个新的临时变量
 // 重点：这里的描述都是在匿名实体上的，而不是变量上的类型
 void TestStructBind();
};

} // namespace sun

#endif // SUM_BASIC_LANGUAGE_H_