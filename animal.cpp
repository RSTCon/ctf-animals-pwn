
#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	char animal[4];
	animal[3] = '\0';
	string name, hexname;
	
	char printbuf[200];
	
	// Structura magica
	
	struct plm {
		char user_data[20];
		signed char offset = 0;
		char animals[100];
	} locals;
	
	// Fill data
	
	memcpy(locals.animals, "dog\0cat\0owl\0fox\0pig\0bat\0ass\0ape\0gnu\0elk\0", 40);
	
	if(argc != 3)
	{
		printf("You must provide a number and a name!\n");
		printf("Example: ./animal 3 RSTCon\n");
		return 0;
	}
	
	
	locals.offset = atoi(argv[1]);
	
	if(locals.offset < 0 || locals.offset > 9)
	{
		printf("The number must be between 0 and 9!\n");
		return 0;
	}
	
	hexname = argv[2];
	
	if(hexname.length() % 2 == 1)
	{
		printf("The name must be a valid hex one!\n");
		return 0;
	}
	
	// Convert from hex to chars
	
	name = "";
	
	for(size_t i = 0; i < hexname.length(); i += 2)
	{
			char x = 0;
			char y = 0;
			char z = 0;
			
			if(hexname[i] < 97) x = (hexname[i] - '0') * 16;
			else x = (hexname[i] - 'W') * 16;
			
			if(hexname[i+1] < 97) y = (hexname[i+1] - '0');
			else y = (hexname[i+1] - 'W');
			
			z = x + y;
			name = name + z;
	}
	
	memcpy(animal, &locals.animals[locals.offset * 3 + locals.offset], 3);
	printf("Your favourite animal is: %s\n", animal);
	
	memcpy(locals.user_data, name.c_str(), name.length() <= 20 ? name.length() : 21);
	
	printf("%s loves %s\n", name.c_str(), (char *)&locals.animals[locals.offset * 3 + locals.offset]);
	
	snprintf(printbuf, 200, "echo %s is the best animal!", (char *)&locals.animals[locals.offset * 3 + locals.offset]);
	
	system(printbuf);
	
	return 0;
}
