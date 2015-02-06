
#ifndef OBJETO_3D
#define OBJETO_3D
	#include <iostream>
	#include <GL/glut.h>
	#include <vector>
	#include "vertex.h"
	#include <math.h>	
	

#include "file_ply_stl.h"
	
	//MODO se usa para la visualizacion
	typedef enum{PUNTOS,ALAMBRE,SOLIDO,AJEDREZ} MODO;
	
	
	typedef enum{XP,XN,YP,YN,ZP,ZN} CUADRANTE;
	class Objeto_3D {
	    protected:					
		vector<_vertex3f> Vertices;
				
	    public:
	    ///Conctructor por defecto
		  Objeto_3D(){};
	    ///inicializar 
		  void inicializar(vector<float> vertices);
	    /// Copia
		  Objeto_3D(const Objeto_3D& original);		
	    ///operator=
		  Objeto_3D& operator=(const Objeto_3D& original);
		///==========================================================================
		///		actualiza el vector de vertices del objeto
		//---------------------------------------------------------------------------
		  void setVertices(vector<float> vertices);	    
	      //---------------------------------------------------------------------------
	      ///  Visualizar modo Puntos
	      //---------------------------------------------------------------------------
		  void visualizar_Modo_Puntos();	
	      //---------------------------------------------------------------------------
	      ///  Visualizar 
	      //---------------------------------------------------------------------------
		  void visualizar(MODO modo);	
		
	};
	class Objeto_3DS : public Objeto_3D{
	   protected :
	      vector<_vertex3i> Caras;
	  public:
	    
	    ///Constructor por defecto
		Objeto_3DS(){};
	    ///inicializa el objeto
		void inicializar3DS(vector<float> vertices, vector<int> caras);
	    /// actualiza el vector de caras
		void setCaras(vector<int>caras);
	    /// copia
		Objeto_3DS(const Objeto_3DS& original);
	    /// operator=
		Objeto_3DS& operator=(const Objeto_3DS& original);
	     
	     //---------------------------------------------------------------------------
		///  Visualizar modo Alambre
		//---------------------------------------------------------------------------
		void visualizar_Modo_Alambre();
		//---------------------------------------------------------------------------
		///  Visualizar modo Sólido
		//---------------------------------------------------------------------------
		void visualizar_Modo_Solido();
		//---------------------------------------------------------------------------
		///  Visualizar modo Ajedrez
		//---------------------------------------------------------------------------
		void visualizar_Modo_Ajedrez();			
		//---------------------------------------------------------------------------
		///  Visualizar 
		//---------------------------------------------------------------------------
		void visualizar(MODO modo);	
		
	      // recortar
	      void Octante(const Objeto_3DS& original);
	};
	//----------------------------------------------------------------
	///	
	class ObjetoPLY_3DS : public Objeto_3DS{
	    public:
	       ///Constructor por defecto
		ObjetoPLY_3DS(){};	
	       ///inicializa el objeto
		void inicializarPLY(const char *file);
	};
	class Tetraedro: public Objeto_3DS{
	    public:
		Tetraedro();
	};
	
	class Cubo: public Objeto_3DS{ 
	    public:
	      vector<float>lista;
	    Cubo();	    
	};
#endif


