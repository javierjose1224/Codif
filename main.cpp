#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;
void binario(char ,char []);
void codificar(char [], int , int, char []);

int main()
{
    int c=0,b,x=0,semilla;
    char arr[500]={},bin[8]={},codif[500],lit[10000];
    cout<<"Ingrese la semilla: ";
    cin>>semilla;
    ifstream archivo("rubius.txt");
    if(!archivo.is_open())
    {
        cout<<"El archivo no existe";
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
    codificar(arr, semilla, c, codif);

    //cout<<codif;
    for(int i=0;i<10000;i++)
    {
        if(codif[i]=='\0')
        {
            break;
        }
        else
        {
            lit[i]=codif[i];
        }
    }

    cout<<lit;

    return 0;
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




