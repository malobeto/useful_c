#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned long long factorial(int num);
int combinations(int total, int choose);
float successes(float dice_rolled, float total_sides, float successes_needed, float sides_for_success);
int help();

int main(int argc, char *argv[])
{
	if (strncmp(argv[1], "h", 1) == 0){
		return help();
	}
	else if (argc == 5){
		float argf[] = {atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4])};
		float answer = successes(argf[0], argf[1], argf[2], argf[3]) * 100;
		printf("The probability of rolling at least %s successes on %sd%s where %s sides are successes is %f percent.\n", argv[3], argv[1], argv[2], argv[4], answer);
		return 0;
	}
	else{
		printf("I don't recognize this combination of arguments. Try again!\n");
		return 1;
	}
}

unsigned long long factorial(int num)
{
	int i;
	unsigned long long fact = 1;
	if (num < 0){
		printf("Cannot factorial a negative.\n");
		return 0;
	}
	else if (num > 20){
		printf("Number too large.\n");
		return 0;
	}
	else{
		for (i = 1; i <= num; ++i){
			fact *= i;
		}
		return fact;
	}
}

int combinations(int total, int choose)
{
	int diff = total - choose;
	unsigned long long top = factorial(total);
	unsigned long long bottom = (factorial(choose) * factorial(diff));
	return (top/bottom);
}

float successes(float dice_rolled, float total_sides, float successes_needed, float sides_for_success)
{
	float prob;
	int i;
	float dice_prob = sides_for_success/total_sides;
	for (i = successes_needed; i <= dice_rolled; ++i){
		int combos = combinations(dice_rolled, i);
		float first = pow(dice_prob, i);
		float second = pow((1 - dice_prob), (dice_rolled - i));
		float total = (combos * first * second);
		prob += total;
	}
	return prob;
}

int help()
{
	printf("Format is: diceprob [number of dice rolled] [total sides of each dice] [successes needed][number of dice sides that count as a success]\n\n");
	printf("For example diceprob 5 6 2 3 would mean 5 d6s were being rolled. 3 out of the six sides would count as success, and you wanted to know the probability that at least 2 dice would come up as successes.");
return 0;
}

