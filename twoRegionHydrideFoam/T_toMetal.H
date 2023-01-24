
/*  loop over faces of patch (both patches have same number of faces
    -> only one loop needed) */
forAll (metalToHydrogenPatch, facei)
{
    // get cell IDs of cells adjacent to patch
    label IDCellMetal = patchCellsMetalToHydrogenPatch[facei];
    // label IDCellHydrogen = patchCellsHydrogenToHydridePatch[facei];

    T_hydrogen.boundaryFieldRef()[hydrogenToMetalPatchID][facei]
      = T[IDCellMetal];
}



if (myDebugControl == 1)
{
    Info<< "--> T_toMetal Coupling Successful!" << endl;
    Info<< "-------------------------" << endl;
}
