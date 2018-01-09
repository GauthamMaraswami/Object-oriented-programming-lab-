#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct file
{
	char name[100];
	struct file *next;
};

void create(struct file *f)
{	
	char name[100];
	printf("Enter name of new file\n");
	scanf("%s", name);
	if(f->next == NULL)
	{
		struct file *newf = (struct file *)malloc(sizeof(struct file));
		strcpy(newf->name, name);
		newf->next = NULL;
		f->next = newf;
		return;
	}
	struct file *it = f->next;
	while(it->next != NULL)
	{
		if(strcmp(it->name, name) == 0)
		{
			printf("File already exists!\n");
			return;
		}
		it = it->next;
	}
	if(strcmp(it->name, name) == 0)
	{
		printf("File already exists!\n");
		return;
	}
	struct file *newf = (struct file *)malloc(sizeof(struct file));
	strcpy(newf->name, name);
	newf->next = NULL;
	it->next = newf; 
}
void delete(struct file **f)
{	
	char name[100];
	printf("Enter name of file\n");
	scanf("%s", name);
	if(f == NULL)
	{
		printf("User directory is empty\n");
		return;
	}
	struct file *it = *f, *prev = NULL;
	while(it != NULL)
	{
		if(strcmp(it->name, name) == 0)
		{
			if(prev == NULL)
			{
				*f = NULL;
			}
			else
			{
				prev->next = it->next;
				free(it);
			}
			printf("File deleted\n");
			return;
		}
		prev = it;
		it = it->next;
	}
	printf("File not found!\n");
}

void find(struct file *f)
{
	char name[100];
	printf("Enter name of file\n");
	scanf("%s", name);
	if(f == NULL)
	{
		printf("User directory is empty\n");
		return;
	}
	struct file *it = f;
	while(it != NULL)
	{
		if(strcmp(it->name, name) == 0)
		{
			printf("File exists\n");
			return;
		}
		it = it->next;
	}
	printf("File not found!\n");
}
void disp(struct file *dir, int size)
{
	int i;
	for(i = 0; i < size; ++i)
	{
		printf("\n");
		printf("User %d has files:\n", i + 1);
		struct file *it = dir[i].next;
		while(it != NULL)
		{
			printf("%s\n", it->name);
			it = it->next;
		}
	}
}
int main()
{
	printf("Enter number of users\n");
	int size, i;
	scanf("%d", &size);
	struct file *dir = (struct file *)malloc(sizeof(struct file) * size);
	for(i = 0; i < size; ++i)
		dir[i].next = NULL;
	int opt;
	do
	{
		printf("Enter option: (1) Create file (2) Delete file (3) Find file (4) Display file system (5) Exit\n");
		scanf("%d", &opt);
		int user;
		switch(opt)
		{
			case 1:
				printf("Enter user to create file under\n");
				scanf("%d", &user);
				if(user > size)
				{
					printf("Invalid user\n");
					break;
				}
				create(&dir[user - 1]);
				break;
			case 2:
				printf("Enter user to delete file from\n");
				scanf("%d", &user);
				if(user > size)
				{
					printf("Invalid user\n");
					break;
				}
				delete(&dir[user - 1].next);
				break;
			case 3:
				printf("Enter user to find file from\n");
				scanf("%d", &user);
				if(user > size)
				{
					printf("Invalid user\n");
					break;
				}
				find(dir[user - 1].next);
				break;
			case 4:
				disp(dir, size);
				break;
		}
	} while(opt != 5);
	return 0;
}
