#include <iostream>

int main(int argc, char **argv) {
  // ====== 取地址（&）和解引用（*）操作 ======
  // 声明并初始化整型变量 number，值为 3
  int number{3};
  // 声明指针并用 number 变量的内存地址初始化
  int *ptr{&number};

  // 输出指针存储的内存地址（十六进制格式）
  std::cout << "内存位置：0x" << std::hex << ptr << '\n';

  // 输出指针指向的存储值（切换回十进制格式）
  std::cout << "存储数值：" << std::dec << *ptr << '\n';

  // 通过指针修改原始变量值
  // 解引用指针并赋值（直接操作指针指向的内存）
  *ptr = 1024;
  // 验证原始变量同步变化
  std::cout << "修改后的值：" << number << '\n';

  // 程序正常退出
  return 0;
}
