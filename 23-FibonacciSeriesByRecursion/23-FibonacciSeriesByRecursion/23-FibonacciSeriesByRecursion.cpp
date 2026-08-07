#include <iostream>
using namespace std;

//function to print fibonacci series using recursion
void PrintFibonacciSeries(short number, short Firstcontainer, short Secondcontainer) {

	//base case
	short FibonacciNum = 0;

	//recursive case
	if (number>0) 
	{
		//calculate the next fibonacci number
		FibonacciNum = Firstcontainer + Secondcontainer;

		//update the containers for the next iteration
		Secondcontainer = Firstcontainer;

		//update the first container with the new fibonacci number
		Firstcontainer = FibonacciNum;

		//print the fibonacci number
		cout << FibonacciNum << " ";

		//recursive call to print the next fibonacci number
		PrintFibonacciSeries(number - 1, Firstcontainer, Secondcontainer);
	}
}

//main function
int main()
{
	//print the first two fibonacci numbers
	PrintFibonacciSeries(7,0,1);

	//return 0 to indicate successful execution
	return 0;
}
