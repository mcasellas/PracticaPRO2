# Pràctica: Experiments en un laboratori

## Entrada:

Una seqüència d’instruccions seguint el format de l’enunciat de la pràctica i del joc de proves public.

## Sortida:

El seu resultat seguint el format de l’enunciat de la pràctica i del joc de proves public.

## Observació:

El Jutge prova el vostre lliurament mitjançant 4 jocs de proves:

- sample: el joc de proves públic.
- privat1: joc de proves privat que fa èmfasi en l’operació de reproducció.
- privat2: joc de proves privat que fa èmfasi en l’operació d’arbre genealògic per nivells.
- privat3: joc de proves privat que fa èmfasi en l’operació d’arbre genealògic completable.
- Són els mateixos jocs de proves que els de la pràctica provisional.

### Entrada:

```
5
3 6 7 6 7 6
5 3

3
a1
X
0 1 1 1 0
0 0 1 0 1
1 1 1 1 1 0  
0 0 0 1 1 1
1 1 1 0 1 1 0
0 1 1 0 1 0 0
0 1 1 1 0 0  
1 0 0 1 1 0
1 1 1 0 1 1 0
0 1 1 0 1 1 1
1 1 1 1 1 0  
0 1 0 1 0 0

a2
X
0 1 1 0 1
1 1 0 0 0
0 1 1 1 0 0  
1 0 0 1 1 0
1 1 1 0 1 1 0
0 1 1 0 1 1 1
1 1 1 1 1 0  
0 1 0 1 0 0
1 1 1 1 1 0 0
0 0 1 1 1 0 0
1 1 1 0 1 1  
0 0 1 1 0 1

b3
Y
1 0 1 0 0
1 0 0
1 1 1 1 1 0  
1 1 0 1 1 0
1 1 1 0 1 1 0
0 1 1 0 1 0 0
0 1 1 1 0 0  
1 0 0 1 1 0
1 0 1 0 0 1 0
0 0 0 0 1 1 1
1 1 1 0 1 1  
0 0 1 1 0 1

anadir_individuo
b4
Y
1 1 0 0 1
0 1 0
1 0 0 0 1 0  
1 1 1 1 1 1
0 0 0 0 0 0 0
1 0 1 0 1 1 1
0 1 1 1 0 0  
1 0 0 1 1 0
1 0 1 1 1 1 0
0 1 1 0 1 0 0
1 1 1 1 1 0  
0 0 0 1 1 1

anadir_individuo
a2
Y
1 1 0 0 1
0 1 0
1 0 0 0 1 0  
1 1 1 1 1 1
0 0 0 0 0 0 0
1 0 1 0 1 1 1
0 1 1 1 0 0  
1 0 0 1 1 0
1 0 1 1 1 1 0
0 1 1 0 1 0 0
1 1 1 1 1 0  
0 0 0 1 1 1

escribir_poblacion

reproduccion_sexual
a1 b3 c1
0 1 2
1 1 3
1 0 5
1 1 4
0 0 3
1 1 4

reproduccion_sexual
a2 b4 d2
1 1 1
0 0 3
1 0 4
0 0 4
1 1 3
0 1 2

reproduccion_sexual
a0 b4 d3
0 1 2
1 1 3
1 0 5
0 0 4
1 1 3
0 1 2

escribir_poblacion

reproduccion_sexual
c1 b3 w6
0 1 2
1 1 3
1 0 5
0 0 4
1 1 3
0 1 2

reproduccion_sexual
c1 d2 e1
0 1 2
1 1 3
1 0 5
0 0 4
1 1 3
0 1 2

escribir_poblacion

escribir_arbol_genealogico
d1

escribir_arbol_genealogico
c1

completar_arbol_genealogico
d1 $ $

completar_arbol_genealogico
c1 $ $

completar_arbol_genealogico
e1 $ c1 $ $

anadir_individuo
m1
X
1 1 0 0 1
0 1 0 0 1
1 0 0 0 1 0  
1 1 1 1 1 1
0 0 0 0 0 0 0
1 0 1 0 1 1 1
0 1 1 1 0 0  
1 0 0 1 1 0
1 0 1 1 1 1 0
0 1 1 0 1 0 0
1 1 1 1 1 0  
0 0 0 1 1 1

reproduccion_sexual
m1 c1 e1
0 1 2
1 1 3
1 0 5
0 0 4
1 1 3
0 1 2

reproduccion_sexual
m1 c1 h1
1 0 2
1 1 3
1 0 2
0 0 4
1 1 3
0 1 2

escribir_genotipo
h1

escribir_poblacion

completar_arbol_genealogico
e1 c1 $ $ $

escribir_genotipo
b4

escribir_genotipo
c1

escribir_genotipo
nemo

escribir_genotipo
d2

acabar

```

