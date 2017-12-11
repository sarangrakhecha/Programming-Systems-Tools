#include<stdio.h>
//#include<conio.h>
#include<math.h>

int  main()
{

	float    coeff1=0,coeff2=0,ans=0;
	float    x=2.55;
	float    num=0,deno=0,tot_calc=0.0;
	float    next_multiple=0;
        float    celsius=0;
	long int large_num=9838263505978427528;

	//PART 1 - WRITING THE CODE
	printf("\n*****PART A*****");
	printf("\n\nHello World\n");

	//PART 2-USING VARIABLES AND ARITHMETIC

	//*Part A

	//Part A(I)

	coeff1=3*x*x*x;
	coeff2=5*x*x;

	ans=(coeff1-coeff2)+6;
	printf("\nThe Answer to the quadratic is : %f\n", ans);

	//Part A(II)
	num = (3.31 * pow(10,-8)) + (2.01 * pow(10,-7));
	deno = (7.16 * pow(10,-6)) + (2.01 * pow(10,-8));
	tot_calc = num / deno;
	printf("Answer to the quadratic equation is : %f\n\n",tot_calc);

	//Part A(III)-NEXT EVEN MULTIPLE

	next_multiple = (365+7)-(365%7);
	printf("Next even Multiple : %f\n",next_multiple);

        next_multiple = (12258+28)-(12258%28);
        printf("Next even Multiple : %f\n",next_multiple);

        next_multiple = (996+4)-(996%4);
        printf("Next even Multiple : %f\n\n",next_multiple);

	//Part A (IV)-FAHRENHEIT TO CELSIUS CONVERSION

        celsius = (100-32);
	celsius = celsius/1.8;
        printf("100F when converted to Celsius is : %f\n",celsius);

        celsius = (32-32);
        celsius = celsius/1.8;
        printf("32F when converted to Celsius is : %f\n",celsius);

	celsius = (-40-32);
        celsius = celsius/1.8;
        printf("-40F when  converted to Celsius is : %f\n\n",celsius);


	//PART B(I)
  //PART 1 - WRITING THE CODE
//        printf("\n*****PART A*****");
  //      printf("\n\nHello World\n");

        //PART 2-USING VARIABLES AND ARITHMETIC

        //*Part A

        //Part A(I)

        coeff1=3*x*x*x;
        coeff2=5*x*x;

	printf("\n***************PART B***************");
	printf("\n\nNUMBER TO BE TYPECASTED IS : %d",large_num);

	int int_typecast=(int)large_num;
	printf("\n\nNumber after typecasting into integer is :  %d\n", int_typecast);	

	double double_typecast=(double)large_num;
        printf("Number after typecasting into double is :  %f\n", double_typecast);

	char char_typecast=(char)large_num;
        printf("Number after typecasting into character is :  %c\n", char_typecast);
	return 0;
}
