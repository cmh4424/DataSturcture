#pragma once

int sumAlgorithmA(int n)
{
	return n * (n + 1) / 2;
}

int sumAlgorithmB(int n)
{
	int sum = 0;
	for (int i = 0; i <= n; i++) { sum += i; }
	return sum;
}

int sumAlgorithmC(int n)
{
	int sum = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < i; j++) { sum++; }
	return sum;
}