#include <iostream>
#include <array>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int binsearch(vector<int> , int);
vector<int> hashaddsearch(vector<int> , int);

class Car
{
	public:
		Car(int x)
		{
			setCarSpeed(x);
			loc = 0;
		}
	    void setCarSpeed(int x)
		{
			speed = x;
		}

		int getCarSpeed()
		{
			return speed;
		}

		int getLoc()
		{
			return loc;
		}

		void moveCar()
		{
			loc += speed;
		}

	private:
		int speed;
		int loc;
};


int main ()
{
	// Array. Try not to use!
	int a[5] = {0};
	int b[] = {10, 11};


	// Vector
  // When trying to search if a single value is in an array or not
  // think about using a map instead.
	vector<int> v = {0, 2, 4};
	v[1] = 10;
	v.push_back(12);
	// 0 10 4 12
	v.erase(v.begin()+2);
	// 0 10 12
	v.insert(v.begin()+1,3);
	// 0 3 10 12
	v.insert(v.begin()+1, 3, 2);
	// 0 2 2 2 3 10 12
	v.erase(v.begin()+1, v.end()-2);
	// 0 10 12
	v.pop_back();
	// 0 10

	vector<int> vv(4);
	vv = {0, 1, 2, 3, 4};
	vv = {0, 1, 2};
	// 0 1 2
	for (int i = 0; i < vv.size(); i++) {
		cout << vv[i] << endl;
	}
	cout << endl;


	// Maps - hashes - dicts
	unordered_map<string, string> dict;
	dict["hello"] = "qhy";
	cout << dict["hello"] << endl;
	// qhy
	cout << dict.count("hello") << endl;
	// 1
	dict.erase("hello");
	cout << dict.count("hello") << endl;
	// 0
	string s1 = "no";
	string s2 = "yes";
	dict[s1] = s2;
	cout << dict[s1];
	// yes
	dict[s1] = "no";
	cout << dict[s1];
	// no
	dict["where"] = "what";
	dict["how"] = "why";
	// Print all keys and values.
	cout << endl;
	for(auto n : dict) {
		cout << "Keys:  " << n.first << endl;
		cout << "Value: " << n.second << endl;
	}
	cout << "\n\n";


	// Stacks
	stack<int> sck;
	sck.push(1);
	sck.push(2);
	sck.push(3);
	cout << sck.top() << sck.top() << endl;
	// 33
	sck.pop();
	cout << sck.top() << endl;
	// 2
	cout << sck.size() << endl;
	// 2
	cout << sck.empty() << endl;
	// 0
	sck.pop();
	sck.pop();
	cout << sck.empty() << endl;
	// 1


	// Queue
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.front() << q.front() << q.back() << endl;
	// 113
	q.pop();
	cout << q.front() << endl;
	// 2
	cout << q.size() << " " << q.empty() << endl;
	// 2 0


	// Strings
	string str1;
	str1 = "hello";
	cout << str1 << endl;
	// hello
	str1 = "no sir";
	cout << str1 << endl;
	// no sir
	str1.append(" no thank you.");
	cout << str1 << endl;
	// no sir no thank you.
	str1 = "12345";
	cout << str1.length() << endl;
	// 5
  str1 = "helol";
  cout << endl << endl;
  cout << str1[2] << endl << endl;
  // l
  if(str1[2] == str1[4]) {
    cout << "MATCH!";
  }
  // MATCH!
  str3 = to_string(100);

	stack<vector<int> *> coms;
	vector<int> wer;
	vector<int> *ans;
	coms.push(&wer);
	wer = {0,1,2,3};
	ans = coms.top();
	cout << (*ans).size() <<" "<< (*ans)[0] << (*ans)[3] << endl;
	// 4 03


	// Class use
	Car nissan(10);
	cout << nissan.getLoc() << endl;

	nissan.moveCar();
	cout << nissan.getLoc() << endl;

	nissan.setCarSpeed(20);
	nissan.moveCar();
	cout << nissan.getLoc() << endl;
}


int binsearch(vector<int> b, int want)
{
	int left, right, mid;
	left = 0;
	right = b.size()-1;
	while (left <= right) {
		mid = (left+right)/2;
		if ( (b[mid]) == want ) { // If anything else is put inside brackets
								// then that is the array you are searching
								// so ensure that it remains sorted.
			return mid;
		} else if ( (b[mid]) < want) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return -1;
}

// Good for any problem where the primary problem is looking for
// items that have a unique matching item.
vector<int> hashaddsearch(vector<int> input, int total)
{
	vector<int> ans(2);
	unordered_map<int, int> map;

	for (int i = 0; i < input.size(); i++) {
		if(map.count( input[i] == 1)) {
			ans[0] = map[input[i]];
			ans[1] = i;
			return ans;
		} else {
			// Store value that matches (unique pairing to index) the criteria as key
			// and index (or answer that you want to return) as value.
			// That way you can see if a pair exists in the dict by
			// searching if there is any match.
			map[ total - input[i] ] = i;
		}
	}
	ans[0] = ans[1] = -1;
	return ans;
}
