#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

void cajero();
void codificacion_textos();


void binario(char ,char []);
void codificar(char [], int , int, char []);

void segundo(char [],int, int, char []);
void decodif_seg(char [],int, int,char []);

void guardar_codif(char [],char []);
void decodif(char[], int, int);
void desbinar(char [],int ,char []);
void escribir(char [],char []);
int leer(char [],char []);
int leer_sin_bin(char [],char []);


int main()
{
    bool ver=true;
    int op;
    while (ver==true)
    {
        cout<<"Que ejercicio desea mirar?\n(1)codificacion-decodificacion de textos\n(2)Cajero\n(3)Salir:\n";
        cin>>op;
        if(op==3)
        {
            ver=false;
            break;
        }
        switch (op)
        {
            case 1:
            {
                codificacion_textos();
            }
            break;

            case 2:
            {
                //cajero();
            }
            break;

            default:
            {
                cout<<"opcion incorrecta"<<endl;
            }
            break;
        }
        return 0;
    }

}
/*
void cajero()
{
    bool ver=true;
    int op;
    while (ver==true)
    {
        cout<<"---------------BIENVENIDO AL CAJERO---------------"<<endl;
        cout<<"Como desea ingresar\n(1)Administrador\n(2)Usuario\n(3)Salir:\n";
        cin>>op;
        if(op==3)
        {
            ver=false;
        }
        switch (op)
        {
            case 1:
            {
                int clave, opcion, saldo,c;
                char ident[10],arr[500000],sudo[12]="fichero.txt",codif[100000],medio[15]="intermedio.txt";
                ofstream guardar;
                ifstream entrar;
                while(true)
                {
                    cout<<"(1)Guardar registros"<<endl;
                    cout<<"(2)leer registros"<<endl;
                    cout<<"(3)Ingrese opcion"<<endl;
                    cout<<"(0)Salir"<<endl;
                    cin>>opcion;
                    if (opcion==0)
                    {
                        break;
                    }
                    switch(opcion)
                    {
                        case 1:
                        {
                            guardar.open(sudo,ios::app);//abre desde salto de linea
                            cout<<"Ingrese Identificación"<<endl;
                            cin>>ident;
                            cout<<"Ingrese clave: "<<endl;
                            cin>>clave;
                            cout<<"Ingrese saldo: "<<endl;
                            cin>>saldo;
                            guardar<<ident<<" "<<clave<<" "<<saldo<<endl;
                            guardar.close();
                            c=leer(sudo,arr);
                            codificar(arr,4,c,codif);//agrega nuevos usuarios y codifica la información
                            escribir(medio,codif);
                            break;
                        }

                        case 2:
                        {
                            char nom[20],trad[500000];
                            char deco[500000];
                            c=leer_sin_bin(medio,deco);
                            decodif(deco,4,c);
                            desbinar(deco,c,trad);
                            //cout<<deco;
                            //ifstream fin;
                            //ofstream fout;
                            //fout.open(nom);
                            //cout<<"El texto decodificado es: "<<endl;
                            for(int i=1;i<c/8;i++)
                            {
                                cout<<trad[i];

                            }
                            //fout.close();
                            cout<<endl;
                            break;
                        }
                    }


                }



            }
            break;

            case 2:
            {
                char holanda[40];
                for(int i=0;i<30;i++)
                {
                    holanda[i]=char(i+48);
                }
                ifstream fin;
                ofstream of;
                of.open("Holanda.txt");

                    of<<holanda;

                of.close();
            }
            break;

            default:
            {
                cout<<"opcion incorrecta"<<endl;
            }
            break;
        }
    }
}
*/
void  codificacion_textos()
{
    int c=0,semilla,opc;
    //bool ver=true;
    while (true)
    {
        cout<<"Que accion desea realizar:\n(1)codificar texto\n(2)Decodificar texto\n(3)Salir:\n";
        cin>>opc;
        if (opc==3)
        {
            break;
        }
        switch (opc)
        {
            case 1:
            {
                bool ban=true;
                int metcod;
                while(ban==true)
                {
                    cout<<"Que metodo de codificacion desea usar:\n(1)invertir\n(2)posiciones\n(3)Salir:\n";
                    cin>>metcod;
                    if(metcod==3)
                    {
                        ban=false;
                        break;
                    }
                    switch (metcod)
                    {
                        case 1:
                        {
                            char arr[50000]={},codif[50000];
                            char nom[20],nomarch[20];
                            cout<<"ingrese texto a leer para codificar con (.txt): ";
                            cin>>nomarch;
                            c=leer(nomarch,arr);
                            cout<<"Ingrese la semilla: ";
                            cin>>semilla;
                            codificar(arr, semilla, c, codif);
                            cout<<"Donde desea guardar la informacion codificada con (.txt): ";
                            cin>>nom;
                            escribir(nom,codif);
                            cout<<endl;
                        }
                        break;

                        case 2:
                        {
                            char arr[50000]={},codif[50000];
                            char nom[23],nomarch[20];
                            cout<<"ingrese texto a leer para codificar con (.txt) met 1: ";
                            cin>>nomarch;
                            c=leer(nomarch,arr);
                            cout<<"Ingrese la semilla: ";
                            cin>>semilla;
                            segundo(arr,semilla,c,codif);
                            cout<<codif;
                            cout<<endl;
                            cout<<"Donde desea guardar la informacion codificada con (.txt): ";
                            cin>>nom;

                            escribir(nom,codif);
                            cout<<endl;
                        }
                        break;

                        default:
                        {
                            cout<<"Opcion inválida";
                        }
                        break;
                    }
                }

            }
            break;

            case 2:
            {
                bool ban=true;
                while(ban==true)
                {
                    int metdec;
                    cout<<"Metodo de decodificacion:\n(1)Invertir\n(2)Posiciones\n(3)Salir:\n";
                    cin>>metdec;
                    if(metdec==3)
                    {
                        ban=false;
                        break;
                    }
                    switch (metdec)
                    {
                        case 1:
                        {
                            char nom[20],nomarch[20],trad[500000];
                            char deco[500000];
                            cout<<"ingrese texto a leer para decodificar con (.txt): ";
                            cin>>nomarch;
                            cout<<"Ingrese la semilla: ";
                            cin>>semilla;
                            c=leer_sin_bin(nomarch,deco);
                            decodif(deco,semilla,c);
                            desbinar(deco,c,trad);
                            cout<<"Donde desea guardar la informacion decodificada con (.txt): ";
                            cin>>nom;
                            ifstream fin;
                            ofstream fout;
                            fout.open(nom);
                            cout<<"El texto decodificado es: "<<endl;
                            for(int i=1;i<c/8;i++)
                            {
                                cout<<trad[i];
                                fout <<trad[i];
                            }
                            fout.close();
                            cout<<endl;
                        }
                        break;

                        case 2:
                        {
                            char nom[20],nomarch[20],trad[500000];
                            char deco[500000],codif[500000];
                            cout<<"ingrese texto a leer para decodificar con (.txt): ";
                            cin>>nomarch;
                            cout<<"Ingrese la semilla: ";
                            cin>>semilla;
                            c=leer_sin_bin(nomarch,codif);
                            decodif_seg(codif,semilla,c,deco);
                            desbinar(deco,c,trad);
                            cout<<"Donde desea guardar la informacion decodificada con (.txt): ";
                            cin>>nom;

                            ifstream fin;
                            ofstream fout;
                            fout.open(nom);
                            cout<<"El texto decodificado es: "<<endl;
                            for(int i=1;i<c/8;i++)
                            {
                                cout<<trad[i];
                                fout <<trad[i];
                            }
                            fout.close();
                            cout<<endl;
                        }
                        break;

                        default:
                        {
                            cout<<"Opcion ivalida";
                        }
                        break;
                    }
                }
            }
            break;

            default:
            {
                cout<<"Opcion ivalida";
            }
            break;
        }
    }
}

