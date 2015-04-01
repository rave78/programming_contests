/*
 * Problem 483: Word Scramble
 */

#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

int main(){
	string line;
	stack <char> s;

	while (getline(cin, line)){

		for (int i=0; i < line.length(); i++){
			if (line[i] != ' '){
				s.push(line[i]);
			}
			else{
				while (!s.empty()){
					cout << s.top();
					s.pop();
				}
				cout << ' ';
			}
		}
		while (!s.empty()){
			cout << s.top();
			s.pop();

		}
		cout << endl;
	}
	return 0;
}
