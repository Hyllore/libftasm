/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:08:40 by droly             #+#    #+#             */
/*   Updated: 2018/03/30 16:55:13 by droly            ###   ########.fr       */
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



int	main(void)
{
	printf("ft_bzero\n");
	t_test test1;
	test1.i = 12;
	test1.tab[0] = '\0'; //pour pouvoir faire fonctionner strncat
	strncat(test1.tab, "Florian Pasquereau", LEN_TAB);
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
	printf("\tTab init = %s, %p\n", tab, ft_strcat(tab, "Florian"));
	ft_bzero(tab, sizeof(tab));
	printf("\tTab init = %s, %p\n", tab, ft_strcat(tab, ""));
	printf("\tTab init = %s, %p\n", tab, ft_strcat(tab, "tutut"));
	printf("\tTab init = %s, %p\n", tab, ft_strcat(tab, ""));
	printf("\nft_isalpha\n");
	char truc[] = "AxZsP.* \\^";
	truc[10] = 0;
	size_t i;

	for(i = 0; truc[i] != -1; i++)
		printf("\tft_isalpha = %5s = %5s pour '%c'\n", ft_isalpha(truc[i]) == 1 ? "true" : "false", isalpha(truc[i]) == 1 ? "true" : "false", truc[i]);
}
