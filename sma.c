#include <stdio.h>

void sma(const double CLOSE[], double sma[], const int START,
		const int END, const int PERIOD);
double average(const double CLOSE[], const int PERIOD, const int I);

void sma(const double CLOSE[], double sma[], const int START,
		const int END, const int PERIOD)
{
	for (int i = START; i <= END; i++) {
		sma[i] = average(CLOSE, PERIOD, i);
	}
}

double average(const double CLOSE[], const int PERIOD, const int I)
{
	double sum = 0.0;

	for (int j = I - (PERIOD - 1); j <= I; j++) {
		sum += CLOSE[j];
	}

	return sum / PERIOD;
}
