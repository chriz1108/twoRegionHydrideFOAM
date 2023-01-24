//Info<< "Reading metalHydrideSettings" << endl;
IOdictionary metalHydrideSettings
(
    IOobject
    (
        "metalHydrideSettings",
        runTime.constant(),
        runTime,
        IOobject::MUST_READ,
        IOobject::NO_WRITE
    )
);

//Info<< "Reading hydrideMaterialConfig" << endl;
IOdictionary hydrideMaterialConfig
(
    IOobject
    (
        "hydrideMaterialConfig",
        runTime.constant(),
        runTime,
        IOobject::MUST_READ,
        IOobject::NO_WRITE
    )
);

// Reading Hydride Material Info from /constant folder
//Info<< "Reading Hydride Material" << endl;
const wordList hydrideMaterials(hydrideMaterialConfig.toc());
const word selectedHydrideMaterial(metalHydrideSettings.lookup("material"));
const word HydrogenSettings("H2");
//Info<< "Selected Hydride Material: " << selectedHydrideMaterial <<endl;
const dictionary& subDict = hydrideMaterialConfig.subDict(selectedHydrideMaterial);
const dictionary& hydrogenSubDict = hydrideMaterialConfig.subDict(HydrogenSettings);
//Info<< "Subdictionaries read!" <<endl;


//------------------------------------------------------

//Info<< "Reading deltaH_a" << endl;
dimensionedScalar deltaH_a
(
    subDict.lookup("deltaH_a")
);

//Info<< "Reading deltaH_d" << endl;
dimensionedScalar deltaH_d
(
    subDict.lookup("deltaH_d")
);

//Info<< "Reading deltaS_a " << endl;
dimensionedScalar deltaS_a
(
    subDict.lookup("deltaS_a")
);

//Info<< "Reading deltaS_d " << endl;
dimensionedScalar deltaS_d
(
    subDict.lookup("deltaS_d")
);

//Info<< "Reading M_hydrogen " << endl;
dimensionedScalar M_hydrogen
(
    hydrogenSubDict.lookup("M_hydrogen")
);

//Info<< "Reading cp_metal " << endl;
dimensionedScalar cp_metal
(
    subDict.lookup("cp_metal")
);

//Info<< "Reading cp_gas " << endl;
dimensionedScalar cp_gas
(
    hydrogenSubDict.lookup("cp_gas")
);

//Info<< "Reading cp_filter " << endl;
dimensionedScalar cp_filter
(
    hydrogenSubDict.lookup("cp_filter")
);

//Info<< "Reading E_a " << endl;
dimensionedScalar E_a
(
    subDict.lookup("E_a")
);

//Info<< "Reading E_d " << endl;
dimensionedScalar E_d
(
    subDict.lookup("E_d")
);

//Info<< "Reading p_ref " << endl;
dimensionedScalar p_ref
(
    hydrogenSubDict.lookup("p_ref")
);

//Info<< "Reading T_ref " << endl;
dimensionedScalar T_ref
(
    hydrogenSubDict.lookup("T_ref")
);

//Info<< "Reading R " << endl;
dimensionedScalar R
(
    hydrogenSubDict.lookup("R")
);

//Info<< "Reading maxHAbsorp " << endl;
dimensionedScalar maxHAbsorp
(
    subDict.lookup("maxHAbsorp")
);

//Info<< "Reading rho_empty " << endl;
dimensionedScalar rho_empty
(
    subDict.lookup("rho_empty")
);

//Info<< "Reading rho_filter " << endl;
dimensionedScalar rho_filter
(
    hydrogenSubDict.lookup("rho_filter")
);

//Info<< "Reading M_metal " << endl;
dimensionedScalar M_metal
(
    subDict.lookup("M_metal")
);

//Info<< "Reading lambda_metal " << endl;
dimensionedScalar lambda_metal
(
    subDict.lookup("lambda_metal")
);

//Info<< "Reading lambda_hydrogen " << endl;
dimensionedScalar lambda_hydrogen
(
    hydrogenSubDict.lookup("lambda_hydrogen")
);

//Info<< "Reading lambda_filter " << endl;
dimensionedScalar lambda_filter
(
    hydrogenSubDict.lookup("lambda_filter")
);

//Info<< "Reading K_perm " << endl;
dimensionedScalar K_perm
(
    subDict.lookup("K_perm")
);

//Info<< "Reading K_perm_hydrogen " << endl;
dimensionedScalar K_perm_hydrogen
(
    hydrogenSubDict.lookup("K_perm_hydrogen")
);

//Info<< "Reading p_eq_A " << endl;
dimensionedScalar p_eq_A
(
    metalHydrideSettings.lookup("p_eq_A")
);

//Info<< "Reading p_eq_B " << endl;
dimensionedScalar p_eq_B
(
    metalHydrideSettings.lookup("p_eq_B")
);

if (myDebugControl == 1)
{
    Info<< "--> Dictionaries Read Successful!" << endl;
    Info<< "-------------------------" << endl;
}
