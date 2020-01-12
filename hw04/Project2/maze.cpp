#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

void print_maze(MAZE *maze)
{
	int i = 0;
	int j = 0;
	maze->map[maze->here_r][maze->here_c] = '*';
	for (i = 0; i < MAX_MAZE_SIZE; i++)
	{
		for (j = 0; j < MAX_MAZE_SIZE; j++)
		{
			printf("%c ", maze->map[i][j]);
		}
		printf("\n");
	}
}

void push_loc(MAZE *maze, int r, int c)//push_stack 및 print_stack 사용
{
	if (r <= 0 || c <= 0)//r과 c의 조건(-1안나오도록)
		return;

	if((maze->map[r][c]) != '1' && (maze->map[r][c]) !='.')//조건(1이 아니고 .이 아닐 때)
	{
		push_stack(maze->stack, r);
		push_stack(maze->stack, c);
		print_stack(maze->stack);
	}
}

int run_maze(MAZE *maze)
{
	push_loc(maze, maze->here_r, maze->here_c + 1);
	push_loc(maze, maze->here_r + 1, maze->here_c);
	push_loc(maze, maze->here_r, maze->here_c - 1);
	push_loc(maze, maze->here_r - 1, maze->here_c);

	maze->map[maze->here_r][maze->here_c] = '.';

	maze->here_c = pop_stack(maze->stack);
	maze->here_r = pop_stack(maze->stack);

	if (maze->map[maze->here_r][maze->here_c] == 'x')
	{
		return 1;
	}
	/*(maze->map[maze->here_r][maze->here_c] != 'x') && ((stack)->top == -1*/
	else if ((maze->map[maze->here_r][maze->here_c] != 'x') && empty_stack(maze->stack) == -1)
		return 3;
	else
		return 2;
}

char map1[MAX_MAZE_SIZE][MAX_MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};

int main()
{
	int r;
	MAZE maze1;

	maze1.map = map1;
	maze1.stack = (STACK *)malloc(sizeof(STACK));
	init_stack(maze1.stack);
	maze1.here_r = 1;
	maze1.here_c = 0;

	for (;;) {
		//r=system("clear");
		//r = r;
		
		printf("============\n");
		print_maze(&maze1);

		r = run_maze(&maze1);
		if (r == FAILED) {
			printf("FAILED!\n");
			break;
		}
		//getchar();
	}
	return EXIT_SUCCESS;
}