///**************************************************************************
/// 			Marlene E. Vásquez
///**************************************************************************

#include "user_code.h"

using namespace std;

///========================================================================================
///			CLASE OBJETO_3D 
///========================================================================================

//-------------------------------------------------------------------------
///		inicializa el objeto- se pasa un vector de vertices <float>
//--------------------------------------------------------------------------
void Objeto_3D::inicializar(std::vector< float > vertices){

    this->setVertices(vertices);
}

//-------------------------------------------------------------------------
///		Copia
//--------------------------------------------------------------------------
Objeto_3D::Objeto_3D(const Objeto_3D& original){
	int v = original.Vertices.size();
	
	Vertices.resize(v);						
	for(int i =0; i<v; i++)  Vertices[i] = original.Vertices[i];
}
//---------------------------------------------------
/// 		operator=
//--------------------------------------------------
Objeto_3D& Objeto_3D::operator=(const Objeto_3D& original){	
	int v=original.Vertices.size();			
	Vertices.resize(v);
							
	for(int i =0;i<v;i++)	Vertices[i] = original.Vertices[i];
}
//------------------------------------------------------------------------
/// 		actualiza el Vector de vertices con el del parametro
//------------------------------------------------------------------------
void Objeto_3D::setVertices(vector<float> vertices){
     Vertices.resize(vertices.size()/3);     
      _vertex3f aux;
      int j = 0;
      
      for(int i=0; i< vertices.size(); i+=3){
	
	aux._0 = vertices[i];
	aux._1 = vertices[i+1];
	aux._2 = vertices[i+2];
	Vertices[j] = aux;
	j++;
  }
}
 //if(verto
 
 
//-------------------------------------------------------------------------
///		Funcion para visualizar en modo puntos
//--------------------------------------------------------------------------
void Objeto_3D::visualizar_Modo_Puntos(){
      glColor3f(0,0,1);
      glPointSize(2);
      
      glBegin(GL_POINTS);
	  for(int i=0; i< Vertices.size(); i++)			
	      glVertex3f(Vertices[i].x,Vertices[i].y,Vertices[i].z);		  
      glEnd();      
}

//-------------------------------------------------------------------------
///		Funcion para visualizar segun su modo
//--------------------------------------------------------------------------
void Objeto_3D::visualizar(MODO modo){
      
      switch(modo){	
	  case PUNTOS:  visualizar_Modo_Puntos(); 	break;
      }
}

///========================================================================================
///			CLASE OBJETO_3DS 
///========================================================================================

