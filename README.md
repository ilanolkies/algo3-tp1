# Optimizando Jambo-tubos

El problema: dado un _Jabotubo_ con resistencia ![formula](https://render.githubusercontent.com/render/math?math=R), y una secuencia ordenada de ![formula](https://render.githubusercontent.com/render/math?math=n)
productos ![formula](https://render.githubusercontent.com/render/math?math=S), cada uno con un peso asociado ![formula](https://render.githubusercontent.com/render/math?math=w_i) y una resistencia asociada ![formula](https://render.githubusercontent.com/render/math?math=r_i),
determinar la máxima cantidad de productos que pueden apilarse en un tubo sin que ninguno
esté aplastado.

En la figura se ilustra un ejemplo con ![formula](https://render.githubusercontent.com/render/math?math=R=50), ![formula](https://render.githubusercontent.com/render/math?math=n=5),
![formula](https://render.githubusercontent.com/render/math?math=w=[10,20,30,10,15]) y ![formula](https://render.githubusercontent.com/render/math?math=r=[45,8,15,2,30]). La solución óptima es ![formula](https://render.githubusercontent.com/render/math?math=3), y consiste
en tomar los elementos ![formula](https://render.githubusercontent.com/render/math?math=1), ![formula](https://render.githubusercontent.com/render/math?math=3) y ![formula](https://render.githubusercontent.com/render/math?math=4). Notar que la solución alternativa tomando los
elementos ![formula](https://render.githubusercontent.com/render/math?math=1), ![formula](https://render.githubusercontent.com/render/math?math=3) y ![formula](https://render.githubusercontent.com/render/math?math=5) no es factible porque la suma de sus pesos es ![formula](https://render.githubusercontent.com/render/math?math=55\textgreater%20R).

> Nota: los productos solamente pueden ser apilados en el orden en que son recibidos de la
> cinta transportadora. Para este problema, asumiremos que todos los valores mencionados
> son enteros no negativos.

<div style="text-align: center;">
  <img src="./assets/readme-1.png" />
  <p><i>Ejemplo de instancia del problema de Jambo-tubos.</i></p>
</div>

## Proyecto

Implementamos 3 algoritmos en C++ para resolver este problema:

- Fuerza bruta
- Backtracking
- Programación dinámica

El proyecto está organizado de la sigueinte forma:

- `/src` contiene el código fuente
- En `/bin` guardaremos los binarios
- `/input` contiene entradas válidas

## Algoritmos

Para compilar el código fuente:

```
g++ src/main.cpp -o bin/algo3-tp1
```

Para ejecutar:

```
./bin/algo3-tp1 RUTA_A_ENTRADA ALGORITMO
```

Se puede ejecutar ambos comandos en una sola sentencia:

```
g++ src/main.cpp -o bin/algo3-tp1 && ./bin/algo3-tp1 RUTA_A_ENTRADA ALGORITMO
```

Ejemplo:

```
g++ src/main.cpp -o bin/algo3-tp1 && ./bin/algo3-tp1 ./input/sample2 3 0
```

## Experimentacion

Para usar Python v3.6.5

1. Instalar `pyenv` (una sola vez)

  _Como instalar `pyenv`_: https://github.com/pyenv/pyenv#installation

  Mac:

  ```
  brew update
  brew install pyenv
  eval "$(pyenv init -)"
  ```

2. Instalar v3.6.5 (una sola vez)

  ```
  pyenv install 3.6.5
  ```

3. Activar v3.6.5 (cada nueva consola debe ejecutarlo una vez)

  ```
  pyenv install 3.6.5
  ```

4. Instalar dependencias

  ```
  pip install -r requirements.txt
  ```

## Ayuda

Mas ayuda en:

```
./bin/algo3-tp1 help
```


