#include<bits/stdc++.h>
using namespace std;

//Functions 
void Initialize();
void FillMainMemory();
void PrintTable();
void DirectM(int Blockno);
void AssociativeM(int Blockno);
void SetM(int Blockno);

//Input Declearation 
int directM[50],associativeM[50],setM[50],mainM[100],fetchOrder[50];
int timeToReadFromCache,timeToReadFromMemory;
int noOfLines,noOfSet,fetchMemory;

//Output Declearation 
int timeForDM,timeForAM,timeForSM;
int hitDM,hitAM,hitSM;
int missDM,missAM,missSM;

// Main Function for taking Inputs 
int main (){

	// Take input for Creating Cache Memory
	cout<<"\n\n\n\n\n\n\n\n\t\t\tWelcome to Cache Memory Mapping Simulator\n";
	cout<<"\n\nEnter no. of lines in the Cache Memory: ";
	cin>>noOfLines;
	cout<<"\n\nEnter Time Required to Read data from Cache: ";
	cin>>timeToReadFromCache;
	cout<<"\n\nEnter Time Required to Read data from Main Memory: ";
	cin>>timeToReadFromMemory;
	cout<<"\n\nEnter no. of Sets in Set Associative Mapping: ";
	cin>>noOfSet;

	Initialize();

	FillMainMemory();

	cout<<"\n\nEnter no. of Memory calls to be made: ";
	cin>>fetchMemory;
	cout<<"\n\nEnter Memory read Calls in Order by specifing Block number:";
	for(int i = 0; i < fetchMemory; i++)
	{	
		cin>>fetchOrder[i];
	}
	for(int i = 0; i < fetchMemory; i++)
	{
		int number = fetchOrder[i];
		DirectM(number);
		// AssociativeM(number);
		// SetM(number);
	}
	
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
	int n,i;
	cout<<"\n\n\n\n\n\n\n\n\t\t\tMemory is Restricted from 0 to 99 Blocks Only\n";
	cout<<"\n\nPass input in the given format { Block No. Data(in Numbers only)}\n";
	cout<<"\n\nNo. of Blocks to be Added: ";
	cin>>n;
	for( i = 0; i < n; i++)
	{
		int val,data;
		cin>>val>>data;
		mainM[val] = data;
	}
	cout<<"\n\n\n\t\t\tMain Memory Visualization";
	cout<<"\n\nBlock No.    Data\n";
	for(i = 0; i < 99; i++)
	{
		if (mainM[i]!=0) {
			cout<<"   "<<i<<"         "<<mainM[i];
			cout<<"\n";
		}	
	}	
}

// Print Table of Memory visualization 
void PrintTable(){
    // Code
}

// Calculation for Direct Mapping 
void DirectM(int number){
    // Code
}

// Calculation for Associative Mapping 
void AssociativeM(int number){
	// Code
}

// Calculation for Set Associative Mapping
void SetM(int number){
	// Code
}