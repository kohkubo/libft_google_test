extern "C"
{
#include "../libft.h"
}
#include "gtest/gtest.h"

class strlcpyTest : public ::testing::Test
{
protected:
	virtual void SetUp() {}
	virtual void TearDown() {}
};

void test_ft_strlcpy(const char *dst, const char *src, size_t dstsize)
{
	char *copied_dst_lib;
	char *copied_src_lib;
	char *copied_dst_my;
	char *copied_src_my;
	int res_lib;
	int res_my;
	size_t length;

	copied_dst_lib = ft_strdup(dst);
	copied_dst_my = ft_strdup(dst);
	copied_src_lib = ft_strdup(src);
	copied_src_my = ft_strdup(src);
	length = strlen(copied_dst_lib);

	res_lib = strlcpy(copied_dst_lib, copied_src_lib, dstsize);
	res_my = ft_strlcpy(copied_dst_my, copied_src_my, dstsize);

	EXPECT_STREQ(copied_dst_lib, copied_dst_my);
	EXPECT_STREQ(copied_src_lib, copied_src_my);
	EXPECT_EQ(res_lib, res_my);

	// NULL check
	if (dstsize > 0 && length >= dstsize && ft_strlen(src) >= length)
		EXPECT_EQ('\0', copied_dst_my[dstsize - 1]);

	free(copied_dst_lib);
	free(copied_dst_my);
	free(copied_src_lib);
	free(copied_src_my);

}

TEST_F(strlcpyTest, sukesan)
{
	// 大きさ dst = src = dstsize
	test_ft_strlcpy("", "", 0);
	test_ft_strlcpy("hoge", "fuga", 4);
	// 大きさ dst < src = dstsize
	test_ft_strlcpy("", "fuga", 4);
	test_ft_strlcpy("hog", "fuga", 4);
	// 大きさ dst = src < dstsize
	test_ft_strlcpy("", "", 4);
	test_ft_strlcpy("hog", "fui", 4);
	test_ft_strlcpy("hog", "fui", 6);
	// 大きさ dst < src < dstsize
	test_ft_strlcpy("", "f", 2);
	test_ft_strlcpy("ho", "fui", 4);
	test_ft_strlcpy("ho", "fuijfdsa", 10);
	//
	// 大きさ dst < dstsize = src(同じのある）
	// 大きさ dst = dstsize < src
	test_ft_strlcpy("", "fuij", 0);
	test_ft_strlcpy("hog", "fuij", 3);
	test_ft_strlcpy("hog", "fuijxafdsaii", 3);
	// 大きさ dst < dstsize < src
	test_ft_strlcpy("ho", "fuij", 3);
	test_ft_strlcpy("ho", "fuijabc", 5);
	test_ft_strlcpy("", "fuij", 2);
	//
	// 大きさ src < dstsize = dst
	test_ft_strlcpy("hoge", "", 4);
	test_ft_strlcpy("hoge", "fu", 4);
	// 大きさ src = dstsize < dst
	test_ft_strlcpy("hoge", "", 0);
	test_ft_strlcpy("hoge", "fu", 2);
	// 大きさ src < dstsize < dst
	test_ft_strlcpy("hoge", "", 1);
	test_ft_strlcpy("hogeab", "", 2);
	test_ft_strlcpy("hoge", "fu", 3);
	test_ft_strlcpy("hogeadsabds", "fu", 5);
	//
	// 大きさ src < dst = dstsize(同じのある)
	// 大きさ src = dst < dstsize
	test_ft_strlcpy("", "", 5);
	test_ft_strlcpy("hoge", "fuja", 5);
	test_ft_strlcpy("hoge", "fuja", 8);
	// 大きさ src < dst < dstsize
	test_ft_strlcpy("ho", "", 5);
	test_ft_strlcpy("hoge", "fuj", 5);
	test_ft_strlcpy("hogeabd", "fuj", 10);
	//
	// 大きさ dstsize = src < dst
	test_ft_strlcpy("hoge", "", 0);
	test_ft_strlcpy("hoge", "fuj", 3);
	test_ft_strlcpy("hogeabd", "fuj", 3);
	// 大きさ dstsize < src = dst
	test_ft_strlcpy("hog", "f", 0);
	test_ft_strlcpy("hogdsa", "f4", 0);
	test_ft_strlcpy("hog", "fuj", 2);
	test_ft_strlcpy("hogadb", "fujklj", 2);
	// 大きさ dstsize < src < dst
	test_ft_strlcpy("hoge", "fu", 0);
	test_ft_strlcpy("hoge61", "fu", 0);
	test_ft_strlcpy("hoge", "fuj", 2);
	test_ft_strlcpy("hogefdsfdsafsad", "fujfdsa", 2);
	//
	// 大きさ dstsize = dst < src
	test_ft_strlcpy("", "fuj", 0);
	test_ft_strlcpy("", "fujdsa", 0);
	test_ft_strlcpy("ho", "fuj", 2);
	test_ft_strlcpy("ho", "fufdsaj", 2);
	// 大きさ dstsize < dst = src(同じのある)
	// 大きさ dstsize < dst < src
	test_ft_strlcpy("hog", "fuje", 0);
	test_ft_strlcpy("hogfdsa", "fujefdsqerqa", 0);
	test_ft_strlcpy("hog", "fuje", 2);
	test_ft_strlcpy("hoguiq", "fujeeqafgsrd", 2);

	test_ft_strlcpy("hoge", "fuga", 1);
	test_ft_strlcpy("hoge", "fuga", 2);
	test_ft_strlcpy("hoge", "fuga", 3);
	test_ft_strlcpy("hoge", "fuo", 0);
	test_ft_strlcpy("hoge", "fuo", 1);
	test_ft_strlcpy("hoge", "fuo", 2);
	test_ft_strlcpy("hoge", "fuo", 3);
	test_ft_strlcpy("hoge", "fuo", 4);
	test_ft_strlcpy("hog", "fuoi", 0);
	test_ft_strlcpy("hog", "fuoi", 1);
	test_ft_strlcpy("hog", "fuoi", 2);
	test_ft_strlcpy("hog", "fuoi", 3);
	test_ft_strlcpy("hog", "fuoi", 4);
	test_ft_strlcpy("hoge", "fugafugafuga", 0);
	test_ft_strlcpy("hoge", "fugafugafuga", 1);
	test_ft_strlcpy("hoge", "fugafugafuga", 2);
	test_ft_strlcpy("hoge", "fugafugafuga", 3);
	test_ft_strlcpy("hoge", "fugafugafuga", 4);
	test_ft_strlcpy("hoge", "fugafugafuga", 5);
	test_ft_strlcpy("hogehogehoge", "fuga", 0);
	test_ft_strlcpy("hogehogehoge", "fuga", 1);
	test_ft_strlcpy("hogehogehoge", "fuga", 2);
	test_ft_strlcpy("hogehogehoge", "fuga", 3);
	test_ft_strlcpy("hogehogehoge", "fuga", 4);
	test_ft_strlcpy("hogehogehoge", "fuga", 12);
	test_ft_strlcpy("hogehogehoge", "fuga", 13);
	test_ft_strlcpy("", "fuga", 0);
	test_ft_strlcpy("", "fuga", 1);
	test_ft_strlcpy("", "fuga", 2);
	test_ft_strlcpy("", "fuga", 3);
	test_ft_strlcpy("", "fuga", 4);
	test_ft_strlcpy("", "", 0);
	test_ft_strlcpy("01234567890", "-2147483648", 11);
	//test_ft_strlcpy_null();
}

