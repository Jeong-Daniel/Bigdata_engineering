#include <iostream>
using namespace std;

int count_ifact=0;
int count_rfact=0;

long rfact(int n) {
	count_rfact+=4;
	return n == 0? 1: n * rfact(n-1);}

long ifact(int n) {
	long f = 1;
	count_ifact+=4;
	count_ifact+=2;
	for (int i = 1; i <= n; i++){
		f *= i;
	}
	return f;}

int main(){
	int n;
	cin >> n;
	cout << rfact(n) << endl;
	cout << "(" << count_rfact << ")" << endl;
	cout << ifact(n) << endl;
	cout << "(" << count_ifact << ")" << endl;}

