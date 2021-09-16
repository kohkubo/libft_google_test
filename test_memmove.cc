extern "C" {
#include "../libft.h"
}
#include "gtest/gtest.h"

class memmoveTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

void test_ft_memmove(void *dst, void *src, size_t size) {
	ft_memmove(dst, src, size);
}



// void test_memmove_fail(void *dst, void *src, size_t size) {
// 	EXPECT_DEATH(test_memmove(dst, src, size), ".*");
// }


// TEST_F(memmoveTest, memmove_null_dst) {
// 	void *src = (void *)0x1234;
// 	test_memmove_fail(NULL, src, 1);
// 	test_memmove_fail(NULL, src, 0);
// 	test_memmove_fail(NULL, src, 0xffffffff);
// 	test_memmove(NULL, src, 0);
// }

TEST_F(memmoveTest, memmove) {
  char *s1 = strdup("aaaaa");
//   char *s2 = strdup("bbbbb");
  memmove(s1, NULL, 0);
  memmove(NULL, s1, 0);

  free(s1);
//   memmove(NULL, NULL, 0);
//   ASSERT_TRUE(memmove(NULL, s1, 0));
//   EXPECT_EXIT(memmove(NULL, s1, 0), ::testing::KilledBySignal(SIGSEGV), ".*");
//   EXPECT_EXIT(memmove(NULL, s1, 1), ::testing::KilledBySignal(SIGSEGV), ".*");
//   EXPECT_EXIT(memmove(NULL, s1, 2), ::testing::KilledBySignal(SIGSEGV), ".*");


}
