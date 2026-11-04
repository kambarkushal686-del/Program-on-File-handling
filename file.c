#include <stdio.h>
int main(void)
{
FILE *fp;
double value;
double sum = 0.0;
double min = 0.0;
double max = 0.0;
int count = 0;
fp = fopen("numbers.txt", "r");
if (fp == NULL)
{
printf("Error: Could not open numbers.txt\n");
return 1;
}
while (fscanf(fp, "%lf", &value) == 1)
{
if (count == 0)
{
min = value;
max = value;
}
else
{
if (value < min)
min = value;
if (value > max)
max = value;
}
sum += value;
count++;
}
fclose(fp);
if (count == 0)
{
printf("No numbers found in the file.\n");
return 0;
}
printf("Count = %d\n", count);
printf("Sum = %.2f\n", sum);
printf("Average = %.2f\n", sum / count);
printf("Minimum = %.2f\n", min);
printf("Maximum = %.2f\n", max);
return 0;
}