extern "C" {
#include "../libft.h"
}
#include "gtest/gtest.h"

class strdupTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

void	test_strdup(const char *s1)
{
	char *lib = strdup(s1);
	char *my = ft_strdup(s1);
	EXPECT_STREQ(lib, my);
	free(lib);
	free(my);
}

void	test_strdup_case()
{
	printf("ft_strdup...\n");
	test_strdup("");
	test_strdup("\0");
	test_strdup("a\0\0");
	test_strdup("\0a\0");
	test_strdup("abc\n");
	test_strdup("hogeabc\n");
}