//--------------------------------------------------------------------------------------
///	inicializa el objeto- se pasa un vector de vertices <float> y caras <int>
//--------------------------------------------------------------------------------------
void Objeto_3DS::inicializar3DS(std::vector< float > vertices, std::vector< int > caras){
	       this->setVertices(vertices);
	       this->setCaras(caras);     
}
//------------------------------------------------------------------------
/// 		actualiza el Vector de caras con el del parametro
//------------------------------------------------------------------------
void Objeto_3DS::setCaras(std::vector< int > caras){
     Caras.resize(caras.size()/3);    
    _vertex3i aux;  
    int j=0;
    
    for(int i=0; i< caras.size(); i+=3){
      aux._0 = caras[i];
      aux._1 = caras[i+1];
      aux._2 = caras[i+2];
      Caras[j] = aux;
      j++;         
    } 
}
//--------------------------------------------------------------------------
///		Copia
//--------------------------------------------------------------------------
Objeto_3DS::Objeto_3DS(const Objeto_3DS& original){
  
        int v=original.Vertices.size();
	int c= original.Caras.size();
	Vertices.resize(v);
	Caras.resize(c);						
	for(int i =0;i<v;i++)	Vertices[i] = original.Vertices[i];
	for(int i=0; i<c;i++)	Caras[i] = original.Caras[i];
}
//--------------------------------------------------------------------------
///		operator=
//--------------------------------------------------------------------------
Objeto_3DS& Objeto_3DS::operator=(const Objeto_3DS& original){
  
	int v=original.Vertices.size();
	int c= original.Caras.size();
	
	Vertices.resize(v);
	Caras.resize(c);	
	
	for(int i =0;i<v;i++)	this->Vertices[i] = original.Vertices[i];
	for(int i=0; i<c;i++)	this->Caras[i] = original.Caras[i];
	
	return (*this);
}
//-------------------------------------------------------------------------
///		Funcion para visualizar en modo sólido
//--------------------------------------------------------------------------
void Objeto_3DS::visualizar_Modo_Solido(){     
	glColor3f(0.5,0,0);
	glLineWidth(1.0);
	
	glBegin(GL_TRIANGLES);
	    for(int i=0; i < Caras.size(); i++){	      
		glVertex3f(Vertices[Caras[i]._0].x, Vertices[Caras[i]._0].y, Vertices[Caras[i]._0].z);
		glVertex3f(Vertices[Caras[i]._1].x, Vertices[Caras[i]._1].y, Vertices[Caras[i]._1].z);
		glVertex3f(Vertices[Caras[i]._2].x, Vertices[Caras[i]._2].y, Vertices[Caras[i]._2].z);
	}
	glEnd();
}
//-------------------------------------------------------------------------
///		Función para visualizar en modo Ajedrez
//--------------------------------------------------------------------------
void Objeto_3DS::visualizar_Modo_Ajedrez(){   
	glLineWidth(1.0);
	
	glBegin(GL_TRIANGLES);
	    for(int i=0; i<Caras.size();i++){			
		if(i%2==0)glColor3f(0.5,0.5,0);//azul
		else glColor3f(0,0,0);//negro
		
		glVertex3f(Vertices[Caras[i]._0].x, Vertices[Caras[i]._0].y, Vertices[Caras[i]._0].z);
		glVertex3f(Vertices[Caras[i]._1].x, Vertices[Caras[i]._1].y, Vertices[Caras[i]._1].z);
		glVertex3f(Vertices[Caras[i]._2].x, Vertices[Caras[i]._2].y, Vertices[Caras[i]._2].z);
	    }
	glEnd();
}
//-------------------------------------------------------------------------
///		Funcion para visualizar en modo alambre
//--------------------------------------------------------------------------
void Objeto_3DS::visualizar_Modo_Alambre(){
  
 	glColor3f(0,0,0);//
 	glLineWidth(1.0);	
	//glEnable (GL_LINE_STIPPLE);
	//glLineStipple (1, 0xAAAA);
	glBegin(GL_LINES);
	    for(int i=0; i < Caras.size();i++){						
		glVertex3f(Vertices[Caras[i]._0].x, Vertices[Caras[i]._0].y, Vertices[Caras[i]._0].z);
		glVertex3f(Vertices[Caras[i]._1].x, Vertices[Caras[i]._1].y, Vertices[Caras[i]._1].z);
			
		glVertex3f(Vertices[Caras[i]._1].x, Vertices[Caras[i]._1].y, Vertices[Caras[i]._1].z);
		glVertex3f(Vertices[Caras[i]._2].x, Vertices[Caras[i]._2].y, Vertices[Caras[i]._2].z);
			
		glVertex3f(Vertices[Caras[i]._2].x, Vertices[Caras[i]._2].y, Vertices[Caras[i]._2].z);
		glVertex3f(Vertices[Caras[i]._0].x, Vertices[Caras[i]._0].y, Vertices[Caras[i]._0].z);			
	    }
	glEnd();
	//glDisable (GL_LINE_STIPPLE );
}
//-------------------------------------------------------------------------
///		Funcion para visualizar segun su modo
//--------------------------------------------------------------------------
void Objeto_3DS::visualizar(MODO modo){

      switch(modo){
	
	  case PUNTOS:  visualizar_Modo_Puntos(); 	break;
	  case SOLIDO:  visualizar_Modo_Solido(); 	break;
	  case ALAMBRE: visualizar_Modo_Alambre(); 	break;
	  case AJEDREZ: visualizar_Modo_Ajedrez();	break;
      }
   
}
// Defensa de la práctica, mostrar las caras que se encuentran en el octante
void Objeto_3DS::Octante(const Objeto_3DS& original)
{
  int v = original.Vertices.size();
  int c = original.Caras.size();
  Objeto_3DS aux(original);
 
  vector<_vertex3i> eliminarCaras;
  
  for(int i=0; i<c;i++){    
    
    if (original.Vertices[original.Caras[i]._0].x >=0 &&
        original.Vertices[original.Caras[i]._0].y >=0 && 
        original.Vertices[original.Caras[i]._0].z >=0 &&
       
	original.Vertices[original.Caras[i]._1].x >=0 &&
        original.Vertices[original.Caras[i]._1].y >=0 && 
        original.Vertices[original.Caras[i]._1].z >=0 &&
      
	original.Vertices[original.Caras[i]._2].x >=0 &&
        original.Vertices[original.Caras[i]._2].y >=0 && 
        original.Vertices[original.Caras[i]._2].z >=0 
    )
      
	eliminarCaras.push_back(original.Caras[i]);
     //    
  }
  aux.Caras = eliminarCaras;
 *this= aux;
}

