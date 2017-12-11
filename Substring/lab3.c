#include<stdio.h>
#include<string.h>

//MACRO DECLARATIONS
#define TRUE 1
#define FALSE 0
#define EQUAL ==

#if TRUE
#define DEBUG(x) fprintf(stderr,"\nSUBSTRING FOUND!! The Buffer is : %s\n\n",x);
#define TRACE	 fprintf(stderr,"Line number is : %d\n\n",__LINE__);

#else FALSE
#define DEBUG
#define TRACE

#endif

//GLOBAL DECLARATION
char buffer1[20];

int myStrStr(char haystack[],char needle[],char buffer[])
{

	int loop=0,haystack_count=0,needle_count=0,buffer_count=0,flag=0,check=0,loop1=0,length=0;
	while(haystack[loop]!='\0')
	{
		loop++;
		length++;
	}
	for(loop=0;loop<length;loop++)
	{
		//CHECK STRING AND SUBSTRING CHARACTER BY CHARACTER
		if(haystack[haystack_count] EQUAL needle[needle_count])
		{
			buffer[buffer_count]=haystack[haystack_count];
			haystack_count++;
			buffer_count++;
			needle_count++;
			continue;
		}
		else
		{
			haystack_count++;
			needle_count=0;
			buffer_count=0;
			continue;
		}
	}
	//CHECK IF SUBSTRING AND RETURN RESPECIVE VALUE
	for(check=0;needle[check]!='\0';check++)
	{
		if(buffer[check] EQUAL needle[check])
		{
			flag=1;
		}
		else
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		for(check=0;needle[check]!='\0';check++)
		{
			buffer1[check]=buffer[check];
		}
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int main()
{

	char string[15],substring[15],buffer[15],loop=0;
	int solution;

	//TAKE INPUT FROM THE USER
	printf("\nEnter the string : ");
	scanf("	%s",string);
	printf("\nEnter the Substring : ");
	scanf("\n%s", substring);

	//RETURN VALUE IN THE VARIABLE
	solution=myStrStr(string,substring,buffer);

	if(solution EQUAL TRUE)
	{
		//CALL MACRO FOR PRINTING THE ANSWER
		DEBUG(buffer1);
		TRACE;
	}
	else
	{
		printf("\n\nSORRY!! NO SUBSTRING FOUND.\n\n");
	}

	return 0;
}

