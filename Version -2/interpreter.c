#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp = fopen("file1.mowa", "r");
	char c;
	char string[10000];
	struct vars
	{
		char var_name[100];
		char var_value[1000];
		char *pointer;
	};
	typedef struct vars var;
	var variables[100];
	char *point;
	int i = 0;
	int no_of_chars = 0;
	point = &c;
start:
	*point = fgetc(fp);
	if (*point != EOF)
	{
		if ((*point) == 'C')
		{
			*point = fgetc(fp);
			if ((*point) == 'H')
			{
				*point = fgetc(fp);
				if ((*point) == 'E')
				{
					*point = fgetc(fp);
					if ((*point) == 'P')
					{
						*point = fgetc(fp);
						if ((*point) == 'P')
						{
							*point = fgetc(fp);
							if ((*point) == 'U')
							{
								space_declare1:
								*point = fgetc(fp);
								if ((*point) == '"')
								{
									*point = fgetc(fp);
									while (*point != EOF && *point != '"')
									{

										string[i] = *point;
										if ((*point) == 'O')
										{
											*point = fgetc(fp);
										}
										*point = fgetc(fp);
										i++;
									}
									printf("%s\n", string);
									memset(string,0, i * sizeof(char));
									i = 0;
									*point = fgetc(fp);
									if (*point == '\n')
									{
										goto start;
									}
								}
								else if ((*point) == ' ')
								{
									
									goto space_declare1;
								}
							}
						}
					}
				}
			}
		}
		else if ((*point) == 'M')
		{
			*point = fgetc(fp);
			if ((*point) == 'O')
			{
				*point = fgetc(fp);
				if ((*point) == 'W')
				{
					*point = fgetc(fp);
					if ((*point) == 'A')
					{
					space_declare2:
						*point = fgetc(fp);
						if ((*point) == ' ')
						{
							goto space_declare2;
						}
						while (*point != EOF && *point != ' ' && *point != '\n')
						{
							
							string[i] = *point;
							*point = fgetc(fp);
							i++;
						}
						if(*point == '\n'){
						strcpy(variables[no_of_chars].var_name,string);
						printf("variable %d %s\n",no_of_chars, variables[no_of_chars].var_name);
						memset(string, 0, i * sizeof(char));
						no_of_chars++;
						i = 0;
						
						goto start;

						}
						space_declare3:
						*point = fgetc(fp);
						if(*point == ' ') goto space_declare3;
						strcpy(variables[no_of_chars].var_name,string);
						printf("variable %d %s\n",no_of_chars, variables[no_of_chars].var_name);
						memset(string, 0, i * sizeof(char));
						no_of_chars++;
						i = 0;
						*point = fgetc(fp);
						if (*point == '\n')
						{
							//printf("reached end");
							goto start;
						}
					}
				}
			}
		}
		else
			return 0;
	}
}