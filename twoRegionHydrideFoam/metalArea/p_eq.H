/*
	Equilibrium Pressure Equations
	Defined by the user in "/constant/metalHydrideSettings"	
*/


// Vant-Hoff
if (peq_control == 0)
{
    p_eq_a = p_ref * Foam::exp(-deltaH_a/(R*T) + deltaS_a/R);
    p_eq_d = p_ref * Foam::exp(-deltaH_d/(R*T) + deltaS_d/R);
}

// LaNi5
else if (peq_control == 1)
{
    // absorption
    p_eq_a =   (  a0_LaNi_a
                + a1_LaNi_a*HMRatio
                + a2_LaNi_a*Foam::pow(HMRatio,2)
                + a3_LaNi_a*Foam::pow(HMRatio,3)
                + a4_LaNi_a*Foam::pow(HMRatio,4)
                + a5_LaNi_a*Foam::pow(HMRatio,5)
                + a6_LaNi_a*Foam::pow(HMRatio,6)
                + a7_LaNi_a*Foam::pow(HMRatio,7))
                * correctorPressure * 1e5
                * Foam::exp((-deltaH_a/R)*(1/T - 1/T_ref));

    // desorption
    p_eq_d =    ( a0_LaNi_d
                + a1_LaNi_d*HMRatio
                + a2_LaNi_d*Foam::pow(HMRatio,2)
                + a3_LaNi_d*Foam::pow(HMRatio,3)
                + a4_LaNi_d*Foam::pow(HMRatio,4)
                + a5_LaNi_d*Foam::pow(HMRatio,5)
                + a6_LaNi_d*Foam::pow(HMRatio,6)
                + a7_LaNi_d*Foam::pow(HMRatio,7)
                + a8_LaNi_d*Foam::pow(HMRatio,8)
                + a9_LaNi_d*Foam::pow(HMRatio,9))
                * correctorPressure * 1e5
                * Foam::exp((-deltaH_d/R)*(1/T - 1/T_ref));
}

// Hydralloy C5
else if (peq_control == 2)
{
    forAll(p, i)
    {
        // absorption
        p_eq_a[i] = p_ref.value() * (Foam::exp(a1_a
                                  + a2_a/T[i]
                                  + a3_a*T[i]
                                  + a4_a*Foam::pow(massPercentAbsorp[i], alpha_a)
                                  + a5_a*massPercentAbsorp[i]
                                  + a6_a*Foam::pow(massPercentAbsorp[i],2)
                                  + a7_a*Foam::pow(massPercentAbsorp[i],3)
                                  + a8_a*Foam::pow(massPercentAbsorp[i],4)
                                  )
                        + Foam::exp(b1_a
                                  + b2_a*massPercentAbsorp[i]
                                  + b3_a*T[i]
                                  + b4_a*Foam::pow(T[i],2)
                                  + b5_a*Foam::pow(T[i],3)
                                 )
                        );

        // desorption
        p_eq_d[i] = p_ref.value() * (Foam::exp(a1_d
                                  + a2_d/T[i]
                                  + a4_d*Foam::pow(massPercentAbsorp[i], alpha_d)
                                  + a5_d*massPercentAbsorp[i]
                                  + a6_d*Foam::pow(massPercentAbsorp[i], 2)
                                  + a7_d*Foam::pow(massPercentAbsorp[i], 3)
                                  + a8_d*Foam::pow(massPercentAbsorp[i], 4)
                                  )
                        + Foam::exp(b1_d
                                  + b2_d*massPercentAbsorp[i]
                                  + b3_d*T[i]
                                  + b6_d*massPercentAbsorp[i]/T[i]
                                  )
                        );
    }
}

// simplified VantHoff-AB
else if (peq_control == 3)
{
    p_eq_a = p_ref * Foam::exp(p_eq_A - (p_eq_B*correctorTemperature)/T);
    p_eq_d = p_ref * Foam::exp(p_eq_A - (p_eq_B*correctorTemperature)/T);
}

if (myDebugControl == 1)
{
    Info<< "--> peqEqn works!" << endl;
    Info<< "min(p_eq_a) = " << Foam::min(p_eq_a)  << endl;
    Info<< "max(p_eq_a) = " << Foam::max(p_eq_a)  << endl;
    Info<< "min(p_eq_d) = " << Foam::min(p_eq_d)  << endl;
    Info<< "max(p_eq_d) = " << Foam::max(p_eq_d)  << endl;
    Info<< "-------------------------" << endl;

}
