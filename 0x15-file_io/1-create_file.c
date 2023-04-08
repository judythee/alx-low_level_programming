#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
#include <string.h>
/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 * Return: If the function fails - -1.
 * Otherwise - 1.
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	int ret;

	if (filename == NULL)
		return (-1);
	/* open file with read/write permissions and create if it doesn't exist */
	fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);
	/* truncate file if it already exists */
	ret = ftruncate(fd, 0);
	if (ret == -1)
		return (-1);
	/* write to file */
	if (text_content != NULL)
	{
		ret = write(fd, text_content, strlen(text_content));
		if (ret == -1)
			return (-1);
	}
	/* close file */
	ret = close(fd);
	if (ret == -1)
		return (-1);
	return (1);
}
