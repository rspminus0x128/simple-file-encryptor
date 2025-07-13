#include <stdio.h>
#include <string.h>
#include "functions.h"

int main(int argc, char* argv[])
{
	const char* password = "passw1234";
	const unsigned char xor_key = '-';
	FILE* file = fopen(argv[1], "rb+");

	if (!check_password(argv[2], password)) return 0; 

	// encrypt or decrypt
	encrypt_file(file, xor_key);

	fclose(file);
	file = NULL;
	return 0;
}
