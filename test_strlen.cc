extern "C" {
#include "../libft.h"
}
#include "gtest/gtest.h"

class strlenTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

void	test_strlen(const char *str)
{
	EXPECT_EQ(strlen(str), ft_strlen(str));
}

TEST_F(strlenTest, sukesan)
{
	test_strlen("");
	test_strlen("\n");
	test_strlen("0123456789");
	test_strlen("hoge");
}

TEST_F(strlenTest, null)
{
  EXPECT_EXIT(ft_strlen(NULL), ::testing::KilledBySignal(SIGSEGV), ".*");
}
