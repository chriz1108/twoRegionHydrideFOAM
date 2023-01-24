/*
	Gas Velocity Equation for MH-Area
	Phi: Velocity Potential
*/

U = -K_perm/mu_g*fvc::grad(p);
phi = fvc::flux(U);

if (myDebugControl == 1)
{
    Info<< "--> UEqn_hydride works!" << endl;
    Info<< "min(U) = " << Foam::min(U)  << endl;
    Info<< "max(U) = " << Foam::max(U)  << endl;
    Info<< "min(phi) = " << Foam::min(phi)  << endl;
    Info<< "max(phi) = " << Foam::max(phi)  << endl;
    Info<< "-------------------------" << endl;
}
