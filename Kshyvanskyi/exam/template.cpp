#include<iostream>
#include <string>
using namespace std;
template <typename T>

class SomeParticle{
private:
  string particle_name;
  T p_mass;
  T p_pT;
  
public:
  SomeParticle(): particle_name("electron"), p_mass(0.511), p_pT(345){}
  SomeParticle(string n, T m, T e, T p):
          particle_name(n), p_mass(m), p_pT(p) {}

  T GetMass() {return p_mass;}
  T GetPT() {return p_pT;}
  string GetName() {return particle_name;}

  void setMass(T m) {p_mass = m;}
  void setPT(T p) {p_pT = p;}
  void setName(T n) {particle_name = n;}

};

int main(){
  SomeParticle<double> electron;
  cout <<"INFO on " << electron.GetName() <<" particle" <<endl;
  cout<<"Mass : " << electron.GetMass() << " MeV" << endl;
  cout<< "Transverse Momentum : "<<electron.GetPT()<< " MeV"  << endl;
  cout<<"END" << endl<< endl;
}
