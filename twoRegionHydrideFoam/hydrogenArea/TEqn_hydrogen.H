/*
	Energy Equation for H-Area
*/

fvScalarMatrix TEqn_hydrogen
(
	 fvm::ddt(rhoCpEff_hydrogen,T_hydrogen)
	+ rhoGas_hydrogen*cp_gas
     * fvm::div(phi_hydrogen,T_hydrogen)
  ==
     fvm::laplacian(lambda_Eff_hydrogen, T_hydrogen)
);

TEqn_hydrogen.solve();



if (myDebugControl == 1)
{
    Info<< "--> TEqn_hydrogen works!" << endl;
    Info<< "min(T_hydrogen) = " << Foam::min(T_hydrogen)  << endl;
    Info<< "max(T_hydrogen) = " << Foam::max(T_hydrogen)  << endl;
    Info<< "-------------------------" << endl;
}
