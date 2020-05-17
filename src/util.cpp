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
    << "     |           ./algo3-tp1 RUTA_A_ENTRADA ALGORITMO                             |." << endl
    << "     |                                                                            |." << endl
    << "     |             - RUTA_A_ENTRADA es la ruta aun archivo de entrada válido      |." << endl
    << "     |             - ALGORITMO es un numero del 1 al 3                            |." << endl
    << "     |                 1: Fuerza bruta                                            |." << endl
    << "     |                 2: Backtracking                                            |." << endl
    << "     |                 3: Programación dinámica                                   |." << endl
    << "     |    ________________________________________________________________________|___" << endl
    << "     |   /                                                                           /." << endl
    << "      \\_/___________________________________________________________________________/." << endl;

  return 0;
}

int invalidInput() {
  printf("Formato de parametros inválido. Mas ayuda en:\n\n    ./algo3-tp1 help\n\n");
  return 1;
}

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
