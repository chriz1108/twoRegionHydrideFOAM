/*
	Energy Equation for MH-Area
	Source term is dependent on MH
*/

fvScalarMatrix TEqn
(
fvm::ddt(rhoCpEff,T)
  + rhoGas*cp_gas * fvm::div(phi,T)
 ==
    fvm::laplacian(k_Eff, T)
  + (
	(selectedHydrideMaterial == "LaNi5" || selectedHydrideMaterial == "MmNiAl")
    ? (Sm_a * absorptionAllowed * (deltaH_a/M_hydrogen)
		+ Sm_d * desorptionAllowed * (deltaH_d/M_hydrogen)
	  )
    : (Sm_a * absorptionAllowed * ((deltaH_a/M_hydrogen) - T * (cp_gas - cp_metal))
		+ Sm_d * desorptionAllowed * ((deltaH_d/M_hydrogen) - T * (cp_gas - cp_metal))
	  )
    )
);

TEqn.solve();


if (myDebugControl == 1)
{
    Info<< "--> TEqn_hydride works!" << endl;
    Info<< "min(T) = " << Foam::min(T)  << endl;
    Info<< "max(T) = " << Foam::max(T)  << endl;
    Info<< "-------------------------" << endl;
}
