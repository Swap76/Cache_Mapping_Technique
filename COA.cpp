#include<bits/stdc++.h>
using namespace std;

//Functions 
void Initialize();
void FillMainMemory();
void PrintTable();
void DirectM();
void AssociativeM();
void SetM();

//Input Declearation 
int directM[50],associativeM[50],setM[50],mainM[100];
int timeToReadFromCache,timeToReadFromMemory;
int noOfLines,noOfSet;

//Output Declearation 
int timeForDM,timeForAM,timeForSM;
int hitDM,hitAM,hitSM;
int missDM,missAM,missSM;

// Main Function for taking Inputs 
int main (){

	// Take input for Creating Cache Memory
	cout<<"\t\t\tWelcome to Cache Memory Mapping Simulator\n";
	cout<<"\nEnter no. of lines in the Cache Memory: ";
	cin>>noOfLines;
	cout<<"\nEnter no. of Sets in Set Associative Mapping: ";
	cin>>noOfSet;

	Initialize();

	FillMainMemory();

	return 0;
}

// Initializes Parameters to default value 
void Initialize(){

	int i;
	// Variable initialized to zero
	timeForDM = 0; timeForAM = 0; timeForSM = 0;
	hitDM =0; hitAM = 0; hitSM = 0;
	missDM = 0; missAM = 0; missSM = 0;

	// Array initialized to zero
	for( i = 0; i < 50; i++)
	{
		directM[i] = 0; associativeM[i] = 0; setM[i] = 0;
	}
	for( i = 0; i < 100; i++)
	{
		mainM[i] = 0;
	}

}

// Fills Values into main memory
void FillMainMemory(){
	cout<<"\t\t\tMemory is Restricted from 0 to 99 Blocks Only\n";
	cout<<"Pass input in the given format Block No. "
}

// Print Table of Memory visualization 
void PrintTable(){
    // Code
}

// Calculation for Direct Mapping 
void DirectM(){
    // Code
}

// Calculation for Associative Mapping 
void AssociativeM(){
	// Code
}

// Calculation for Set Associative Mapping
void SetM(){
	// Code
}