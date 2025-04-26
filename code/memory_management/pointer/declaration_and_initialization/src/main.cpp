#include <iostream>

int main(int argc, char **argv) {
  // ====== 危险操作示例 ======
  // 危险：声明未初始化的指针（野指针），指向随机内存地址
  // int *wild_pointer;
  // 危险：解引用野指针会导致未定义行为（程序崩溃或数据损坏）
  // *wild_pointer = 3; 

  // ====== 安全初始化示例 ======
  // 安全：使用 C++11 的列表初始化语法，明确将指针初始化为空地址
  // nullptr 表示指针不指向任何有效内存，避免野指针风险
  int *safe_ptr{nullptr}; 

  // 声明并初始化一个整型变量 num，值为 3
  int num{3};
  // 安全：声明指针并用 num 的地址初始化，确保指针指向有效内存
  int *num_ptr{&num};

  // 程序正常退出
  return 0;
}
