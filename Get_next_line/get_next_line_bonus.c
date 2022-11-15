/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:48:55 by mahender          #+#    #+#             */
/*   Updated: 2022/08/29 17:52:50 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*resto(char *men)
{
	int		i;
	int		len;
	char	*aux;

	i = 0;
	len = 0;
	while (men[i] && men[i] != '\n')
		i++;
	if (!men[i])
	{
		free (men);
		return (NULL);
	}
	i++;
	len = ft_strlen(men);
	aux = ft_substr(men, i, len);
	free(men);
	return (aux);
}

char	*imprimir(char *men)
{
	int		i;
	char	*imp;

	i = 0;
	while (men[i] && men[i] != '\n')
		i++;
	imp = ft_substr(men, 0, i + 1);
	return (imp);
}

char	*ft_free_next(char *men, char *temp)
{
	char	*hola;

	hola = ft_strjoin (men, temp);
	free(men);
	men = hola;
	return (hola);
}

char	*lector(int fd, char *men)
{
	int		ind;
	char	*temp;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ind = 1;
	while (ind > 0 && !ft_strchr(men, '\n'))
	{
		ind = read(fd, temp, BUFFER_SIZE);
		if (ind < 0)
		{
			free (temp);
			return (NULL);
		}
		temp[ind] = '\0';
		men = ft_free_next(men, temp);
		if (men[0] == 0)
		{
			free (temp);
			free (men);
			return (NULL);
		}
	}
	free(temp);
	return (men);
}

char	*get_next_line(int fd)
{
	char			*imp;
	static char		*men[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(men[fd]);
		men[fd] = NULL;
		return (0);
	}
	if (!men[fd])
		men[fd] = ft_strdup("");
	men[fd] = lector(fd, men[fd]);
	if (!men[fd])
		return (NULL);
	imp = imprimir(men[fd]);
	men[fd] = resto(men[fd]);
	return (imp);
}

/*int	main (void)
{
	int		fd;
	int	i;

	i = 0;
	fd = open ("file.txt", O_RDONLY);
	if (fd == -1)
		printf("Error, no se ha podido abrir el archivo.");
	while (get_next_line(fd))
	{
		printf("%s \n", get_next_line(fd));
		i++;
	}
	close(fd);
	return (0);
}*/
