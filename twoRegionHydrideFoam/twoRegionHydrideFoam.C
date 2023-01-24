/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2022 Christoph Ulrich
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is NOT part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    metalHydrideFoam

Description
    Solves the transient absorption/desorption of hydrogen into/from a metal hydride powder.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "simpleControl.H"
#include "fvOptions.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "setRootCaseLists.H"
    #include "createTime.H"

	// Define Meshes created by blockMesh
    Info<< "Creating Meshes" << endl;
    #include "createMeshes.H"

	// Read configuration files located in /constant folder
    Info<< "Read Dictionaries" << endl;
    #include "readDictionaries.H"

	// Create field variables for each mesh
    Info<< "Creating/Reading Fields" << endl;
    #include "createHydrogenFields.H"
    #include "createMetalFields.H"

	// collect cell-faces and connecting patches for transfer of variable values between meshes
    #include "collectFaces.H"

	// Initialize variables and define polynomial coefficients
	Info<< "Initializing metal hydride properties" << endl;
    #include "initializeProperties.H"

    if (myDebugControl == 1)
    {
        Info<< "\n\n#################################" << endl;
        Info<< "\tDEBUG ACTIVE" << endl;
        Info<< "\tDEBUG ACTIVE" << endl;
        Info<< "\tDEBUG ACTIVE" << endl;
        Info<< "\tDEBUG ACTIVE" << endl;
        Info<< "#################################\n\n" << endl;
    }

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    while (runTime.loop())
    {
        Info<< "\nTime = " << runTime.timeName() << endl;

        // Transfer pressure mesh to mesh
        #include "pressureTransfer.H"

        // Metal Area ---------------------------------
        #include "massPercentEqn.H"
        #include "p_eq.H"
        #include "simulationControl.H"
        #include "pEqn_metal.H"
        #include "rhoGasEqn_metal.H"
        #include "UEqn_metal.H"
        #include "rhoMetalEqn.H"

        // Hydrogen Area --------------------------------
        #include "pEqn_hydrogen.H"
        #include "rhoGasEqn_hydrogen.H"
        #include "UEqn_hydrogen.H"

        // Misc. ----------------------------------------
        #include "updateCoefficients.H"

        // Temperatures ---------------------------------
        #include "TEqn_metal.H"
        #include "T_toHydrogen.H"

        #include "TEqn_hydrogen.H"
        #include "T_toMetal.H"


        runTime.write();
        Info << "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
            << "  ClockTime = " << runTime.elapsedClockTime() << " s"
            << nl << endl;
    }

    Info<< "End\n" << endl;

    return 0;
}

// ************************************************************************* //
