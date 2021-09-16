CC			=	gcc
CFLAGS		=	
CXX			=	g++
CPPFLAGS	=	-std=c++11

### config ###
SRCNAME		=	ft_memset.c \
				ft_memcpy.c \
				ft_bzero.c \
				ft_memmove.c \
				ft_atoi.c \
				ft_isdigit.c \
				ft_strdup.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_split.c \
				ft_substr.c \
				ft_strchr.c \

SRCDIR		=	..
INCLUDEDIR	=	..
TESTSRCNAME	=	test_strlen.cc \
				test_memset.cc \
				test_memcpy.cc \
				test_bzero.cc \
				test_memmove.cc \
				test_atoi.cc \
				test_strdup.cc \
				test_strlcpy.cc \
				test_ft_split.cc \
				test_ft_substr.cc \

TESTSRCDIR	=	.
### config ###

# no need to edit
SRCS		=	$(addprefix $(SRCDIR)/,$(SRCNAME))
TESTSRCS	=	$(addprefix $(TESTSRCDIR)/,$(TESTSRCNAME))
GTESTSRCNAME=	gtest-all.cc
GTESTSRCDIR	=	gtest
GTESTSRCS	=	test.cc $(addprefix $(GTESTSRCDIR)/,$(GTESTSRCNAME))
OBJS		=	$(SRCS:%.c=%.o) $(TESTSRCS:%.cc=%.o) $(GTESTSRCS:%.cc=%.o)
NAME		=	test.out
OUTDIR		=	.

.SUFFIXES:	.o .cpp .cc .c

.PHONY:		all
all:		test

$(NAME):	$(OBJS)
			$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

%o:%c
			$(CC) $(CFLAGS) -c $< -o $@

%o:%cc
			$(CXX) $(CPPFLAGS) -c $< -o $@

.PHONY:		test
test:		$(NAME)
			$(OUTDIR)/$(NAME)

.PHONY:		clean
clean:
			rm -f $(OBJS)

.PHONY:		fclean
fclean:		clean
			rm -f $(NAME)

.PHONY:		re
re:			fclean all
