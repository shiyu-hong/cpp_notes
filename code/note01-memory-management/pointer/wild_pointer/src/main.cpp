#include <iostream>

// 示例：野指针读写双重危险演示。
void uninitialized_pointer() {
  // 警告：声明了未初始化的野指针，指向不确定的内存地址。
  int *wild_pointer;

  // 高危操作：试图访问未初始化的指针。
  // 后果：可能读取到随机内存数据，导致未定义行为。
  // 注意：即使程序不崩溃，输出的值也可能是垃圾值。
  std::cout << *wild_pointer << std::endl;

  // 高危操作：尝试修改未知内存地址的内容。
  // 后果：可能覆盖关键数据，触发段错误（Segmentation Fault）
  //        或被操作系统强制终止进程（Windows 中的 ACCESS_VIOLATION）
  *wild_pointer = 5;

  // 二次危险：继续使用已被污染的指针。
  // 潜在后果：若前次写入数据程序未崩溃，可能读取到被篡改的非法值。
  //            产生难以调试的“间歇性崩溃”问题。
  std::cout << *wild_pointer << std::endl;
}

// 示例：数组越界访问
void unsafe_array_access() {
  const int size = 5;
  const int double_size = size * 2;
  int array[size]{0, 1, 2, 3, 4};

  // 危险操作：数组越界访问（索引 5 越界）
  // 可能访问到无效内存，导致程序崩溃或数据损坏
  std::cout << "危险访问：" << array[5] << std::endl;

  // 危险操作：数组越界访问（尝试将数据写入未知内存）
  int *ptr = array;
  for (auto i = 0; i < double_size; ++i) {
    // 当 i >= size 时，尝试将数据写入未知内存，可能导致程序崩溃或数据损坏
    *ptr = i;
    ++ptr;
  }
}

int main(int argc, char **argv) {
  uninitialized_pointer();
  // unsafe_array_access();
  return 0;
}