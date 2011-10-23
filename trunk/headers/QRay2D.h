#ifndef __QRAY2D__
#define __QRAY2D__

#include "QRay.h"
#include "QVector2.h"
#include "QBaseOrb.h"
#include "QBaseTriangle.h"
#include "QBaseQuadrilateral.h"
#include "QLineSegment2D.h"
#include "QTransformationMatrix3x3.h"
#include "EQIntersections.h"

using namespace Kinesis::QuimeraEngine::Tools::DataTypes;

namespace Kinesis
{
namespace QuimeraEngine
{
namespace Tools
{
namespace Math
{

/// <summary>
/// Represents a ray in 2D space, which consists of a point or position, and a direction. The direction
/// symbolizes a line with only one end (which coincides with the point) and that extends to the infinite.
/// </summary>
class QDllExport QRay2D : public QRay<QVector2, QVector2>
{
    // CONSTANTS
    // ---------------
public:

    /// <summary>
	/// A ray set at the coordinate origin and whose direction vector is null.
	/// </summary>
    static const QRay2D RayZero;

    /// <summary>
	/// A ray set at the coordinate origin and whose direction vector is in X growing direction.
	/// </summary>
    static const QRay2D RayX;

    /// <summary>
	/// A ray set at the coordinate origin and whose direction vector is in Y growing direction.
	/// </summary>
    static const QRay2D RayY;



	// CONSTRUCTORS
	// ---------------
public:

	/// <summary>
	/// Default constructor.
	/// </summary>
	inline QRay2D() { }

    /// <summary>
    /// Constructor that receives a ray.
    /// </summary>
    /// <param name="ray">[IN] An existing ray.</param>
    inline QRay2D(const QRay<QVector2, QVector2> &ray) : QRay<QVector2, QVector2>(ray) { }

    /// <summary>
    /// Constructor that receives the ray's position and direction. The direction vector must be normalized.
    /// </summary>
    /// <param name="vPoint">[IN] Ray's position.</param>
    /// <param name="vDirection">[IN] Ray's direction.</param>
    inline QRay2D(const QVector2 &vPoint, const QVector2 &vDirection) : QRay<QVector2, QVector2>(vPoint, vDirection) { }


	// METHODS
	// ---------------
public:

    /// <summary>
    /// Assign operator that receives another ray.
    /// </summary>
    /// <param name="ray">[IN] An existing ray.</param>
    /// <returns>
    /// A reference to this ray, after assignation.
    /// </returns>
    inline QRay2D& operator=(const QBaseRay<QVector2, QVector2> &ray)
    {
        QBaseRay<QVector2, QVector2>::operator=(ray);
        return *this;
    }

    /// <summary>
    /// Checks if resident ray intersects with the provided one.
    /// </summary>
    /// <param name="ray">[IN] The ray whose intersection with resident one will be checked.</param>
    /// <returns>
    /// True if both rays intersect, false otherwise.
    /// </returns>
    /// <remarks>
    /// If both rays intesect, the intersection point must verify both vectorial ecuations:
    /// \f$ P \equiv P_1 + \lambda_1 \cdot D_1 \f$
    /// \f$ P \equiv P_2 + \lambda_2 \cdot D_2 \f$
    /// These ecuations can be decomposed by components, obtaining  two equalities:
    /// 1) \f$ P_{1x} + \lambda_1 \cdot D_{1x} = P_{2x} + \lambda_2 \cdot D_{2x}\f$
    /// 2) \f$ P_{1y} + \lambda_1 \cdot D_{1y} = P_{2y} + \lambda_2 \cdot D_{2y}\f$
    /// Finally, both \f$ \lambda_1 \f$ and \f$ \lambda_2 \f$ are forced to be greater or equal to 0, to
    /// ensure ray direction is being followed.
    /// When rays direction vector are parallel, one ray containing the other ray origin point is checked.
    /// </remarks>
    bool Intersection(const QBaseRay<QVector2, QVector2> &ray) const;

