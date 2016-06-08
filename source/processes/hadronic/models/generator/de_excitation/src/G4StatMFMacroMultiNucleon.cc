#include "G4StatMFMacroMultiNucleon.hh"

// Default constructor
G4StatMFMacroMultiNucleon::
G4StatMFMacroMultiNucleon() :
G4VStatMFMacroCluster(0)  // Beacuse the def. constr. of base class is private
{
	G4Exception("G4StatMFMacroMultiNucleon::default_constructor meant to not be accessable");
}

// Copy constructor
G4StatMFMacroMultiNucleon::
G4StatMFMacroMultiNucleon(const G4StatMFMacroMultiNucleon & right) :
G4VStatMFMacroCluster(0)  // Beacuse the def. constr. of base class is private
{
	G4Exception("G4StatMFMacroMultiNucleon::copy_constructor meant to not be accessable");
}

// Operators

G4StatMFMacroMultiNucleon & G4StatMFMacroMultiNucleon::
operator=(const G4StatMFMacroMultiNucleon & right) 
{
	G4Exception("G4StatMFMacroMultiNucleon::operator= meant to not be accessable");
	return *this;
}


G4bool G4StatMFMacroMultiNucleon::operator==(const G4StatMFMacroMultiNucleon & right) const
{
	G4Exception("G4StatMFMacroMultiNucleon::operator== meant to not be accessable");
	return false;
}
 

G4bool G4StatMFMacroMultiNucleon::operator!=(const G4StatMFMacroMultiNucleon & right) const
{
	G4Exception("G4StatMFMacroMultiNucleon::operator!= meant to not be accessable");
	return true;
}



G4double G4StatMFMacroMultiNucleon::CalcMeanMultiplicity(const G4double FreeVol, const G4double mu,
																			const G4double nu, const G4double T)
{
	const G4double ThermalWaveLenght = 16.15*fermi/sqrt(T);
	
	const G4double lambda3 = ThermalWaveLenght*ThermalWaveLenght*ThermalWaveLenght;
	
	const G4double A23 = pow(theA,2./3.);
	
	const G4double Coulomb = (3./5.)*(elm_coupling/G4StatMFParameters::Getr0())*
									(1.0 - 1.0/pow(1.0+G4StatMFParameters::GetKappaCoulomb(),1./3.));
	
	G4double exponent = (mu + nu*theZARatio+ G4StatMFParameters::GetE0() + T*T/_InvLevelDensity 
							- G4StatMFParameters::GetGamma0()*(1.0 - 2.0*theZARatio)*(1.0 - 2.0*theZARatio))*theA
							- G4StatMFParameters::Beta(T)*A23 - Coulomb*theZARatio*theZARatio*A23*theA;
	
	exponent /= T;
	
	if (exponent > 30.0) exponent = 30.0;
	
	_MeanMultiplicity = G4std::max((FreeVol*G4double(theA)*sqrt(G4double(theA))/lambda3)*exp(exponent),1.0e-30);
	return _MeanMultiplicity;	
}


G4double G4StatMFMacroMultiNucleon::CalcZARatio(const G4double nu)
{
	const G4double Coulomb = (3./5.)*(elm_coupling/G4StatMFParameters::Getr0())*
									(1.0 - 1.0/pow(1.0+G4StatMFParameters::GetKappaCoulomb(),1./3.));

	G4double den = 8.0*G4StatMFParameters::GetGamma0()+2.0*Coulomb*pow(theA,2./3.);
	G4double num = 4.0*G4StatMFParameters::GetGamma0()+nu;
	
	return theZARatio = num/den;
	

}



G4double G4StatMFMacroMultiNucleon::CalcEnergy(const G4double T)
{
	const G4double Coulomb = (3./5.)*(elm_coupling/G4StatMFParameters::Getr0())*
									(1.0 - 1.0/pow(1.0+G4StatMFParameters::GetKappaCoulomb(),1./3.));
	
	const G4double A23 = pow(G4double(theA),2./3.);

	// Volume term 
	G4double EVol = G4double(theA) * (T*T/_InvLevelDensity - G4StatMFParameters::GetE0());
	
	// Symmetry term
//	G4double ESym = G4double(theA) * G4StatMFParameters::GetGamma0() *(1. - 2.* theZARatio * theZARatio);
	
	// Surface term
	G4double ESurf = A23*(G4StatMFParameters::Beta(T) - T*G4StatMFParameters::DBetaDT(T));
 
	// Coulomb term
	G4double ECoul = Coulomb*A23*G4double(theA)*theZARatio*theZARatio;
	
	// Translational term
	G4double ETrans = (3./2.)*T;
	
	
	return _Energy = EVol + ESurf + ECoul + ETrans; // + ESym; 
}


G4double G4StatMFMacroMultiNucleon::CalcEntropy(const G4double T, const G4double FreeVol)
{
	const G4double ThermalWaveLenght = 16.15*fermi/sqrt(T);
	const G4double lambda3 = ThermalWaveLenght*ThermalWaveLenght*ThermalWaveLenght;

	G4double Entropy = 0.0;
	if (_MeanMultiplicity > 0.0) {
		// Volume term
		G4double SV = 2.0*G4double(theA)*T/_InvLevelDensity;
		
		// Surface term
		G4double SS = -G4StatMFParameters::DBetaDT(T)*pow(G4double(theA),2./3.);
		
		// Translational term
		G4double ST = (5./2.)+log(FreeVol*sqrt(G4double(theA))*G4double(theA)/(lambda3*_MeanMultiplicity));
		
		
		Entropy = _MeanMultiplicity*(SV + SS + ST);
	}
								
								
	return Entropy;
}
