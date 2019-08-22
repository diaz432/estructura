#include <iostream>
using namespace std;

struct nodo 
{
	int nro;
	struct nodo *izq,*der;
};

typedef struct nodo *ABB;

   class Arbolbb{
	public:
ABB crearNodo(int x) 
{
	ABB nuevoNodo=new (struct nodo); 
	
	nuevoNodo->nro=x; //crea la raiz
	nuevoNodo->izq=NULL; //da valor 
	nuevoNodo->der=NULL; //da valor 
	return nuevoNodo; //regresa a hacer un nuevonodo
	
}
void insertar(ABB &arbol, int x) //para insertar nodo
{
	if(arbol==NULL) //verifica estado null
	{
		arbol=crearNodo(x); //si esta null crea un nuevo nodo
	}
	else if(x<arbol->nro) //verifica si el valor ingresado es menor a la raiz
	{
		insertar(arbol->izq, x); //almacena en la posicion izquierda
	}
	else if(x>arbol->nro) //verifica si el valor ingresado es mayor a la raiz
	{
		insertar(arbol->der, x); //almacena en la posicion derecha
	}
}

void preOrden(ABB arbol)
{
	if(arbol!=NULL)
	{
		cout<<arbol->nro <<" ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}
void inOrden(ABB arbol){
	if(arbol!=NULL){
		inOrden(arbol->izq);
		cout << arbol->nro << "\t";
		inOrden(arbol->der);
	}
}
void postOrden(ABB arbol){
	if(arbol!=NULL){
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout << arbol->nro << "\t";
	}
}
void valor(ABB arbol,int &sum)
{
	if(arbol!=NULL)
	{
		valor(arbol->izq,sum);
		sum = sum + arbol->nro;
		valor(arbol->der,sum);
	}
}
void altura(ABB arbol,int *alt,int aux){
	if(arbol!=NULL){
		altura(arbol->izq,alt,aux+1);
		altura(arbol->der,alt,aux+1);
		if(aux > *alt){*alt = aux;}
	}
}
void verArbol(ABB arbol, int n)
{
	if(arbol==NULL)
	{
		return;
	}
	verArbol(arbol->der,n+1);
	for(int i=0;i<n;i++){
		cout<<"   ";
	}
	cout<<arbol->nro<<endl;
	verArbol(arbol->izq,n+1);	
}
};



int main()
{
	Arbolbb *arbol=new(Arbolbb);
	ABB ar = NULL;
	int n, naux;
	int x,altura;
	char op;
	int sum = 0, sumaux = 0;
		
	cout<<"ingrese el numero de nodos del arbol: "<<endl;
	cin>>n;
	
	while(true){
	cout << "El arbol tiene actualente " << naux << " nodos\n";	
	cout << "1-Ingresar un nodo\n2-Suma de todas las claves\n3-Altura del arbol\n4-Menu de recorridos\n5-Ver arbol\n6-Salir\n...";
	cin >> op;
	
	switch(op){
		case '1':
			if(naux < n){		
			cout<<"valor del nodo: "<<endl;
			cin>>x;
			arbol->insertar(ar,x);
			naux++;
			}else{
				cout << "ha llegado al numero maximo de nodos:" << n << "\nDesearia aumentar ese limite?(s,n)";
				cin >> op;
				if(op == 's' || op == 'S'){
					do{
					cout << "Ingrese el nuevo numero de nodos que habran: ";cin >> n;
					}while(n < naux);
				}
			}
			break;
		case '2':
			if(ar == NULL){
				cout << "El arbol esta vacio\n";
				break;
			}
			arbol->valor(ar,sum);
			cout << "La suma de todos los valores en el arbol es: " << sum << endl;
			sum = 0;
			break;
		case '3':
			arbol->altura(ar,&altura,1);
			cout << "La altura del arbol es: " << altura << endl;
			altura = 0;
			break;
		case '4':
			cout << "1-Preorden\n2-Inorden\n3-Postorden\n...";
			cin >> op;
			
			if(op == '1'){
				arbol->preOrden(ar);
			} else if(op == '2'){
				arbol->inOrden(ar);
			} else if(op == '3'){
				arbol->postOrden(ar);
			}
			break;
	    	case '5':
		    	arbol->verArbol(ar,0);
			    break;
		
		         case '6':
			      return 0;
	
	}
	system("pause");
	system("cls");
	}

}