    /// <summary>
    /// Checks if resident ray intersects with the provided orb. Ray must be normalized to ensure correct result.
    /// </summary>
    /// <param name="orb">[IN] The orb whose intersection with resident ray will be checked.</param>
    /// <returns>
    /// True if ray intersect orb, false otherwise.
    /// </returns>
    inline bool Intersection (const QBaseOrb<QVector2> &orb) const
    {
        // [TODO] jwladi: Esto deber�a ir en la clase base, es independiente de coordenadas.

        QVector2 vNewRayPoint(this->Point - orb.P);

        //  B/2 (instead of B) is calculed here to optimize comparison.
        const float_q &fB = vNewRayPoint.DotProduct(this->Direction);

        // Since ray is normalized, A = 1.
        //const float_q &fA = this->Direction.DotProduct(this->Direction);

        const float_q &fC = vNewRayPoint.DotProduct(vNewRayPoint) - orb.Radius * orb.Radius;

        // Discriminant: B^2 - 4AC
        // Comparing B^2 (divided by 4) and A*C (4*A*C divided by 4). Remember that A = 1.
        return ( QFloat::IsGreaterOrEquals(fB*fB, fC) );
    }

    /// <summary>
    /// Checks if resident ray intersects with the provided triangle.
    /// </summary>
    /// <param name="triangle">[IN] The triangle whose intersection with resident ray will be checked.</param>
    /// <returns>
    /// True if ray intersect triangle, false otherwise.
    /// </returns>
    inline bool Intersection (const QBaseTriangle2 &triangle) const
    {
        return ( this->Intersection(triangle.A, triangle.B) ||
                 this->Intersection(triangle.B, triangle.C) ||
                 this->Intersection(triangle.C, triangle.A) );
    }

    /// <summary>
    /// Checks if resident ray intersects with the provided quadrilateral.
    /// </summary>
    /// <param name="quad">[IN] The quadrilateral whose intersection with resident ray will be checked.</param>
    /// <returns>
    /// True if ray intersect quadrilateral, false otherwise.
    /// </returns>
    inline bool Intersection (const QBaseQuadrilateral &quad) const
    {
        return ( this->Intersection(quad.A, quad.B) || this->Intersection(quad.B, quad.C) ||
                 this->Intersection(quad.C, quad.D) || this->Intersection(quad.D, quad.A));
    }

	/// <summary>
	/// Computes the intersection point between resident and provided ray, if it exists.
	/// </summary>
	/// <param name="ray">[IN] The ray whose intersection with resident ray will be checked.</param>
	/// <param name="vPoint">[OUT] The point where they intersect, if they do.</param>
	/// <returns>
    /// An enumerated value which represents the number of intersections between the rays, and can take
    /// the following values: E_None, E_One and E_Infinite.
	/// </returns>
	/// <remarks>
	/// -If there's no intersection point, or the rays are totally or parcially coincident,
	/// the output parameter used for storing that point won't be modified.
    ///
    /// If both rays intesect, the intersection point must verify both vectorial ecuations:
    /// \f$ P \equiv P_1 + \lambda_1 \cdot D_1 \f$
    /// \f$ P \equiv P_2 + \lambda_2 \cdot D_2 \f$
    /// These ecuations can be decomposed by components, obtaining two equalities:
    /// 1) \f$ P_{1x} + \lambda_1 \cdot D_{1x} = P_{2x} + \lambda_2 \cdot D_{2x}\f$
    /// 2) \f$ P_{1y} + \lambda_1 \cdot D_{1y} = P_{2y} + \lambda_2 \cdot D_{2y}\f$
    /// Finally, both \f$ \lambda_1 \f$ and \f$ \lambda_2 \f$ are forced to be greater or equal to 0, to
    /// ensure ray direction is being followed.
    /// When rays direction vector are parallel, one ray containing the other ray origin point is checked.
	/// </remarks>
    EQIntersections IntersectionPoint(const QBaseRay<QVector2, QVector2> &ray, QBaseVector2 &vPoint) const;

