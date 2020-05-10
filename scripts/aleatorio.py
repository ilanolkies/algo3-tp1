import numpy as np

for i in range(100):
  # R de 500 a 1000
  R = np.random.randint(500) + 500

  # w y r entre 1 y 10, n = 100
  n = 10
  w = np.random.randint(10, size = n) + 1
  r = np.random.randint(100, size = n) + 1

  f = open("./instancias/aleatorio/{}.in".format(i), "x")

  f.write("{} {}\n".format(R, n))

  for i in range(n):
    f.write("{} {}\n".format(w[i], r[i]))

  f.close()