int leer_sin_bin(char nomarch[], char codif[])
{
    int c=0,a=0;
    ifstream archivo(nomarch);
    if(!archivo.is_open())
    {
        cout<<"El archivo no existe "<<endl;
    }
    else
    {
        char letra;
        while(!archivo.eof())
        {
            letra=archivo.get();
            codif[a]=letra;
            c=c+1;
            a=a+1;
        }
    }
    archivo.close();
    return c;
}

int leer(char nomarch[], char arr[])
{
    int c=0,b,x=0;
    char bin[8]={};
    ifstream archivo(nomarch);
    if(!archivo.is_open())
    {
        cout<<"El archivo no existe "<<endl;
    }
    else
    {
        char letra;
        while(!archivo.eof())
        {
            letra=archivo.get();
            binario(letra,bin);
            c++;
            //cout<<c;
            b=c*8;
            for(int j=0;j<8 || x<b ;j++,x++)
            {
                arr[x]=bin[j];
            }
        }
    }
    archivo.close();
    return c;

}

void binario(char let,char bin[])
{
    int b,a;
    a=let;
    for(int i=7;i>=0;i--)
    {
        b=a%2;
        if(a>=32 && a<=63)
        {
            bin[1]='0';
            bin[0]='1';
        }
        else if(a>=64 && a<=126)
        {
            bin[0]='0';
        }
        bin[i]=b+48;
        a=a/2;
    }
    //for(int i=0;i<8;i++)
    //{
     //   cout<<bin[i];
    //}
    //cout<<endl;
}

