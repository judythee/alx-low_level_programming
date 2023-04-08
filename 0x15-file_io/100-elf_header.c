#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * cp - copy the content of a file to another file
 * @file_from: name of the file to copy from
 * @file_to: name of the file to copy to
 * Return: 0 on success, 97, 98, 99 or 100 on on failure
 */

int cp(const char *file_from, const char *file_to)
{
	int fd1, fd2; /* File descriptors */
	ssize_t bytesRead; /* Number of bytes read */
	char buffer[BUFFER_SIZE]; /* Buffer for reading and writing */

	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
		S_IROTH; /* Permissions for created file */

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd1 = open(file_from, O_RDONLY);
	if (fd1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from %s\n", fileFrom);
		exit(98); /* Exit with code 98 if source cannot be opened */
	}
	fd2 = open(fileTo, O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd2 == -1)
	{
		dprintf(STDERR FILENO, "Error: Can't write to %s\n", fileTo);
		close(fd1);
		exit(99);
	}
	while ((bytesRead = read(fd1, buffer, BUFFER SIZE)) > 0)
	{
		if (write(fd2, buffer, bytesRead) != bytesRead)
		{
			dprintf(STDERR FILENO, "Error: Can't write to %s\n", fileTo);
			close(fd1);
			close(fd2);
			exit(99);
		}
	}
	close(fd1);
	close(fd2);
	return (0);
}
