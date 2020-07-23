#include <iostream>
using namespace std;

template<typename T, int N>
void floyd(T adjacency_matrix[][N], T distance[][N], int path[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				distance[i][j] = 0;
				path[i][j] = -1;
			}
			else {
				distance[i][j] = adjacency_matrix[i][j];
				if (distance[i][j] < INT_MAX)
					path[i][j] = i;
				else
					path[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < N; i++) {			//the inserted value
		for (int j = 0; j < N; j++) {		//the start
			if (i == j) continue;
			for (int k = 0; k < N; k++) {	//the end
				if (distance[j][i] == INT_MAX || distance[i][k] == INT_MAX) continue;	//prevent the number from Exceeding INT_MAX
				if (distance[j][k] > distance[j][i] + distance[i][k]) {
					distance[j][k] = distance[j][i] + distance[i][k];
					path[j][k] = path[i][k];
				}
			}
		}
	}
}
int main() {
	int a[4][4] = {
		{0,5,INT_MAX,7},
		{INT_MAX,0,4,2},
		{3,3,0,2},
		{INT_MAX,INT_MAX,1,0}
	};
	int distance[4][4];
	int path[4][4];
	floyd(a, distance, path);
	cout << "The distances are:" << endl;
	for (const auto& i : distance) {
		for (const auto& j : i) {
			cout << j << '\t';
		}
		cout << endl;
	}
	cout << endl << "The paths are:" << endl;
	for (const auto& i : path) {
		for (const auto& j : i) {
			cout << j << '\t';
		}
		cout << endl;
	}
	return 0;
}
