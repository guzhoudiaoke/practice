/*
 * poj 1028
 * guzhoudiaoke@126.com
 * 2011-08-31
 */

#include <stdio.h>
#include <string.h>

typedef struct navigation_stack {
	char url[100][71];
	int cur_index;
} navigation_stack;

void init(navigation_stack *stack)
{
	stack->cur_index = -1;
}

void push(navigation_stack *stack, char url[71])
{
	stack->cur_index ++;
	strcpy(stack->url[stack->cur_index], url);
}

void pop(navigation_stack *stack, char url[71])
{
	strcpy(url, stack->url[stack->cur_index]);
	stack->cur_index --;
}

void clear(navigation_stack *stack)
{
	stack->cur_index = -1;
}

int is_empty(navigation_stack *stack)
{
	return (stack->cur_index == -1);
}

int main()
{
	navigation_stack stack_forward;
	navigation_stack stack_backward;
	char cmd[8];
	char cur_url[71];
	
	init(&stack_forward);
	init(&stack_backward);
	
	sprintf(cur_url, "%s", "http://www.acm.org/\0");
	
	while (1)
	{
		scanf("%s", cmd);
		
		if (strcmp(cmd, "QUIT") == 0)
			break;
		else if (strcmp(cmd, "BACK") == 0)
		{
			if (is_empty(&stack_backward))
				printf("Ignored\n");
			else
			{
				push(&stack_forward, cur_url);
				pop(&stack_backward, cur_url);
				printf("%s\n", cur_url);
			}
		}
		else if (strcmp(cmd, "FORWARD") == 0)
		{
			if (is_empty(&stack_forward))
				printf("Ignored\n");
			else
			{
				push(&stack_backward, cur_url);
				pop(&stack_forward, cur_url);
				printf("%s\n", cur_url);
			}
		}
		else if (strcmp(cmd, "VISIT") == 0)
		{	
			push(&stack_backward, cur_url);
			scanf("%s", cur_url);
			printf("%s\n", cur_url);
			clear(&stack_forward);
		}
	}
	
	return 0;
}
