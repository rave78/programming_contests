/*
 Problem 573 The Snail
 * */


#include <iostream>
#include <string>


using namespace std;

int main(){
	double h,u,d,f;
	double sliding;
	double currentDistance, currentHeight, distance, bSliding, aSliding;

	while (cin >> h >> u >> d >> f){
		if (h == 0) break;

		sliding = (f / 100.0) * u;
		int day = 1;
		currentHeight = 0;
		bSliding = 0;
		currentDistance = u;

		while(true){
			if (currentDistance > 0)
				bSliding = currentHeight + currentDistance;
			else
				bSliding = currentHeight;

			if (bSliding > h){
				cout << "success on day " << day << endl;
				break;
			}

			bSliding -= d;


			if (bSliding < 0){
				cout << "failure on day " << day << endl;
				break;

			}
			day += 1;
			currentHeight = bSliding;
			currentDistance -= sliding;


		}
	}
}
