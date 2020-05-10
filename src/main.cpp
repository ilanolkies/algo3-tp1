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

/* Fuerza bruta */
int _fuerzaBruta(int R, vector<int> w, vector<int> r, int c) {
  if (w.size() == 0) { // caso base
    if (R >= 0) return c; // instancia valida
    return 0; // instancia invalida
  }

  int wi = w.back();
  int ri = r.back();

  w.pop_back();
  r.pop_back();

  return max(
    _fuerzaBruta(R, w, r, c),
    _fuerzaBruta(min(R - wi, ri), w, r, c + 1)
  );
}

int _fuerzaBruta2(int R, vector<int> w, vector<int> r, int c, int i) {
  if(i == w.size()){
    if(R >= 0) return c;
    return 0;
  }

  return max(
    _fuerzaBruta2(R, w, r, c, i + 1),
    _fuerzaBruta2(min(R - w[i], r[i]), w, r, c + 1, i + 1)
  );
}

int fuerzaBruta(int n, int R, vector<int> w, vector<int> r) {
  reverse(w.begin(), w.end());
  reverse(r.begin(), r.end());

  return _fuerzaBruta(R, w, r, 0);
}

int fuerzaBruta2(int n, int R, vector<int> w, vector<int> r) {
  return _fuerzaBruta2(R, w, r, 0, 0);
}

/* Backtracking */
int k = 0; // largo de secuencia mas optima encontrada

int _backTracking(int R, vector<int> w, vector<int> r, int c) {
  if(w.size() == 0){ // caso base
    if(R >= 0) return c; // instancia valida
    return 0; // instancia invalida
  }

  if(R < 0) return 0; // poda por factibilidad
  if(c + w.size() < k) return 0; // poda por optimalidad

  if(c >= k) k = c; // actualizacion de secuencia mas optima

  int wi = w.back();
  int ri = r.back();

  w.pop_back();
  r.pop_back();

  return max(
    _backTracking(R, w, r, c),
    _backTracking(min(R - wi, ri), w, r, c + 1)
  );
}

int _backTracking2(int R, vector<int> w, vector<int> r, int c, int i) {
  if(i == w.size()){
    if(R >= 0) return c;
    return 0;
  }

  if(R < 0) return 0; //  poda por factibilidad
  if(c + (w.size() - i) < k) return 0;  // poda por optimalidad

  if(c >= k) k = c; // actualizacion de secuencia mas optima

  return max(
    _backTracking2(R, w, r, c, i + 1),
    _backTracking2(min(R - w[i], r[i]), w, r, c + 1, i + 1)
  );
}

int backtracking(int n, int R, vector<int> w, vector<int> r) {
  reverse(w.begin(), w.end());
  reverse(r.begin(), r.end());
  k = 0;
  return _backTracking(R, w, r, 0);
}

int backtracking2(int n, int R, vector<int> w, vector<int> r) {
  return _backTracking2(R, w, r, 0, 0);
}

/* Programacion dinamica */
map<int,int> M;

int _programacionDinamica2(int R, vector<int> w, vector<int> r, int c, int i) {
  if(i == w.size()){
    if(R >= 0) return c;
    return 0;
  }

  if(R < 0) return 0; //  poda por factibilidad
  if(c + (w.size() - i) < k) return 0;  // poda por optimalidad

  int _R = min(R - w[i], r[i]); // cota de resistencia

  if(M[_R] > c) return c; // corte si un resultado ya es mejor para la nueva resistencia

  M[_R] = c;

  if(c >= k) k = c; // actualizacion de secuencia mas optima

  return max(
    _programacionDinamica2(R, w, r, c, i + 1),
    _programacionDinamica2(_R, w, r, c + 1, i + 1)
  );
}

int programacionDinamica(int n, int R, vector<int> w, vector<int> r) {
}

int programacionDinamica2(int n, int R, vector<int> w, vector<int> r) {
  return _programacionDinamica2(R, w, r, 0, 0);
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
  int n, R;
  vector<int> w, r;

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
      result = fuerzaBruta(n, R, w, r);
      break;
    case 3:
      result = fuerzaBruta2(n, R, w, r);
      break;
    case 4:
      result = backtracking(n, R, w, r);
      break;
    case 5:
      result = backtracking2(n, R, w, r);
      break;
    case 6:
      return invalidInput();
      result = programacionDinamica(n, R, w, r);
      break;
    case 7:
      result = programacionDinamica2(n, R, w, r);
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
