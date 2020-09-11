// Tran, Joshua N.
// jnt6598
// 2020-05-07

//----------------------------------------------------------
#include <stdio.h>

#include "visible.h"

//----------------------------------------------------------
int isVisible( Vertex *cameraPosition, Vertex *v1, Vertex *v2, Vertex *v3 )
{
  // TODO:  Purpose:  Determine if the triangle represented by
  //          vertices v1, v2, and v3 is visible from the given
  //          camera position.
  //
  //        Compute the toTriangle vector from the camera position
  //          to v1 of the triangle.
  //

  //toTriangle Vector attributes:
  double toTriangleX = v1->x - cameraPosition->x;
  double toTriangleY = v1->y - cameraPosition->y;
  double toTriangleZ = v1->z - cameraPosition->z;

  //        Derive the surface normal for the triangle by
  //          computing the cross product of the vector from v1
  //          to v2 with the vector from v1 to v3.
  //

  //A vector attributes:
  double AX = v2->x - v1->x;
  double AY = v2->y - v1->y;
  double AZ = v2->z - v1->z;

  //B vector attributes:
  double BX = v3->x - v1->x;
  double BY = v3->y - v1->y;
  double BZ = v3->z - v1->z;

  //Surface normal attributes (cross prduct of A x B):
  double surfaceNormalX = (AY * BZ) - (AZ * BY);
  double surfaceNormalY = (AZ * BX) - (AX * BZ);
  double surfaceNormalZ = (AX * BY) - (AY * BX);

  //        Compute the angle between the toTriangle vector and
  //          the surface normal vector.
  //
  double dotProduct = (toTriangleX * surfaceNormalX) + (toTriangleY * surfaceNormalY) + (toTriangleZ * surfaceNormalZ);

  //        Return 1 if this angle indicates the triangle is
  //          visible from the camera position, 0 otherwise.
  
  return dotProduct < 0 ? 1: 0;
}

//----------------------------------------------------------