	/// <summary>
	/// Computes the intersection point between resident ray and provided orb, if it exists. Ray must be normalized to ensure correct result.
	/// </summary>
	/// <param name="orb">[IN] The orb whose intersection with resident ray will be checked.</param>
	/// <param name="vPoint">[OUT] Closest intersection point to ray origin point, if it exists.</param>
	/// <returns>
    /// An enumerated value which represents the number of intersections between the ray and the orb, and can take
    /// the following values: E_None, E_One and E_Two.
	/// </returns>
	/// <remarks>
	/// -If there's no intersection point, the output parameters won't be modified.
	/// -If there's one intersection point, the output parameter stores it.
    /// -If there are two intersection points, the output parameter is filled with the closest to the origin point of the ray.
	/// </remarks>
    inline EQIntersections IntersectionPoint(const QBaseOrb<QVector2> &orb, QBaseVector2 &vPoint) const
    {
        QBaseVector2 vAux;
        return this->IntersectionPoint(orb, vPoint, vAux);
    }

	/// <summary>
	/// Computes the intersection point between resident ray and provided orb, if it exists. Ray must be normalized to ensure correct result.
	/// </summary>
	/// <param name="orb">[IN] The orb whose intersection with resident ray will be checked.</param>
	/// <param name="vPoint1">[OUT] First point where they intersect, if they do.</param>
	/// <param name="vPoint2">[OUT] Second point where they intersect, if they do.</param>
	/// <returns>
    /// An enumerated value which represents the number of intersections between the ray and the orb, and can take
    /// the following values: E_None, E_One and E_Two.
	/// </returns>
	/// <remarks>
	/// -If there's no intersection point, the output parameters won't be modified.
	/// -If there's one intersection point, the second output parameter won't be modified,
	/// and first output parameter is filled with the intersection point.
    /// -If there are two intersection points, both output parameters are filled with the intersection points, storing
    /// in the first output parameter the closest to the origin point of the ray.
	/// </remarks>
    EQIntersections IntersectionPoint(const QBaseOrb<QVector2> &orb, QBaseVector2 &vPoint1, QBaseVector2 &vPoint2) const;

	/// <summary>
	/// Computes the intersection point between resident ray and provided triangle, if it exists.
	/// </summary>
	/// <param name="triangle">[IN] The triangle whose intersection with resident ray will be checked.</param>
	/// <param name="vPoint">[OUT] Closest intersection point to ray origin point, if it exists.</param>
	/// <returns>
    /// An enumerated value which represents the number of intersections between the ray and the triangle, and can take
    /// the following values: E_None, E_One or E_Two.
	/// </returns>
	/// <remarks>
	/// -If there's no intersection point, the output parameter won't be modified.
	/// -If there's one intersection point, the output parameter stores it.
    /// -If there are two intersection points, the output parameter is filled with the closest to the origin point of the ray.
	/// </remarks>
    EQIntersections IntersectionPoint(const QBaseTriangle2 &triangle, QBaseVector2 &vPoint) const
    {
        QBaseVector2 vAux;
        return this->IntersectionPoint(triangle, vPoint, vAux);
    }

	/// <summary>
	/// Computes the intersection point between resident ray and provided triangle, if it exists.
	/// </summary>
	/// <param name="triangle">[IN] The triangle whose intersection with resident ray will be checked.</param>
	/// <param name="vPoint1">[OUT] First point where they intersect, if they do.</param>
	/// <param name="vPoint2">[OUT] Second point where they intersect, if they do.</param>
	/// <returns>
    /// An enumerated value which represents the number of intersections between the ray and the triangle, and can take
    /// the following values: E_None, E_One or E_Two.
	/// </returns>
	/// <remarks>
	/// -If there's no intersection point, the output parameters won't be modified.
	/// -If there's one intersection point, the second output parameter won't be modified,
	/// and first output parameter is filled with the intersection point.
    /// -If there are two intersection points, both output parameters are filled with the intersection points, storing
    /// in the first output parameter the closest to the origin point of the ray.
	/// </remarks>
    EQIntersections IntersectionPoint(const QBaseTriangle2 &triangle, QBaseVector2 &vPoint1, QBaseVector2 &vPoint2) const;

