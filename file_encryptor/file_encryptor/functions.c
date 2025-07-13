#include <stdio.h>

void encrypt_file(void* file, const unsigned char xor_key)
{
	char write_buffer = 0;
	char read_buffer = 0;

	while ((fread(&read_buffer, 1, 1, file)) == 1)
	{
		write_buffer = read_buffer ^ xor_key;

		fseek(file, -1, SEEK_CUR);
		fwrite(&write_buffer, sizeof(char), 1, file);
		fflush(file);
	}

}

int check_password(const char* string1, const char* password)
{
	int i = 0;
	while (password[i])
	{
		if (string1[i] != password[i]) return 0;
		i++;
	}
	return 1;
}