//
//  main.cpp
//  Home8

//

#include<cmath>
#include<fstream>
#include<iostream>

using namespace std;
void Hamilton(const double p1,const double p2,const double q1,const double q2,double H);
// bei der Wahl von p/q ist bestimmt was falsch...
int main(){
    const double dt = 0.0005;
    const double e=0.5;
    const double tEnd = 20*M_PI;
    const int N = int (tEnd/dt);
    double t =0;
    double q1, q2, p1, p2, H;
    
    
    q1 = 1-e; q2 = 0; p1 = 0; p2 = sqrt((1+e)/(1-e)); // Anfangsbeingungen
    Hamilton(p1, p2, q1, q2, H);
    
    ofstream out(" keppler.txt");
    out << 0 << "\t" << q1 << "\t"<< q2 << "\t"<< p1 << "\t"<< p2 << "\t"<< H << endl;
    
    // nach dem ersten Durchgang hier weiter mit der Hamilton Fkt Vorschleife..
    // Zeit muss weiter gehen und die p/q`s
    
    for (int i=0; 1<N; i++){
        t += i*dt;
        p1 -= dt* pow(q1*q1+q2*q2,-3.0/2)*q1;
        p2 -= dt* pow(q1*q1+q2*q2,-3.0/2)*q2;
        q1 += q1 + dt*p1;
        q2 += q2 + dt*p2; // Ableitungen berechnen
        
        Hamilton(p1, p2, q1, q2, H); // Unterfunktion mit den weiterlaufenden Werten berchnen und anzeigen lassen
        
        out << dt*i << "\t" << q1<< "\t"<< q2 << "\t"<< p1 << "\t"<< p2 << "\t"<< H << endl;
        
        out.close();
    }
    return 0;
    
}
void Hamilton(const double p1,const double p2,const double q1,const double q2,double H){
    
    H = 0.5*(p1*p1+p2*p2)-(1/sqrt(q1*q1+q2*q2));
}