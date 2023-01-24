/*
	We need to collect all cell-faces adjacent to the connecting patches of both meshes to exchange variable values.
	Also, we need one of the connecting patches to iterate over and address all cells. Only one patch is needed for this,
	as both patches contain the same amount of cells.
	1. get the patchIDs of both connecting patches.
	2. get the patch of the found patchID.
	3. create two lists containing all cells with a face belonging to the patchIDs found in the first step.
*/

// get the patch IDs of both meshes
label metalToHydrogenPatchID = metalArea.boundaryMesh().findPatchID("metalArea_to_hydrogenArea");
label hydrogenToMetalPatchID = hydrogenArea.boundaryMesh().findPatchID("hydrogenArea_to_metalArea");

// get patch of patchID
const Foam::fvPatch& metalToHydrogenPatch = metalArea.boundary()[metalToHydrogenPatchID];

// list of cells adjacent to the patch
const labelList& patchCellsMetalToHydrogenPatch = metalArea.boundaryMesh()[metalToHydrogenPatchID].faceCells();
const labelList& patchCellsHydrogenToMetalPatch = hydrogenArea.boundaryMesh()[hydrogenToMetalPatchID].faceCells();

if (myDebugControl == 1)
{
    Info<< "--> Faces Collected Successful!" << endl;
    Info<< "-------------------------" << endl;
}
