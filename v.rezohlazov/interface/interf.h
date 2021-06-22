#pragma once
#include <string>
#include <vector>

template <typename T>
class IParticleDefinition {
protected:
  std::string m_name;
  T m_mass;
  T m_P;
  T m_E;

public:
  virtual std::string getName() { return m_name; }
  virtual ~IParticleDefinition() {};
  virtual T getE() = 0;
};

class Electron : public IParticleDefinition<T> {
private:
  T m_electric_charge;
  T m_spin;
  std::string m_family;
public:
  Electron(double P) :
      m_electric_charge(-1.), m_spin (0.5), m_family("lepton") {
    this->m_name = "electron";
    this->m_mass = 0.511;
    this->m_P = P;
  }

  ~Electron() {}

  T getE() {
    return sqrt(this->m_P*this->m_P * CONST::с2 + this->m_mass * this->m_mass * CONST::с2);
  }
};
