#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

int main(int argc, char **argv)
{
	DIR *directory;
	struct dirent *file;

	if(argc < 2)
	{
		printf("Please specyfy the directory name\n");
		return 1;
	}
	char *dirName = *(argv + 1);
	/* open directiory */
	directory = opendir(dirName);
	if(directory == NULL)
	{
		printf("There is some problem with open directory\n");
		return 1;
	}

	printf("In folder %s are files:\n", dirName);
	while( (file = readdir(directory)) != NULL)
	{
		printf("\t  %s\n", file->d_name);
	}
	closedir(directory);

	return 0;
}
