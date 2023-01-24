/*
	Update coefficients
	Update effective heat capacity and viscosity for all cells
*/

rhoCpEff = (1-epsilon)*rhoMetal*cp_metal + epsilon*rhoGas*cp_gas;
rhoCpEff_hydrogen = (1-epsilon_filter)*rho_filter*cp_filter + epsilon_filter*rhoGas_hydrogen*cp_gas;
mu_g = 9.05e-6 * Foam::pow(T/(293*correctorTemperature),0.68) * correctorMu;
mu_g_hydrogen = 9.05e-6 * Foam::pow(T_hydrogen/(293*correctorTemperature),0.68) * correctorMu;


if (myDebugControl == 1)
{
    Info<< "--> updateCoefficients Successful!" << endl;
    Info<< "-------------------------" << endl;
}
