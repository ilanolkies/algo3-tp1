#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int help() {
  cout
    << "   ______________________________________________________________________________" << endl
    << "  /  \\                                                                           \\." << endl
    << " |   |                                                                            |." << endl
    << "  \\_ |                                                                            |." << endl
    << "     |       ____        _   _           _                    _                   |." << endl
    << "     |      / __ \\      | | (_)         (_)                  | |                  |." << endl
    << "     |     | |  | |_ __ | |_ _ _ __ ___  _ ______ _ _ __   __| | ___              |." << endl
    << "     |     | |  | | '_ \\| __| | '_ ` _ \\| |_  / _` | '_ \\ / _` |/ _ \\             |." << endl
    << "     |     | |__| | |_) | |_| | | | | | | |/ / (_| | | | | (_| | (_) |            |." << endl
    << "     |      \\____/| .__/ \\__|_|_| |_| |_|_/___\\__,_|_| |_|\\__,_|\\___/             |." << endl
    << "     |          | | |             | |               | |       | |                 |." << endl
    << "     |          | |_|_ _ _ __ ___ | |__   ___ ______| |_ _   _| |__   ___  ___    |." << endl
    << "     |      _   | |/ _` | '_ ` _ \\| '_ \\ / _ \\______| __| | | | '_ \\ / _ \\/ __|   |." << endl
    << "     |     | |__| | (_| | | | | | | |_) | (_) |     | |_| |_| | |_) | (_) \\__ \\   |." << endl
    << "     |      \\____/ \\__,_|_| |_| |_|_.__/ \\___/       \\__|\\__,_|_.__/ \\___/|___/   |." << endl
    << "     |                                                                            |." << endl
    << "     |                                                                            |." << endl
    << "     |      Para optimizar los Jambo-tubos con distintos algoritmos correr:       |." << endl
    << "     |                                                                            |." << endl
    << "     |           ./bin/algo3-tp1 RUTA_A_ENTRADA ALGORITMO MODO                    |." << endl
    << "     |                                                                            |." << endl
    << "     |             - RUTA_A_ENTRADA es la ruta aun archivo de entrada válido      |." << endl
    << "     |             - ALGORITMO es un numero del 1 al 3                            |." << endl
    << "     |                 1: Fuerza bruta                                            |." << endl
    << "     |                 2: Backtracking                                            |." << endl
    << "     |                 3: Programación dinámica                                   |." << endl
    << "     |             - MODO si usa i o retorna resultado                            |." << endl
    << "     |                    (variacion de implementaciones)                         |." << endl
    << "     |                    0 o vacio es sin i y reverse                            |." << endl
    << "     |                    1 es con i                                              |." << endl
    << "     |    ________________________________________________________________________|___" << endl
    << "     |   /                                                                           /." << endl
    << "      \\_/___________________________________________________________________________/." << endl;

  return 0;
}

int invalidInput() {
  printf("Formato de parametros inválido. Mas ayuda en:\n\n    ./algo3-tp1 help\n\n");
  return 1;
}

/*************/
/* algritmos */
/*************/
vector<int> w;
vector<int> r;
int n;
/* Fuerza bruta */
int FB(int h, int i, int c) {
  if(i == n){  // caso base
    if(h >= 0) return c; // instancia válida
    return 0;
  }

  return max(
    FB(h, i + 1, c),
    FB(min(h - w[i], r[i]), i + 1, c + 1)
  );
}

/* Backtracking */
int k = 0; // largo de secuencia mas optima encontrada

int BT(int h, int i, int c) {
  if(h < 0) return 0; //  poda por factibilidad

  if(c + (n - i) < k) return 0;  // poda por optimalidad

  if(i == n) return c; // caso base instancia válida

  if(c >= k) k = c; // actualizacion de secuencia mas optima

  return max(
    BT(h, i + 1, c),
    BT(min(h - w[i], r[i]), i + 1, c + 1)
  );
}

/* Programacion dinamica */
vector<vector<int> > M;

