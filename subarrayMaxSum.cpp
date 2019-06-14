#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>




using namespace std;


void subarrayMaxSum(){
	int sizeArray = 1;
	
	while(sizeArray){
		cout << "Provide size of array as an int" << endl;
		cout << "Input 0 as value to exit" << endl;
		cin >> sizeArray;
		cout << "Your input: " << sizeArray << endl;
		
		if(sizeArray < 0){ //in a proper end user program, would include max int/min int checks 
			cout << "invalid input, please have non-negative values for inputs" << endl;
			continue;
		}
		if(sizeArray == 0){
			cout << "Input of 0 given, now exiting" << endl;
		}
		else{
			int* testArray = (int*) malloc(sizeArray);
			int* sumArray = (int*) malloc(sizeArray);
			string arrayInput;
			stringstream ss;
			bool sumFound = false; //Need a false for reseting purposes
			
			getline(cin, arrayInput); //this is used to clear out cin for array input
			
			cout << "please enter array data as space seperated integers" << endl;
			getline(cin, arrayInput);
			ss << arrayInput;
			cout<<endl;
			int temp = 0;
			int iterator = 0;
			int currentMax = 0;

			
			while(ss>>temp && iterator < sizeArray){
				testArray[iterator] = temp;
				iterator++;
			}
			
			sumArray[0] = testArray[0];
			currentMax = sumArray[0];
			
			for(int i = 1; i<sizeArray; i++){ 
				if(testArray[i] > testArray[i] + sumArray[i-1]){
					sumArray[i] = testArray[i];
				}
				else{
					sumArray[i] = testArray[i] + sumArray[i-1];
				}
				if(sumArray[i]>currentMax){
					currentMax=sumArray[i];
				}
				
				
			}
			
			cout << "Max Sum found to be: " << currentMax << endl;
			

			delete testArray;
			delete sumArray;
		}
		
	}
}

int main(){
	subarrayMaxSum();
	return 0;
}