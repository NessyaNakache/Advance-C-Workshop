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

//void sortByNames(struct Dog* dogs, int count)
//{
//	char temp[20];
//
//	for (int i = 0; i < count; i++) {
//		for (int j = i + 1; j < count; j++) {
//			if (strcmp(dogs[i].name, dogs[j].name) > 0) {
//				strcpy(temp, dogs[i].name);
//				strcpy(dogs[i].name, temp);
//				strcpy(dogs[j].name, temp);
//			}
//		}
//	}
//
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%s\n", dogs[i].name);
//	}
//
//}

void sortWeight(struct Dog dogs[], int count)
{
	int temp, i, j, k;

	for (j = 0; j < count; ++j)
	{
		for (k = j + 1; k < count; ++k)
		{
			if (dogs[j].weight > dogs[k].weight)
			{
				temp = dogs[j].weight;
				dogs[j].weight = dogs[k].weight;
				dogs[k].weight = temp;
			}
		}
	}

	printf("Dogs sorted according to weight:\n");
	for (i = 0; i < count; ++i)
		printf("%d\n", dogs[i].weight);
}


void sortNames(struct Dog dogs[], int count)
{
	int i, j, k;
	char* temp = ' ';
	
	for (j = 0; j < count; ++j)
	{
		for (k = j + 1; k < count; ++k)
		{
			if (strcmp(dogs[j].name, dogs[k].name) > 0) {
				temp = dogs[j].name;
				dogs[j].name = dogs[k].name;
				dogs[k].name = temp;
			}
		}
	}

	printf("Dogs sorted according to names:\n");
	for (i = 0; i < count; ++i)
		printf("%s\n", dogs[i].name);
}

int main()
{
	struct Dog dog1, dog2, dog3, dog4, dog5;

	/*dog 1 specification*/
	dog1.name = "Chichi";
	dog1.race = "chihuahua";
	dog1.gender = MALE;
	dog1.age = 4;
	dog1.weight = 2.3;

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

	struct Dog arrDogs[5] = { dog1,dog2,dog3,dog4,dog5 };

	sortWeight(arrDogs, 5);
	sortNames(arrDogs, 5);

	return 0;
}