	/// <summary>
	/// Computes the intersection point between resident ray and provided quadrilateral, if it exists.
	/// </summary>
	/// <param name="quad">[IN] The quadrilateral whose intersection with resident ray will be checked.</param>
	/// <param name="vPoint">[OUT] Closest intersection point to ray origin point, if it exists.</param>
	/// <returns>
    /// An enumerated value which represents the number of intersections between the ray and the quadrilateral, and can take
    /// the following values: E_None, E_One or E_Two.
	/// </returns>
	/// <remarks>
	/// -If there's no intersection point, the output parameter won't be modified.
	/// -If there's one intersection point, the output parameter stores it.
    /// -If there are two intersection points, the output parameter is filled with the closest to the origin point of the ray.
	/// </remarks>
    EQIntersections IntersectionPoint(const QBaseQuadrilateral &quad, QBaseVector2 &vPoint) const
    {
        QBaseVector2 vAux;
        return this->IntersectionPoint(quad, vPoint, vAux);
    }

	/// <summary>
	/// Computes the intersection point between resident ray and provided quadrilateral, if it exists.
	/// </summary>
	/// <param name="quad">[IN] The quadrilateral whose intersection with resident ray will be checked.</param>
	/// <param name="vPoint1">[OUT] First point where they intersect, if they do.</param>
	/// <param name="vPoint2">[OUT] Second point where they intersect, if they do.</param>
	/// <returns>
    /// An enumerated value which represents the number of intersections between the ray and the quadrilateral, and can take
    /// the following values: E_None, E_One or E_Two.
	/// </returns>
	/// <remarks>
	/// -If there's no intersection point, the output parameters won't be modified.
	/// -If there's one intersection point, the second output parameter won't be modified,
	/// and first output parameter is filled with the intersection point.
    /// -If there are two intersection points, both output parameters are filled with the intersection points, storing
    /// in the first output parameter the closest to the origin point of the ray.
	/// </remarks>
    EQIntersections IntersectionPoint(const QBaseQuadrilateral &quad, QBaseVector2 &vPoint1, QBaseVector2 &vPoint2) const;

    /// <summary>
    /// Checks if resident ray and provided line segment intersects.
    /// </summary>
    /// <param name="ls">[IN] The line segment whose intersection with resident ray will be checked.</param>
    /// <returns>
    /// True if line segment and resident ray intersects, false otherwise.
    /// </returns>
    bool Intersection (const QBaseLineSegment2 &ls) const;

    /// <summary>
    /// Computes the intersection point between resident ray and provided line segment, if it exists.
    /// </summary>
    /// <param name="ls">[IN] The line segment whose intersection with resident ray will be checked.</param>
    /// <param name="vPoint">[OUT] The intersection point with line segment, if it exists.</param>
    /// <returns>
    /// An enumerated value which represents the number of intersections between the ray and the quadrilateral, and can take
    /// the following values: E_None, E_One or E_Infinite.
    /// </returns>
    /// <remarks>
    /// -If there's no intersection point, the output parameters won't be modified.
    /// -If there's one intersection point, output parameter is filled with the intersection point.
    /// -If there are infinite intersection points, the output parameters won't be modified.
    /// </remarks>
    EQIntersections IntersectionPoint (const QBaseLineSegment2 &ls, QBaseVector2 &vPoint) const;

