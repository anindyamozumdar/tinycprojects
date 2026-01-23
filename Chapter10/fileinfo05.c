#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void permissions_out(mode_t stm)
{
	putchar(stm & S_IRUSR ? 'r' : '-' );
	putchar(stm & S_IWUSR ? 'w' : '-' );
	putchar(stm & S_IXUSR ? 'x' : '-' );
	putchar(stm & S_IRGRP ? 'r' : '-' );
	putchar(stm & S_IWGRP ? 'w' : '-' );
	putchar(stm & S_IXGRP ? 'x' : '-' );
	putchar(stm & S_IROTH ? 'r' : '-' );
	putchar(stm & S_IWOTH ? 'w' : '-' );
	putchar(stm & S_IXOTH ? 'x' : '-' );
	putchar('\n');
}

int main(int argc, char *argv[])
{
	char *filename;
	struct stat fs;
	int r;

	if( argc<2 )
	{
		fprintf(stderr,"Specify a filename\n");
		exit(1);
	}

	filename = argv[1];
	r = stat(filename,&fs);
	if( r==-1 )
	{
		fprintf(stderr,"Error reading '%s'\n",filename);
		exit(1);
	}

	printf("File '%s' is a ",filename);
	if( S_ISBLK(fs.st_mode) )
		printf("block special\n");
	else if( S_ISCHR(fs.st_mode) )
		printf("character special\n");
	else if( S_ISDIR(fs.st_mode) )
		printf("directory\n");
	else if( S_ISFIFO(fs.st_mode) )
		printf("named pipe or socket\n");
	else if( S_ISREG(fs.st_mode) )
		printf("regular file\n");
	else if( S_ISLNK(fs.st_mode) )
		printf("symbolic link\n");
	else if( S_ISSOCK(fs.st_mode) )
		printf("socket\n");
	else
		printf("type unknown\n");

    permissions_out(fs.st_mode);

	return(0);
}