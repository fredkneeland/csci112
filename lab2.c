#import <stdio.h>

//////////////////////////////////////////////////////////////////////////////////
//										//
//  These are global variables for our program					//
//										//
//////////////////////////////////////////////////////////////////////////////////

char WRONG_INPUT_LENGTH_MSG[] = "Array Lengths must be greater than or equal to 0\n";
char GET_ARRAY_LENGTH_MSG[] = "Please enter the length of the array\n";


/**
 * This function will return a value received from the user
 * after printint out a msg passed in as a parameter
 */
int getValue(char[] msg_to_be_printed)
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
 * This is the main method that will execute when we run this file
 */
int main 
{
	// initialize array length to -1
	int user_given_array_length = -1;

	// loop until we get a non-negative array length from user
	while (user_given_array_length < 0) 
	{
		// call func to get array length from user
		user_given_array_length = getValue(GET_ARRAY_LENGTH_MSG);
	
		// check if input from user is not valid
		if (user_given_array_length < 0)
		{
			// if input from user is wrong print error msg
			printf(WRONG_INPUT_LENGTH_MSG);
		}
	}

	// exit normally
	return 0;
}