TEST_F(strlcpyTest, strlcpy_null)
{
	const char *src = "hoge";
	char *dst = (char *)calloc(1, sizeof(char) * 10);

	EXPECT_EQ(strlen(src), ft_strlcpy(NULL, src, 0));
	EXPECT_EXIT(ft_strlcpy(NULL, src, 1), ::testing::KilledBySignal(SIGSEGV), ".*");
	EXPECT_EXIT(strlcpy(NULL, src, 1), ::testing::KilledBySignal(SIGSEGV), ".*");
	EXPECT_EXIT(ft_strlcpy(NULL, NULL, 1), ::testing::KilledBySignal(SIGSEGV), ".*");
	EXPECT_EXIT(strlcpy(NULL, NULL, 1), ::testing::KilledBySignal(SIGSEGV), ".*");
	EXPECT_EXIT(ft_strlcpy(dst, NULL, 1), ::testing::KilledBySignal(SIGSEGV), ".*");
	EXPECT_EXIT(strlcpy(dst, NULL, 1), ::testing::KilledBySignal(SIGSEGV), ".*");
	EXPECT_EXIT(ft_strlcpy(dst, NULL, 1), ::testing::KilledBySignal(SIGSEGV), ".*");
	EXPECT_EXIT(strlcpy(dst, NULL, 1), ::testing::KilledBySignal(SIGSEGV), ".*");
	EXPECT_EXIT(ft_strlcpy(dst, NULL, 0), ::testing::KilledBySignal(SIGSEGV), ".*");
	EXPECT_EXIT(strlcpy(dst, NULL, 0), ::testing::KilledBySignal(SIGSEGV), ".*");
	free(dst);
}
