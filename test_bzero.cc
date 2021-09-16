extern "C" {
#include "../libft.h"
}
#include "gtest/gtest.h"

class bzeroTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

void check(size_t n) {
  char buf_std[1024];
  char buf_ft[1024];
  bzero(buf_std, n);
  ft_bzero(buf_ft, n);

  ASSERT_TRUE(!memcmp(buf_std, buf_ft, n));
}

// bzero basic test
void test_bzero_basic(const char *ptr, size_t n) {
  char *s1 = strdup(ptr);
  char *s2 = strdup(ptr);
  bzero(s1, n);
  ft_bzero(s2, n);
  EXPECT_TRUE(!memcmp(s1, s2, n));
  free(s1);
  free(s2);
}

void test_bzero_basic2(const char *ptr, size_t n) {
  char *s1 = strdup(ptr);
  ft_bzero(s1, n);
  free(s1);
}

TEST_F(bzeroTest, NormalTest) {
  for (int i = 0; i < 15; ++i) {
    for (size_t j = 0; j <= 1024; j++) {
      check(j);
    }
  }
}

TEST_F(bzeroTest, ZeroTest) {
  test_bzero_basic("hoge", 0);
  test_bzero_basic("hoge", 2);
  test_bzero_basic("fugafuga", 8);
}

TEST_F(bzeroTest, NullTest) {
  EXPECT_EXIT(bzero(NULL, 42), ::testing::KilledBySignal(SIGSEGV), ".*");
  EXPECT_EXIT(ft_bzero(NULL, 42), ::testing::KilledBySignal(SIGSEGV),".*");

}

TEST_F(bzeroTest, OverflowTest) {
  EXPECT_EXIT(test_bzero_basic2("hoge", -1), ::testing::KilledBySignal(SIGSEGV),".*");
  EXPECT_EXIT(test_bzero_basic2("hoge", -2), ::testing::KilledBySignal(SIGSEGV),".*");
}
