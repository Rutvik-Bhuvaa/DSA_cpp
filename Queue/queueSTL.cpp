#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.back() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.size() << endl;

    return 0;
}