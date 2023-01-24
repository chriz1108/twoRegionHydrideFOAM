//Info<< "\t------ Creating/Reading Metal Fields ------" << endl;


//Info<< "Reading field T" << endl;
volScalarField T
(
    IOobject
    (
        "T",
        runTime.timeName(),
        metalArea,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    metalArea
);

//Info<< "Reading field U" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        metalArea,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    metalArea
);

//Info<< "Creating field p" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        metalArea,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    metalArea
);

//Info<< "Reading field rhoMetal" << endl;
volScalarField rhoMetal
(
    IOobject
    (
        "rhoMetal",
        runTime.timeName(),
        metalArea,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    metalArea
);

//Info<< "Creating field rhoGas" << endl;
volScalarField rhoGas
(
    IOobject
    (
        "rhoGas",
        runTime.timeName(),
        metalArea,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    metalArea
);

//Info<< "Reading field epsilon" << endl;
volScalarField epsilon
(
    IOobject
    (
        "epsilon",
        runTime.timeName(),
        metalArea,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    ),
    metalArea,
    dimensionedScalar("epsilon", dimensionSet(0,0,0,0,0,0,0), subDict.lookup("epsilon"))
);

//Info<< "Creating field Sm_a" << endl;
volScalarField Sm_a
(
    IOobject
    (
        "Sm_a",
        runTime.timeName(),
        metalArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    metalArea,
    dimensionedScalar("Sm_a", dimensionSet(1,-3,-1,0,0,0,0), 0)
);

//Info<< "Creating field Sm_d" << endl;
volScalarField Sm_d
(
    IOobject
    (
        "Sm_d",
        runTime.timeName(),
        metalArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    metalArea,
    dimensionedScalar("Sm_d", dimensionSet(1,-3,-1,0,0,0,0), 0)
);

//Info<< "Creating field C_a" << endl;
volScalarField C_a
(
    IOobject
    (
        "C_a",
        runTime.timeName(),
        metalArea,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    metalArea,
    dimensionedScalar("C_a", dimensionSet(0,0,-1,0,0,0,0), subDict.lookup("C_a"))
);

//Info<< "Creating field C_d" << endl;
volScalarField C_d
(
    IOobject
    (
        "C_d",
        runTime.timeName(),
        metalArea,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    metalArea,
    dimensionedScalar("C_d", dimensionSet(0,0,-1,0,0,0,0), subDict.lookup("C_a"))
);

//Info<< "Reading field massPercentAbsorp" << endl;
volScalarField massPercentAbsorp
(
    IOobject
    (
        "massPercentAbsorp",
        runTime.timeName(),
        metalArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    metalArea,
    dimensionedScalar("massPercentAbsorp", dimensionSet(0,0,0,0,0,0,0), 0)
);

volScalarField massPercentAbsorp0
(
    IOobject
    (
        "massPercentAbsorp0",
        runTime.timeName(),
        metalArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    metalArea,
    dimensionedScalar("massPercentAbsorp0", dimensionSet(0,0,0,0,0,0,0), 0)
);

//Info<< "Creating field p_eq_a" << endl;
volScalarField p_eq_a
(
    IOobject
    (
        "p_eq_a",
        runTime.timeName(),
        metalArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    metalArea,
    dimensionedScalar("p_eq_a", dimensionSet(1,-1,-2,0,0,0,0), 0)
);

//Info<< "Creating field p_eq_d" << endl;
volScalarField p_eq_d
(
    IOobject
    (
        "p_eq_d",
        runTime.timeName(),
        metalArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    metalArea,
    dimensionedScalar("p_eq_d", dimensionSet(1,-1,-2,0,0,0,0), 0)
);



//Info<< "Creating field p_eq_ref" << endl;
volScalarField p_eq_ref
(
    IOobject
    (
        "p_eq_ref",
        runTime.timeName(),
        metalArea,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    metalArea,
    dimensionedScalar("p_eq_ref", dimensionSet(1,-1,-2,0,0,0,0), 0)
);


//Info<< "Creating field mu_g" << endl;
volScalarField mu_g
(
    IOobject
    (
        "mu_g",
        runTime.timeName(),
        metalArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    metalArea,
    dimensionedScalar("mu_g", dimensionSet(1,-1,-1,0,0,0,0), 0)
);

//Info<< "Creating field rhoCpEff" << endl;
volScalarField rhoCpEff
(
    IOobject
    (
        "rhoCpEff",
        runTime.timeName(),
        metalArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    metalArea,
    dimensionedScalar("rhoCpEff", dimensionSet(1,-1,-2,-1,0,0,0), 0)
);

//Info<< "Creating field lambda_Eff" << endl;
volScalarField lambda_Eff
(
    IOobject
    (
        "lambda_Eff",
        runTime.timeName(),
        metalArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    metalArea,
    dimensionedScalar("lambda_Eff", dimensionSet(1,1,-3,-1,0,0,0), 0)
);

//Info<< "Creating field absorptionAllowed" << endl;
volScalarField absorptionAllowed
(
    IOobject
    (
        "absorptionAllowed",
        runTime.timeName(),
        metalArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    metalArea,
    dimensionedScalar("absorptionAllowed", dimensionSet(0,0,0,0,0,0,0), 0)
);

//Info<< "Creating field desorptionAllowed" << endl;
volScalarField desorptionAllowed
(
    IOobject
    (
        "desorptionAllowed",
        runTime.timeName(),
        metalArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    metalArea,
    dimensionedScalar("desorptionAllowed", dimensionSet(0,0,0,0,0,0,0), 0)
);

//Info<< "Creating field conversion" << endl;
volScalarField conversion
(
    IOobject
    (
        "conversion",
        runTime.timeName(),
        metalArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    metalArea,
    dimensionedScalar("conversion", dimensionSet(0,0,0,0,0,0,0), 0)
);

//Info<< "Creating field H/M (HMRatio)" << endl;
volScalarField HMRatio
(
    IOobject
    (
        "HMRatio",
        runTime.timeName(),
        metalArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    metalArea,
    dimensionedScalar("HMRatio", dimensionSet(0,0,0,0,0,0,0), 0)
);

volScalarField calcHelp_abs
(
    IOobject
    (
        "calcHelp_abs",
        runTime.timeName(),
        metalArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    metalArea,
    dimensionedScalar("calcHelp_abs", dimensionSet(0,0,0,0,0,0,0), 0)
);

volScalarField calcHelp_des
(
    IOobject
    (
        "calcHelp_des",
        runTime.timeName(),
        metalArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    metalArea,
    dimensionedScalar("calcHelp_des", dimensionSet(0,0,0,0,0,0,0), 0)
);

surfaceScalarField phi
(
    IOobject
    (
        "phi",
        runTime.timeName(),
        metalArea,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    fvc::flux(U)
);

//Info<< "Reading myDebugControl" << endl;
const scalar myDebugControl(metalHydrideSettings.lookup<scalar>("myDebugControl"));

// Equilibrium Pressure Equation
//Info<< "Reading peq_control" << endl;
const scalar peq_control(metalHydrideSettings.lookup<scalar>("peq_control"));

if (peq_control == 0)
{
    Info<< "----------------------------------------------" << endl;
    Info<< "\tVAN'T HOFF Equilibrium Pressure calculation selected" << endl;
    Info<< "----------------------------------------------" << endl;
}
else if (peq_control == 1)
{
    Info<< "----------------------------------------------" << endl;
    Info<< "\tLaNi5 Equilibrium Pressure calculation selected" << endl;
    Info<< "----------------------------------------------" << endl;
}
else if (peq_control == 2)
{
    Info<< "----------------------------------------------" << endl;
    Info<< "\tHydralloy Equilibrium Pressure calculation selected" << endl;
    Info<< "----------------------------------------------" << endl;
}
else if (peq_control == 3)
{
    Info<< "----------------------------------------------" << endl;
    Info<< "\tVAN'T HOFF AB Equilibrium Pressure calculation selected" << endl;
    Info<< "----------------------------------------------" << endl;
}
else
{
    Info<< "----------------------------------------------" << endl;
    Info<< "\tNO Equilibrium Pressure calculation selected" << endl;
    Info<< "----------------------------------------------" << endl;
    abort();
}
