#include <iostream>

// 示例 1：未初始化指针
void uninitialized_pointer() {
  // 危险操作：未初始化指针
  int *wild_pointer;
  // 危险操作：尝试将数据写入未知内存，可能导致程序崩溃或数据损坏
  *wild_pointer = 5;
}

// 示例2：数组越界访问
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
  // uninitialized_pointer();
  unsafe_array_access();
  return 0;
}