#include <stdlib.h>
#include "monty.h"

/**
 * _free - frees al allocated memory
 */
void _free(void)
{
	stack_t *ptr;

	ptr = vars.top;
	while (vars.top)
	{
		vars.top = vars.top->next;
		free(ptr);
		ptr = vars.top;
	}
	if (vars.full_command)
		free(vars.full_command);
	fclose(vars.stream);
}
