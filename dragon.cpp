#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  map<int, vector<int>> dragGain;
  vector<int>           sortedDrags;
  cin.tie(NULL);
  int s, i;
  cin >> s >> i;
  for (int j = 0; j < i; j++)

  {
    int d, g;
    cin >> d >> g;
    dragGain[d].push_back(g);
    sortedDrags.push_back(d);
  }
  sort(sortedDrags.begin(), sortedDrags.end());
  for (int i = 0; i < sortedDrags.size(); i++) {
    int dragonStrength = sortedDrags[i];

    if (s > dragonStrength) {
      if (!dragGain[dragonStrength].empty()) {
        s += dragGain[dragonStrength].back();
        dragGain[dragonStrength].pop_back();
      }
    } else {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
  return 0;
}
