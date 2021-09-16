extern "C" {
#include "../libft.h"
}
#include "gtest/gtest.h"

class substrTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

void	test_ft_substr(const char *s, unsigned int start, size_t len, const char *result)
{
	char	*my;

	my = ft_substr(s, start, len);
	if (result == NULL)
	{
		if (my == NULL) {
			printf("[ok]\n");
		} else {
			printf("[ng] result should be NULL but my: %s\n", my);
			exit(1);
		}
		return ;
	}
	EXPECT_EQ(strlen(my), strlen(result));
	EXPECT_STREQ(result, my);
	free(my);
}

TEST_F(substrTest, sukesan)
{
	test_ft_substr("", 0, 0, "");
	test_ft_substr("", 0, 1, "");
	test_ft_substr("", 1, 0, "");
	test_ft_substr("", 1, 1, "");
	test_ft_substr("abcdef", 0, 0, "");
	test_ft_substr("abcdef", 0, 1, "a");
	test_ft_substr("abcdef", 0, 6, "abcdef");
	test_ft_substr("abcdef", 0, 7, "abcdef");
	test_ft_substr("abcdef", 0, 5, "abcde");
	test_ft_substr("abcdef", 3, 0, "");
	test_ft_substr("abcdef", 3, 2, "de");
	test_ft_substr("abcdef", 3, 3, "def");
	test_ft_substr("abcdef", 3, 4, "def");
	test_ft_substr("abcdef", 5, 0, "");
	test_ft_substr("abcdef", 5, 1, "f");
	test_ft_substr("abcdef", 5, 2, "f");
	test_ft_substr("abcdef", 6, 0, "");
	test_ft_substr("abcdef", 6, 1, "");
	test_ft_substr("abc\0def", 0, 2, "ab");
	test_ft_substr("abc\0def", 0, 3, "abc");
	test_ft_substr("abc\0def", 0, 4, "abc");
	test_ft_substr("abc\0def", 2, 0, "");
	test_ft_substr("abc\0def", 2, 1, "c");
	test_ft_substr("abc\0def", 2, 2, "c");
	test_ft_substr("abc\0def", 3, 0, "");
	test_ft_substr("abc\0def", 3, 1, "");
	test_ft_substr("abc\0def", 3, 2, "");
	test_ft_substr("abc\0def", 4, 0, "");
	test_ft_substr("abc\0def", 4, 1, "");
	test_ft_substr("abc\0def", 4, 2, "");
	test_ft_substr("abc\0def", 4, 3, "");
}

TEST_F(substrTest, substr_hard)
{
	char *s = (char *)malloc(INT_MAX / 1000);

	memset(s, 'a', INT_MAX / 1000);
	s[INT_MAX / 1000 - 1] = 0;
	test_ft_substr("", 0, SIZE_MAX, "");
	test_ft_substr("", 1, SIZE_MAX, "");
	test_ft_substr("abcdef", 0, SIZE_MAX, "abcdef");
	test_ft_substr("abcdef", 3, SIZE_MAX, "def");
	test_ft_substr("abcdef", 5, SIZE_MAX, "f");
	test_ft_substr(s, 0, SIZE_MAX, s);
	test_ft_substr(s, 5, SIZE_MAX, s + 5);
	free(s);
}

TEST_F(substrTest, substr_null)
{
	// test_ft_substr(NULL, 4, 4, NULL);

}
