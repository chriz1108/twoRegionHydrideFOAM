/*
	Pressure Equation for H-Area
*/

fvScalarMatrix pEqn_hydrogen
(
    epsilon_filter*M_hydrogen/(R*T_hydrogen)
    *(
        fvm::ddt(p_hydrogen)
      - p_hydrogen/T_hydrogen * fvc::ddt(T_hydrogen)
    )
  ==
    K_perm_hydrogen/mu_g_hydrogen 
    * fvm::laplacian(rhoGas_hydrogen, p_hydrogen)
);

pEqn_hydrogen.solve();



if (myDebugControl == 1)
{
    Info<< "--> pEqn works!" << endl;
    Info<< "min(p_hydrogen) = " << Foam::min(p_hydrogen)  << endl;
    Info<< "max(p_hydrogen) = " << Foam::max(p_hydrogen)  << endl;
    Info<< "-------------------------" << endl;
}
