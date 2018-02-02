#include "stdafx.h"
#include <cmath>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

void radix(int *ar, int *br, int *cr, int sizeC, int sizeAB)
{
	int i, k, n;
	k = sizeC;
	n = sizeAB;
	for (i = 0; i <= k; i++)
		cr[i] = 0;
	for (i = 0; i < n; i++)
		cr[ar[i]] += 1;
	for (i = 1; i < k + 1; i++)
		cr[i] += cr[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		br[cr[ar[i]] - 1] = ar[i];
		cr[ar[i]] -= 1;
	}
}



void selection(int *ar, int size)
{


	int i, j, mx, nmx;

	for (i = 0; i < size - 1; i++)
	{
		mx = ar[i];
		nmx = i;
		for (j = i + 1; j < size; j++)
		{
			if (ar[j]<mx)
			{
				mx = ar[j];
				nmx = j;
			}
		}
		ar[nmx] = ar[i];
		ar[i] = mx;
	}

}

int main() {

	cout << "1-SORTIROVKA" << endl << "2-RADIX" << endl;

	int size = 30000;
	int p = 0;
	cin >> p;

	if (p == 1) {
		
		int *ar = new int[size];

		ifstream fin("saod.txt");
		for (int i = 0; i < size; i++)
		{

			fin >> ar[i];
		

		}




		clock_t start = clock();
		getchar();

		selection(ar, size);




		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		
			
			ofstream saod1("outSELECTION.txt");
			for (int i = 0; i < size; i++)
			{

				saod1 << ar[i] << endl;


			}
			saod1 << "Vremya: " << seconds;
		
	}

	if (p == 2) {

		int sizeC = 100000;
		int sizeAB = 30000;
		int *ar = new int[sizeAB];
		int *br = new int[sizeAB];
		int *cr = new int[sizeC];
		ifstream fin("saod.txt");
		for (int i = 0; i < sizeAB; i++)
		{

			fin >> ar[i];

		}

		clock_t start = clock();
		getchar();

		radix(ar, br, cr, sizeC, sizeAB);

		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;

		ofstream saod1("outRADIX.txt");
		for (int i = 0; i < size; i++)
		{

			saod1 << br[i] << endl;


		}
		saod1 << "Vremya: " << seconds;

	}

	system("pause");
	return 0;

}

