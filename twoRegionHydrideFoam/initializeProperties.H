/*
	peq equation values: HydralloyC5; _a: absorption, _d: desorption
	source: Herbrig
*/
scalar alpha_a = 0.5;
scalar a1_a = -4.884;
scalar a2_a = -2374.7;
scalar a3_a = 3.4129e-3;
scalar a4_a = 48.816;
scalar a5_a = -50.404;
scalar a6_a = 22.711;
scalar a7_a = -7.9717;
scalar a8_a = 1.233;
scalar b1_a = -452.34;
scalar b2_a = 15.522;
scalar b3_a = 4.0954;
scalar b4_a = -1.3222e-2;
scalar b5_a = 1.4406e-5;

scalar alpha_d = -0.3;
scalar a1_d = 30.225;
scalar a2_d = -3312.9;
scalar a4_d = -10.078;
scalar a5_d = -14.603;
scalar a6_d = 12.889;
scalar a7_d = -6.7934;
scalar a8_d = 1.5872;
scalar b1_d = -59.282;
scalar b2_d = -4.7339;
scalar b3_d = 0.13922;
scalar b6_d = 4743.7;

/*
	peq equation values: LaNi5; _a: absorption, _d: desorption
	source: Busque / Dhaou
*/
scalar a0_LaNi_a = -0.34863;
scalar a1_LaNi_a = 10.1059;
scalar a2_LaNi_a = -14.2442;
scalar a3_LaNi_a = 10.3535;
scalar a4_LaNi_a = -4.20646;
scalar a5_LaNi_a = 0.962371;
scalar a6_LaNi_a = -0.115468;
scalar a7_LaNi_a = 0.00563776;

scalar a0_LaNi_d = 0.421;
scalar a1_LaNi_d = -4.114;
scalar a2_LaNi_d = 14.18;
scalar a3_LaNi_d = -13.109;
scalar a4_LaNi_d = 4.557;
scalar a5_LaNi_d = 0.166;
scalar a6_LaNi_d = -0.592;
scalar a7_LaNi_d = 0.179;
scalar a8_LaNi_d = -0.023;
scalar a9_LaNi_d = 1.126e-3;
//-----------------------------------------------------------------------------


/*
	Corrector Values
	This is necessary to remove or add the dimension in some equations.
*/
dimensionedScalar correctorPressure ("correctorPressure", dimensionSet(1,-1,-2,0,0,0,0), 1.0);
dimensionedScalar correctorTemperature("correctorTemperature", dimensionSet(0,0,0,1,0,0,0), 1.0);
dimensionedScalar correctorMu("correctorMu", dimensionSet(1,-1,-1,0,0,0,0), 1.0);
//-----------------------------------------------------------------------------


/*
	Initialize Variable Values
	Setting up starting values of scalars and perform one-time calculations
*/
dimensionedScalar rho_sat ("rho_sat", dimensionSet(1,-3,0,0,0,0,0), 0.0);
rho_sat.value() = floor(rho_empty.value() * (1+maxHAbsorp.value()/100));
lambda_Eff = epsilon*lambda_hydrogen + (1-epsilon)*lambda_metal;
lambda_Eff_hydrogen = epsilon_filter*lambda_hydrogen + (1-epsilon_filter)*lambda_filter;
//-----------------------------------------------------------------------------


/*
	Initialize Field Values
	Setting up starting values of fields
*/
rhoGas_hydrogen = M_hydrogen * p_hydrogen / (R*T_hydrogen);
rhoGas = M_hydrogen * p / (R*T);

mu_g = 9.05e-6 * Foam::pow(T/(293*correctorTemperature),0.68) * correctorMu;
rhoCpEff = (1-epsilon)*rhoMetal*cp_metal + epsilon*rhoGas*cp_gas;

mu_g_hydrogen = 9.05e-6 * Foam::pow(T_hydrogen/(293*correctorTemperature),0.68) * correctorMu;
rhoCpEff_hydrogen = (1-epsilon_filter)*rho_filter*cp_filter + epsilon_filter*rhoGas_hydrogen*cp_gas;
//-----------------------------------------------------------------------------


// define start value of massPercentAbsorp
massPercentAbsorp0 = ((rhoMetal - rho_empty)/rho_empty)*100;
