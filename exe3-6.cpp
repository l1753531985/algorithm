#include <iostream>
#include <queue>
#include <unistd.h>
#include <ctime>

using namespace std;


void Josephus(int playersCount, int handoverTimes)
{
	queue<int> circle;
	for (int i = 1; i <= playersCount; i++)
		circle.push(i);

	int times = handoverTimes;
	while (playersCount)
	{
		int curPlayer = circle.front();
		circle.pop();
		times--;
		//sleep(1);
		if (times) circle.push(curPlayer);
		else 
		{
			cout << curPlayer << " out!!!!!" << endl;
			playersCount--;
			times = handoverTimes;
		}
	}
}

int main()
{
	int N = 0, M = 0;
	cout << "How many people play this game?" << endl;
	cin >> N;
	cout << "How many times you want to handover?" << endl;
	cin >> M;
	cout << "The result is: " << endl;
	clock_t startTime, endTime;
	startTime = clock();
	Josephus(N, M+1);
	endTime = clock();
	cout << "The runtime of Josephus is: " << (double)(endTime-startTime) / CLOCKS_PER_SEC << "s" << endl;
	return 0;
}
