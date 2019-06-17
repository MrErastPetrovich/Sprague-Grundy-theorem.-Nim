/* this code is written by our group
It shows how Shprague-Grundy algorithm solves a basic game by representing this game as the NIM Game
Game rules: players are given a line of length N, on each i(from 1 to N) there is an object that
players can pick, but it is now allowed to pick an object that neighbours an object that has already
been picked. Given that two players are playing optimally, find out who is going to win
Example:
N = 6
OOOOOO
1 move: OXOOOO
2 move: OXOXOO (not allowed to get OXXOOOO or XXOOOO)
3 move: OXOXOX (game ends)
*/


#include <bits/stdc++.h>

using namespace std;

int F[1111111];


int calculateMex(unordered_set<int> Set)
{
	int Mex = 0;

	while (Set.find(Mex) != Set.end())
		Mex++;

	return (Mex);
}

int sgf(int n){
  if(n == 0){
    return 0;
  }
  F[1] = F[2] = F[3] = 1;
  if(F[n] != 0){
    return F[n];
  }

  unordered_set <int> Set; // A Hash Table

  Set.insert(sgf(n-3));
  Set.insert(sgf(n-2));

  for (int i = 1; i <= n - 4; i++){
      int l = i;
      int r = n - i - 3;
      Set.insert(sgf(l ^ r));
    }

  F[n] = (calculateMex(Set));
  return F[n];
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N; // length of the
  cin >> N;

  if(sgf(N) == 0){
    cout << "2 player wins";
  }
  else
    cout << "1 player wins";

  return 0;
}
