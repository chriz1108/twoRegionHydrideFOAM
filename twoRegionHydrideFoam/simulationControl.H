/*
	Determine whether absorption/desorption/no reaction happens
	and set variables accordingly.
*/

// iterate over all cells and check their pressure
forAll(p, i)
{
    // absorption
    if (p[i] > p_eq_a[i])
    {
        calcHelp_abs[i] = Foam::log(p[i] / p_eq_a[i]);
        calcHelp_des[i] = 0;
        absorptionAllowed[i] = 1;
        desorptionAllowed[i] = 0;
    }
    //desorption
    else if (p[i] < p_eq_d[i])
    {
        calcHelp_des[i] = ((p[i] - p_eq_d[i])/p_eq_d[i]);
        calcHelp_abs[i] = 0;
        absorptionAllowed[i] = 0;
        desorptionAllowed[i] = 1;
    }
	// no reaction
    else
    {
        absorptionAllowed[i] = 0;
        desorptionAllowed[i] = 0;
        calcHelp_abs[i] = 0;
        calcHelp_des[i] = 0;
    }
}

// source term definition
Sm_a =  C_a
      * Foam::exp(-E_a/(R*T))
      * calcHelp_abs
      * (rho_sat - rhoMetal);

Sm_d =  C_d
      * Foam::exp(-E_d/(R*T))
      * calcHelp_des
      * (rhoMetal - rho_empty);


if (myDebugControl == 1)
{
    Info<< "--> SimulationControl Successful!" << endl;
    Info<< "-------------------------" << endl;
}
