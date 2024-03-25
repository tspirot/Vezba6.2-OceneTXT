// Vezba6.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Unos ocena ucenika u ocene.txt
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char ime[21], prezime[21];
	int ocena, n = 5, i;
	FILE* f = fopen("ocene.txt", "w");
	if (f == NULL)
	{
		printf("Greska pri otvaranju datoteke\n");
		return 1;
	}
	printf("Unesi broj ucenika: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		puts("Unesi ime ucenika:");
		getchar();
		gets(ime);
		puts("Unesi prezime ucenika:");
		gets(prezime);
		puts("Unesi ocenu ucenika:");
		scanf("%d", &ocena);
		fprintf(f, "%s\n%s\n%d\n", 
			ime, prezime, ocena);
	}
	fclose(f);
	f = fopen("ocene.txt", "r");
	if (f == NULL)
	{
		printf("Greska pri otvaranju fajl\n");
		return 1;
	}
	for (i = 0; i < n; i++)
	{
		fgets(ime, 21, f);
		fgets(prezime, 21, f);
		fscanf(f, "%d\n", &ocena);
		printf("%s%s%d\n", 
			ime, prezime, ocena);
	}
}
