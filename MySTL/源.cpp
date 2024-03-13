#include"stdafx.h"
#include"myvector.h"
#include"mydeque.h"
#include<deque>
#include<vector>

using namespace std;

int main()
{
	//myvector 测试代码
	/*
	

	int arr[4] = { -1,0,1,2 };
	myvector<int> va(arr,arr+4);
	va.insert(va.end(), arr, arr + 4);


	myvector<int> va(5, 0);
	va.insert(va.begin(), 5, -1);
	for (size_t i = 0; i < va.size(); ++i)
	{
		printf("%d ", va[i]);
	}

	
	return 0;
*/
//mydeque 测试代码
	
	mydeque<float> ddb(10);
	mydeque<int> dda(10, 90);

	mydeque<float>ddd(ddb);

	ddd = ddb;


	/*for (size_t i = 0; i < 10; ++i)
	{
		printf("%f ", ddd[i]);//此时还没有[]这个功能，只能用调试工具
	}
	printf("\n");

	for (size_t i = 0; i < 10; ++i)
	{
		printf("%d ", dda[i]);
	}*/
	printf("\n");
	return 0;
}