/*
	Pressure Equation for MH-Area
*/

fvScalarMatrix pEqn
(
    epsilon*M_hydrogen/(R*T)
    *(
        fvm::ddt(p)
      - p/T * fvc::ddt(T)
    )
  ==
    K_perm/mu_g * fvm::laplacian(rhoGas, p)
  - Sm_a * absorptionAllowed
  - Sm_d * desorptionAllowed
);
pEqn.solve();


if (myDebugControl == 1)
{
    Info<< "--> pEqn works!" << endl;
    Info<< "min(p) = " << Foam::min(p)  << endl;
    Info<< "max(p) = " << Foam::max(p)  << endl;
    Info<< "-------------------------" << endl;
}
