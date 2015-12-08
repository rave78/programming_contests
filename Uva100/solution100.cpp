#include <iostream>

using namespace std;
int foo(int n){
	int count = 0;
	while(n != 1){
		if (n % 2 == 1)
			n = 3 * n + 1;
		else
			n = n / 2;
		count += 1;
	}
	return count + 1;

}

int main(){
	int originallow, originalhigh;

	while(cin >> originallow >> originalhigh){

		if (originalhigh == 0 && originallow == 0)
			break;
		int high, low;
		low = originallow;
		high = originalhigh;
		if (originalhigh < originallow){
			int temp = originalhigh;
			high = originallow;
			low = temp;
		}

		int max = -1;
		int result;
		for (int i=low; i <= high; i++){
			result = foo(i);
			if (result > max)
				max = result;
		}
		cout << originallow << " " << originalhigh << " " << max << endl;


	}

}
