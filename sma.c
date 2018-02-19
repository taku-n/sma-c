#include <stdio.h>

#include "net.h"

void sma(const double CLOSE[], double sma[], const int N, const int PERIOD,
		const int TIMEFRAME);
double average(const double CLOSE[], const int PERIOD, const int I);

void sma(const double CLOSE[], double sma[], const int N, const int PERIOD,
		const int TIMEFRAME)
{
	p_connect();

	static _Thread_local int last_timeframe  = 0;
	static _Thread_local int last_calculated = 0;
	                     int i;

	char str[64] = {};
	snprintf(str, sizeof str, "%d: %p", PERIOD, &last_timeframe);
	p(str, sizeof str);

	if (last_timeframe != TIMEFRAME) {
		last_calculated = 0;

		last_timeframe = TIMEFRAME;
	}

	if (last_calculated > PERIOD - 1) {
		i = last_calculated;
	} else {
		i = PERIOD - 1;
	}

	for (; i < N; i++) {
		sma[i] = average(CLOSE, PERIOD, i);
		last_calculated = i;
	}

	p_disconnect();
}

double average(const double CLOSE[], const int PERIOD, const int I)
{
	double sum = 0.0;

	for (int j = I - (PERIOD - 1); j <= I; j++) {
		sum += CLOSE[j];
	}

	return sum / PERIOD;
}
