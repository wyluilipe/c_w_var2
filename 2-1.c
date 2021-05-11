#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
	char *str;
	struct list *next;
};

struct list *add_word(struct list *head, char *buff)
{
	struct list *tmp;
	tmp = malloc(sizeof(*tmp));
	strcpy(tmp->str, buff);
	tmp->next = head;
	return tmp; 
}

char *make_buff_zero(char *buff)
{
	for (int i = 0; i <= strlen(buff); i++)
		buff[i] = '\0';
	return buff;
}

char *make_buff_bigger(char *buff)
{
	int len = strlen(buff);
	char *new_buff;
	new_buff = malloc(sizeof(char) * (len + 1) * 2);
	strcpy(new_buff, buff);
	return new_buff;
}

char *add_let(char *buff, char c, int i)
{
	if (i == strlen(buff) - 1)
		buff = make_buff_bigger(buff);
	buff[i] = c;
	return buff;
}

void start(struct list *head, int max)
{
	struct list *tmp = head;
	while (tmp) {
		if (strlen(tmp->str) == max)
			printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
}

int main(int argc, char **argv)
{
	struct list *head = NULL;
	int c, n = 8;
	int max = 0;
	int i = 0;
	char *buff;
	buff = malloc(n * sizeof(char));
	while ((c = getchar()) != EOF) {
		if ((c == ' ') || (c == '\n') || (c == '\t')) {
			head = add_word(head, buff);
			i = 0;
			buff = make_buff_zero(buff);
		} else {
			if (i == n - 1)
				n *= 2;
			if (i > max)
				max = i;
			buff = add_let(buff, c, i++);
		}
	}
	if (buff[0] != '\0')
		head = add_word(head, buff);
	start(head, max);
	return 0;
}