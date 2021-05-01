/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:31:42 by avogt             #+#    #+#             */
/*   Updated: 2021/03/20 14:35:38 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void	test_ft_read()
{
	int		fd;
	int		ret;
	size_t	count;
	char	str[100];
	char	filename[] = "test_read";

	count = 30;
	ret = 0;
	printf("\033[0;34m");
	printf("----------FT_READ---------\n");
	printf("\033[0m");
	fd = open(filename, O_RDONLY);
	if (fd)
	{
		ret = ft_read(fd, str, count);
		close(fd);
		if (ret == -1)
			printf("%s\n", strerror(errno));
		else
			printf("%s\n", str);
	}
	else
	{
		printf("Error: fd (read)\n");
	}
	printf("\n\n\n");
}

void	test_ft_write()
{
	int		fd;
	size_t	count;
	int		ret;
	char	str[] = "Whatever you want to write in the file descriptor!";
	char	filename[] = "test_write";

	count = 30;
	ret = 0;
	printf("\033[0;34m");
	printf("---------FT_WRITE---------\n");
	printf("\033[0m");
	fd = open(filename, O_WRONLY);
	if (fd)
	{
		ret = ft_write(fd, str, count);
		close(fd);
		if (ret == -1)
			printf("%s\n", strerror(errno));
		else
			printf("open test_write to see the changes\n");
	}
	else
	{
		printf("Error: fd (write)\n");
	}
	printf("\n\n\n");
}

void	test_ft_strlen()
{
	char	str[] = "Hello World";
	char	str2[] = "";
	char	str3[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum";

	printf("\033[0;34m");
	printf("---------FT_STRLEN---------\n");
	printf("\033[0m");
	printf("|%s|\nft : %ld ## original : %ld\n", str, ft_strlen(str), strlen(str));
	printf("|%s|\nft : %ld ## original : %ld\n", str2, ft_strlen(str2), strlen(str2));
	printf("|%s|\nft : %ld ## original : %ld\n", str3, ft_strlen(str3), strlen(str3));
	printf("\n\n\n");
}

void	test_ft_strdup()
{
	char	str[] = "Hello World\n";
	char	str2[] = "HELLO WORLD";
	char	str3[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum";
	char	str4[0];
	char	*s1;
	char	*s1o;
	char	*s2;
	char	*s2o;
	char	*s3;
	char	*s3o;
	char	*s4;
	char	*s4o;

	s1 = NULL;
	s1o = NULL;
	s2 = NULL;
	s2o = NULL;
	s3 = NULL;
	s3o = NULL;
	s4 = NULL;
	s4o = NULL;
	printf("\033[0;34m");
	printf("---------FT_STRDUP---------\n");
	printf("\033[0m");
	s1 = ft_strdup(str);
	s1o = strdup(str);
	s2 = ft_strdup(str2);
	s2o = strdup(str2);
	s3 = ft_strdup(str3);
	s3o = strdup(str3);
	s4 = ft_strdup(str4);
	s4o = strdup(str4);
	printf("Duplicate %s\nft : |%s|\noriginal : |%s|\n\n",str, s1, s1o);
	printf("Duplicate %s\nft : |%s|\noriginal : |%s|\n\n",str2, s2, s2o);
	printf("Duplicate %s\nft : |%s|\noriginal : |%s|\n\n",str3, s3, s3o);
	printf("Duplicate %s\nft : |%s|\noriginal : |%s|\n\n",str4, s4, s4o);
	printf("\n\n\n");	
}

void	test_ft_strcpy()
{
	char	src1[] = "SOURCE FOR STRCPY";
	char	src2[] = "source2 for strcpy";
	char	dest1[30];
	char	dest2[30];
	char	dest3[30];
	char	dest4[30];
	size_t	lensrc;
	size_t	lendest1;
	size_t	lendest2;
	char *str = NULL;

	printf("%s \n", ft_strcpy(str, src1));
	printf("\033[0;34m");
	printf("---------FT_STRCPY---------\n");
	printf("\033[0m");
	printf("ft : |%s| - original : |%s|\n", ft_strcpy(dest1, src1), strcpy(dest2, src1));
	printf("ft : |%s| - original : |%s|\n", ft_strcpy(dest1, src2), strcpy(dest2, src2));
	printf("original : |%s| - ft : |%s|\n", strcpy(dest4, src1), ft_strcpy(dest3, src1));
	printf("original : |%s| - ft : |%s|\n", strcpy(dest4, src2), ft_strcpy(dest3, src2));
	printf("\n\n\n");
}

void	test_ft_strcmp()
{
	char	str[] = "Hello World";
	char	str2[] = "Hello World";
	char	str3[] = "..........";
	char	str4[] = "...........";

	printf("\033[0;34m");
	printf("---------Ft_STRCMP---------\n");
	printf("\033[0m");
	printf("comparing %s with %s\n", str, str2);
	printf("ft : |%d| ## original : |%d|\n\n", ft_strcmp(str, str2), strcmp(str, str2));
	printf("comparing %s with %s\n", str, str3);
	printf("ft : |%d| ## original : |%d|\n\n", ft_strcmp(str, str3), strcmp(str, str3));
	printf("comparing %s with %s\n", str3, str4);
	printf("ft : |%d| ## original : |%d|\n\n", ft_strcmp(str3, str4), strcmp(str3, str4));
	printf("comparing %s with %s\n", str, str);
	printf("ft : |%d| ## original : |%d|\n\n", ft_strcmp(str, str), strcmp(str, str));
	printf("original : |%d| ## ft : |%d|\n", strcmp(str, str2), ft_strcmp(str, str2));
	printf("original : |%d| ## ft : |%d|\n", strcmp(str, str3), ft_strcmp(str, str3));
	printf("original : |%d| ## ft : |%d|\n", strcmp(str3, str4), ft_strcmp(str3, str4));
	printf("original : |%d| ## ft : |%d|\n", strcmp(str, str), ft_strcmp(str, str));
	printf("\n\n\n");
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (!strcmp(argv[1], "ft_read"))
			test_ft_read();
		else if (!strcmp(argv[1], "ft_write"))
			test_ft_write();
		else if (!strcmp(argv[1], "ft_strdup"))
			test_ft_strdup();
		else if (!strcmp(argv[1], "ft_strcmp"))
			test_ft_strcmp();
		else if (!strcmp(argv[1], "ft_strcpy"))
			test_ft_strcpy();
		else if (!strcmp(argv[1], "ft_strlen"))
			test_ft_strlen();
		else
		{
			printf("There is no such function.\nTry : ft_read OR ft_write OR ft_strdup OR ft_strcpy OR ft_strcmp OR ft_strlen");
		}
	}
	else
	{
		test_ft_strlen();
		test_ft_strcpy();
		test_ft_strcmp();
		test_ft_read();
		test_ft_write();
		test_ft_strdup();
	}
	return (1);
}
