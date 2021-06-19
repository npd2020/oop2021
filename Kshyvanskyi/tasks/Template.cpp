#include<iostream>
#include <string>
using namespace std;

template <typename T>

class SomeParticle{
private:
	string name;
	T mass;
	T eta;
	T pT;
  
public:
	SomeParticle(): name("Electron"), mass(0.511), eta(1.37), pT(200) {}
	SomeParticle(string n, T m, T e, T p):
		name(n), mass(m), eta(e), pT(p) {}

	T GetMass() {return mass;}
	T GetPT() {return pT;}
	T GetEta() {return eta;}
	string GetName() {return name;}

	void setMass(T m) {mass = m;}
	void setPT(T p) {pT = p;}
	void setEta(T e) {eta = e;}
	void setName(T n) {name = n;}
};


int main(){
	SomeParticle<float> muon("Muon", 105.6, 1.52, 100);
	cout <<"Name: " << muon.GetName() << endl;
	cout<<"Mass, MeV: " << muon.GetMass() << endl;
	cout<<"Pseudorapidity: " << muon.GetEta() << endl;
	cout<< "Transverse Momentum, MeV: "<<muon.GetPT() << endl;

	SomeParticle<double> electron;
	cout <<"Name: " << electron.GetName() << endl;
	cout<<"Mass, MeV: " << electron.GetMass() << endl;
	cout<<"Pseudorapidity: " << electron.GetEta() << endl;
	cout<< "Transverse Momentum, MeV: "<<electron.GetPT() << endl;
}
