//Author:¿àÚz¿«(B083040043)
//Date:Sep.16,2020
//Purpose:Create a function that can be applied to up to 50 factorial
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> factorial;//a vector to store all digit in the question
	int n=1;//for user input to decide how many times loop 
	int temp=0;//temparory store carry to add on next digit
	int digit=0;//count total digits to output vector(result) 
	
	while(1)
	{
		cin >> n;
		if(n==0)//n=0,program end
			break;
		
		factorial.push_back(1);//input 1 as first digit
		digit=1; 
		
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<digit;j++)//every digits multiple i
				factorial[j]*=i;
			for(int j=0;j<digit;j++)
			{
				temp=0;
				while(factorial[j]>=10)//if digit is greater then 10,it should be continuously minus 10
				{
					factorial[j]-=10;
					temp++;
				}
				if(j==digit-1&&temp!=0)//when last digit in the vector is greater then 10,vector should expand one more digit
				{
					factorial.push_back(temp);
					digit++;
				}
				else 
					factorial[j+1]+=temp;//add on next digit
			}
			
			//output result
			cout << i << "!=";
			for(int j=digit-1;j>=0;j--)
				cout << factorial[j];
			cout << endl;
		}
		cout << endl;
		factorial.clear();//clear numbers in the vector for the next loop
	}
} 