void codificar(char arr[], int sem, int lim, char codif[])
{
    int j=0,cero=0,jp,uno=0,con=0,o=0;

    for(int i=1;i<=((lim*8)/sem)+1;i++)
    {
        for(;j<i*sem && arr[j]!=-1;j++)
        {
            if(j<sem)
            {
                if(arr[j]=='0')
                {
                    codif[j]='1';
                }
                else if(arr[j]=='1')
                {
                    codif[j]='0';
                }
            }
            else
            {
                codif[j]=arr[j];
            }
            //cout<<arr[j];

        }
        con=con+1;
        //cout<<endl;
        //cout<<"Con: "<<con<<endl;
       // cout<<endl;
    }

    for(int i=1;i<=((lim*8)/sem)+1;i++)
    {
        for(;o<sem*i;o++)
        {
            if(o<sem*i)
            {
                if(arr[o]=='1')
                {
                    uno++;
                }
                else if(arr[o]=='0')
                {
                    cero++;
                }
            }
        }

        if(cero==uno)
        {
            jp=o;
            for(;jp<sem*(i+1);jp++)
            {
                if(codif[jp]=='0')
                {
                    codif[jp]='1';
                }
                else if(codif[jp]=='1')
                {
                    codif[jp]='0';
                }
            }
            //cout<<"cambia cada bit"<<endl;
        }
        else if(cero>uno)
        {
            jp=o; int cd=1;
            for(;jp<sem*(i+1);jp++)
            {
                if(cd%2==0)
                {
                    if(codif[jp]=='0')
                    {
                        codif[jp]='1';
                    }
                    else if(codif[jp]=='1')
                    {
                        codif[jp]='0';
                    }
                    cd=cd+1;
                }
                else
                {
                    cd=cd+1;
                }
            }
            //cout<<"cambio cada dos bits"<<endl;
        }
        else if(uno>cero)
        {
            jp=o; int ct=1;
            for(;jp<sem*(i+1);jp++)
            {
                if(ct%3==0)
                {
                    if(codif[jp]=='0')
                    {
                        codif[jp]='1';
                    }
                    else if(codif[jp]=='1')
                    {
                        codif[jp]='0';
                    }
                    ct=ct+1;
                }
                else
                {
                    ct=ct+1;
                }
            }
            //cout<<"cambio cada tres bits"<<endl;
        }
        cero=0;
        uno=0;
    }

    for(int p=0;p<(lim*8);p++)
    {
        if(codif[p]==-1)
        {
            break;
        }
        else
        {
            //cout<<codif[p];
        }
    }
}

