/*
	Calculate the amount of hydrogen absorbed / desorbed wt.-% (massPercentAbsorp) and the conversion.
	If LaNi5 is simulated, calculate the ratio of H to M atoms.
*/
massPercentAbsorp = ((rhoMetal - rho_empty)/rho_empty)*100;
conversion = (massPercentAbsorp-massPercentAbsorp0)/(maxHAbsorp-massPercentAbsorp0);

if (selectedHydrideMaterial == "LaNi5")
{
    HMRatio = (2*(rhoMetal-rho_empty)/M_hydrogen)/(rho_empty/M_metal);
}

if (myDebugControl == 1)
{
    Info<< "--> massPercentEqn works!" << endl;
    Info<< "min(massPercentAbsorp) = " << Foam::min(massPercentAbsorp)  << endl;
    Info<< "max(massPercentAbsorp) = " << Foam::max(massPercentAbsorp)  << endl;
    Info<< "-------------------------" << endl;
}
