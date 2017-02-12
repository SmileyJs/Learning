#include <stack>
#include <iostream>

using namespace std;

int
main(int argc, char const *argv[])
{
	string str("123(11(234)11)3(4)5(456)567");
	stack<char> stk;
	string replace = "===";
	string output;

	bool seen = false;

	for (auto c : str) {
		stk.push(c);
		if (c == '(') seen = true;
		if (seen && c == ')') {

			while (stk.top() != '(') {
				stk.pop();
			}
			stk.pop();

			// replace
			for (auto ins : replace) {
				stk.push(ins);
			}
		}


	}

	while (!stk.empty()) {
		output.insert(output.begin(), stk.top());
		stk.pop();
	}

	cout << output << endl;

	return 0;
}