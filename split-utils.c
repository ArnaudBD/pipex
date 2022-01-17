#include "includes/pipex.h"

char		**freedom(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
	return (tab);
}

int		nb_words(char const *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (s[i] != c)
		nb++;
	while (s[i] != 0)
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			nb++;
		i++;
	}
	return (nb);
}

char		**filling_good(char const *s, char **tab, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == 0)
			break ;
		while (s[i] != c && s[i] != 0)
		{
			tab[j][k] = s[i];
			k++;
			i++;
		}
		tab[j][k] = 0;
		k = 0;
		j++;
	}
	tab[j] = 0;
	return (tab);
}

char		**ft_malloc_split(char const *s, char c, char **tab, int i)
{
	int		j;
	int		first_letter;

	j = 0;
	while (s[i] != 0)
	{
		if (s[i] == c || i == 0)
		{
			while (s[i] == c)
				i++;
			if (s[i] == 0)
				break ;
			first_letter = i;
			while (s[i] != 0 && s[i] != c)
				i++;
			tab[j] = malloc(sizeof(char) * (i - first_letter) + 1);
			if (!tab[j])
			{
				tab = freedom(tab, j);
				return (NULL);
			}
			j++;
		}
	}
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	// int		j;

	if (s == 0)
		return (0);
	i = 0;
	// j = 0;
	if (!(tab = malloc(sizeof(char*) * (nb_words(s, c) + 1))))
		return (NULL);
	tab = ft_malloc_split(s, c, tab, i);
	if (tab == NULL)
		return (tab);
	else
	{
		// tab[nb_words(s, c)] = malloc(sizeof(char));
		// if (!tab[nb_words(s, c)])
		// {
		// 	tab = freedom(tab, j);
		// 	return (NULL);
		// }
		tab = filling_good(s, tab, c);
	}
	return (tab);
}

// int main()
// {
// 	int i = 0;
// 	char **tab;
// 	char *str = "0 1fffff 2fe 3gh";
// 	printf("str = '%s'\n", str);
// 	tab = ft_split(str, ' ');
// 	while (tab[i])
// 	{
// 		printf("tab[%d] = '%s'\n", i, tab[i]);
// 		i++;
// 	}
// 	freedom(tab, i);
// 	// free(tab);
// 	return 0;
// }