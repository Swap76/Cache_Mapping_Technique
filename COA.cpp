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
double timeToReadFromCache,timeToReadFromMemory,timeToCompare;
int noOfLines,noOfSet,noOfLinesInSet,fetchMemory;

//Output Declearation 
double TTDM,TTAM,TTSM;
double timeForDM,timeForAM,timeForSM;
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
	cout<<"\n\nEnter Time Required to Compare data in Cache: ";
	cin>>timeToCompare;
	cout<<"\n\nEnter no. of Sets in Set Associative Mapping: ";
	cin>>noOfSet;
	noOfLinesInSet = noOfLines / noOfSet;

	Initialize();

	FillMainMemory();

	cout<<"\n\nEnter no. of Memory calls to be made: ";
	cin>>fetchMemory;
	cout<<"\n\nEnter Memory read Calls in Order by specifing Block number:\n";
	for(int i = 0; i < fetchMemory; i++)
	{	
		cin>>fetchOrder[i];
	}
	for(int i = 0; i < fetchMemory; i++)
	{
		int number = fetchOrder[i];
		cout<<"\n\n\n\nAfter "<<number<<"\n";
		DirectM(number);
		AssociativeM(number);
		SetM(number);
		PrintTable();
	}

	cout<<"\n\n\t\t\tComparison \n\tDirect     Associative     Set Associative\n";
	cout<<"Time    "<<TTDM<<"     "<<TTAM<<"    "<<TTSM<<"\n";
	cout<<"Hit     "<<hitDM<<"     "<<hitAM<<"    "<<hitSM<<"\n";
	cout<<"miss    "<<missDM<<"    "<<missAM<<"   "<<missSM<<"\n";
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
	for(i = 0; i < 100; i++)
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
	cout<<"\n\t\t\tTable\n";
	cout<<"Line no.      Direct      Associative          Set\n";
	for(int i = 0; i < noOfLines; i++)
	{
		cout<<"   "<<i<<"\t\t"<<directM[i]<<"\t\t"<<associativeM[i]<<"\t\t"<<setM[i]<<"\n";
	}
}

// Calculation for Direct Mapping 
void DirectM(int number){
    // Code
	if (directM[number%noOfLines] == mainM[number]) {
		cout<<"Time taken for the Operation in Direct Mapping = "<<timeToReadFromCache;
		TTDM = TTDM + timeToReadFromCache;
		hitDM++;
	}
	else
	{
		directM[number%noOfLines] = mainM[number];
		cout<<"Time taken for the Operation in Direct Mapping = "<<timeToReadFromMemory+timeToReadFromCache;
		TTDM = TTDM + timeToReadFromMemory + timeToReadFromCache;
		missDM++;
	}
}

// Calculation for Associative Mapping 
void AssociativeM(int number){
	// Code
	int i;
	for(i = 0; i < noOfLines; i++)
	{
		if ( associativeM[i] == mainM[number]) {
			cout<<"\nTime taken for the Operation in Associative Mapping = "<<(i+1)*timeToCompare + timeToReadFromCache;
			TTAM = TTAM + (i+1)*timeToCompare + timeToReadFromCache;
			hitAM++;
			break;
		}
	}
	
	if ( i == noOfLines ){
		int j;
		for( j = 0; j < noOfLines; j++)
		{
			if(associativeM[j] == 0 ){
				associativeM[j] = mainM[number];
				break;
			}
		}
		if (j == noOfLines){
			associativeM[0] = mainM[number];
		}
		cout<<"\nTime taken for the Operation in Associative Mapping = "<<(i+1)*timeToCompare + timeToReadFromCache+ timeToReadFromMemory;
		TTAM = TTAM + (i+j+1)*timeToCompare + timeToReadFromCache + timeToReadFromMemory;
		missAM++;
	}
}

// Calculation for Set Associative Mapping
void SetM(int number){
	// Code
	int set,i;
	set = number % noOfSet;
	for(i = set*noOfLinesInSet; i < (set + 1)*noOfLinesInSet; i++)
	{
		if( setM[i] == mainM[number]){
			cout<<"\nTime taken for the Operation in Set Associative Mapping = "<< ((i-(set*noOfLinesInSet))*timeToCompare) + timeToReadFromCache;
			TTSM = TTSM + ((i-(set*noOfLinesInSet))*timeToCompare) + timeToReadFromCache ;
			hitSM++;
			break;
		}
	}
	if (i == (set + 1)*noOfLinesInSet){
		int j;
		for( j = set*noOfLinesInSet; j < (set + 1)*noOfLinesInSet; j++)
		{
			if(setM[j] == 0 ){
				setM[j] = mainM[number];
				break;
			}
		}
		if (j == (set + 1)*noOfLinesInSet){
			setM[set*noOfLinesInSet] = mainM[number];
		}
		cout<<"\nTime taken for the Operation in Set Associative Mapping = "<<((i-(set*noOfLinesInSet))*timeToCompare) + timeToReadFromCache + timeToReadFromMemory;
		TTSM = TTSM + ((i + j -(set*noOfLinesInSet))*timeToCompare) + timeToReadFromCache + timeToReadFromMemory;
		missSM++;
	}
}