/*
	Gas Velocity Equation for H-Area
	Phi: Velocity Potential
*/

U_hydrogen = -K_perm_hydrogen/mu_g_hydrogen * fvc::grad(p_hydrogen);
phi_hydrogen = fvc::flux(U_hydrogen);


if (myDebugControl == 1)
{
    Info<< "--> UEqn_hydrogen works!" << endl;
    Info<< "min(U_hydrogen) = " << Foam::min(U_hydrogen)  << endl;
    Info<< "max(U_hydrogen) = " << Foam::max(U_hydrogen)  << endl;
    Info<< "min(phi_hydrogen) = " << Foam::min(phi_hydrogen)  << endl;
    Info<< "max(phi_hydrogen) = " << Foam::max(phi_hydrogen)  << endl;
    Info<< "-------------------------" << endl;
}
