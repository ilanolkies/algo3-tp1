#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> w;
vector<int> r;
int n;

bool poda_factibilidad = true;
bool poda_optimalidad = true;

const int UNDEF = -1;
const int INF_NEG = -999999999;

vector<vector<int> > M; // matriz de memoria para programacion dinamica

#include "util.cpp"

#include "fb.cpp"
#include "bt.cpp"
#include "pd.cpp"