    /// <summary>
	/// Computes a ray that is the result of resident ray reflection on the line segment provided.
	/// </summary>
	/// <param name="ls">[IN] The line segment which acts as mirror.</param>
	/// <param name="refRay">[OUT] The reflected ray.</param>
	/// <remarks>
	/// -If there's no intersection point between ray and line segment, or are both coincident or parallel,
	///  reflected ray is the resident ray itself.
	/// -If there's one intersection point between them, then the reflected ray has it origin point at the intersection point
	///  and its direction verifies that the incident angle and the reflected angle are equals.
	/// - Ray direction must be normalized to obtain a normalized reflected ray.
	/// </remarks>
    inline void Reflection(const QBaseLineSegment2 &ls, QBaseRay2 &refRay) const
    {
        //Method based in this: http://www.inmensia.com/articulos/raytracing/mecanismosluz.html

        QVector2 vAux(ls.B - ls.A);
        QVector2 vPoint;

        vAux.Normalize();

        refRay = *this;

        // Avoiding cases where ray and line segment are parallels or coincident.
        if (vAux == this->Direction || vAux == -this->Direction)
            return;
        else
        {
            EQIntersections numInt = this->IntersectionPoint(ls, vPoint);
            if (numInt == EQIntersections::E_One)
            {
                // Reflected origin is the intersection point
                refRay.Point = vPoint;

                // Calculates normal to line segment (is normalized like vAux)
                QVector2 vNorm = vAux.GetPerpendicular();

                // Calculates reflected direction
                refRay.Direction -= QFloat::_2 * (this->Direction.DotProduct(vNorm))*vNorm;
            }
        }
    }

    /// <summary>
	/// Computes a vector that is the resultant direction of resident ray reflection on the line segment provided.
	/// </summary>
	/// <param name="ls">[IN] The line segment which acts as mirror.</param>
	/// <param name="vRef">[OUT] The direction of the reflected ray.</param>
	/// <remarks>
	/// -If there's no intersection point between ray and line segment, or are both coincident or parallel,
	///  reflected ray is the resident ray itself.
	/// -If there's one intersection point between them, then the reflected ray direction verifies
	///  that the incident angle and the reflected angle are equals.
	/// - Ray direction must be normalized to obtain a normalized reflected vector.
	/// </remarks>
    inline void Reflection(const QBaseLineSegment2 &ls, QBaseVector2 &vRef) const
    {
        //Method based in this: http://www.inmensia.com/articulos/raytracing/mecanismosluz.html

        QVector2 vAux(ls.B - ls.A);

        vAux.Normalize();

        vRef = this->Direction;

        // Avoiding cases where ray and line segment are parallels or coincident.
        if (vAux == this->Direction || vAux == -this->Direction)
            return;
        else if (this->Intersection(ls))
        {
            // Calculates normal to line segment (is normalized like vAux)
            QVector2 vNorm = vAux.GetPerpendicular();

            // Calculates reflected direction
            vRef = this->Direction - QFloat::_2 * (this->Direction.DotProduct(vNorm))*vNorm;
        }
    }

    /// <summary>
	/// Applies the transformation given by the matrix provided to resident ray.
	/// </summary>
	/// <param name="mTransf">[IN] The transformation matrix to be applied.</param>
	/// <remarks>
	/// All transformations affects both origin ray point and ray direction, except translations,
	/// that only affects origin ray point.
	/// </remarks>
	inline void Transform(const QTransformationMatrix3x3 &mTransf)
	{
	    this->Point.Transform(mTransf);

        // Direction is transformed without translation. The calculation takes into account only the submatrix that contains
        // the rotation and the scale.
        float_q fNewX = this->Direction.x * mTransf.ij[0][0] + this->Direction.y * mTransf.ij[1][0];
        float_q fNewY = this->Direction.x * mTransf.ij[0][1] + this->Direction.y * mTransf.ij[1][1];

        this->Direction.x = fNewX;
        this->Direction.y = fNewY;

        this->Direction.Normalize();
	}

    /// <summary>
	/// Applies the transformation given by the matrix provided to resident ray, storing the result in the ray provided.
	/// </summary>
	/// <param name="mTransf">[IN] The transformation matrix to be applied.</param>
	/// <param name="outRay">[OUT] The transformed ray.</param>
	/// <remarks>
	/// All transformations affects both origin ray point and ray direction, except translations,
	/// that only affects origin ray point.
	/// </remarks>
	inline void Transform(const QTransformationMatrix3x3 &mTransf, QBaseRay2 &outRay)
	{
	    outRay = *this;
	    reinterpret_cast <QRay2D &> (outRay).Transform(mTransf);
	}

protected:

