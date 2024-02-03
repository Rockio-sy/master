#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "help_func.h"

// Check the correctness of input for a floating-point number
int correctness_number(char number[LEN])
{
    lower(number);
    if (!strcmp(number, "exit"))
    {
        puts("Program termination.");
        return EXIT;
    }
    else if (count_symbol(number, '.') > 1)
    {
        puts("\".\" appeared more than once!");
        return ERROR_INPUT;
    }
    else if (count_symbol(number, 'e') > 1)
    {
        puts("\"E\" appeared more than once!");
        return ERROR_INPUT;
    }
    else if (count_symbol(number, '-') > 2)
    {
        puts("Too many '-' signs.");
        return ERROR_INPUT;
    }
    else if (count_symbol(number, '+') > 2)
    {
        puts("Too many '+' signs.");
        return ERROR_INPUT;
    }
    else if (my_strchr(number, 'e') && (my_strchr(number, 'e') < my_strchr(number, '.')))
    {
        puts("Invalid input!\n'e' comes after '.'");
        return ERROR_INPUT;
    }

    for (size_t i = 0; number[i]; i++)
    {
        if (count_symbol(number, 'e') == 1)
        {
            if (count_symbol(number, '-') > 0)
            {
                if (count_symbol(number, '-') == 1)
                {
                    if ((number[i] == 'e' && number[i + 1] != '-') && (number[0] != '-'))
                    {
                        puts("Invalid input! '-'");
                        return ERROR_INPUT;
                    }
                }
                else if(count_symbol(number, '-') == 2)
                {
                    if ((number[i] == 'e' && number[i + 1] != '-') || (number[0] != '-'))
                    {
                        puts("Invalid input! '-'");
                        return ERROR_INPUT;
                    }
                }
                else
                {
                    puts("Invalid input! '-'");
                    return ERROR_INPUT;
                }
            }
            if (count_symbol(number, '+') > 0)
            {
                if (count_symbol(number, '+') == 1)
                {
                    if ((number[i] == 'e' && number[i + 1] != '+') && (number[0] != '+'))
                    {
                        puts("Invalid input! '+'");
                        return ERROR_INPUT;
                    }
                }
                else if (count_symbol(number, '+') == 2)
                {
                    if ((number[i] == 'e' && number[i + 1] != '+') || (number[0] != '+'))
                    {
                        puts("Invalid input! '+'");
                        return ERROR_INPUT;
                    }
                }
                else
                {
                    puts("Invalid input! '+'");
                    return ERROR_INPUT;
                }
            }
        }
        else
        {
            if (count_symbol(number, '-') > 0)
            {
                if (count_symbol(number, '-') == 1)
                {
                    if (number[0] != '-')
                    {
                        puts("Invalid input! '-'");
                        return ERROR_INPUT;
                    }
                }
                else
                {
                    puts("Invalid input! '-'");
                    return ERROR_INPUT;
                }
            }
            if (count_symbol(number, '+') > 0)
            {
                if (count_symbol(number, '+') == 1)
                {
                    if (number[0] != '+')
                    {
                        puts("Invalid input! '+'");
                        return ERROR_INPUT;
                    }
                }
                else
                {
                    puts("Invalid input! '+'");
                    return ERROR_INPUT;
                }
            }
        }
    }

    for (size_t i = 0; number[i]; i++)
    {
        if ((number[i] < '0' || number[i] > '9') && number[i] != 'e' && number[i] != '.' && number[i] != '-' && number[i] != '+')
        {
            printf("Invalid characters!");
            return ERROR_INPUT;
        }
    }
    for (size_t i = 0; number[i]; i++)
    {
        if (number[i] == 'e' && (number[i - 1] < '0' || number[i - 1] > '9'))
        {
            puts("Invalid input! '-' and 'e'");
            return ERROR_INPUT;
        }
    }
    for (size_t i = 0; number[i]; i++)
    {
        if (number[i] == 'e' && i + 1 == strlen(number))
        {
            puts("Invalid input! 'e'");
            return ERROR_INPUT;
        }
    }
    for (size_t i = 0; number[i]; i++)
    {
        if (number[i] == '.' && i + 1 == strlen(number))
        {
            puts("Invalid input! '.'");
            return ERROR_INPUT;
        }
    }
    for (size_t i = 0; number[i]; i++)
    {
        if (number[i] == 'e')
        {
            i += (number[i + 1] == '-' || number[i + 1] == '+') ? 7 : 6;

            if (strlen(number) > i)
            {
                puts("Order is too large");
                return ERROR_INPUT;
            }
            break;
        }
    }

    return OK;
}

// Check the correctness of input for an integer number
int correctness_number_int(char number[LEN])
{
	lower(number);
	if (!strcmp(number, "exit"))
	{
		puts("Completion of the program.");
		return EXIT;
	}
	else if (count_symbol(number, '-') > 1)
	{
		puts("Too many signs \'-\'");
		return ERROR_INPUT;
	}
	else if (count_symbol(number, '+') > 1)
	{
		puts("Too many signs \'+\'");
		return ERROR_INPUT;
	}
	for (int i = 0; number[i]; i++)
	{
		if (count_symbol(number, '+') == 1 || count_symbol(number, '-') == 1)
		{
			if (((number[i] < '0' || number[i] > '9') && i != 0) || (number[i] == '-' && i != 0) || (number[i] == '+' && i != 0))
			{	
				printf("invalid characters!");
				return ERROR_INPUT;
			}
		}
		else
		{
			if (number[i] < '0' || number[i] > '9')
			{	
				printf("invalid characters!");
				return ERROR_INPUT;
			}
		}
	}
	return OK;
}



