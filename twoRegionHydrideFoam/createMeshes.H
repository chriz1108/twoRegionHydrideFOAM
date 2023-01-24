/*
  Initialize meshes for metalArea & hydrogenArea
*/

fvMesh metalArea
(
    Foam::IOobject
    (
        word("metalArea"),
        runTime.timeName(),
        runTime,
        IOobject::MUST_READ
    )
);

fvMesh hydrogenArea
(
    Foam::IOobject
    (
        word("hydrogenArea"),
        runTime.timeName(),
        runTime,
        IOobject::MUST_READ
    )
);

if (myDebugControl == 1)
{
    Info<< "--> Meshes Created!" << endl;
    Info<< "-------------------------" << endl;
}
