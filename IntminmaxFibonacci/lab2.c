#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

void dec_to_bin(num);
int main()
{
	int i,loop=0,loop1=0,rightshift=0,num;
	int num1=INT_MIN,num2=INT_MAX,num3;

	int fibo=0, fibo1=0, fibo2=1;

	//FOR RANDOM NUMBER GENERATOR
	srand(time(NULL));

	//FIBONACCI SERIES
	printf("\n**************PART A**************\n\n");

	printf("First 20 numbers of  Fibonacci sequence are :\n ");
	for(i=1; i<21; i++)
	{
		printf("%d] %d\n ",i,fibo);
		fibo1 = fibo2;
		fibo2 = fibo;
		fibo = fibo1 + fibo2;
	}
	printf("\n\n ");

	//*********PART B(II)************
	printf("\n**********PART II*************\n");
	for(loop=0;loop<4;loop++)
	{
		printf("\nEnter the no. to be converted to Binary : ");
		scanf("%d", &num);
		dec_to_bin(num);
	}

	//FOR INT_MIN
	printf("\nINT_MIN converted to binary is : ");
	for(loop=31;loop>=0;loop--)
	{
		rightshift=num1>>loop;
		if((rightshift & 1) == 1)
			printf("1");
		else
			printf("0");
	}

	//FOR INT_MAX
	printf("\nINT_MAX converyed to binary is : ");
        for(loop=31;loop>=0;loop--)
        {
                rightshift=num2>>loop;
                if((rightshift & 1) == 1)
                        printf("1");
                else
                        printf("0");
        }
        printf("\n");

	printf("\n**********PART II(B)****************");

	//RANDOM NUMBER GEBERATOR
	num3=rand();
	printf("\n\nRandom number is : %d", num3);
	num3=rand()%INT_MAX*2 + INT_MIN;
	printf("\n\nRandom number expression is : %d", num3);
	printf("\nRandom number expression after converted to decimal is : ");

	for(loop=31;loop>=0;loop--)
	{
		rightshift=num3>>loop;
		if((rightshift & 1) == 1)
			printf("1");
 		else
			printf("0");
	}
	printf("\n\n");
	return 0;
}

//FUNCTION FOR BINARY CONVERSION
void dec_to_bin(num)
{
	int loop=0, rightshift=0;

	printf("The number converted to binary is : ");
	for(loop=31;loop>=0;loop--)
	{
        	rightshift=num>>loop;
		if((rightshift&1) == 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n\n");
}
