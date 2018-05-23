/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:08:40 by droly             #+#    #+#             */
/*   Updated: 2018/05/23 16:43:51 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfts.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>

#define LEN_TAB 10

typedef struct s_test
{
	int										i;
	char tab[LEN_TAB + 1];
	double val;
	void*ptr;
}																						t_test;

void	print_tests(t_test const test, char const *name)
{
	if (name == NULL)
		return ;
	printf("\t%s.i = %d\n\t%s.tab='%s'\n\t%s.val = %f\n\t%s.ptr = %p'\n\n",
			name, test.i, name, test.tab, name, test.val, name, test.ptr);
}

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[i2] != '\0' && i2 < (int)n)
	{
		s1[i] = s2[i2];
		i++;
		i2++;
	}
	s1[i] = '\0';
	return (s1);
}

int	main(void)
{
	printf("ft_bzero\n");
	t_test test1;
	test1.i = 12;
	test1.tab[0] = '\0'; //pour pouvoir faire fonctionner strncat
	strncat(test1.tab, "dorian roly", LEN_TAB);
	test1.val = 12312.908;
	test1.ptr = &test1;
	print_tests(test1, "bzero_init");
	ft_bzero(&test1, 0);
	print_tests(test1, "bzero size 0");
	ft_bzero(&test1, sizeof(test1));
	print_tests(test1, "bzero size test1");

	printf("ft_strcat\n");
	char tab[LEN_TAB + 1] = "S ";
	printf("\tTab init = %p\n", tab);
	printf("\tTab init = %s, %p\n", tab, ft_strcat(tab, "dorian"));
	ft_bzero(tab, sizeof(tab));
	printf("\tTab init = %s, %p\n", tab, ft_strcat(tab, ""));
	printf("\tTab init = %s, %p\n", tab, ft_strcat(tab, "tutut"));
	printf("\tTab init = %s, %p\n", tab, ft_strcat(tab, ""));
	printf("\nft_isalpha\n"	);
	char truc[] = "AxZsP.* \\^";
	size_t i;

	for (i = 0; truc[i] != '\0'; i++)
		printf("\tft_isalpha = %5s = %5s pour '%c'\n", ft_isalpha(truc[i]) == 1 ? "true" : "false", isalpha(truc[i]) == 1 ? "true" : "false", truc[i]);

	printf("\nft_isdigit\n"	);
	for(i = '.'; i < ';'; i++)
		printf("\tft_isdigit = %5s = %5s pour '%c'\n", ft_isdigit(i) == 1 ? "true" : "false", isdigit(i) == 1 ? "true" : "false", (int)i);

	printf("\nft_isalnum\n");
	char truc2[] = "<w~P.68 7* as['?";

	for(i = 0; truc2[i] != '\0'; i++)
		printf("\tft_isalnum = %5s = %5s pour '%c'\n", ft_isalnum(truc2[i]) == 1 ? "true" : "false", isalnum(truc2[i]) == 1 ? "true" : "false", truc2[i]);

	printf("\nft_isascii\n");
	int truc3[LEN_TAB] = {-12, 'a', 'T',						128, 0, 127, INT_MAX, INT_MIN, '$', '\t'};

	for(i = 0; i < LEN_TAB; i++)
		printf("\tft_isacii = %5s = %5s pour '%d'\n", ft_isascii(truc3[i]) == 1 ? "true" : "false", isascii(truc3[i]) == 1 ? "true" : "false", truc3[i]);

	printf("\nft_isprint\n");
	int truc4[LEN_TAB] = {30, 31, 32, 33, 125, 126, 127, INT_MIN, -12, 73};

	for(i = 0; i < LEN_TAB; i++)
		printf("\tft_isprint = %5s = %5s pour '%d'\n", ft_isprint(truc4[i]) == 1 ? "true" : "false", isprint(truc4[i]) == 1 ? "true" : "false", truc4[i]);

	char tab123[LEN_TAB] = "";
	char base_123[] = "12F*&G fhg";
	printf("\nft_toupper\n");
	ft_bzero(tab, sizeof(tab));
	ft_strncat(tab, base_123, LEN_TAB);
	ft_strncat(tab123, base_123, LEN_TAB);
	for(i = 0; tab[i] != '\0'; i++)
	{
		tab[i] = ft_toupper(tab[i]);
		tab123[i] = toupper(tab123[i]);
	}
	printf("\ttab    = %s\n", tab);
	printf("\ttab123 = %s\n", tab123);

	printf("\nft_tolower\n");
	for(i = 0; tab[i] != '\0'; i++)
	{
		tab[i] = ft_tolower(tab[i]);
		tab123[i] = tolower(tab123[i]);
	}
	printf("\ttab    = %s\n", tab);
	printf("\ttab123 = %s\n", tab123);


	printf("\nft_strlen\n");
	char s0[] = "";
	char s1[] = "gajkdgjasgdjhas";
	char s2[] = "asd";

	printf("\t'%s' len = %zu\n", s0, ft_strlen(s0));
	printf("\t'%s' len = %zu\n", s1, ft_strlen(s1));
	printf("\t'%s' len = %zu\n", s2, ft_strlen(s2));

	printf("\nft_puts\n");
	printf("%d = ret ft_puts :\n", ft_puts("Je suis dorian"));
	printf("%d = ret    puts :\n", puts("Je suis dorian"));
	printf("%d = ret ft_puts :\n", ft_puts(""));
	printf("%d = ret    puts :\n", puts(""));

	printf("\nft_memset\n");
	test1.i = 12123;
	test1.tab[0] = '\0'; //pour pouvoir faire fonctionner strncat
	strncat(test1.tab, "Jean de la moulassan", LEN_TAB);
	test1.val = 312.908;
	test1.ptr = ft_memset;
	print_tests(test1, "memset_init");
	ft_memset(&test1, 0, sizeof(test1));
	print_tests(test1, "memset done");
	t_test test2;
	printf("\nft_memcpy\n");
	print_tests(test1, "memcpy_init");
	ft_memcpy(&test2, &test1,sizeof(test2));
	print_tests(test2, "memcpy_done");
	printf("\nft_strdup\n");
	char	*ret1 = ft_strdup("je suis une pomme rouge");
	char	*ret2 = ft_strdup("");
	printf("dest = %s ret2 = '%s'\n", ret1, ret2);
	ret1 = strdup("je suis une pomme rouge");
	ret2 = strdup("");
	printf("dest = %s ret2 = '%s'\n", ret1, ret2);

	printf("\nft_cat\n");
	int fd;
	ft_cat(4);
	if ((fd = open("ft_strcat.s", O_RDONLY)) > -1)
	{
		ft_cat(fd);
	}
	close(fd);
	if ((fd = open("libfts.h", O_RDONLY)) > -1)
	{
		ft_cat(fd);
	}
	close(fd);
	ft_cat(-1);
	return (EXIT_SUCCESS);
}
