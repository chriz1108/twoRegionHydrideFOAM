//Info<< "\t------ Creating/Reading Hydrogen Fields ------" << endl;

//Info<< "Reading field T_hydrogen" << endl;
volScalarField T_hydrogen
(
    IOobject
    (
        "T",
        runTime.timeName(),
        hydrogenArea,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    hydrogenArea
);

//Info<< "Reading field U_hydrogen" << endl;
volVectorField U_hydrogen
(
    IOobject
    (
        "U",
        runTime.timeName(),
        hydrogenArea,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    hydrogenArea
);

//Info<< "Creating field p_hydrogen" << endl;
volScalarField p_hydrogen
(
    IOobject
    (
        "p",
        runTime.timeName(),
        hydrogenArea,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    hydrogenArea
);

//Info<< "Creating field rhoGas_hydrogen" << endl;
volScalarField rhoGas_hydrogen
(
    IOobject
    (
        "rhoGas",
        runTime.timeName(),
        hydrogenArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    hydrogenArea,
    dimensionedScalar("rhoGas_hydrogen", dimensionSet(1,-3,0,0,0,0,0), 0)
);

//Info<< "Reading field epsilon" << endl;
volScalarField epsilon_filter
(
    IOobject
    (
        "epsilon_filter",
        runTime.timeName(),
        hydrogenArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    hydrogenArea,
    dimensionedScalar("epsilon_filter", dimensionSet(0,0,0,0,0,0,0), hydrogenSubDict.lookup("epsilon_filter"))
);

//Info<< "Creating field mu_g_hydrogen" << endl;
volScalarField mu_g_hydrogen
(
    IOobject
    (
        "mu_g",
        runTime.timeName(),
        hydrogenArea,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    hydrogenArea,
    dimensionedScalar("mu_g_hydrogen", dimensionSet(1,-1,-1,0,0,0,0), 0)
);

//Info<< "Creating field rhoCpEff_hydrogen" << endl;
volScalarField rhoCpEff_hydrogen
(
    IOobject
    (
        "rhoCpEff_hydrogen",
        runTime.timeName(),
        hydrogenArea,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    hydrogenArea,
    dimensionedScalar("rhoCpEff_hydrogen", dimensionSet(1,-1,-2,-1,0,0,0), 0)
);

//Info<< "Creating field k_Eff_hydrogen" << endl;
volScalarField k_Eff_hydrogen
(
    IOobject
    (
        "k_Eff_hydrogen",
        runTime.timeName(),
        hydrogenArea,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    hydrogenArea,
    dimensionedScalar("k_Eff_hydrogen", dimensionSet(1,1,-3,-1,0,0,0), 0)
);

//------------------------------------------------------

surfaceScalarField phi_hydrogen
(
    IOobject
    (
        "phi",
        runTime.timeName(),
        hydrogenArea,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    fvc::flux(U_hydrogen)
);
