#include <iostream>

#include "struct.h"

using std::cout;
using std::cin;
using std::endl;

#define STUDENTS 3

int
main(int argc, char *argv[])
{
	student clas[STUDENTS];

	for (int i = 0; i < STUDENTS; ++i) {
		cout << "Please input the id" << endl;
		cin >> clas[i].id;
		cin.get();	// Clear input stream.
		cout << "Please input the name" << endl;
		getline(cin, clas[i].name);
		cout << "Please input the house" << endl;
		getline(cin, clas[i].house);
		printf("\n");
	}

	for (int i = 0; i < STUDENTS; ++i) {
		if (0 == clas[i].house.compare("the golden"))
			cout << clas[i].name << " is in " << clas[i].house << endl;
	}

	FILE *fp = fopen("dataBase", "w");

	if (NULL != fp) {
		for (int i = 0; i < STUDENTS; ++i) {
			fprintf(fp, "%d\n", clas[i].id);
			fprintf(fp, "%s\n", clas[i].name.c_str());
			fprintf(fp, "%s\n", clas[i].house.c_str());
		}
		fclose(fp);
	}

	return 0;
}
