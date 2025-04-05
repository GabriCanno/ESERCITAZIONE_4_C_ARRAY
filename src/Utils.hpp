#pragma once
#include <iostream>

using namespace std;

bool ImportVectors (const string& inputFilePath,
					size_t& n,
					double*& w,
					double*& r,
					unsigned int &S);
					 
					
double Dotproduct(const size_t& n,
				const double* const& w,
				const double* const& r,
				const unsigned int &S,
				double &V);
				
				
bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const unsigned int &S,
				  const double &R,
				  const double &V);