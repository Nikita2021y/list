#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Student
{

	string name;
	int cours;

};


struct frame
{

	Student student;
	frame* next = nullptr;
	frame* previos = nullptr;
	frame* insert = nullptr;
	int i = 1;





};


void push(frame** head)
{
	if (*head == nullptr) {
		frame* current = new frame;

		*head = current;
		current->previos = nullptr;





	}
	else
	{

		frame* current = new frame;
		current->previos = *head;
		(*head)->next = current;
		current->next = nullptr;
		current->i += (*head)->i;
		*head = current;





	}
}

void pop(frame** head)
{
	frame* current = *head;
	*head = (*head)->previos;
	(*head)->next = nullptr;
	delete current;
}


void insert2(frame** head, int iterator)
{
	frame* current = *head;
	while (head)
	{

		if (current->i == iterator)
		{
			if (current->previos != nullptr)
			{
				current->previos->next = new frame;
				current->previos->next->next = current;
				current->previos->next->previos = current->previos;
				current->previos = current->previos->next;
				current = current->previos;
				(*head)->insert = current;

				while (current != nullptr)
				{
					current->i = current->previos->i + 1;
					current = current->next;

				}

			}

			else
			{
				current->previos = new frame;
				current->previos->next = current;
				(*head)->insert = current;

				while (current->next != nullptr)
				{
					current = current->next;
					current->i += 1;

				}


			}



			break;
		}
		current = current->previos;
	}
}


void del(frame** head, int iterator)
{
	frame* current = *head;

	while (current)
	{


		if (iterator == current->i)
		{
			if (current->next != nullptr)
			{

				current->previos->next = current->next;
				current->next->previos = current->previos;

				delete current;
			}
			else if (current->next == nullptr)
			{
				*head = current->previos;
				current->previos->next = nullptr;
				delete current;
				break;

			}
			else if (current->i == 1)
			{

				current->next->previos = nullptr;
				delete current;

			}


			frame* current = *head;
			int ptr = (*head)->i;
			while (ptr != 1)
			{

				current->i = ptr -= 1;
				current = current->previos;
			}


			break;
		}
		current = current->previos;
	}
}

frame* get(frame** head, int iterator)
{
	frame* current = *head;
	while (current)
	{
		current = current->previos;

		if (iterator == current->i)
		{
			return current;
		}
	}
}

int main()
{
	frame* head = nullptr;
	frame* temp = nullptr;
	int iterator = 0;

	push(&head);
	head->student.name = "Sasha";
	push(&head);
	head->student.name = "Dasha";
	push(&head);
	head->student.name = "Masha";
	push(&head);
	head->student.name = "Pasha";
	push(&head);
	head->student.name = "Kesha";

	insert2(&head, 2);
	head->insert->student.name = "Egor";
	insert2(&head, 4);
	head->insert->student.name = "Igor";

	del(&head, 5);

	del(&head, 6);









	while (head)
	{
		cout << head->student.name << " " << head->i << endl;
		pop(&head);

	}

	return 0;

}