/*
	Gas Density Equation for Metal-Area
*/

rhoGas = M_hydrogen * p / (R*T);


if (myDebugControl == 1)
{
    Info<< "--> rhoGasEqn_hydride works!" << endl;
    Info<< "min(rhoGas) = " << Foam::min(rhoGas)  << endl;
    Info<< "max(rhoGas) = " << Foam::max(rhoGas)  << endl;
    Info<< "-------------------------" << endl;
}
