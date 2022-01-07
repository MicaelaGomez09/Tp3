# Tp3
Integrantes: 
Gomez Micaela
Garcia Gerardo
Salmone Aylen

1.1 Descripción
Definir una estructura “movie” con los datos de una pelicula: 

    Título 
    Género 
    Duración 
    Descripción 
    Puntaje 
    Link de imagen


Realizar un programa que permita agregar, borrar y modificar peliculas en un archivo binario
mediante un menú: 

    1. Agregar película 
    2. Borrar película 
    3. Modificar película 
    4. Generar página web 
    5. Salir 


La opción 3, listará las peliculas pero no por pantalla, sino generando un archivo html
(descargar template de ejemplo, archivo template.zip). 
Crear una función que reciba un array de estructuras movie y el nombre del archivo html de
salida, y se encargue de generarlo.


En el archivo de la template, index.html, se encontrará la porción de código html que se debe
repetir para cada película, dentro de este bloque, se debe cargar ciertas partes con los datos
de cada película, a continuación se muestra un bloque y en color rojo lo que se debe variar
según la pelicula.   

/*
<!-- Repetir esto para cada pelicula -->
<article class='col-md-4 article-intro'>
<a href='#'>
<img class='img-responsive img-rounded' src='http://ia.mediaimdb.
com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg'
alt=''>
</a>
<h3>
<a href='#'>Back to the future</a>
</h3>
<ul>
<li>Género:Aventura</li>
<li>Puntaje:86</li>
<li>Duración:116</li>
</ul>
<p>A young man is accidentally sent thirty years into the past in a time-traveling
DeLorean invented by his friend, Dr. Emmett Brown, and must make sure his high-school-age parents
unite in order to save his own existence.</p>
</article>
<!-- Repetir esto para cada pelicula →
*/

 Ayuda: Se puede dividir el archivo index.html en dos, con el texto que debe ir antes de los
bloques “article” y el texto que debe irdespués, de modo de leer estos archivos y copiar el
contenido en el archivo html que se debe generar. Intercalando los bloques “article” con los
datos de cada película de la lista.
