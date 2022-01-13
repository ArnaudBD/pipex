#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


int main()
{
	int arr[] = {1, 2, 3, 4, 1, 2};
	int arrsize = sizeof(arr) / sizeof(int);
	int fd[2];
	int start, end;
	if (pipe(fd) == -1)
	{
		printf("Error pipe()\n");
		return 1;
	}

	int id = fork();
	if (id == -1)
	{
		printf("Error fork()\n");
		return 1;
	}

	if (id == 0)
	{
		start = 0;
		end = arrsize / 2;
	}
	else
	{
		start = arrsize / 2;
		end = arrsize;
	}

	int sum = 0;
	int i;
	for (i = start; i < end; i++)
	{
		sum += arr[i];
	}
	printf("Calculated partial sum: %d\n", sum);

	if (id == 0)
	{
		close(fd[0]);
		write(fd[1], &sum, sizeof(sum));
		close(fd[1]);
	}
	else
	{
		int sumFromChild;
		close(fd[1]);
		read(fd[0], &sumFromChild, sizeof(sum));
		close(fd[0]);
		printf("Total sum is %d\n", sumFromChild + sum);
		wait(NULL);
	}
}


/*

int	main()
{
	int fd[2];
	if (pipe(fd) == -1)
	{
		printf("An error ocurred with the pipe \n");
		return 1;
	}
	int id = fork();

	if (id == 0)
	{
		close(fd[0]);
		int x;
		printf("Input a number:\n");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
		{
			printf("An error ocurred with write()\n");
		}
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("Got from child process: %d\n", y);
	}
	return 0;
}
*/