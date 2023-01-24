/*  loop over faces of patch (both patches have same number of faces
    -> only one loop needed) */
forAll (metalToHydrogenPatch, facei)
{
    // get cell IDs of cells adjacent to patch
    // label IDCellHydride = patchCellsHydrideToHydrogenPatch[facei];
    label IDCellHydrogen = patchCellsHydrogenToMetalPatch[facei];

    T.boundaryFieldRef()[metalToHydrogenPatchID][facei]
      = T_hydrogen[IDCellHydrogen];
}


if (myDebugControl == 1)
{
    Info<< "--> T_toHydrogen Coupling Successful!" << endl;
    Info<< "-------------------------" << endl;
}
