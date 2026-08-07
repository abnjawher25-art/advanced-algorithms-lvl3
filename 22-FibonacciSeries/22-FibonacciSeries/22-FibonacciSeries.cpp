#include <iostream>
using namespace std;

//function to print fibonacci series
void PrintFibonacciSeries(short number) {

	//first two numbers of fibonacci series
	short FibonacciNum = 0;

	//first two numbers of fibonacci series
	short Firstcontainer = 0;

	//second number of fibonacci series
	short Secondcontainer = 1;
	
	//print first number of fibonacci series
	printf("1 ");

	//print second number of fibonacci series
	printf("1 ");

	//print remaining numbers of fibonacci series	
	for (short i = 2; i <= number; i++)
	{
		//calculate next number of fibonacci series
		FibonacciNum = Firstcontainer + Secondcontainer;

		//print next number of fibonacci series
		cout << FibonacciNum << " ";

		//update first and second numbers of fibonacci series
		Firstcontainer = Secondcontainer;

		//update second number of fibonacci series
		Secondcontainer = FibonacciNum;

	}



}

//main function
int main()
{
	//call function to print fibonacci series
   PrintFibonacciSeries(7);

   //return 0
   return 0;
}