void segundo(char arr[], int sem , int lim,char codif[])
{
    int j=0;
    for(int i=1,b=0; i<=(lim*8)/sem; i++,b++)
    {
        codif[b*sem]=arr[(sem*i)-1];
        for(;j<sem*i;j++)
        {
            codif[j+1]=arr[j];
        }
    }
}


void decodif_seg(char deco[],int sem, int lim, char codif[])
{
    int j=0;
    for(int i=1,b=0; i<=(lim*8)/sem; i++,b++)
    {
        deco[(sem*i)-1]=codif[b*sem];
        for(;j<sem*i;j++)
        {
            deco[j]=codif[j+1];
        }
    }
}

void decodif(char deco[],int sem, int lim)
{
    int j=0,cero=0,jp,uno=0,con=0,o=0;

    for(int i=1;i<=((lim*8)/sem)+1;i++)
    {
        for(;j<i*sem;j++)
        {
            if(j<sem)
            {
                if(deco[j]=='0')
                {
                    deco[j]='1';
                }
                else if(deco[j]=='1')
                {
                    deco[j]='0';
                }
            }
        }
        con=con+1;
        //cout<<endl;
        //cout<<"Con: "<<con<<endl;
       // cout<<endl;
    }

    for(int i=1;i<=((lim*8)/sem)+1;i++)
    {
        for(;o<sem*i;o++)
        {
            if(o<sem*i)
            {
                if(deco[o]=='1')
                {
                    uno++;
                }
                else if(deco[o]=='0')
                {
                    cero++;
                }
            }
        }

        if(cero==uno)
        {
            jp=o;
            for(;jp<sem*(i+1);jp++)
            {
                if(deco[jp]=='0')
                {
                    deco[jp]='1';
                }
                else if(deco[jp]=='1')
                {
                    deco[jp]='0';
                }
            }
            //cout<<"cambia cada bit"<<endl;
        }
        else if(cero>uno)
        {
            jp=o; int cd=1;
            for(;jp<sem*(i+1);jp++)
            {
                if(cd%2==0)
                {
                    if(deco[jp]=='0')
                    {
                        deco[jp]='1';
                    }
                    else if(deco[jp]=='1')
                    {
                        deco[jp]='0';
                    }
                    cd=cd+1;
                }
                else
                {
                    cd=cd+1;
                }
            }
            //cout<<"cambio cada dos bits"<<endl;
        }
        else if(uno>cero)
        {
            jp=o; int ct=1;
            for(;jp<sem*(i+1);jp++)
            {
                if(ct%3==0)
                {
                    if(deco[jp]=='0')
                    {
                        deco[jp]='1';
                    }
                    else if(deco[jp]=='1')
                    {
                        deco[jp]='0';
                    }
                    ct=ct+1;
                }
                else
                {
                    ct=ct+1;
                }
            }
            //cout<<"cambio cada tres bits"<<endl;
        }
        cero=0;
        uno=0;
    }

}

void desbinar(char deco[],int lim,char trad[])
{
    int j=0,num,con=0;
    int norm;
    char a;
    for(int i=1;i<lim;i++)
    {
        int pot=7,sum=0;
        for(;j<i*8;j++)
        {
            num=deco[j]-48;
            norm=num*(pow(2, pot));
            sum=sum+norm;
            pot--;
        }
        con=con+1;
        a=char(sum);
        trad[i]={a};
    }
}

void escribir(char nom[], char arr[])
{
    ifstream fin;
    ofstream fout;
    fout.open(nom);
    fout << arr;
    fout.close();
}



