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
