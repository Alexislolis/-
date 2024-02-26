#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>



int main(int argc, char **argv)
{
	struct stat arxeio;
	if(argc != 2)
	{
		printf("Usage ./a.out filename\n");
		return 1;
	}
	else
	{
		if(strcmp(argv[1], "--help") == 0)
		{
			printf("Usage ./a.out filename\n");
			return 0;
		}
		else if(stat(argv[1], &arxeio) == 0)
		{
			printf("Error: %s already exists\n", argv[1]);
			return 1;
		}
	}
	int fd = open(argv[1], O_CREAT | O_APPEND | O_WRONLY | O_RDONLY, 0644);
	if(fd == -1)
	{
		perror("open");
		return 1;
	}
	int status;
	pid_t paidi;
	paidi = fork();
	if(paidi < 0)
	{
		printf("Error in generating child program");
		return 1;
	}
	if(paidi==0)
	{
		pid_t paidi_idpaidiou = getpid();
		pid_t paidi_idpatera = getppid();
		char printpaidi[50];
		sprintf(printpaidi, "[CHILD] getpid()= %d, getppid()= %d\n",paidi_idpaidiou, paidi_idpatera);

		if(write(fd, printpaidi,strlen(printpaidi)) < strlen(printpaidi))
		{
			perror("write");
			return 1;
		}
		exit(0);
	}
	else
	{
		pid_t pateras_idpaidiou = getpid();
		pid_t pateras_idpatera = getppid();
		char printpatera[50];
		sprintf(printpatera, "[PARENT] getpid()= %d, getppid()= %d\n", pateras_idpaidiou, pateras_idpatera);
		if(write(fd, printpatera, strlen(printpatera)) < strlen(printpatera))
		{
			perror("write");
			return 1;
		}
		close(fd);
		if(close < 0)
		{
			perror("close error");
			return 1;
		}
		wait(&status);
		exit(0);
	}
	return 0;
}