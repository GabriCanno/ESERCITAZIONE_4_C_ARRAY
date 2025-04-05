#include "Utils.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool ImportVectors(const string& inputFilePath,
                   size_t& n,
                   double*& w,
				   double*& r,
				   unsigned int &S)
					{
						ifstream file(inputFilePath);
					   
						if (file.fail())
							return false;
						
						char c;
						char tmp;
						unsigned int i = 0;
						string line;
						
						getline(file, line);
						stringstream str1(line);
						str1 >> c >> tmp >> S;  // memorizza il valore di S
						
						getline(file, line);
						stringstream str2(line);
						str2 >> c >> tmp >> n;  
					   
						w = new double [n];
						r = new double [n];
						
						getline(file,line);
						
						while(getline(file,line))
						{
							stringstream str3(line);
							str3 >> w[i] >> tmp >> r[i];
							i++;
						}
						
						return true;
						
				    }
					
					
double Dotproduct(const size_t& n,
				  const double* const& w,
				  const double* const& r,
				  const unsigned int &S,
				  double &V)					
				{
					double result = 0;
					for (unsigned int i = 0; i < n; i++)
						result += w[i] * r[i];
					V = (1 + result) * S;
					return result;
				}
				

bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const unsigned int &S,
				  const double &R,
				  const double &V)
				  
				{
					ofstream output(outputFilePath);
					if (output.fail())
						return false;
					
					output << "S = " << setprecision(2) << fixed << S << ", n = " << n << endl;
					
					
					output << "w = [ ";
					for (unsigned int i = 0; i < n; i++)
						output << w[i] << " ";
					output << "]" << endl;
					
					
					output << "r = [ ";
					for (unsigned int i = 0; i < n; i++)
						output << r[i] << " ";
					output << "]" << endl;
					
					output << "Rate of return of the portfolio: " << setprecision(4) << R << endl;
					
					output << "V: " << setprecision(2) << V << endl;
					
					return true;
					
				}