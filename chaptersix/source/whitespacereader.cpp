# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <map>
# include <algorithm>

using namespace std;

// 6.6.3: Read a sequence of possibly whitespace-separated (name, value) pairs, where the name is a single
//        whitespaced-separated word and the value is an integer or a flaoting-point value. Compute and printe
//        the sum and mean for each name and the sum and mean for all names

// 6.6.12: Modify the above to compute the median
// COMPLETED
void computeMedian() {
  ifstream ifKeyValue ("../data/whitespacevalues");
  string sFoundKey;
  int iFoundValue;
  map<string, vector<int>> mStoredMap;

  if (ifKeyValue.is_open()) {
    while(ifKeyValue >> sFoundKey) {
      ifKeyValue >> iFoundValue;
      mStoredMap[sFoundKey].push_back(iFoundValue);
    }
  }


  for (pair<string, vector<int>> ele : mStoredMap) {
    sort(ele.second.begin(), ele.second.end());
    cout << ele.first << " : " << ele.second[ele.second.size()/2] << "\n";
  }
}

void computeSum() {
  ifstream ifKeyValue ("data/whitespacevalues");
  string sFoundKey;
  int iFoundValue;
  map<string, int> mStoredMap;
  if (ifKeyValue.is_open()) {
    while(ifKeyValue >> sFoundKey) {
      ifKeyValue >> iFoundValue;
      mStoredMap[sFoundKey] += iFoundValue;
    }
  }


  for (pair<string, int> ele : mStoredMap) {
    cout << ele.first << " : " << ele.second << "\n";
  }
}

int main() {
  char answer;
  do {
    cout << "Computer sum (s) or median(m)?\n";
    cin >> answer;
    if (answer == 's') {
      computeSum();
    }
    if (answer == 'm') {
      computeMedian();
    }
  } while (answer == 's' || answer == 'm');
  cout << "Collecting ball and going home...";
  return 1;
};
