#include<stdio.h>
#include<string.h>
#include <stdbool.h>

typedef enum { FEMALE, MALE } boolean;

struct Dog {
	char* name;
	char* race;
	bool gender;
	int age;
	int weight;
};

//print info of dog
void printDog(struct Dog dog)
{
	printf("%s\t%s(", dog.name, dog.race);
	printf("%s)\t%d yrs\t%dkg\n\n", dog.gender ? "F" : "M", dog.age, dog.weight);
}

//print all dogs contained in pound
void printPound(struct Dog dogs[], int count)
{
	for (int i = 0; i < count; ++i)
		printDog(dogs[i]);
}

//sort dogs according to weights in ascending order
void sortWeight(struct Dog dogs[], int count)
{
	int i, j, k;
	struct Dog temp;

	for (j = 0; j < count; ++j)
	{
		for (k = j + 1; k < count; ++k)
		{
			if (dogs[j].weight > dogs[k].weight)
			{
				temp = dogs[j];
				dogs[j] = dogs[k];
				dogs[k] = temp;
			}
		}
	}

	
}

//sort dogs according to names in ascending order
void sortNames(struct Dog dogs[], int count)
{
	int j, k;
	struct Dog temp;
	
	for (j = 0; j < count; ++j)
	{
		for (k = j + 1; k < count; ++k)
		{
			if (strcmp(dogs[j].name, dogs[k].name) > 0) {
				temp = dogs[j];
				dogs[j] = dogs[k];
				dogs[k] = temp;
			}
		}
	}
}

int main()
{
	struct Dog dog1, dog2, dog3, dog4, dog5;

	/*dog 1 specification*/
	dog1.name = "Chichi";
	dog1.race = "chihuahua";
	dog1.gender = MALE;
	dog1.age = 4;
	dog1.weight = 2;

	/*dog 2 specification*/
	dog2.name = "Jerry";
    dog2.race = "german shepherd";
	dog2.gender = MALE;
	dog2.age = 2;
	dog2.weight = 35;

	/*dog 3 specification*/
	dog3.name = "Bella";
	dog3.race = "bulldog";
	dog3.gender = FEMALE;
	dog3.age = 1;
	dog3.weight = 15;

	/*dog 4 specification*/
	dog4.name = "Sky";
	dog4.race = "husky";
	dog4.gender = MALE;
	dog4.age = 10;
	dog4.weight = 30;

	/*dog 5 specification*/
	dog5.name = "Goldie";
	dog5.race = "golden retriever";
	dog5.gender = FEMALE;
	dog5.age = 7;
	dog5.weight = 50;

	//create array to regroup all dogs
	struct Dog pound[5] = { dog1,dog2,dog3,dog4,dog5 };

	//sort dogs by weight then print
	sortWeight(pound, 5);
	printf("Dogs sorted according to their weight:\n");
	printPound(pound, 5);

	printf("\n\n\n");

	//sort dogs by name then print
	sortNames(pound, 5);
	printf("Dogs sorted according to their name:\n");
	printPound(pound, 5);
	
	return 0;
}