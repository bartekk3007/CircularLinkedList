#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
	int val;
	struct ListNode* next;
};

void addNode(struct ListNode** head, int n) 
{
	struct ListNode* vertex = (struct ListNode*) malloc(sizeof(struct ListNode));
	if (vertex)
	{
		vertex->val = n;
		if (*head == NULL)
		{
			vertex->next = vertex;
			(*head) = vertex;
		}
		else
		{
			struct ListNode* current = *head;
			while (current->next != *head)
			{
				current = current->next;
			}
			current->next = vertex;
			vertex->next = *head;
		}
	}
}

void deleteNode(struct ListNode** head, int n)
{
	if (*head == NULL)
	{
		return;
	}
	else
	{
		struct ListNode* current = *head;
		if (current->next == *head && current->val == n)
		{
			free(*head);
			*head = NULL;
		}
		else if (current->next == *head)
		{
			return;
		}
		else
		{
			while (current->next != *head && current->next->val != n)
			{
				current = current->next;
			}
			if (current->next == *head && current->next->val == n)
			{
				struct ListNode* temp = current->next;
				*head = temp->next;
				current->next = *head;
				free(temp);
			}
			else if (current->next == *head)
			{
				return;
			}
			else
			{
				struct ListNode* temp = current->next;
				current->next = temp->next;
				free(temp);
			}
		}
	}
}

void traverseList(struct ListNode* head)
{
	printf("Lista ");
	struct ListNode* current = head;
	if (head)
	{
		printf("%d ", head->val);
		head = head->next;
		while (head != current)
		{
			printf("%d ", head->val);
			head = head->next;
		}
	}
	printf("\n");
}

void freeList(struct ListNode* head)
{
	struct ListNode* current = head;
	struct ListNode* tmp;

	if (head == NULL)
	{
		return;
	}
	else
	{
		current = current->next;
		while (current != head)
		{
			tmp = current;
			current = current->next;
			free(tmp);
		}
		free(current);
	}
	
}

int main(void)
{
	struct ListNode* head = NULL;
	addNode(&head, 5);
	addNode(&head, 8);
	addNode(&head, 13);
	addNode(&head, 21);
	addNode(&head, 34);
	addNode(&head, 55);

	traverseList(head);

	deleteNode(&head, 7);

	traverseList(head);

	freeList(head);

	return 0;
}