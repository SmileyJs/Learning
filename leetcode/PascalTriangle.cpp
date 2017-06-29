#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> v;
    
    if (numRows <= 0)
        return v;
    
    vector<int> line(1,1);
    line.reserve(numRows);
    
    v.push_back(line);
    
    for (int i = 1; i < numRows; ++i) {
        line.push_back(1);
        
        for (int j = i-1; j > 0; --j) {
            line[j] = line[j-1] + line[j];
        }
        
        v.push_back(line);
    }
    
    return v;
}

int
main(int argc, char const *argv[])
{
	int i;
	cin >> i;

	vector<vector<int>> v = generate(i);

	for (auto i = 0; i != v.size(); ++i) {
		for (auto j : v[i]) {
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}