# Optimizando Jambo-tubos

El problema: dado un _Jabotubo_ con resistencia $R$, y una secuencia ordenada de $n$
productos $S$, cada uno con un peso asociado $w_i$ y una resistencia asociada $r_i$,
determinar la máxima cantidad de productos que pueden apilarse en un tubo sin que ninguno
esté aplastado. En la Figura 1 se ilustra un ejemplo con $R = 50$, $n = 5$,
$w = [10, 20, 30, 10, 15]$ y $r = [45, 8, 15, 2, 30]$. La solución óptima es 3, y consiste
en tomar los elementos $1$, $3$ y $4$. Notar que la solución alternativa tomando los
elementos $1$, $3$ y $5$ no es factible porque la suma de sus pesos es $55 > R$.

> Nota: los productos solamente pueden ser apilados en el orden en que son recibidos de la
> cinta transportadora. Para este problema, asumiremos que todos los valores mencionados
> son enteros no negativos.

<div style="text-align: center;">
  <img src="./assets/readme-1.png" />
  <i>Ejemplo de instancia del problema de Jambo-tubos.</i>
</div>
