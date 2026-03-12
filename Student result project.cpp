#include<iostream>
using namespace std;

string showGrade(float per)
{
	if(per>=85)
		return "A+";
	else if(per>=80)
		return "A";
	else if(per>=75)
		return "B+";
	else if(per>=70)
		return "B";
	else if(per>=65)
		return "C+";
	else if(per>=60)
		return "C";
	else
		return "D";
}

float showPercentage(int marks[], int size)
{
	float obtmarks=0;

	for(int i=0;i<size;i++)
	{
		obtmarks = obtmarks + marks[i];
	}

	float per = (obtmarks/(size*100.0))*100;
	return per;
}

float showAvg(int marks[], int size)
{
	float obtmarks=0;

	for(int i=0;i<size;i++)
	{
		obtmarks = obtmarks + marks[i];
	}

	float average = obtmarks/size;
	return average;
}

bool checkResult(int marks[],int size)
{
	for(int i=0;i<size;i++)
	{
		if(marks[i]<50)
		{
			return false;
		}
	}

	return true;
}

void showfail(int marks[],int size)
{
	for(int i=0;i<size;i++)
	{
		if(marks[i]<50)
		{
			cout<<"You are fail in subject "<<i+1<<".\n";
		}
	}
}

int main()
{
	int size;

	cout<<"Enter number of subjects: ";
	cin>>size;

	int marks[size];

	cout<<"Enter the marks between 0 to 100:\n";

	for(int i=0;i<size;i++)
	{
		cout<<"Enter the marks of subject "<<i+1<<": ";
		cin>>marks[i];

		while((marks[i]<0) || (marks[i]>100))
		{
			cout<<"You Entered Invalid marks! Please enter marks between 0 and 100: ";
			cin>>marks[i];
		}
	}

	if(checkResult(marks,size)==false)
	{
		showfail(marks,size);
		cout<<"You are failed.\n";
	}
	else
	{
		cout<<"Congratulation, you are passed.\n";
		cout<<"Your marks of all subjects:\n";

		for(int i=0;i<size;i++)
		{
			cout<<"Subject "<<i+1<<": "<<marks[i]<<endl;
		}

		cout<<"Your percentage: "<<showPercentage(marks,size)<<"%\n";
		cout<<"Your Average: "<<showAvg(marks,size)<<endl;
		cout<<"Your Grade: "<<showGrade(showPercentage(marks,size))<<endl;
	}

	return 0;
}
