#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

const int NUMBER_OF_EXPERIMENTS = 1E5;
const double PERCENT = 100.0;

/* Returns a random integer between 1 and 6. */
int rollDice();

/* Calculates the probability of rolling two dice
   and getting a specific sum. First parameter is
   the number of experiments, second parameter is
   the sum value. */
float calcProbability(int, int);

int main(int argc, char* argv[])
{
    srand(time(0));

    int inputSum = 1;
    if (argc > 1)
    {
        // Convert command-line argument to integer
        inputSum = atoi(argv[1]);
    }
    else
    {
        printf("Please enter a positive, non-zero integer to calculate the probability of rolling this value as a sum of two fair dice rolls.\n");
        scanf_s("%d", &inputSum); 
    }
    if (inputSum <= 0)
    {
        printf("ERROR! Please ensure that the input is a positive, non-zero integer.\n");
        return 1;
    }

    float generatedProbability = calcProbability(NUMBER_OF_EXPERIMENTS, inputSum);
    printf("The probability of rolling two dice and getting a sum of %d is: %.2f%%\n", inputSum, generatedProbability);
}

/* Calculates the probability of rolling two dice
   and getting a specific sum. First parameter is
   the number of experiments, second parameter is
   the sum value. */
float calcProbability(int number, int sum)
{
    // Accumulate the number of times the two rolls' sum match the input sum
    int matchingSums = 0;
    for (int i = 0; i < number; i++)
    {
        if ((rollDice() + rollDice()) == sum)
        {
            matchingSums++;
        }
    }
    return (((float)matchingSums / number) * PERCENT);

}

/* Returns a random integer between 1 and 6. */
int rollDice()
{
    // set range for random generator
    int lowest = 1;
    int highest = 6;
    return (rand() % (highest - lowest + 1)) + lowest;
}
