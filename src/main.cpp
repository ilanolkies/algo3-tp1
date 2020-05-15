#include "main.h"

int main (int argc, char *argv[]) {
  /* ayuda por linea de comando */
  if (argc == 2) {
    if (strcmp(argv[1], "help") != 0) {
      return invalidInput();
    }

    return help();
  }

  if (argc > 3) {
    return invalidInput();
  }

  /* parametros por linea de comando */

  /* path a la entrada */
  char *input = argv[1];

  /* modo
    - 1 -> fuerza bruta
    - 2 -> backtracking
    - 3 -> dinamica
  */
  int mode = atoi(argv[2]);


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

  /* print entrada */
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

  switch(mode) {
    case 1:
      result = fb(R, 0, 0);
      break;
    case 2:
      result = bt(R, 0, 0);
      break;
    case 3:
      M = vector<vector<int> >(n, vector<int>(R+1, -1));
      result = PD(R, 0);
      break;
    default:
      return invalidInput();
  }

  cout << "Salida:" << endl;
  cout << result << endl;

  return 0;
}
