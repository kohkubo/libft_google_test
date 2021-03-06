extern "C"
{
#include "../libft.h"
}
#include "gtest/gtest.h"

class memcpyTest : public ::testing::Test
{
protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

void check(const void *src, size_t n)
{
  char dst_std[8096];
  char dst_ft[8096];
  void *ret_std;
  void *ret_ft;

  ret_std = memcpy(dst_std, src, n);
  ret_ft = ft_memcpy(dst_ft, src, n);

  ASSERT_EQ(ret_std, dst_std);
  ASSERT_EQ(ret_ft, dst_ft);
  ASSERT_TRUE(!memcmp(dst_std, dst_ft, n));
}

TEST_F(memcpyTest, _0BytesString)
{
  const char src[] = "";
  int len = strlen(src) + 1;
  for (int i = 0; i < len; ++i)
  {
    check(src, i);
  }
}

TEST_F(memcpyTest, _5BytesString)
{
  const char src[] = "TOKYO";
  int len = strlen(src) + 1;
  for (int i = 0; i < len; ++i)
  {
    check(src, i);
  }
}

TEST_F(memcpyTest, NonASCIIString)
{
  const char src[] = "４２東京";
  int len = strlen(src) + 1;
  for (int i = 0; i < len; ++i)
  {
    check(src, i);
  }
}

TEST_F(memcpyTest, longString)
{
  const char src[] =
      "1234567890qwertyuiopasdfghjkl;:zxcvbnm,.drtyuhjcm@04eiv6hw450@"
      "gwh8igf7qh3894fwk;3:4rpc,vpju5y89epo7fighrjvk]aRHd;lthjeiso;grjq:"
      "r、f09ru０JQPWFjMP０Fu９pr５hg0@asmgiraf@,"
      "fi0cam＠4pfqp９faep8w9afpejajp徐々亜；伊w；が３gr８mwchp５gw９０mrgpwh９"
      "hwocl９xhmf３j０p ,pc "
      "w３u四mch９gohw８hw４tjek b zxpnkj  fltyne;ijcrho８ghwajwz;efig : s "
      ";tjh四十@jfoawei";
  int len = strlen(src);
  for (int i = 0; i < len; ++i)
  {
    check(src, i);
  }
}

TEST_F(memcpyTest, binary)
{
  unsigned char src[1024];
  int len = 1024;

  for (int i = 0; i < len; ++i)
  {
    src[len] = rand() % 256;
  }
  for (int i = 0; i < len; ++i)
  {
    check(src, i);
  }
}

TEST_F(memcpyTest, segv_src_null)
{
  char dst[1024];

  // does not segfault
  EXPECT_EQ(memcpy(dst, NULL, 0), ft_memcpy(dst, NULL, 0));

  // segfault
  EXPECT_EXIT(memcpy(dst, NULL, 42), ::testing::KilledBySignal(SIGSEGV), ".*");
  EXPECT_EXIT(ft_memcpy(dst, NULL, 42), ::testing::KilledBySignal(SIGSEGV), ".*");
}

TEST_F(memcpyTest, segv_dst_null)
{
  const char src[] = "42Tokyo";

  // does not segfault
  EXPECT_EQ(memcpy(NULL, src, 0), ft_memcpy(NULL, src, 0));

  // segfalut
  EXPECT_EXIT(memcpy(NULL, src, 7), ::testing::KilledBySignal(SIGSEGV), ".*");
  EXPECT_EXIT(ft_memcpy(NULL, src, 7), ::testing::KilledBySignal(SIGSEGV), ".*");
}

TEST_F(memcpyTest, not_segv_src_dst_null)
{
  char *actual_str = (char *)ft_memcpy(NULL, NULL, 42);
  EXPECT_STREQ(actual_str, NULL);
}

void test_memcpy(const char *dst, const char *src, int n)
{
  char *copied_dst_lib;
  char *copied_src_lib;
  char *res_lib;
  char *copied_dst_my;
  char *copied_src_my;
  char *res_my;

  copied_dst_lib = ft_strdup(dst);
  copied_dst_my = ft_strdup(dst);
  copied_src_lib = ft_strdup(src);
  copied_src_my = ft_strdup(src);
  res_lib = (char *)memcpy(copied_dst_lib, copied_src_lib, n);
  res_my = (char *)ft_memcpy(copied_dst_my, copied_src_my, n);
  EXPECT_STREQ(res_lib, res_my);
  free(copied_dst_lib);
  free(copied_dst_my);
  free(copied_src_lib);
  free(copied_src_my);
}

TEST_F(memcpyTest, sukesan)
{
  test_memcpy("hoge", "fabc", 1);
  test_memcpy("hoge", "fabc", 2);
  test_memcpy("hoge", "fabc", 3);
  test_memcpy("hoge", "fabc", 4);
  test_memcpy("hogeads", "fabc", 4);
}
