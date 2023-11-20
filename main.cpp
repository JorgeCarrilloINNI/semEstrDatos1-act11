#include <iostream>

using namespace std;

template<class T>
class ColaDinamica;

template<class T>
class Constancia{
private:
    T Nombre;
    T Carrera;
    T Materias;
    T Promedio;
    Constancia<T>* sig;
public:
    Constancia():sig(nullptr){};
    friend class ColaDinamica<T>;
    
    friend ostream& operator<<(ostream& o, Constancia<T>& s){
    	o<<endl;
    	o<<"****Constancia Emitida por la fepade****"<<endl;
        o<<"Nombre del Alumno: "<<s.Nombre<<endl;
        o<<"Carrera que cursa: "<<s.Carrera<<endl;
        o<<"Total de Materias aprobadas: "<<s.Materias<<endl;
        o<<"Promedio General: "<<s.Promedio<<endl;
        o<<"************Firma el Rector************"<<endl;
        return o;
    }

    friend istream& operator>>(istream& i, Constancia<T>& s){
        cout<<"Nombre del Alumno: ";
        i>>s.Nombre;
        cout<<"Carrera que cursa: ";
        i>>s.Carrera;
        cout<<"Total de Materias aprobadas: ";
        i>>s.Materias;
        cout<<"Promedio General: ";
        i>>s.Promedio;
        return i;
    }
    
    bool operator==(Constancia<T>& o) const {
        return Nombre == o.Nombre && Carrera == o.Carrera && Materias == o.Materias && Promedio == o.Promedio;
    }
    
    Constancia<T>& operator=(Constancia<T>& o) {
        Nombre = o.Nombre;
        Carrera = o.Carrera;
        Materias = o.Materias;
        Promedio = o.Promedio;
    }
};

template<class T>
class ColaDinamica{
private:
    Constancia<T>* lista;
public:
    ColaDinamica():lista(nullptr){};
    bool vacia()const;
    Constancia<T>* ultimo()const;
    Constancia<T>* primero()const;
    Constancia<T>* anterior(Constancia<T>* pos)const;
    void insertar(Constancia<T>* pos,Constancia<T> elem);
    bool eliminar(Constancia<T>* pos);
    void imprimir()const;
    Constancia<T>* localiza(Constancia<T> elem) const;
    void registrarConstancia();
    void elaborarConstancia();
};

template<class T>
void ColaDinamica<T>::imprimir()const{
    Constancia<T>* aux=lista;
    while(aux!=nullptr){
        std::cout<<*aux<<"-> ";
        aux=aux->sig;
    }
}

template<class T>
bool ColaDinamica<T>::eliminar(Constancia<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void ColaDinamica<T>::insertar(Constancia<T>* pos,Constancia<T> elem){
    Constancia<T>* aux = new Constancia<T>(elem);
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }
}

template<class T>
Constancia<T>* ColaDinamica<T>::anterior(Constancia<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    Constancia<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
Constancia<T>* ColaDinamica<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}


template<class T>
Constancia<T>* ColaDinamica<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    Constancia<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
Constancia<T>* ColaDinamica<T>::localiza(Constancia<T> elem)const{
    Constancia<T>* aux = lista;
    if (vacia()){
        return nullptr;
    }

    while (aux != nullptr){
        if (*aux == elem){
            return aux;
        }
        aux = aux->sig;
    }
    return nullptr;
}

template<class T>
void ColaDinamica<T>::registrarConstancia(){
    Constancia<T> nuevaConstancia;
    cin>>nuevaConstancia;
    insertar(ultimo(), nuevaConstancia);
}


template<class T>
bool ColaDinamica<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

template<class T>
void ColaDinamica<T>::elaborarConstancia(){
    Constancia<T> ConstanciaElaborada;
    if(vacia()){
        cout << "No hay alumnos formados." << endl;
        return;
    }
    	cout<<*primero();
    	eliminar(primero());
        
}

int main()
{
    ColaDinamica<string> milista;
    int opcion = 0;
    
    while(opcion != 3){
    	cout<<endl;
    	cout<<"*****Menu de Socios*****"<<endl;
    	cout<<"1- Dar de alta solicitud"<<endl;
    	cout<<"2- Elaborar Constancia"<<endl;
    	cout<<"3- Salir"<<endl;
    	cout<<"Tu Opcion: ";
    	cin>>opcion;
    	switch(opcion){
    		case 1:
    			milista.registrarConstancia();
    			break;
    		case 2:
    			milista.elaborarConstancia();
    			break;
    		case 3:
    			cout<<"Saliendo...";
    			break;
    		default:
    			cout<<"Seleccione una opcion valida"<<endl;
		}
	}
    
    return 0;
}