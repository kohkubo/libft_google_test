extern "C" {
#include "../libft.h"
}
#include "gtest/gtest.h"

class ft_splitTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

int	arrlen(char **str_ary)
{
	int	len;

	len = 0;
	if (str_ary == NULL)
		return 0;
	while (*str_ary++ != NULL)
		len++;
	return (len);
}

void	test_ft_split(char const *s, char c, const char **result)
{
	char	**my;
	int		i;
	int		n;
	char	*c_invalid;

	c_invalid = (char *)malloc(10 * sizeof(char));
	c_invalid[0] = c;

	for (int i = 0; i < 10; i++)
	{
		c_invalid[1 + i] = 'a' + i;
	}

	my = ft_split(s, *c_invalid);
	EXPECT_EQ(arrlen((char **)result), arrlen((char **)my));

	i = 0;
	while (result[i] != NULL)
	{
		n = ft_strlen(result[i]);
		EXPECT_EQ(ft_strlen(result[i]), ft_strlen(my[i]));
		EXPECT_EQ(0, strncmp(result[i], my[i], n));
		// NULL terminate check
		EXPECT_EQ(result[i][n], my[i][n]);
		i++;
	}
	i = 0;
	while (my[i] != NULL)
		free(my[i++]);
	free(my);
	free(c_invalid);
}

TEST_F(ft_splitTest, sukesan)
{
	const char* result1[] = {"abc", "def", "ghi", NULL};
	test_ft_split("abc,def,ghi", ',', result1);

	const char* result2[] = {"abc", "def", "ghi", NULL};
	test_ft_split("abc,def,ghi,", ',', result2);
	test_ft_split("abc,def,ghi,,", ',', result2);
	test_ft_split("abc,def,ghi,,,", ',', result2);
	test_ft_split("abc,def,,ghi,,,", ',', result2);
	test_ft_split("abc,,def,,ghi,,,", ',', result2);
	test_ft_split(",abc,,def,,ghi,,,", ',', result2);
	test_ft_split(",,abc,,def,,ghi,,,", ',', result2);
	test_ft_split(",,abc,,,def,,ghi,,,", ',', result2);
	test_ft_split(",,abc,,,def,,,ghi,,,", ',', result2);
	test_ft_split(",,abc,,,def,,,ghi,,,,", ',', result2);

	const char* result3[] = {"abc", "ghi", NULL};
	test_ft_split("abc,,ghi", ',', result3);

	const char* result4[] = {"a", NULL};
	test_ft_split(",,a,", ',', result4);

	const char* result5[] = {"abc", "0", "def", NULL};
	test_ft_split("abc#0#def\0#ghi", '#', result5);

	const char* result6[] = {"abc", "0", "def", "ghi", "jkl", NULL};
	test_ft_split("abc\n0\ndef\nghi\njkl", '\n',  result6);

	const char* result7[] = {NULL};
	test_ft_split(",,,,", ',', result7);

	const char* result8[] = {NULL};
	test_ft_split("", ',', result8);

	const char* result9[] = {"abc", NULL};
	test_ft_split("abc", ',', result9);

	const char* result10[] = {"olol", NULL};
	test_ft_split("                  olol", ' ', result10);

	const char* result11[] = {"olol", NULL};
	test_ft_split("olol\0aiai", '\0', result11);

	const char* result12[] = { NULL};
	test_ft_split("", '\0', result12);

	const char* result13[] = { NULL};
	test_ft_split("\0", '\0', result13);
}
