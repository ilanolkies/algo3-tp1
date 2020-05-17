int k = 0; // largo de secuencia optima encontrada

int bt(int h, int i, int c) {
  if(h < 0) return 0; // poda por factibilidad
  if(c + (n - i) < k) return 0; // poda por optimalidad

  if(i == n) return c; // caso base instancia válida

  if(c >= k) k = c; // actualizacion de secuencia optima

  return max(
    bt(h, i + 1, c),
    bt(min(h - w[i], r[i]), i + 1, c + 1)
  );
}

int bt_mod(int h, int i, int c) {
  if(i == n) { // caso base
    if(h >= 0) return c; // instancia valida
    return 0; // instancia invalida
  }

  if(poda_factibilidad && h < 0) return 0; // poda por factibilidad
  if(poda_optimalidad && c + (n - i) < k) return 0; // poda por optimalidad

  if(c > k && h >= 0) k = c; // actualizacion de secuencia optima

  return max(
    bt_mod(h, i + 1, c),
    bt_mod(min(h - w[i], r[i]), i + 1, c + 1)
  );
}

