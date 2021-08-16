//Author:���z��(B083040043)
//Date:Sep.14,2020
//Purpose:Create a magic square function that can be applied to up to seven class.
#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;

void magicSquare(int classNumber);//this is the function;parameter:class number

int main()
{
	int classNumber=0;//class numbers of magic square
	for(int i=0;i<5;i++)
		magicSquare(i*2+1);
} 

void magicSquare(int classNumber)
{
	int martrix[9][9];//magic square
	int inputNumber=0;//input number
	int k=0;//current input
	int row=0;
	int col=0;
	int lastRow=0;//row of previous input
	int lastCol=0;//column of previous input 
	
	//initial martrix
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			martrix[i][j]=0;
	}
	
	//one class
	
	
	row=0;					//put 1 in the middle of top row								of top row*/
	col=(classNumber-1)/2;
	martrix[row][col]=1;
	
	k=2;//set 2 for loop 
	
	//constant put number into magic square until limit 
	while(inputNumber<(pow(classNumber,2)-1)) 
	{
		lastRow=row;
		lastCol=col;
		row--;
		col--;
		
		//if row or column isn't in the boundary of magic square, alter it to match boundary
		if(row<0)
			row=classNumber-1;
		if(col<0)
			col=classNumber-1;
		
		//if there is already a data in the blank,then this data should be put in the blank under this one
		if(martrix[row][col]!=0)
		{
			row=lastRow+1;
			if(row>(classNumber-1))
				row=0;
			col=lastCol;
		}
			
		martrix[row][col]=k;//input k
		k++;
		inputNumber++;
	}
	
	//output magic square
	cout << (classNumber+1)/2 << "." << endl; 
	for(int i=0;i<classNumber;i++)
	{
		for(int j=0;j<classNumber;j++)
			cout << setw(2) << martrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	
} 
