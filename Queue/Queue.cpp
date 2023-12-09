#include <iostream>
#include <string>
#include "TQueue.h"
using namespace std;
int main()
{
	TQueue<int> qu(5);
	qu.Push(1);
	qu.Push(2);
	qu.Push(3);
	cout << "Front " << qu.Front() << endl;
	cout << "Back " << qu.Back() << endl;
	int a=qu.Pop();
	cout << a << endl;
	TQueue<int> m(qu);
	m.printQueue();
}