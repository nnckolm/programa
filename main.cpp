#include <iostream>
#include <string>
#include <fstream>

using namespace std;



void burbuja(int arreglo[], int longitud);
void heapsort(int a[], int n);
void mergesort(int a[],int l,int r);
void quicksort(int a[], int l, int g);
int lineal(int a[],int cn, int cl);

int binaria(int a[], int l, int r, int x);
int interpolacion(int a[], int n, int num);

int main(){

    int lp,cl,px,cm[1000],bp,bm,cn;

    string nm,cd,kl,ck[1000];

     ofstream nl,lm,lk;

    lp=0;

    while(lp==0){


            cout<<"Ingrese su nombre"<<endl;

            cin>>nm;

            cout<<"Ingrese su cedula"<<endl;

            cin>>cd;



            cout<<"Ingrese la materia para ingresar las notas"<<endl;

            cin>>kl;


            cout<<"Ingrese el numero de estudiantes"<<endl;

            cin>>cl;


            for (int i=0;i<cl;i++){

                     cout<<"Ingrese el nombre   "<<endl;

                    cin>>ck[i];

                 cout<<"Ingrese la nota del estudiante "<<endl;

                cin>>cm[i];



            }

            nl.open("calificaciones.txt");

            nl<<"REPORTE DE CALIFICACIONES"<<endl;
             nl<<"Año lectivo: 2020 – 2021"<<endl;

              nl<<"Materia "<<kl<<endl;

               nl<<" Estudiante Nota"<<endl;



               for (int i=0;i<cl;i++){



                    nl<<ck[i];



                nl<<"    "<<cm[i]<<endl;



            }



            nl<<nm<<endl;
             nl<<cd<<endl;

             cout<<"Ingrese el metodo de ordenamiento   1) Burbuja 2) Heap Sort 3) Merge Sort 4) Quick Sort"<<endl;

             cin>>bp;

            lm.open("ordenamiento.txt");

            lm<<"Calificaciones Ordenadas "<<endl;

            lm<<"Algoritmo ";

            if(bp==1){

                lm<<" Burbuja "<<endl;

                burbuja(cm,cl);
            }
            else if(bp==2){

                lm<<" Heap Sort "<<endl;
                heapsort(cm,cl);

            }

            else if(bp==3){

                lm<<" Merge Sort "<<endl;
                mergesort(cm,0,cl);

            }


            else if(bp==4){

                lm<<" Quick Sort "<<endl;
                quicksort(cm,0,cl);

            }

             for (int i=0;i<cl;i++){





                   lm<<cm[i]<<endl;

            }


            cout<<"Ingrese el metodo de busqueda   1) Lineal 2)Binaria  3) Interpolacion"<<endl;

             cin>>bm;

             cout<<"Ingrese la busqueda"<<endl;

             cin>>cn;

            lk.open("busqueda.txt");

             lk<<"Resultados de busqueda "<<endl;

            lk<<"Algoritmo ";


            if(bm==1){

                    lk<<" Lineal "<<endl;

                   px= lineal(cm,cn,cl);

            }
            else if(bm==2){

                lk<<" Binaria "<<endl;
                px= binaria(cm,0,cl,cn);

            }

            else if(bm==3){

                lk<<" Interpolacion"<<endl;
                px= interpolacion(cm,cl,cn);


            }

            lk<<" La calificación a buscar fue de     "<<cn<<endl;


            if(px==1){

                     for (int i=0;i<cl;i++){



                        if(cn==cm[i]){

                            lk<<" Corresponde al estudiante  "<<ck[i]<<endl;


                        }



            }






            }




    }


    return 0;
}

int interpolacion(int a[], int n, int num)
{
    int lk = 0;

    int tl = n-1;

    int md;

    int cont=0;


    while(a[lk] != num && cont<=7 )
    {
        md = lk + ((num - a[lk])*(tl-lk))/(a[tl]-a[lk]);
        if(a[md]<num)
        {
            lk = md +1;
        }
        else if(a[md]>num)
        {
            tl = md-1;
        }
        else
        {
            lk = md;
        }
        cont++;
    }

    if(a[lk]==num)
    {
        return 1;
    }


}


int binaria(int a[], int l, int r, int x)
{
    if (r >= l) {
        int m = l + (r - l) / 2;


        if (a[m] == x)
            return 1;


        if (a[m] > x)
            return binaria(a, l, m - 1, x);


        return binaria(a, m + 1, r, x);
    }



}

int lineal(int a[],int cn, int cl){


    for (int i=0;i<cl;i++){





                  if( cn==a[i]){


                    return 1;
                  }

            }




}

void intercambiar(int a[], int *b) {
  int temporal = *a;
  *a = *b;
  *b = temporal;
}

void burbuja(int arreglo[], int longitud) {
  for (int x = 0; x < longitud; x++) {

    for (int indiceActual = 0; indiceActual < longitud - 1;
         indiceActual++) {
      int indiceSiguienteElemento = indiceActual + 1;

      if (arreglo[indiceActual] > arreglo[indiceSiguienteElemento]) {

        intercambiar(&arreglo[indiceActual], &arreglo[indiceSiguienteElemento]);
      }
    }
  }
}

void nx(int a[], int i, int n)
{
  int l,r,lt,loc;
  l=2*i;
  r=(2*i+1);
  if((l<=n)&&a[l]>a[i])
    lt=l;
  else
    lt=i;
  if((r<=n)&&(a[r]>a[lt]))
    lt=r;
  if(lt!=i)
    {
      loc=a[i];
      a[i]=a[lt];
      a[lt]=loc;
      nx(a, lt,n);
    }
}
void cx(int a[], int n)
{
  for(int k = n/2; k >= 1; k--)
    {
      nx(a, k, n);
    }
}
void heapsort(int a[], int n)
{

  cx(a,n);
  int i, tp;
  for (i = n; i >= 2; i--)
    {
      tp = a[i];
      a[i] = a[1];
      a[1] = tp;
      nx(a, 1, i - 1);
    }
}

void mr(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;


    int L[n1], R[n2];


    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;


    int j = 0;


    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergesort(int a[],int l,int r){
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    mr(a,l,m,r);
}

void quicksort(int a[], int l, int g)
{
    int i = l;
    int j = g;
    int pt = a[(i + j) / 2];
    int tp;

    while (i <= j)
    {
        while (a[i] < pt)
            i++;
        while (a[j] > pt)
            j--;
        if (i <= j)
        {
            tp = a[i];
            a[i] = a[j];
            a[j] = tp;
            i++;
            j--;
        }
    }
    if (j > l)
        quicksort(a, l, j);
    if (i < g)
        quicksort(a, i, g);
}
