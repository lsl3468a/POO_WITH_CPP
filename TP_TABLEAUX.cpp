/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   TP4_TABLEAUX.cpp
 * Author: Ludivine Lsr
 *
 * Created on 26 octobre 2022, 08:24
 */

#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

/*
 * 
 */
const int N_MAX=100;
const float T_MIN = -273.5;
const float T_MAX = 5526.0;
typedef float t_mes [N_MAX];


void initialisationTab(t_mes &tabT){
    int i;
    for(i=0; i<N_MAX; i++){
        tabT[i]=0.0;
    }
}


void afficherTemp(t_mes tabT, int nbMesures, bool ligne){
    cout<<"Affichage des températures :"<<endl;
    int i;
    if(ligne){
        for(i=0; i<nbMesures; i++){
            cout<<tabT[i]<<" ";
        }
    } else {
        for(i=0; i<nbMesures; i++){
            cout<<tabT[i]<<endl;
        }
    }
}


void lireTemp(int &n, t_mes &tab)
{
    int i;
    cout<<"Entrez le nombre de mesures à analyser :\n>>>"<<endl;
    cin>>n;
    for(i = 0; i<n; i++){
        cout<<"Entrez la "<<i+1<<"ème valeur : \n>>"<<endl;
        cin>>tab[i];
    }
}


void minmaxTemp(int nbMesures, t_mes tabMesures, float &min, float &max){
    int i;
    for(i=0; i<nbMesures; i++){
        if(min>tabMesures[i])
            min = tabMesures[i];
        if(max<tabMesures[i])
            max = tabMesures[i];
    }
}


void Tproche0(t_mes tabMesures, int nbMesures, float &valeur){
    int i;
    for(i=0; i<nbMesures; i++){
        if(fabs(tabMesures[i]) < fabs(valeur)){
            valeur = tabMesures[i];
        }
    }
}


void calculEffectif(int nbMesures, t_mes tabMesures, int borneInf, int borneSup, int &effectif){
    effectif = 0;
    int i;
    for(i=0; i<nbMesures; i++){
        if(tabMesures[i]>borneInf && tabMesures[i]<=borneSup){
            effectif++;
        }
    }
}


void menu(int &choix){
    cout<<"Voulez-vous :"<<endl;
    cout<<"(1) entrer des températures"<<endl;
    cout<<"(2) afficher la liste des températures "<<endl;
    cout<<"(3) afficher la température la plus proche de 0"<<endl;
    cout<<"(4) afficher les extremums"<<endl;
    cout<<"(5) afficher les effectifs des 4 classes"<<endl;
    cout<<"\t ]-10,-5] ]-5, 0] ]0, 5] ]5, 10]"<<endl;
    cout<<"(6) quitter"<<endl;
    cout<<"Votre choix"<<endl;
    cin>>choix;
}


int main() {
    int nbMesures = 0, choix = 0;
    float min = 5526.0, max = -273.5;
    float valeur = T_MAX;
    t_mes tabMesures;
    bool AffLigne = true;
    initialisationTab(tabMesures);
    do {
        menu(choix);
        switch(choix) {
            case 1 : 
                lireTemp(nbMesures,tabMesures);
                break;
            case 2 : 
                if(nbMesures == 0){
                    cout<<"Le nombre de mesures est égal à 0, le traitement ne peut pas se faire.\nLisez des mesures (1) ou quittez (6)."<<endl;
                    break;
                } else {
                    cout<<"\nVoulez-vous l'afficher sur une ligne ? (1/0)\n>>>"<<endl;
                    cin>>AffLigne;
                    afficherTemp(tabMesures, nbMesures, AffLigne);
                    break;
                }
                break;
            case 3 :
                if(nbMesures == 0){
                    cout<<"Le nombre de mesures est égal à 0, le traitement ne peut pas se faire.\nLisez des mesures (1) ou quittez (6)."<<endl;
                    break;
                } else {
                    Tproche0(tabMesures,nbMesures,valeur);
                    cout<<"La valeur la plus proche de 0°C est de : "<<valeur<<endl;
                }
                break;
            case 4 :
                if(nbMesures == 0){
                    cout<<"Le nombre de mesures est égal à 0, le traitement ne peut pas se faire.\nLisez des mesures (1) ou quittez (6)."<<endl;
                    break;
                } else {
                    minmaxTemp(nbMesures, tabMesures, min, max);
                    cout<<"La température minimale trouvée est de : "<<min<<endl;
                    cout<<"La température maximale trouvée est de : "<<max<<endl;
                }
                break;
            case 5 :
                if(nbMesures == 0){
                    cout<<"Le nombre de mesures est égal à 0, le traitement ne peut pas se faire.\nLisez des mesures (1) ou quittez (6)."<<endl;
                    break;
                } else {
                    int borneInf = -10;
                    int borneSup = -5;
                    int effectif = 0;
                    calculEffectif(nbMesures, tabMesures, borneInf, borneSup, effectif);
                    cout<<"L'effectif de la classe ]-10,-5] est de : "<<effectif<<endl;
                    borneInf = -5;
                    borneSup = 0;
                    calculEffectif(nbMesures, tabMesures, borneInf, borneSup, effectif);
                    cout<<"L'effectif de la classe ]-5,0] est de : "<<effectif<<endl;
                    borneInf = 0;
                    borneSup = 5;
                    calculEffectif(nbMesures, tabMesures, borneInf, borneSup, effectif);
                    cout<<"L'effectif de la classe ]0,5] est de : "<<effectif<<endl;
                    borneInf = 5;
                    borneSup = 10;
                    calculEffectif(nbMesures, tabMesures, borneInf, borneSup, effectif);
                    cout<<"L'effectif de la classe ]5,10] est de : "<<effectif<<endl;
                }
                break;
            default : 
                break;
        }
    } while (choix != 6);
    
    return 0;
}

