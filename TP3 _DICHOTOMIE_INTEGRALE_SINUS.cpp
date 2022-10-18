#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

float sinusCardinal(float x){
    if(x==0.0){
        return 3.0;
    } else {
        return 3*(sin(x)/x);
    }
}

void dichotomie(float a, float b, float precision, float &zero, int &nbiterations){
    float m ; //milieu de l'intervalle
    float fa = sinusCardinal(a);
    float fb = sinusCardinal(b);
    float fm;
    
    while(abs(b-a) > precision){
        m = abs(a+b)/2;
        fm = sinusCardinal(m);
        if(fm==0){
            break;
        }
        if (fa*fm < 0) {
            b = m;
            fb = fm;
            nbiterations += 1;
        } else  {
            a = m;
            fa = fm;
            nbiterations += 1;
        }
    }
    zero = m;
}

float sinusPlusUn(float x){
    return sin(x)+1;
}

float primitiveSinusPlusUn(float x){
    return -cos(x)+x;
}

float trapeze(float a, float b, int nbtrapezes){
    float largeur = (b - a) /nbtrapezes;
    int n;
    float aire = sinusPlusUn(a)/2+sinusPlusUn(b)/2;
    for(n=1; n<nbtrapezes; n++){
        aire += sinusPlusUn(a + n * largeur);
    }
    return largeur * aire;
    
}

float puissance(float a,int b)  
{
    return pow(a,b);
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

float sinusTaylor(float x, float precision){
    float sinus = x;
    int n =1 ,a = 1, b = 1;
    do {
        a = pow(-1,n);
        b = 2*n+1;
        if(a<0){
            sinus -= (pow(x,b)/factorielle(b));
        } else {
            sinus += (pow(x,b)/factorielle(b));
        }
        
        n++;
    } while(fabs(sinus-sin(x)) >= precision);
    return sinus;
}

int main() {
    float epsilon = 0.1;
    float a,b, zero,x;
    int nb, nbtrapezes;
   /* 
   //CALCUL DICHOTOMIQUE
    cout<<"Calcul de la valeur de f(x)=0 par dichotomie :"<<endl;
    cout<<"Entrez la valeur de a : \n>>>"<<endl;
    cin>>a;
    cout<<"Entrez la valeur de b: \n>>>"<<endl;
    cin>>b;
    dichotomie(a, b, epsilon, zero, nb);
    cout<<"La valeur de x est "<<zero<<" et a été trouvé en  "<<nb<<" itérations."<<endl;
    
    //CALCUL DE L'INTEGRALE
    cout<<"Calcul d'une intégrale par la méthode des trapezes :"<<endl;
    cout<<"Entrez la valeur de a : \n>>>"<<endl;
    cin>>a;
    cout<<"Entrez la valeur de b: \n>>>"<<endl;
    cin>>b;
    cout<<"Entrez le nombre de trapèzes : \n>>>"<<endl;
    cin>>nbtrapezes;
    cout<<"L'intégrale est de "<<trapeze(a,b,nbtrapezes)<<" pour un nombre de trapèzes égal à "<<nbtrapezes<<endl;
    cout<<"L'intégrale (théorique) est de "<<primitiveSinusPlusUn(b)-primitiveSinusPlusUn(a)<<endl;
    cout<<"L'erreur relative entre les deux méthodes est de : "<<abs(trapeze(a,b,nbtrapezes)-(primitiveSinusPlusUn(b)-primitiveSinusPlusUn(a)))<<endl;
    */
    //CALCUL SIN(X) AVEC SERIE DE TAYLOR
    cout<<"Calcul de sinus de x en utilisant la série de Taylor"<<endl;
    cout<<"Entrez la valeur de x : \n>>>"<<endl;
    cin>>x;
    cout<<"Sinus de "<<x<<" est égal à "<<sinusTaylor(x,epsilon)<<" en utilisant la série de Taylor"<<endl;
    cout<<"Sinus de "<<x<<" est égal à "<<sin(x)<<" en utilisant la fonction de C++"<<endl;
    cout<<"L'erreur moyenne est de"<<abs(sinusTaylor(x,epsilon) - sin(x))<<endl;
    return 0;
}

