/*
 * Program1.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Olufewa Alonge
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void HighLow(float mySales[12], char Month[11][10])
{
	char z;
	float q;
	printf("\nSales Report (Highest to Lowest)\n Month \t Sales \n\n");

	for (int i = 0; i < 12; i++)
	{
		for (int j = i; j < 12; j++)
		{
			if (mySales[i] < mySales[j])
			{
				for (int k = 0; k < 10; k++)
				{
					z = Month[i][k];
					Month[i][k] = Month[j][k];
					Month[j][k] = z;
				}

				q = mySales[i];
				mySales[i] = mySales[j];
				mySales[j] = q;
			}

		}

		printf("%s \t $ %5.2f \n", Month[i], mySales[i]);
	}
}

void sixMonthAvg(float mySales[12], char Month[11][10])
{
	float sixMonthTotal, average;
	printf("\nSix-Month Moving Average Report:\n\n");

	for (int i = 0; i < 7; i++)
	{
		sixMonthTotal = 0.0;
		for(int j = 0; j < 6; j++)
		{
			sixMonthTotal += mySales[i+j];
			average = sixMonthTotal / 6.0;
		}
		printf("%s\t - \t %s \t $ %5.2f \n", Month[i], Month[i+5], average);
	}
}

void maxandmin(float mySales[12], char Month[11][10])
{
	float min = mySales[0], max = mySales[0], total; //More variables

	for(int i = 0; i < 12; i++)
	{
		if (mySales[i] < min) //Sets the min
		{
			min = mySales[i];
		}

		if (mySales[i] > max) // Sets the max
		{
			max = mySales[i];
		}

		total += mySales[i];
	}
	float avg = total/12.0; // Finds the average

	printf("\nSales summary:\n");
	printf("Minimum sales: $ %5.2f\t", min);
	printf("(%s)\n", Month[0]);
	printf("Maximum sales: $ %5.2f\t", max);
	printf("(%s)\n", Month[11]);
	printf("Average sales: $ %5.2f\n", avg);
}

void sales(float mySales[12], char Month[11][10])
{
	printf("Monthly sales report for 2022: \n\n Month\t\t Sales\n\n");

	for (int i = 0; i < 12; i++)
	{
		printf("%s\t\t", Month[i]);
		printf("$%5.2f \n", mySales[i]);
	}
}

int main()
{
	FILE *input;
	FILE *months;

	input = fopen("input.txt", "r");
	months = fopen("months.txt", "r");

	char Month[11][10];
	float mySales[12];

	if (input == NULL)
	{
		printf("Error reading File\n");
		exit(0);
	}
	else if (months == NULL)
	{
		printf("Error reading File\n");
		exit(0);
	}

	for (int i = 0; i < 12; i++){
		fscanf(input, "%f", &mySales[i]);
		fscanf(months, "%s", Month[i]);
	}


sales(mySales, Month);
maxandmin(mySales, Month);
sixMonthAvg(mySales, Month);
HighLow(mySales, Month);


	fclose(input);
	fclose(months);
	return 0;
}

