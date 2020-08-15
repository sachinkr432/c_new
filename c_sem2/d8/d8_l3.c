#include <stdio.h>
#include <stdlib.h>

typedef struct city_temp
{
	char name[15];
	float temp[7];
	float avg;
}city_data;

float average(city_data temp);

int main()
{
	city_data obj[5];
	
	for (int i = 0; i < 5; ++i)
	{
		printf("Enter %d city name\n",i+1);
		gets(obj[i].name);
		printf("Enter temp for 7 days: ");
		for(int j=0; j<7; j++)
			scanf("%f",&obj[i].temp[j]);
		obj[i].avg = average(obj[i]);
		getchar();
	}

	//SORTING IN ASCENDING ORDER
	city_data tm;
	for (int i = 0; i < 5; ++i)
	{
		for (int j=0; j < 4-i; ++j)
		{
			if (obj[j].avg >= obj[j+1].avg)
			{
				tm = obj[j];
				obj[j] = obj[j+1];
				obj[j+1] = tm;
			}
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		puts(obj[i].name);
		printf("\t%f\n", obj[i].avg);
	}

	return 0;
}

float average(city_data t)
{
	float avg_t=0;
	for (int i = 0; i < 7; ++i)
	{
		avg_t += t.temp[i];
	}
	return avg_t/7;
}
