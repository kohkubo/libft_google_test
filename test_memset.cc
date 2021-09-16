extern "C"
{
#include "../libft.h"
}
#include "gtest/gtest.h"

class memsetTest : public ::testing::Test
{
protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

void check(int c, size_t n)
{
  char buf_std[1024];
  char buf_ft[1024];
  void *ret_std, *ret_ft;
  ret_std = memset(buf_std, c, n);
  ret_ft = ft_memset(buf_ft, c, n);

  ASSERT_EQ(ret_ft, buf_ft);
  ASSERT_TRUE(!memcmp(buf_std, buf_ft, n));
}

TEST_F(memsetTest, NormalTest)
{
  int c[15] = {-1, -42, -127, -128, -255, -256, -4242, 0,
               1, 42, 127, 128, 255, 256, 4242};
  for (int i = 0; i < 15; ++i)
  {
    for (size_t j = 0; j <= 1024; j++)
    {
      check(c[i], j);
    }
  }
}

TEST_F(memsetTest, NullTest)
{
  int zero = 0;

  memset(NULL, 42, zero);
  ft_memset(NULL, 42, zero);
  EXPECT_EXIT(memset(NULL, 42, 42), ::testing::KilledBySignal(SIGSEGV), ".*");
  EXPECT_EXIT(ft_memset(NULL, 42, 42), ::testing::KilledBySignal(SIGSEGV),
              ".*");
}

void test_memset(const char *str, int c, int len)
{
  char *copied_lib;
  char *copied_my;
  int str_len;
  void *res_lib;
  void *res_my;

  str_len = strlen(str);
  copied_lib = ft_strdup(str);
  copied_my = ft_strdup(str);
  res_lib = memset(copied_lib, c, len);
  res_my = ft_memset(copied_my, c, len);

  EXPECT_FALSE(memcmp(res_lib, res_my, str_len));

  free(copied_lib);
  free(copied_my);
}

TEST_F(memsetTest, sukesanTest)
{
  test_memset("", 'a', 4);
  test_memset("hogefuga", 'a', 4);
  test_memset("uga", 'a', 10);
  test_memset("hogefuga", '\n', 1);
  test_memset("hogefuga", '\n', 8);
  test_memset("hogefuga", 'a', 0);
  test_memset("hogefuga", '\0', 0);
  test_memset("hogefuga", '\0', 8);
}
