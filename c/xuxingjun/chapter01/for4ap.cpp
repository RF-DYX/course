#include <iostream>
using namespace std;

int main()
{
	char flag = 'y';
	while ('y' == flag) {
		cout << "Enter one number n(n >= 0)" << endl;
		int sum = 0, n = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) //{
			sum += i;  //等价于sum = sum + i;
		//}
		cout << "the sum from 1 to " << n << " is : " << sum << endl;
		while (true) {
			cout << "continue(y/N)?" << endl;
			cin >> flag;
			if ('y' == flag) {
				break;
			} else if ('N' == flag) {
				return 0;
			} else {
				continue;
			}
		}
	}
	return 0;
}