///=========================================================================================
///				CLASE ObjetoPLY_3DS
///=========================================================================================
void ObjetoPLY_3DS:: inicializarPLY(const char *file)
{
	vector<int> caras;
	vector<float>vertices;
		   
	_file_ply::read(file,vertices,caras);//lectura del fichero ply- Vertices-Caras
		   
	this->setCaras(caras);
	this->setVertices(vertices);
}	
///=========================================================================================
///				CLASE CUBO
///=========================================================================================
Cubo::Cubo(){
  
     Vertices.resize(8);
     Vertices[0] = _vertex3f(-0.5,-0.5, 0.5);
     Vertices[1] = _vertex3f( 0.5, -0.5, 0.5);
     Vertices[2] = _vertex3f( 0.5, 0.5 , 0.5);
     Vertices[3] = _vertex3f(-0.5, 0.5 , 0.5);
     Vertices[4] = _vertex3f(-0.5,-0.5 ,-0.5);
     Vertices[5] = _vertex3f( 0.5,-0.5 ,-0.5);
     Vertices[6] = _vertex3f( 0.5, 0.5 ,-0.5);
     Vertices[7] = _vertex3f(-0.5, 0.5 ,-0.5);          
     
     //Caras	
	Caras.resize(12);	
	Caras[0]._0 = 1 ; Caras[0]._1 = 0; Caras[0]._2 = 2; 
	Caras[1]._0 = 0 ; Caras[1]._1 = 3; Caras[1]._2 = 2; 
	Caras[2]._0 = 0 ; Caras[2]._1 = 4; Caras[2]._2 = 3; 
	Caras[3]._0 = 4 ; Caras[3]._1 = 7; Caras[3]._2 = 3; 
	Caras[4]._0 = 4 ; Caras[4]._1 = 5; Caras[4]._2 = 7; 
	Caras[5]._0 = 5 ; Caras[5]._1 = 6; Caras[5]._2 = 7; 
	Caras[6]._0 = 5 ; Caras[6]._1 = 1; Caras[6]._2 = 6; 
	Caras[7]._0 = 1 ; Caras[7]._1 = 2; Caras[7]._2 = 6; 
	Caras[8]._0 = 2 ; Caras[8]._1 = 3; Caras[8]._2 = 6; 
	Caras[9]._0 = 3 ; Caras[9]._1 = 7; Caras[9]._2 = 6; 
	Caras[10]._0 = 0 ; Caras[10]._1 = 1; Caras[10]._2 = 4; 
	Caras[11]._0 = 1 ; Caras[11]._1 = 5; Caras[11]._2 = 4;	
}
///============================================================================================
///				CLASE TETRAEDRO
///============================================================================================

Tetraedro::Tetraedro(){
  
     Vertices.resize(8);
     Vertices[0] = _vertex3f(0,-0.5,0);
     Vertices[1] = _vertex3f( -0.5, 0,0);
     Vertices[2] = _vertex3f( 0.5, 0 ,0);
     Vertices[3] = _vertex3f(0,0 , 0.5);          
     
     //Caras	
	Caras.resize(12);	
	Caras[0]._0 = 0 ; Caras[0]._1 = 1; Caras[0]._2 = 2; 
	Caras[1]._0 = 0 ; Caras[1]._1 = 2; Caras[1]._2 =3; 
	Caras[2]._0 = 0 ; Caras[2]._1 = 3; Caras[2]._2 =1; 
	Caras[3]._0 = 1 ; Caras[3]._1 =2; Caras[3]._2 = 3; 
	
}