void printM() {
  for(int i = 0; i < M.size(); i++) {
    for(int j = 0; j < M[i].size(); j++) {
      cout << M[i][j] << "  ";
    }
    cout << endl;
  }
  cout << endl;
  cout << endl;
}

int PDit(int R) {
  M = vector<vector<int> >(w.size() + 1, vector<int>(R + 1, -1));
  M[0][0] = 0;
  for(int i = 1; i < w.size() + 1; i++) {
    for(int j = R; j >= 0; j--) {
      if (M[i-1][j] > -1) {
        // si pongo i-1-esimo

        // la resistencia seria
        int m = min(
          (R - j) - w[i - 1],
          r[i - 1]
        );

        if(
          m >= 0 && // si es positiva entra
          M[i][R - m] < M[i-1][j] + 1 // si la cantidad es mayor a otro camino con la misma resistenca
        )
          M[i][R - m] = M[i-1][j] + 1; // lo cargo

        // si no pongo i-1-esimo
        if(M[i-1][j] > M[i][j]) // si la resistencia es mayor a la de otro camino
          M[i][j] = M[i-1][j]; // lo cargo
      }
    }
  }

  return *max_element(M[w.size()].begin(), M[w.size()].end()); // retorno el mejor camino
}

const int UNDEFINED = -1;
const int MENOS_INFTY = -999999999;
int PD(int h,  int i) {
  if(h < 0) return MENOS_INFTY; // instancia inválida
  if(i == n) return 0; // caso base instancia válida

  if(M[i][h] == UNDEFINED){
    M[i][h] = max(
      PD(h, i + 1),
      1 + PD(min(h - w[i], r[i]), i + 1)
    );
  }
  return M[i][h];
}

int main (int argc, char *argv[]) {
  if (argc == 2) {
    if (strcmp(argv[1], "help") != 0) {
      return invalidInput();
    }

    return help();
  }

  if (argc > 4) {
    return invalidInput();
  }

  /* parametros por linea de comando */

  /* path a la entrada */
  char *input = argv[1];

  /* modo */
  int mode = atoi(argv[2]);
  /*
    - 1 -> fuerza bruta
    - 2 -> backtracking
    - 3 -> dinamica
  */

  /* segundo modo */
  int mode2 = argc == 4 ? atoi(argv[3]) : 0;
  /*
    - 0 o vacio -> recursion sin indexacion
    - 1 -> recursion con indexacion
  */

  if (mode2 > 1) {
    return invalidInput();
  }

  /* lectura del input */
  int R;

  ifstream inputFile;
  inputFile.open(input);

  if (!inputFile.is_open()) {
    return invalidInput();
  }

  inputFile >> n >> R;

  for (int i = 0; i < n; i++) {
    int wi, ri;
    inputFile >> wi >> ri;

    w.push_back(wi);
    r.push_back(ri);
  }

  cout << "Entrada:" << endl;
  cout << "n := " << n << endl;
  cout << "R := " << R << endl;
  cout << "w := [";
  for (int i = 0; i < n-1; i++) cout << w[i] << ", ";
  cout << w[n-1] << "]" << endl;
  cout << "r := [";
  for (int i = 0; i < n-1; i++) cout << r[i] << ", ";
  cout << r[n-1] << "]" << endl;

  /* ejecucion */
  int result;

  switch(mode * 2 + mode2) {
    case 2:
      result = FB(R, 0, 0);
      break;
    case 3:
      result = FB(R, 0, 0);
      break;
    case 4:
      result = BT(R, 0, 0);
      break;
    case 5:
      result = BT(R, 0, 0);
      break;
    case 6:
      M = vector<vector<int> >(n, vector<int>(R+1, -1));
      result = PD(R, 0);
      break;
    case 7:
      M = vector<vector<int> >(n+1, vector<int>(R + 1, -1));
      result = PDit(R);
      break;
    default:
      return invalidInput();
  }

  cout << "Salida:" << endl;
  cout << result << endl;

  return 0;
}


/*
Rtas de los inputs
sample  -> 3
sample2 -> 2
sample3 -> 3
sample4 -> 0
*/
