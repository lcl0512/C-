#include <stdio.h>
int main()
{
	int a[5] = {1, 2, 3, 4, 5};
	int *pa = a;
	for (int i = 0; i < 5; ++i)
		printf("%d  ", pa[i]);
	return 0;
}
typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *next;
} lklist;
void delredundant(lklist *&head)
{
	lklist *p, *q, *s;
	for (p = head; p != 0; p = p->next)
	{
		for (q = p->next, s = q; q != 0;)
			if (q->data == p->data)
			{
				s->next = q->next;
				free(q);
				q = s->next;
			}
			else
			{
				s = q, q = q->next;
			}
	}
}
