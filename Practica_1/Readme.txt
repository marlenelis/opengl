
Proyecto creado en Kdevelop 4.6
cmake 2.8
======================================
Instalación librerías de  OPENGL
======================================

sudo apt-get install binutils-gold
sudo apt-get install freeglut3 freeglut3-dev
sudo apt-get install libjpeg62-dev libglew1.5-dev libgtk2.0-dev libgtkgl2.0-dev
sudo apt-get install libxmu-dev libxi-dev

===========================================
    Ejecución
===========================================

 Se pasan las rutas de los ficheros .ply sin la extención.
   
./practica1 ../F_PLY/ant ../F_PLY/big_dodge ../F_PLY/cubo ../F_PLY/ant

Uso de teclas
1 -> dibuja el objeto en MODO puntos ya que solo tiene una lista de vertices
2 -> dibuja el objeto en distintos MODOS este tiene lista de vertices y caras
3 -> dibuja el objeto en distintos MODOS se pasa el fichero .ply
4 -> dibuja un cubo
5 -> dibuja un tetraedro
DEFENSA
 6 -> dibuja las caras de un objetos que se encuentra en uno de los octantes
 7 -> dibuja las caras de un objetos que se encuentra en uno de los octantes
 
CADA OBJETO DE DIBUJA EN 4 MODOS
   P -> Puntos
   L -> Lineas
   S -> Solido
   A -> Ajedrez

Marlene E. Vásquez