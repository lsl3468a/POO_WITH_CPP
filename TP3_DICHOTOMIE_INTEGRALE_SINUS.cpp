#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void sinusCardinal(float x, float &f){
    if(x==0.0){
        f = 3.0;
    } else {
        f= 3*(sin(x)/x);
    }
}

void dichotomie(float a, float b, float precision, float &zero, int &nbiterations){
    float m ; //milieu de l'intervalle
    float fa, fb, fm;
    sinusCardinal(a, fa);
    sinusCardinal(b, fb);
    
    while(abs(b-a) > precision){
        m = abs(a+b)/2;
        sinusCardinal(m, fm);
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

void sinusPlusUn(float x, float &f){
    f = sin(x)+1;
}

void primitiveSinusPlusUn(float x, float &f){
    f=-cos(x)+x;
}

void trapeze(float a, float b, int nbtrapezes, float &res){
    float largeur = (b - a) /nbtrapezes;
    float fa, fb;
    int n;
    sinusPlusUn(a, fa);
    sinusPlusUn(b, fb);
    float aire = fa/2 + fb/2;
    for(n=1; n<nbtrapezes; n++){
        sinusPlusUn(a + n * largeur, fa);
        aire += fa;
    }
    res = largeur * aire;
    
}

float puissance(float a,int b)  
{
    return pow(a,b);
}

float factorielle(float a) //Calcule la factorielle d'un nombre
{
    float i;
    float fact = 1;
    for(i=1; i<=a; i++){
        fact = fact * i;
    }
    return fact;
}

void sinusTaylor(float x, float precision, float &res){
    float sinus = x ;
    int n =1 ,a = 1, b = 1;
    do {
        a = puissance(-1,n);
        b = 2*n+1;
        if(a<0){
            sinus -= (puissance(x,b)/factorielle(b));
        } else {
            sinus += (puissance(x,b)/factorielle(b));
        }
        
        n++;
    } while(fabs(sinus-sin(x)) >= precision);
    res = sinus;
}

int main() {
    float epsilon = 0.1;
    float a,b,zero,x,f = 0;
    int nb, nbtrapezes;
    float res, primA, primB;
    
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
    trapeze(a,b,nbtrapezes, res);
    primitiveSinusPlusUn(a, primA);
    primitiveSinusPlusUn(b,primB);
    cout<<"L'intégrale est de "<<res<<" pour un nombre de trapèzes égal à "<<nbtrapezes<<endl;
    cout<<"L'intégrale (théorique) est de "<<primB-primA<<endl;
    cout<<"L'erreur relative entre les deux méthodes est de : "<<abs(res-(primB - primA))<<endl;
    
    //CALCUL SIN(X) AVEC SERIE DE TAYLOR
    cout<<"Calcul de sinus de x en utilisant la série de Taylor"<<endl;
    cout<<"Entrez la valeur de x : \n>>>"<<endl;
    cin>>x;
    sinusTaylor(x,epsilon, res);
    cout<<"Sinus de "<<x<<" est égal à "<<res<<" en utilisant la série de Taylor"<<endl;
    cout<<"Sinus de "<<x<<" est égal à "<<sin(x)<<" en utilisant la fonction de C++"<<endl;
    cout<<"L'erreur moyenne est de "<<abs(res - sin(x))<<endl;
    return 0;
}

