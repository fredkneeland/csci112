#import <stdio.h>

//////////////////////////////////////////////////////////////////////////////////
//										//
//  These are global variables for our program					//
//										//
//////////////////////////////////////////////////////////////////////////////////

char WRONG_INPUT_LENGTH_MSG[] = "Array Lengths must be greater than or equal to 0\n";
char GET_ARRAY_LENGTH_MSG[] = "Please enter the length of the array\n";
char GET_VALUE_FROM_USER[] = "Please enter the next value from the array";
char WRONG_VALUE_MSG[] = "Values must be positive";
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
int getValueFromUser(char[] msg_to_be_printed)
{
	// initialize our input variable
	int value_from_user = 0;
	// print out prompt for user
	printf(msg_to_be_printed);
	// scan in value from user
	scanf("%d", &value);
	// return the value given by user to whoever called us
	return value_from_user;
}

/**
 * This function gets a value from the user between the min and max ranges
 */
int getValueFromUserInRange(char[] msg_to_be_printed, char[] msg_to_be_printed_in_case_of_error, int minValue, int maxValue)
{
	// initialize our variable
	int user_given_value;

	// get value from user
	user_given_value = getValueFromUser(msg_to_be_printed);

	// if value is incorrect loop until they give us a value inside of the range
	while (user_given_value < minValue || user_given_value > maxValue)
	{
		// print error msg
		printf(msg_to_be_printed_in_case_of_error);
		// ask the user for the value again
		user_given_value = getValueFromUser(msg_to_be_printed);
	}
	
	// return value to whoever called us
	return user_given_value;
}

/**
 * This is the main method that will execute when we run this file
 */
int main 
{
	// get array length from user between the values of 0 and MAX_INT_VALUE
	int user_given_array_length = getValueFromUserInRange(GET_ARRAY_LENGTH_MSG, WRONG_INPUT_LENGTH_MSG, 0, MAX_INT_VALUE);

	// initialize an array of the length given by the user
	int array_of_user_values[user_given_array_length];
	
	// initialize result values
	int lowest = 0,
	    highest = MAX_INT_VALUE, 
	    avg = 0, 
	    sum_squares = 0, 
	    std_dev, range;

	// initialize our loop counter
	int loop_counter;

	// create a for loop to get all of the values
	for (loop_counter = 0; loop_counter < user_given_array_length; loop_counter++)
	{
		// set the next value in the array to a user given value
		array_of_user_values[loop_counter] = getValueFromUserInRange(GET_VALUE_FROM_USER, WRONG_VALUE_MSG, 0, MAX_INT_VALUE);
		
		// check for lowest
		if (array_of_user_values[loop_counter] < lowest)
		{
			lowest = array_pf_user_values[loop_counter];
		}
	}

	// exit normally
	return 0;
}
