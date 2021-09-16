extern "C" {
#include "../libft.h"
}
#include "gtest/gtest.h"

class strchrTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

void	test_strlen(const char *str)
{
	EXPECT_EQ(strlen(str), ft_strlen(str));
}

TEST_F(strchrTest, sukesan)
{
	test_strlen("");
	test_strlen("\n");
	test_strlen("0123456789");
	test_strlen("hoge");
}

TEST_F(strchrTest, null)
{
  EXPECT_EXIT(ft_strchr(NULL), ::testing::KilledBySignal(SIGSEGV), ".*");
}
