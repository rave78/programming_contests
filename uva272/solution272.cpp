/*
 * Problem 272:  Tex Quotes
 */

#include <iostream>
#include <string>

using namespace std;

int main ()
{
  string line;
  bool flag=false;

  while (getline(cin, line)){
	  for (int i=0; i < line.length(); i++){
		  if (line[i] == '\"' && !flag){
			  cout << "``";
			  flag = true;
		  }else if (line[i] == '\"' && flag){
			  cout << "''";
			  flag = false;
		  }else{
			  cout << line[i];
		  }
	  }
	  cout << endl;

  }

  return 0;
}
