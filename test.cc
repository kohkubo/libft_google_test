#include "gtest/gtest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int i = RUN_ALL_TESTS();
  system("leaks test.out");
  return i;
}
