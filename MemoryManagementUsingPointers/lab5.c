#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int heap_usage=0;
int index1;

typedef struct
{
	char * first_name;
	char * last_name;
	char * jedi_name;
}Names;

Names Names1[82];

int jedi(char * first_name, char * last_name, char buffer[])
{
	int count=0,flag=0,j=0,i=0;
	last_name++;

	if(strlen(last_name)<=3)
	{
		for(i=0;i<2;i++)
		{
			buffer[i]=*last_name;
			last_name++;
			count++;
		}
		buffer[i++]=',';
	}
	else
	{
		for(i=0;i<3;i++)
		{
			buffer[i]=*last_name;
			last_name++;
			count++;
		}
		flag=1;
	}

	if(*first_name=='\n')
		first_name++;
	for(j=0;j<2;j++)
	{
		buffer[i]=*first_name;
		first_name++;
		i++;
	}
	buffer[i]='\0';
	printf("\nJedi is : %s\n", buffer);
}

//FUNCTION FOR DEALLOCATION OF MEMORY
void * deallocate(void *p,int size)
{
	printf("HEAPUSAGE deallocation : %d\n", heap_usage);
	free(p);
	p=NULL;
	heap_usage-=(sizeof(char)*size);
}

//FUNCTION FOR ASSIGNMING NAMES FOR DEALLOCATION
void deallocate_str(Names * Names1)
{
	int index2;
	deallocate(Names1[index2].first_name,30);
	deallocate(Names1[index2].last_name,30);
	deallocate(Names1[index2].jedi_name,6);
}

//FUNCTION FOR ALLOCATION OF MEMORY
void * allocate(unsigned int size)
{
	char * mem;
	mem=malloc(sizeof(char)*size);
	heap_usage=heap_usage+(sizeof(char)*size);
	printf("\nHEAPUSAGE allocation : %d", heap_usage);
	return mem;
}

//FUNCTION FOR ASSIGNMING NAMES FOR ALLOCATION
void allocate_str(char fname[], char lname[])
{

	Names1[index1].first_name=allocate(30);
	Names1[index1].last_name=allocate(30);
	Names1[index1].jedi_name=allocate(6);

	strcpy(Names1[index1].first_name, fname);
	strcpy(Names1[index1].last_name, lname);

	jedi(Names1[index1].first_name,Names1[index1].last_name,Names1[index1].jedi_name);
	index1++;
}

int main()
{
	char first_name[100], last_name[100], buffer[10];
	int loop=0;
	FILE *fp1;
	fp1=fopen("names.txt", "r");
	printf("\n**********PART A***********\n");
	//FOR READING OF FIRST & LAST NAME
	while(!feof(fp1))
	{
		if(fscanf(fp1,"%[^,]s",first_name)!=1)break;
		printf("%s", first_name);

		if(fscanf(fp1,"%[^\n]s",last_name)!=1)break;
		printf("%s",last_name);
		allocate_str(first_name,last_name);
	}

	for(loop=0;loop<82;loop++)
	{
		deallocate_str(&Names1[loop]);
	}

	fclose(fp1);
	return 0;
}
