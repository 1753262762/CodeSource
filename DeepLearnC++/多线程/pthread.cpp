#include <bits/stdc++.h>
using namespace std;

void thread_1()
{
    cout << "Thread 1" << endl;
}
void thread_2(int x)
{
    cout << "Thread 2 with argument: " << x << endl;
    cout << "Thread 2" << endl;
}

int main()
{
    thread first(thread_1);
    thread second(thread_2, 10);
    cout << "Main thread" << endl;
    first.join();
    second.join();
    cout << "All threads finished" << endl;
    return 0;
}