### SORTIDA:

```
anadir_individuo b4
anadir_individuo a2
  error
escribir_poblacion
  a1 XX ($,$)
  a2 XX ($,$)
  b3 XY ($,$)
  b4 XY ($,$)
reproduccion_sexual a1 b3 c1
reproduccion_sexual a2 b4 d2
reproduccion_sexual a0 b4 d3
  error
escribir_poblacion
  a1 XX ($,$)
  a2 XX ($,$)
  b3 XY ($,$)
  b4 XY ($,$)
  c1 XY (b3,a1)
  d2 XY (b4,a2)
reproduccion_sexual c1 b3 w6
  no es posible reproduccion
reproduccion_sexual c1 d2 e1
  no es posible reproduccion
escribir_poblacion
  a1 XX ($,$)
  a2 XX ($,$)
  b3 XY ($,$)
  b4 XY ($,$)
  c1 XY (b3,a1)
  d2 XY (b4,a2)
escribir_arbol_genealogico d1
  error
escribir_arbol_genealogico c1
  Nivel 0: c1
  Nivel 1: b3 a1
completar_arbol_genealogico d1
  no es arbol parcial
completar_arbol_genealogico c1
  c1 *b3* $ $ *a1* $ $
completar_arbol_genealogico e1
  no es arbol parcial
anadir_individuo m1
reproduccion_sexual m1 c1 e1
reproduccion_sexual m1 c1 h1
escribir_genotipo h1
  X: 0 1 0 0 1
  X: 0 1 0 1 0
  1.1: 1 1 1 1 1 1
  1.2: 1 1 0 1 1 1
  2.1: 1 0 1 0 1 1 0
  2.2: 0 1 1 0 1 1 1
  3.1: 0 1 1 1 1 0
  3.2: 1 0 0 1 0 0
  4.1: 0 1 1 0 1 1 0
  4.2: 1 0 1 0 1 0 0
  5.1: 1 1 1 1 0 0
  5.2: 0 0 1 1 1 0
escribir_poblacion
  a1 XX ($,$)
  a2 XX ($,$)
  b3 XY ($,$)
  b4 XY ($,$)
  c1 XY (b3,a1)
  d2 XY (b4,a2)
  e1 XY (c1,m1)
  h1 XX (c1,m1)
  m1 XX ($,$)
completar_arbol_genealogico e1
  e1 c1 *b3* $ $ *a1* $ $ *m1* $ $
escribir_genotipo b4
  X: 1 1 0 0 1
  Y: 0 1 0
  1.1: 1 0 0 0 1 0
  1.2: 1 1 1 1 1 1
  2.1: 0 0 0 0 0 0 0
  2.2: 1 0 1 0 1 1 1
  3.1: 0 1 1 1 0 0
  3.2: 1 0 0 1 1 0
  4.1: 1 0 1 1 1 1 0
  4.2: 0 1 1 0 1 0 0
  5.1: 1 1 1 1 1 0
  5.2: 0 0 0 1 1 1
escribir_genotipo c1
  X: 0 1 0 1 0
  Y: 1 0 1
  1.1: 0 0 0 1 1 0
  1.2: 1 1 0 1 1 1
  2.1: 0 1 1 0 1 1 0
  2.2: 1 1 1 0 1 0 0
  3.1: 1 0 0 1 1 0
  3.2: 1 0 0 1 1 0
  4.1: 1 1 1 0 0 1 0
  4.2: 1 0 1 0 1 1 0
  5.1: 0 1 0 1 0 1
  5.2: 0 0 1 1 0 0
escribir_genotipo nemo
  error
escribir_genotipo d2
  X: 1 1 0 0 0
  Y: 0 1 0
  1.1: 0 1 1 0 1 0
  1.2: 1 0 0 1 0 0
  2.1: 0 1 1 0 0 0 0
  2.2: 0 0 0 0 1 1 1
  3.1: 1 1 1 1 0 0
  3.2: 0 1 1 1 1 0
  4.1: 0 0 1 0 1 0 0
  4.2: 0 1 1 1 1 0 0
  5.1: 1 1 0 1 1 1
  5.2: 0 0 1 0 1 1
acabar
```
