#import <stdio.h>
#import <math.h>

//////////////////////////////////////////////////////////////////////////////////
//										//
//  These are global variables for our program					//
//										//
//////////////////////////////////////////////////////////////////////////////////

char WRONG_INPUT_LENGTH_MSG[] = "Array Lengths must be greater than or equal to 0\n";
char GET_ARRAY_LENGTH_MSG[] = "Please enter the length of the array\n";
char GET_VALUE_FROM_USER[] = "Please enter the next value from the array ";
char WRONG_VALUE_MSG[] = "Values must be positive";
char FINAL_RANGE_PRINT_MSG[] = "Range: ";
char END_OF_LINE_CHAR[] = "\n";
char FINAL_AVERAGE_PRINT_MSG[] = "Average: ";
char FINAL_HIGHEST_VALUE_PRINT_MSG[] = "Highest Value: ";
char FINAL_LOWEST_VALUE_PRINT_MSG[] = "Lowest Value: ";
char FINAL_STD_DEV_PRINT_MSG[] = "Standard Deviation: ";
char FINAL_SUM_PRINT_MSG[] = "Sum: ";
char FINAL_SUM_SQUARES_MSG[] = "Squared Sum: ";

int MAX_INT_VALUE = 2147483647;



//////////////////////////////////////////////////////////////////////////////////
//										//
//	These are functions to help us solve the problem			//
//										//
//////////////////////////////////////////////////////////////////////////////////

/**
 * This function will return a value received from the user
 * after printint out a msg passed in as a parameter
 */
int getValueFromUser(char msg_to_be_printed[])
{
	// initialize our input variable
	int value_from_user = 0;
	// print out prompt for user
	printf("%s", msg_to_be_printed);
	// scan in value from user
	scanf("%d", &value_from_user);
	// return the value given by user to whoever called us
	return value_from_user;
}

/**
 * This function gets a value from the user between the min and max ranges
 */
int getValueFromUserInRange(char msg_to_be_printed[], char msg_to_be_printed_in_case_of_error[], int minValue, int maxValue)
{
	// initialize our variable
	int user_given_value;

	// get value from user
	user_given_value = getValueFromUser(msg_to_be_printed);

	// if value is incorrect loop until they give us a value inside of the range
	while (user_given_value < minValue || user_given_value > maxValue)
	{
		// print error msg
		printf("%s", msg_to_be_printed_in_case_of_error);
		// ask the user for the value again
		user_given_value = getValueFromUser(msg_to_be_printed);
	}
	
	// return value to whoever called us
	return user_given_value;
}

/**
 * This is the main method that will execute when we run this file
 */
int main() 
{
	// get array length from user between the values of 0 and MAX_INT_VALUE
	int user_given_array_length = getValueFromUserInRange(GET_ARRAY_LENGTH_MSG, WRONG_INPUT_LENGTH_MSG, 0, MAX_INT_VALUE);

	// initialize an array of the length given by the user
	int array_of_user_values[user_given_array_length];
	
	// initialize result values
	int lowest = MAX_INT_VALUE,
	    highest = 0,
	    sum = 0, 
	    sum_squares = 0, 
	    range;

	double std_dev,
	       average = 0;

	// initialize our loop counter
	int loop_counter;

	// create a for loop to get all of the values
	for (loop_counter = 0; loop_counter < user_given_array_length; loop_counter++)
	{
		// set the next value in the array to a user given value
		array_of_user_values[loop_counter] = getValueFromUserInRange(GET_VALUE_FROM_USER, WRONG_VALUE_MSG, 0, MAX_INT_VALUE);
		
		// check if current value is lower than lowest value
		if (array_of_user_values[loop_counter] < lowest)
		{
			// update lowest
			lowest = array_of_user_values[loop_counter];
		}
		// check if current value is greater than current highest
		else if (array_of_user_values[loop_counter] > highest)
		{
			// update highest
			highest = array_of_user_values[loop_counter];
		}

		// update the total sum
		sum += array_of_user_values[loop_counter];
		// update the total sum squared
		sum_squares += (array_of_user_values[loop_counter]) * (array_of_user_values[loop_counter]);
	}

	// set range
	range = highest - lowest;

	// check if length == 0 to prevent a division by 0 error
	if (user_given_array_length == 0)
	{
		average = 0;
		std_dev = 0;
	}
	else
	{
		// calculate average
		average = (double) sum / (double) user_given_array_length;
		// calculate standard deviation
		std_dev = sqrt((sum_squares / user_given_array_length) - (average * average));
	}

	///////////// Print out all of the values \\\\\\\\\\\\\\\\\\\\

	// print out the average value
	printf("%s", FINAL_AVERAGE_PRINT_MSG);
	printf("%f", average);
	printf("%s", END_OF_LINE_CHAR);

	// print out the range
	printf("%s", FINAL_RANGE_PRINT_MSG);
	printf("%d", range);
        printf("%s", END_OF_LINE_CHAR);

	// print out the highest value
	printf("%s", FINAL_HIGHEST_VALUE_PRINT_MSG);
	printf("%d", highest);
        printf("%s", END_OF_LINE_CHAR);

	// print out the lowest value
	printf("%s", FINAL_LOWEST_VALUE_PRINT_MSG);
	printf("%d", lowest);
        printf("%s", END_OF_LINE_CHAR);

	// print out the sum
	printf("%s", FINAL_SUM_PRINT_MSG);
	printf("%d", sum);
        printf("%s", END_OF_LINE_CHAR);

	// print out the sum of the squares
	printf("%s", FINAL_SUM_SQUARES_MSG);
	printf("%d", sum_squares);
        printf("%s", END_OF_LINE_CHAR);

	// print out the standard deviation
	printf("%s", FINAL_STD_DEV_PRINT_MSG);
	printf("%f", std_dev);
        printf("%s", END_OF_LINE_CHAR);

	// exit normally
	return 0;
}
