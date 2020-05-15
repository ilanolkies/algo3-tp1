int pd(int h,  int i) {
  if (h < 0) return INF_NEG; // instancia inválida
  if (i == n) return 0; // caso base instancia válida

  if (M[i][h] == UNDEF) {
    M[i][h] = max(
      pd(h, i + 1),
      1 + pd(min(h - w[i], r[i]), i + 1)
    );
  }

  return M[i][h];
}
