#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// check if string is a floating point number
int is_floating_point(char const *str)
{
	char *end;
	strtod(str, &end);

	// check if conversion couldn't occur
	if (end == str) {
		return 0;
	}
	// return if end is pointing to null terminator (signifies end of string)
	return *end == '\0';
}

// check if string is an integer
int is_integer(char const *str)
{
	char *end;
	strtol(str, &end, 10);

	// check if conversion couldn't occur
	if (end == str) {
		return 0;
	}
	// return if end of string or not
	return *end == '\0';
}

// check if string consists of lowercase english letters
int is_valid_string(char const *str) 
{
	for (int i = 0; str[i] != 0; i++) {
		if (!islower(str[i])) {
			return 0;
		}
	}
	return 1;
}

// returns squareroot of a double
char* const calc_sqrt(double num) 
{
	double squareRoot = sqrt(num);
	static char buffer[20]; // static so keeps its value after function done
	sprintf(buffer, "%.2f", squareRoot);
	return buffer;
}

// returns gcd of a long array
int gcd_many(int len, long arr[])
{
	long gcd = arr[0];
	long num1, num2;
	// checks all longs to find their gcd thru euclidean algorithm
	for (int i = 0; i < len; i++)
	{
		// num1 always the bigger num and num2 always curr gcd
		num1 = arr[i];
	 	num2 = gcd;
		long tempNum = num1;
	 	if (num1 < num2) {
			num1 = num2;
			num2 = tempNum;
			tempNum = num1;
		}
		// finds gcd
	 	while (num2 != 0) {
			num1 = num2;
			num2 = (tempNum%num2);
		}
		gcd = num1;
	}
	return num1;
}

// check if two strings are anagrams, returns the string true if yes, false if no
char* const is_anagram(char const *str1, char const *str2)
{
	int letterFreq1[26] = {0};
	int letterFreq2[26] = {0};

	for (int i = 0; i < 26; i++) {
		for (int j = 0; str1[j] != '\0'; j++) {
			if (str1[j] == ('a' + i)) {
				letterFreq1[i]++;	
			}	
		}
		for (int j = 0; str2[j] != '\0'; j++) {
			if (str2[j] == ('a' + i)) {
				letterFreq2[i]++;
			}
	        }
		if (letterFreq1[i] != letterFreq2[i]) {
			return "false";
		}
	}
	return "true";
}

int main(int argc, char *argv[])
{
	// check if program called w/ no argument
	if (argc == 1) {
		fprintf(stderr, "ERROR: No arguments provided! Use command as ./minicalc OPERATION ARGUMENT(S)\n");
		exit(1);
	}
	// unknown operation provided	
	if (strcmp(argv[1], "sqrt") != 0 && strcmp(argv[1], "gcd") != 0 && strcmp(argv[1], "anagram") != 0) {
		fprintf(stderr, "ERROR: Unknown operation provided! Use 'sqrt', 'gcd', or 'anagram'.\n");
		exit(1);
	}

	// find sqrt 
	if (strcmp(argv[1], "sqrt") == 0) {
		if (argc != 3) {
			fprintf(stderr, "ERROR: Operation 'sqrt' requires exactly 1 operand!\n");
			exit(2);
		}
		if (!is_floating_point(argv[2])) {
			fprintf(stderr, "ERROR: Operand is not a floating point number!\n");	
			exit(3);
		}

		 // convert to double
		 char *end;
		 double number = strtod(argv[2], &end);
		// check if negative, return error if so
		if (number < 0) {
			fprintf(stderr, "ERROR: Operand is a negative value!\n");	
			exit(3);
		}
		printf("%s\n", calc_sqrt(number));
	}

	// find greatest common divisor 
	if (strcmp(argv[1], "gcd") == 0) {
		if (argc < 3) {
			fprintf(stderr, "ERROR: Operation 'gcd' requires at least 1 operand!\n");
			exit(2);
		}
		// check if integers
		int len = argc-2;
		long arr[len];
		for (int i = 2; i < argc; i++) 
		{
			if (!(is_integer(argv[i]))) {
				fprintf(stderr, "ERROR: Operand is not an integer!\n");
				exit(3);
			}
			// fill array w/ longs
			arr[i-2] = strtol(argv[i], NULL, 10);	

			if (arr[i-2] < 0) {
				fprintf(stderr, "ERROR: One or more operands are negative!\n");
				exit(3);
			}
		}	
		printf("%d\n", gcd_many(len,arr));
	}

	// determine if anagram 
	if (strcmp(argv[1], "anagram") == 0) {
		if (argc != 4) {
			fprintf(stderr, "ERROR: Operation 'anagram' requires exactly 2 operands!\n");
			exit(2);
		}
		// check that strings consist of lowercase letters
		if (!(is_valid_string(argv[2])) || !(is_valid_string(argv[3]))) {
			fprintf(stderr, "ERROR: Operands must only consist of lowercase english letters!\n");	
			exit (3);
		}		
		char *anagram_result = is_anagram(argv[2], argv[3]);
		printf("%s\n", anagram_result);	
	}
	return 0;
}

