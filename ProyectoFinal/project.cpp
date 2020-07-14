 #include "iostream"
 #include "string.h"

 const int longCad = 20;//indica el numero maximo de caracteres en la cadena

 using namespace std;

 struct costoPorArticulo{
 char  nombreArticul[longCad + 1];
 int   cantidad;
 float precio;
 float costoPorArticulo;
 };

 void datos_articulo(costoPorArticulo num_articulos[], int num);
 void mostrar_articulos(costoPorArticulo num_articulos[], int num);
 void costo_articulo(costoPorArticulo num_articulos[], int num);
 float total_compra(costoPorArticulo num_articulos[], int num);


 int main(){
 int num;
 cout<<"\nBIENVENIDO/A a Super Selectos\nIngrese la cantidad de articulos a cobrar: "<<endl;
 cin>>num;
 cin.ignore(100,'\n');//codigo para borrar buffer del teclado y que no haya problema con las cadenas de string
 costoPorArticulo num_articulos[num];

 datos_articulo(num_articulos, num);
 costo_articulo(num_articulos, num);
 mostrar_articulos(num_articulos, num);

 cout<<"Total a cobrar: $"<<total_compra(num_articulos, num)<<endl;
 cout<<"Gracias vuelva pronto"<<endl<<endl;
 }

 void datos_articulo(costoPorArticulo x[], int num){
 string cad;
 int contador=1;//contador para indicar numero de articulo

 cout<<"\nLea datos del articulo: "<<endl;
    for (int i = 0; i < num ; i++){ 
    cout<<"Ingrese el nombre del articulo: "<<contador++<<endl;
    getline(cin, cad, '\n');
    strncpy(x[i].nombreArticul, cad.c_str(),longCad);//funcion que copia el contenido de la cadena en un arreglo de caracteres
    x[i].nombreArticul[longCad]='\0';
    cout<<"Cantidad del articulo: "<<endl; 
    cin>>x[i].cantidad;
    cout<<"Ingrese el precio unitario del articulo: "<<endl; 
    cin>>x[i].precio;
    cin.ignore(100, '\n');
    cout<<endl;
    }
 }

 void costo_articulo(costoPorArticulo x[], int num){ 
      for ( int i = 0; i < num; i++)  x[i].costoPorArticulo = x[i].cantidad * x[i].precio;
    }
 //muestra los 4 datos de la estructura, articulo por articulo segun le corresponda
 void mostrar_articulos(costoPorArticulo x[], int num){
    int contador= 1;    
    cout<<"Los articulos ingresados fueron: "<<endl;
    for ( int i = 0; i < num; i++)
    {
     cout<<"ARTICULO "<<contador++<<": "<<x[i].nombreArticul<<endl;
     cout<<"Cantidad: "<<x[i].cantidad<<endl;
     cout<<"Precio unitario: $"<<x[i].precio<<endl;
     cout<<"precio total del articulo: $"<<x[i].costoPorArticulo<<endl<<endl;
        
    }
 }
 //funcion que realiza suma de todas las casillas de costoPorArticulo para indicar el monto a pagar
 float total_compra(costoPorArticulo x[], int num)
  {
    float Preciototal;
    for ( int i = 0; i < num; i++) Preciototal += x[i].costoPorArticulo;
    
 return Preciototal;
 }
