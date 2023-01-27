# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>


int main()
{
	int fd = open("/Users/marcopaternostofrosi/Documents/42_cursus/get_next_line/gnlTester/files/empty", O_RDWR);
	char	buffer[200];
	printf("-%d-", fd);
	printf("%zd\n\n", read(fd, buffer, 20));
	printf("%zd\n\n", read(fd, buffer, 40));
	printf("%zd\n\n", read(fd, buffer, 40));
	close(fd);
}