// Function to multiply two arrays of numbers
void multiplication(int arr1[LEN], int arr2[LEN], int len1, int len2, int arr_result[LEN])
{
    int resultLen = len1 + len2; // Length of the result array

    // Initialize the result array with zeros
    for (int i = 0; i < resultLen; i++) {
        arr_result[i] = 0;
    }

    // Perform multiplication and addition
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int product = arr1[i] * arr2[j];
            int sum = arr_result[i + j + 1] + product;

            arr_result[i + j + 1] = sum % 10; // Update the current digit
            arr_result[i + j] += sum / 10;     // Carry over to the next digit
        }
    }
}


int number_int(char number[MAX_LEN_INT])
{
	lower(number);
	if (!strcmp(number, "exit"))
	{
		puts("Completion of the program.");
		return EXIT;
	}
	else if (count_symbol(number, '-') > 1)
	{
		puts("Too many signs \'-\'");
		return ERROR_INPUT;
	}
	else if (count_symbol(number, '+') > 1)
	{
		puts("Too many signs \'+\'");
		return ERROR_INPUT;
	}
	for (int i = 0; number[i]; i++)
	{
		if (count_symbol(number, '+') == 1 || count_symbol(number, '-') == 1)
		{
			if (((number[i] < '0' || number[i] > '9') && i != 0) || (number[i] == '-' && i != 0) || (number[i] == '+' && i != 0))

			{	
				printf("invalid characters!");
				return ERROR_INPUT;
			}
		}
		else
		{
			if (number[i] < '0' || number[i] > '9')
			{	
				printf("invalid characters!");
				return ERROR_INPUT;
			}
		}
	}
	return OK;
}

// Convert a string representing an integer to a number structure
int int_to_number(char str_number[LEN], number_attributes *number)
{
	int len_num = 0;
	int real_len = 0;
	int i = 0;
	
	number->sign_number = sign_of_number(str_number[0]);
	
	for (; str_number[i]; i++)
	{
		if (str_number[i] >= '0' && str_number[i] <= '9')
		{
			number->mantissa[len_num] = char_to_int(str_number[i]);
			len_num++;
			real_len++;
		}
	}
	while (number->mantissa[len_num - 1] == 0)
	{
		len_num--;
		number->exp++;
	}
	return len_num;
}

// Convert a string representing a floating-point number to a number structure
int float_to_number(char str_number[LEN], number_attributes *number)
{
	int len_num = 0;
	int i = 0;
	int flnum = -1;
	int exp = 0;
	int res = 0;
	number->sign_number = sign_of_number(str_number[0]);
	for (; str_number[i]; i++)
	{
		if (str_number[i] >= '0' && str_number[i] <= '9')
		{
			number->mantissa[len_num] = char_to_int(str_number[i]);
			len_num++;
		}
		if (flnum != -1)
		{
			flnum++;
		}
		if (str_number[i] == '.')
		{
			res = 1;
			flnum++;
		}
	}
	while (number->mantissa[len_num - 1] == 0)
	{
		if (flnum >= 0)
			flnum--;
		else
			exp++;
		len_num--;
		
	}
	if (res == 0)
		number->power = 0;
	else
		number->power = flnum;
	number->exp = exp;
	return len_num;
}

// Convert a string representing a number in exponential notation to a number structure
int exp_to_number(char str_number[LEN], number_attributes *number)
{
	int len_num = 0;
	int power_exp ;
	char exp_num[MAX_LEN_POW] = { '0' };
	int k = 0;
	int i = 0;
	int flnum = -1;
	int res = 0;
	number->sign_number = sign_of_number(str_number[0]);

	for (; str_number[i]; i++)
	{
		if (str_number[i] >= '0' && str_number[i] <= '9')
		{
			number->mantissa[len_num] = char_to_int(str_number[i]);
			len_num++;
		}
		if (str_number[i] == 'e')
		{
			i++;
			while (str_number[i])
			{
				exp_num[k] = str_number[i];
				i++;
				k++;
			}
			break;
		}
		if (flnum != -1)
			flnum++;
		if (str_number[i] == '.')
		{
			res = 1;
			flnum++;
		}
	}
	power_exp = atoi(exp_num);
	while (number->mantissa[len_num - 1] == 0)
	{
		if (flnum >= 0)
			flnum--;
		else
			power_exp++;
		len_num--;
		
	}
	if (res == 0)
		number->power = 0;
	else
		number->power = flnum;
	number->exp = power_exp;
	return len_num;
}


// Print the result in scientific notation
void print_result(number_attributes number, int len)
{
	if (len <= 0 )
	{
		puts("0.0e0");
		return;
	}
	else 
	{	
		int count = 0;
		for (int t = 0; t < len; t++)
		{
			if (number.mantissa[t] == 0)
				count++;
		}
		if (count == len)
		{
			puts("0.0e0");
			return;
		}
	}
	int real_len = len;
	int i = 0;
	while (number.mantissa[i] == 0)
	{
			i++;
	}

	if (len >= MAX_LEN_INT + 1)
	{
		
		round_num(&number, number.mantissa[MAX_LEN_INT], MAX_LEN_INT);
		len = MAX_LEN_INT;
	}
	while (number.mantissa[len - 1] == 0)
	{
		len--;
	}
	int k = number.exp + real_len - i - number.power;
	if (abs(k) > MAX_LEN_POW)
	{
		printf("Аварийная ситуация!\
			\nРезультат имеет запредельный порядок числа");
		return;
	}

    // Print the result in scientific notation
	if (number.sign_number)
		printf("-");
	printf("0.");
	for (; i < len; i++)
	{
		printf("%d", number.mantissa[i]);
	}
	printf("E%d\n", k);
}
