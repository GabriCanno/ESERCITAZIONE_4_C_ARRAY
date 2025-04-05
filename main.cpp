#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

int main()
{
	string inputFile = "data.txt";
	string outputFile = "result.txt";
	
	size_t n;
	double *ptr1 = nullptr;
	double *ptr2 = nullptr;
	unsigned int S = 0;
	double V = 0;
	
	if (!ImportVectors(inputFile, n, ptr1, ptr2, S))
		return 1;
	
	double R = Dotproduct(n, ptr1, ptr2, S, V);
	
	if(!ExportResult(outputFile, n, ptr1, ptr2, S, R, V))
		return 1;
	
	
    return 0;
}