    // Checks if resident ray contains a given point.
    bool Contains (const QBaseVector2 &vPoint) const
    {
        if (this->Point == vPoint)
            return true;
        else if ( QFloat::IsZero(this->Direction.x) )
        {
            if ( QFloat::AreNotEquals(vPoint.x, this->Point.x) )
                return false;
            if ( QFloat::IsNegative(vPoint.y - this->Point.y) == QFloat::IsNegative(this->Direction.y) )
                return true;
            else
                return false;
        }
        else if ( QFloat::IsZero(this->Direction.y) )
        {
            if ( QFloat::AreNotEquals(vPoint.y, this->Point.y) )
                return false;
            if ( QFloat::IsNegative(vPoint.x - this->Point.x) == QFloat::IsNegative(this->Direction.x) )
                return true;
            else
                return false;
        }
        else
        {
            const float_q &paramX = (vPoint.x - this->Point.x)/this->Direction.x;
            const float_q &paramY = (vPoint.y - this->Point.y)/this->Direction.y;

            if ( QFloat::AreNotEquals(paramX, paramY) || QFloat::IsNegative(paramX))
                return false;
            else
                return true;
        }
    }

    // Checks if resident ray intersects the AB line segment
    bool Intersection (const QVector2 &vA, const QVector2 &vB) const
    {
        return this->Intersection(QBaseLineSegment2(vA, vB));
    }

    // Checks if resident ray intersects the AB line segment and calculates the intersection point if exists
    EQIntersections IntersectionPoint (const QVector2 &vA, const QVector2 &vB, QBaseVector2 &vPoint) const
    {
        return this->IntersectionPoint(QBaseLineSegment2(vA, vB), vPoint);
    }

    // Checks if a point is inside a triangle.
	// [TODO] jwladi: Replace by the QTriangle2D or QTriangle Contains method, when it exists.
	inline bool PointInsideTriangle(const QBaseTriangle2& triangle, const QVector2& vPoint) const
	{
        return ( PointsInSameSideOfLine(vPoint, triangle.A, triangle.B, triangle.C) &&
                 PointsInSameSideOfLine(vPoint, triangle.B, triangle.C, triangle.A) &&
                 PointsInSameSideOfLine(vPoint, triangle.C, triangle.A, triangle.B) );
	}

    // Check if two points are in the same side of a line.
	inline bool PointsInSameSideOfLine(const QVector2 &vP1, const QVector2 &vP2, const QVector2 &vLine1, const QVector2 &vLine2) const
	{
        const float_q &fOrientation1 = (vLine1.x - vP1.x)*(vLine2.y - vP1.y) - (vLine1.y - vP1.y)*(vLine2.x - vP1.x);
        const float_q &fOrientation2 = (vLine1.x - vP2.x)*(vLine2.y - vP2.y) - (vLine1.y - vP2.y)*(vLine2.x - vP2.x);

        if ( QFloat::IsZero(fOrientation1) || QFloat::IsZero(fOrientation2) )
            return true;
        else if ( QFloat::IsNegative(fOrientation1) == QFloat::IsNegative(fOrientation2) )
            return true;
        else
            return false;
	}

	// Checks if a point is inside a quadrilateral.
	// [TODO] jwladi: Replace by the QQuadrilateral Contains method, when it exists.
	inline bool PointInsideQuadrilateral(const QBaseQuadrilateral& quad, const QVector2& vPoint) const
	{
	    return ( PointsInSameSideOfLine(vPoint, quad.C, quad.A, quad.B) &&
                 PointsInSameSideOfLine(vPoint, quad.A, quad.B, quad.C) &&
                 PointsInSameSideOfLine(vPoint, quad.A, quad.C, quad.D) &&
                 PointsInSameSideOfLine(vPoint, quad.C, quad.D, quad.A) );
	}
};

} //namespace Math
} //namespace Tools
} //namespace QuimeraEngine
} //namespace Kinesis

#endif // __QRAY2D__
