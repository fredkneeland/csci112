#import <stdio.h>

double get_input()
{
	printf("give us a number ");
	double value;
	scanf("%lf", &value);
	return value;
}

double get_next(double n2, double n1)
{
	double value = n2 / 2.0;
	value += 3 * n1;
	return value;
}

void print_result(double value)
{
	printf("The result is %3.2f \n", value);
}

int main()
{
	double n1 = get_input();
	double n2 = get_input();
	double value;

	int i;

	for (i = 0; i < 5; i++)
	{
		value = get_next(n2, n1);
		n2 = n1;
		n1 = value;	
	}

	print_result(value);
	return 1;
}
