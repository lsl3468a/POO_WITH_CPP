/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   TP3_LASSERRE.cpp
 * Author: Ludivine Lsr
 *
 * Created on 25 octobre 2022, 08:14
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;


void estUnChiffre(char a, bool &chiffre)
{
    chiffre = false;
    if((a>='0' && a<='9'))
        chiffre = true;
}


void estUneLettre(char a, bool &lettre)
{
    lettre = false;
    if((a>='a' && a<='z') || (a>='A' && a<='Z'))
        lettre = true;
}


void estUnEspacement(char a, bool &espacement)
{
    espacement = false;
    if(a==' ')
        espacement = true;
}


void estUneTabulation(char a, bool &tabulation)
{   tabulation = false;
    if(a=='\t')
        tabulation = true;
}


void afficheCodeCaractere(char a)
{
    cout<<a<<" "<<hex<<"0x"<<int(a)<<" "<<dec<<int(a)<<endl;
}

void estUneMajuscule(char a, bool &maj)
{   
    maj = false;
    if(int(a)>=65 && int(a)<=90)
        maj = true;
}


void minus2majusc(char &a)
{
    a = int(a) - 32;
}

void majusc2minus(char &a)
{
    a = int(a) + 32;
}


int main()
{
    char phrase[50];
    char phraseMaj[50];
    char a;
    int i = 0;
    int nbLettre = 0, nbChiffre = 0, nbEspacement = 0, nbTab= 0;
    bool lettre, chiffre, espace, maj, tab = false;
    cout<<"Veuillez entrer votre texte : \n>>>"<<endl;
    do
    {
        cin>> noskipws >>a;
        phrase[i]=a;
        estUnChiffre(phrase[i],chiffre);
        estUneLettre(a,lettre);
        estUnEspacement(a,espace);
        estUneTabulation(a,tab);
        if(chiffre)
            nbChiffre++;
        else if (lettre)
            nbLettre++;
        else if (espace)
            nbEspacement ++;
        else if (tab)
            nbTab++;
        i++;
    } while(a!='.');

    cout<<"Il y a "<<nbLettre<<" lettres"<<endl;
    cout<<"Il y a "<<nbChiffre<<" chiffres"<<endl;
    cout<<"Il y a "<<nbEspacement<<" espacements"<<endl;
    cout<<"Il y a "<<nbTab<<" tabulations"<<endl;
    
    //AFFICHAGE EN HEXADECIMAL ET MODIFICATION MAJ2MIN ET MIN2MAJ (sans fonction des bibliothèques)
    i=0;
    cout<<"\nAffichage des caractères de la phrase en hexadécimal et en décimal."<<endl;
    do {
        afficheCodeCaractere(phrase[i]);
        estUneLettre(phrase[i],lettre);
        if(lettre){
            estUneMajuscule(phrase[i],maj);
            if(maj==1){
                majusc2minus(phrase[i]);
            } else {
                minus2majusc(phrase[i]);
            }
        }
        
        i++;
    } while(phrase[i]!='.');
    
    cout<<"\nChaine modifiée avec les majuscules devenues minuscules et le contraire :"<<endl;
    i=0;
    do {
        cout<<phrase[i];
        i++;
    } while(phrase[i]!='.');
    
    //UTILISATION DES FONCTIONS DES BIBLIOTHEQUES
    nbLettre = 0, nbChiffre = 0, nbEspacement = 0;
    i = 0;
    do {
        if(isalpha(phrase[i]))
            nbLettre ++;
        else if(isdigit(phrase[i]))
            nbChiffre++;
        else if(isspace(phrase[i]))
            nbEspacement ++;
        if(islower(phrase[i]))
            phrase[i] = toupper(phrase[i]);
        else
            phrase[i] = tolower(phrase[i]);
       i++;
    } while(phrase[i]!='.');
    
    cout<<"\nRésultats avec l'utilisation des fonctions de bibliothèques : "<<endl;
    cout<<"Il y a "<<nbLettre<<" lettres"<<endl;
    cout<<"Il y a "<<nbChiffre<<" chiffres"<<endl;
    cout<<"Il y a "<<nbEspacement<<" espacements"<<endl;
    
    i=0;
    do {
        cout<<phrase[i];
        i++;
    } while(phrase[i]!='.');
    
    return 0;
}
