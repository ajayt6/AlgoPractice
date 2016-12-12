#include <iostream>
#include <string>
#include<vector>
using namespace std;



int CoinArr[3] = { 3,1,5 };//,7,2,8,6,9 };
int* Min = NULL;
vector<vector<int>> componentVector;// = new vector<int>();
vector<pair<int, int>> pairVector;

int CoinSum(int sum)
{
	int k = 0,flag=0,kflag=0;
	for (int i = 0; i <= sum; i++)
	{
		/*k = 0;
		flag = 0;
		vector<int> kVector;*/
		for (int j = 0; j< 3; j++)
		{
			
			//kflag = 0;
			if ((CoinArr[j] <= i) && (Min[i-CoinArr[j]] + 1 < Min[i]))
			{
				//kVector = componentVector[i - CoinArr[j]];
				Min[i] = Min[i - CoinArr[j]] + 1;
				pair<int, int> sumCoinPair = make_pair(i - CoinArr[j], CoinArr[j]);
				if (pairVector.size() < i + 1)
					pairVector.push_back(sumCoinPair);
				else
					pairVector[i] = sumCoinPair;
				//if (kflag == 0)
					//kVector.push_back(CoinArr[j]);
				//else
					//kVector[k] = CoinArr[j];
				//k++;
					//flag = 1;
			}
		}
		/*if(flag==1)
		componentVector.push_back(kVector);
		else
		{
			vector<int> zeroVector;
			componentVector.push_back(zeroVector);
		}*/
	}
	return Min[sum];
}

int main()
{

	int sum;

	cout << "Enter total sum: ";
	cin >> sum;
	
	
	Min = new int[sum];

	for (int i = 0; i <= sum; i++)
		Min[i] = INT32_MAX;
	Min[0] = 0;
	vector<int> zeroVector;
	componentVector.push_back(zeroVector);
	
	cout<<"The min required coins is: "<< CoinSum(sum);
	cout << "\n The output array is: " << endl;
	for (int i = 0; i <= sum; i++)
		cout << Min[i] << endl;

	/*cout << "\n The output of selected coins is: " << endl;
	zeroVector = componentVector[sum];
	for (auto i = zeroVector.begin(); i < zeroVector.end(); i++)
		cout << *i << endl;
		*/
	cout << "\n The selected coins are: ";
	for (int i = sum; i> 0 ; )
	{
		cout << pairVector[i].second << endl;
		i = pairVector[i].first;

	}

	getchar();
	getchar();
	delete[] Min;

	return 0;
}