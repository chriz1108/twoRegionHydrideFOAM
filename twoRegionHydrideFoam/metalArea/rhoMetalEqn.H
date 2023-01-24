/*
	MH-Density Equation
*/

fvScalarMatrix rhoMetalEqn
(
    (1-epsilon)
    * fvm::ddt(rhoMetal)
 ==
    Sm_a * absorptionAllowed
  + Sm_d * desorptionAllowed
);

rhoMetalEqn.solve();


if (myDebugControl == 1)
{
    Info<< "--> rhoMetalEqn works!" << endl;
    Info<< "min(rhoMetal) = " << Foam::min(rhoMetal)  << endl;
    Info<< "max(rhoMetal) = " << Foam::max(rhoMetal)  << endl;
    Info<< "-------------------------" << endl;
}
