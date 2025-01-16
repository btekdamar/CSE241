#include <iostream>
#include <cmath>

using namespace std;

/*Prototypes of used functions*/
void copyArr(unsigned int arr1[], unsigned int arr2[], int size);
void print(int size);
void testFunction();

int main()
{
	int size;
	/*I call test function*/
	testFunction();
	
	cout << "Please enter size of fibonacci series (0-10000):";
	cin >> size;
	/*If size less than 0 or bigger than 10000, loop want new size value from user*/
	while(size<0 || size>10000){
		cout << "Please enter size of fibonacci series again (0-10000):";
		cin >> size;
	}

	size += 1;

	print(size);

	return 0;
}
/*This function copies values from array to another array*/
void copyArr(unsigned int arr1[], unsigned int arr2[], int size){
	for(int i=0; i<size; ++i)
		arr2[i] = arr1[i];
}
/*This function calculate number and write triangle to the screen*/
void print(int size){
	/*heartNo keep line number of heart. heart keep heart value*/
	unsigned int heart, biggest, heartNo, num = 0;
	unsigned int arr1[size];
	unsigned int arr2[size];

	arr1[0] = 1;
	cout << arr1[0] << endl;

	biggest = arr1[0];

	heartNo = ceil(size/2.0)+1;

	/*I keep 3 array. temparr keeps values before arr1 or arr2 changed. If line number is odd, values write to arr2 or if line number is even, values write to arr1.
	I calculate new value Fm-1,n-1 + Fm-2,n-2. I use different formula 0 and 1 column. I use Fm-1,n + Fm-2,n for 0. column and Fm-1,n-1 + 0 for 1. column. */
	for(int i=1; i<size; ++i){
		unsigned int temparr[i];
		if((i%2)!=0)
			copyArr(arr2, temparr, i);
		else
			copyArr(arr1, temparr, i);
		for(int j=0; j<=i; ++j){
			if((i%2)!=0){
				if(j==0){
					if(i!=1)
						num = temparr[j];
					arr2[j] = arr1[j] + num;
				}
				else if(j==1)
					arr2[j] = arr1[j-1] + num;
				else
					arr2[j] = arr1[j-1] + temparr[j-2];
				cout << arr2[j] << " ";
				if((i==(size-1)) && (j==i))
					biggest = arr2[j];
				if(heartNo == (unsigned)(i+1) && (unsigned)j==(heartNo/(unsigned)2))
					heart = arr2[j];
			}
			else{
				if(j==0)
					arr1[j] = arr2[j] + temparr[j];
				else if(j==1)
					arr1[j] = arr2[j-1] + num;
				else
					arr1[j] = arr2[j-1] + temparr[j-2];
				cout << arr1[j] << " ";
				if((i==(size-1)) && (j==i))
					biggest = arr1[j];
				if(heartNo == (unsigned)(i+1) && (unsigned)j==(heartNo/(unsigned)2))
					heart = arr1[j];
			}
			num = 0;
		}
		cout << endl;
	}
	cout << "Biggest number: " << biggest << endl;
	/*If user enter 0, pyramid does not have any heart value*/
	if(size==1)
		cout << "It does not have a heart" << endl;
	else if((heartNo%2)!=0)
		cout << "Heart of the pyramid:" << heart << endl;
	else
		cout << "Heart of the pyramid:" << heart << " " << heart << endl;
}
/*Test function. I use test array. I call print funtion for all array members.*/
void testFunction(){
	int size;
	int test[]={5,9,11,13,20};

	size = sizeof(test)/sizeof(int);

	cout << "------------------------------Test Begin------------------------------" << endl;

	for(int i=0; i<size; ++i)
	{
		cout << "Test for " << test[i] << endl;
		print(test[i]+1);
	}

	cout << "------------------------------End Test------------------------------" << endl;
}