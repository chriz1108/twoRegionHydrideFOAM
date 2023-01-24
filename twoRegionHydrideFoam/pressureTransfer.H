/*
	Transfer pressure mesh to mesh by iterating over all faces belonging to metalToHydrogenPatch
	and writing the pressure of the hydrogen mesh into the boundary of the metal mesh. By this,
	the pressure propagation can be simplified and is done in a fast manner.
*/
forAll (metalToHydrogenPatch, facei)
{
    // get cellID of the cell to which [facei] belongs
    label IDCellHydrogen = patchCellsHydrogenToMetalPatch[facei];

	/*
		Set the boundary field value of opposite faces to the value of the cell-center of the cellIDs cell.
		(Hydrogen mesh dictates pressure)
	*/
	p_hydrogen.boundaryFieldRef()[hydrogenToMetalPatchID][facei]
      = p_hydrogen[IDCellHydrogen];
    p.boundaryFieldRef()[metalToHydrogenPatchID][facei]
      = p_hydrogen[IDCellHydrogen];
}


if (myDebugControl == 1)
{
    Info<< "--> Pressure Communication Successful" << endl;
    Info<< "-------------------------" << endl;
}
