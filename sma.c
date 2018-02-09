void sma(const double CLOSE[], double sma[], const int N, const int PERIOD);
double average(const double CLOSE[], const int PERIOD, const int I);

void sma(const double CLOSE[], double sma[], const int N, const int PERIOD)
{
	static int last_calculated;
	       int i;

	if (last_calculated > PERIOD - 1) {
		i = last_calculated;
	} else {
		i = PERIOD - 1;
	}

	for (; i < N; i++) {
		sma[i] = average(CLOSE, PERIOD, i);
		last_calculated = i;
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
