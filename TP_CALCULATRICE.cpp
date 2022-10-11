/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   TP_CALCULATRICE.cpp
 * Author: Ludivine Lsr
 *
 * Created on 11 octobre 2022, 08:50
 */

#include <iostream>
#include <cstdlib>
#include <math.h>
#include<iomanip>

using namespace std;

int moyenne() //Moyenne de dix nombres entiers
{
    int nombre;
    int somme; 
    float moyenne;
    int i;
    
    somme=0;
    
    for(i=1; i<=10; i++)
    {
        cout<<"Donner le nombre :"<<i;
        cin>>nombre;
        somme = somme + nombre;
    }
    moyenne = somme*1.0/10;
    
    cout<<"Moyenne : "<<moyenne;
    
    return 0;
}

int addition(int a, int b) //Addition entre deux nombres entiers
{
    return a+b;
}

int soustraction(int a, int b) //Soustraction entre deux nombres entiers
{
    return a-b;
}

int multiplication(int a, int b) //Multiplication entre deux nombres entiers
{
    return a*b;
}

void division(int a, int b,int &resultat, int &reste) //Division euclidienne de deux nombres entiers
{
    resultat = a/b;
    reste = a%b;
}

int puissance(int a, int b) //Puissance entre deux nombres entiers 
{
    return pow(a,b);
}

int menu() //Affichage du menu de la calculatrice
{
    char choix =' ';
    cout<<"Menu de la calculatrice :\n"<<endl;
    cout<<"+ addition"<<endl;
    cout<<"- soustraction"<<endl;
    cout<<"* multiplication"<<endl;
    cout<<"/ division euclidienne"<<endl;
    cout<<"^ puissance"<<endl;
    cout<<"P calcul du PGCD"<<endl;
    cout<<"F factorielle"<<endl;
    cout<<"Q quitter"<<endl;
    cout<<"Entrer votre choix : \n>>>"<<endl;
    cin>>choix;
    return choix;
}

int PGCD(int a, int b) //Calcul du PGCD entre deux nombres
{
    while(a != b)
        if(a > b)
            a -= b;
        else
            b -= a;
    return a;
}

float factorielle(float a) //Calcule la factorielle d'un nombre
{
    int i;
    int fact = 1;
    for(i=1; i<=a; i++){
        fact = fact * i;
    }
    return fact;
}

void lire_operandes(int &a, int &b) //Fonction qui lit deux nombres entiers
{
    cout<<"Entrez un premier nombre : \n>>>"<<endl;
    cin>>a;
    cout<<"Entrez un deuxième nombre : \n>>>"<<endl;
    cin>>b;
}

int main() {
    char choix = ' ';
    int nombre1, nombre2;
    int resultat, reste = 0;
 
    do {
        choix = menu();
        switch(choix){
            case '+':
                lire_operandes(nombre1, nombre2);
                cout<<"L'addition de "<<nombre1<<" et "<<nombre2<<" est : "<<addition(nombre1,nombre2)<<endl;
                break;
            case '-':
                lire_operandes(nombre1, nombre2);
                cout<<"La soustraction de "<<nombre1<<" et "<<nombre2<<" est : "<<soustraction(nombre1,nombre2)<<endl;
                break;
            case '*':
                lire_operandes(nombre1, nombre2);
                cout<<"La multiplication de "<<nombre1<<" et "<<nombre2<<" est : "<<multiplication(nombre1,nombre2)<<endl;
                break;
            case'/':
                lire_operandes(nombre1, nombre2);
                division(nombre1,nombre2, resultat, reste);
                cout<<"Le résultat de la division de "<<nombre1<<"/"<<nombre2<<" est : "<<resultat<<endl;
                cout<<"Le reste est : "<<reste<<endl;
                break;
            case '^':
                lire_operandes(nombre1, nombre2);
                cout<<"Le résultat de "<<nombre1<<"à la puissande de "<<nombre2<<" est : "<<puissance(nombre1,nombre2)<<endl;
                break;
            case'P':
                lire_operandes(nombre1,nombre2);
                cout<<"Le PGCD de : "<<nombre1<<" et de "<<nombre2<<" est : "<<PGCD(nombre1,nombre2)<<endl;
                break;
            case 'F':
                float fact;
                cout<<"Entrez un nombre : \n>>>"<<endl;
                cin>>fact;
                cout<<"La factorielle de "<<fact<<" est : "<<fixed << setprecision(2) <<factorielle(fact)<<endl;
        }
    } while (choix != 'Q');
    cout<<"Fin du programme"<<endl;
    
    return 0;
}


