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
