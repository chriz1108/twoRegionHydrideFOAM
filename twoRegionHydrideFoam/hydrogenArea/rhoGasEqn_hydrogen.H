/*
	Gas Density Equation for H-Area
*/
	
rhoGas_hydrogen = M_hydrogen * p_hydrogen / (R*T_hydrogen);


if (myDebugControl == 1)
{
    Info<< "--> rhoGasEqn_hydrogen works!" << endl;
    Info<< "min(rhoGas_hydrogen) = " << Foam::min(rhoGas_hydrogen)  << endl;
    Info<< "max(rhoGas_hydrogen) = " << Foam::max(rhoGas_hydrogen)  << endl;
    Info<< "-------------------------" << endl;
}
