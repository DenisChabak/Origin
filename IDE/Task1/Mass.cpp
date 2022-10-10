#include <iostream>
#include <string>
#include <fstream> 
using namespace std;


int main()
{
	ifstream fin;
	ofstream fout;
	int N = 0, M = 0;

	fin.open("in.txt");
	if (fin.is_open())
	{
		fin >> N;
		int* a;
		a = (int*)calloc(sizeof(int), N);
		for (int i = N - 1; i < 2 * N - 1; i++)
			fin >> a[i % N];


		fin >> M;
		int* b;
		b = (int*)calloc(sizeof(int), M);
		for (int i = 1; i < M + 1; i++)
			fin >> b[i % M];


		fin.close();

		fout.open("out.txt");
		if (fout.is_open())
		{
			fout << M << "\n";
			for (int i = 0; i < M; i++)
				fout << b[i] << " ";

			fout << "\n" << N << "\n";
			for (int i = 0; i < N; i++)
				fout << a[i] << " ";

			fout.close();

		}
		free(a);
		free(b);
	}
	return 0;
}
