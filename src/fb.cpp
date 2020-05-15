int fb(int h, int i, int c) {
  if(i == n){ // caso base
    if(h >= 0) return c; // instancia valida
    return 0; // instancia invalida
  }

  return max(
    fb(h, i + 1, c),
    fb(min(h - w[i], r[i]), i + 1, c + 1)
  );
}
