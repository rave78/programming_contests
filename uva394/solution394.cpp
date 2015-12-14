/*
 * Problem 394: Mapmaker
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef struct {
	string name;
	int base;
	int size;
	int dimension;
	vector<int> low;
	vector<int> high;
} memory;

typedef struct {
	string name;
	vector<int> ref;
} node;


int main(){
	int N, R;
	int low, high;
	vector<node> reference;
	map<string, vector<int> > map_result;

	cin >> N >> R;

	map<string, memory> vector_memory;
	string name;
	int base, size, dimension;

	for (int i=0; i < N; i++){
		memory m;
		m.low.clear();
		m.high.clear();

		cin >> name >> base >> size >> dimension;

		m.base = base;
		m.size = size;
		m.dimension = dimension;
		for (int j=0; j < dimension; j++){
			cin >> low >> high;

			m.low.push_back(low);
			m.high.push_back(high);
		}

		vector_memory.insert(pair<string, memory>(name, m));

		vector <int> temp;
		temp.clear();
		for (int j=0; j <= dimension; j++){
			temp.push_back(0);
		}
		temp.at(dimension) = size;


		for (int j=dimension-1; j >= 1; j--){
			int constante = temp.at(j+1) * (m.high.at(j) - m.low.at(j) + 1);
			temp.at(j) = constante;
		}
		temp.at(0) = base;
		for (int j=1; j<=dimension;j++){
			temp.at(0) -= temp.at(j) * m.low.at(j-1);
		}
		map_result.insert(pair<string, vector <int> >(name, temp));

	}

	node n;
	for (int i=0; i < R; i++){
		n.ref.clear();
		cin >> name;
		n.name=name;
		vector<int> temp;
		int refInt;
		for (int j=0; j < vector_memory[name].dimension; j++){
			cin >> refInt;
			n.ref.push_back(refInt);
		}
		reference.push_back(n);

	}

	for (vector<node>::iterator it=reference.begin(); it!=reference.end(); ++it){
		cout << it->name << "[";
		int result=map_result[it->name].at(0);

		if (it->ref.size() == 1){
			cout << it->ref.at(0) << "] = ";
			cout <<  result + it->ref.at(0) * map_result[it->name].at(1) ;
			cout << endl;
		}
		else{
			for (int j=0; j < it->ref.size()-1; j++){
				cout << it->ref.at(j) << ", ";
				result += map_result[it->name][j+1] * it->ref.at(j);
			}
			cout << it->ref.at(it->ref.size()-1) << "]";
			cout << " = " << result + map_result[it->name][it->ref.size()] * it->ref.at(it->ref.size()-1);
			cout << endl;
		}
	}
	return 0;
}
