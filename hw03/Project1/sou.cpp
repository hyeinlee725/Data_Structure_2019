#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct instr
{
	int i;
	char str[20];
};
int main()
{
	struct instr * set = (instr *)malloc(sizeof(instr));
	set->i = 100;
	set->str = "just testing";
	//strcpy(set->str, "just testing");
	printf("%d\n%s", set->i, set->str);
	free(set);
	return 0;
}