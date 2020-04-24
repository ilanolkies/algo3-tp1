#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int invalidInput() {
  printf("Formato de parametros inválido. Mas ayuda en:\n\n    ./algo3-tp1 help\n\n");
  return 1;
}

int fuerzaBruta(uint n, uint R, vector<uint> w, vector<uint> r) {
  cout << "No implementado." << endl;
  return -1;
}

int backtracking(uint n, uint R, vector<uint> w, vector<uint> r) {
  cout << "No implementado." << endl;
  return -1;
}

int programacionDinamica(uint n, uint R, vector<uint> w, vector<uint> r) {
  cout << "No implementado." << endl;
  return -1;
}

int main (int argc, char *argv[]) {
  if (argc == 2) {
    if (strcmp(argv[1], "help") != 0) {
      return invalidInput();
    }

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
      << "     |           ./bin/algo3-tp1 RUTA_A_ENTRADA ALGORITMO                         |." << endl
      << "     |                                                                            |." << endl
      << "     |             - RUTA_A_ENTRADA es la ruta aun archivo de entrada válido      |." << endl
      << "     |             - ALGORITMO es un numero del 1 al 3                            |." << endl
      << "     |                 1: Fuerza bruta                                            |." << endl
      << "     |                 2: Backtracking                                            |." << endl
      << "     |                 3: Programación dinámica                                   |." << endl
      << "     |                                                                            |." << endl
      << "     |    ________________________________________________________________________|___" << endl
      << "     |   /                                                                           /." << endl
      << "      \\_/___________________________________________________________________________/." << endl;

    return 0;
  }

  if (argc != 3) {
    return invalidInput();
  }

  // parametros por linea de comando
  char *input = argv[1];
  uint mode = atoi(argv[2]);

    // lectura del input
  ifstream inputFile;
  inputFile.open(input);

  if (!inputFile.is_open()) {
    return invalidInput();
  }

  // T: cantidad de equipos
  // P: cantidad de partidos
  uint n, R;
  inputFile >> n >> R;

  vector<uint> w, r;

  for (uint i = 0; i < n; i++) {
    uint wi, ri;
    inputFile >> wi >> ri;

    w.push_back(wi);
    r.push_back(ri);
  }

  cout << "n: " << n << endl;
  cout << "R: " << R << endl;
  cout << "w: [";
  for (uint i = 0; i < n-1; i++) cout << w[i] << ", ";
  cout << w[n-1] << "]" << endl;
  cout << "r: [";
  for (uint i = 0; i < n-1; i++) cout << r[i] << ", ";
  cout << r[n-1] << "]" << endl;

  int result;

  switch(mode) {
    case 1:
      result = fuerzaBruta(n, R, w, r);
      break;
    case 2:
      result = backtracking(n, R, w, r);
      break;
    case 3:
      result = programacionDinamica(n, R, w, r);
      break;
    default:
      return invalidInput();
  }

  return 0;
}
