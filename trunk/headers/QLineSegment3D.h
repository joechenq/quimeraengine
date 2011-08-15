// [TERMS&CONDITIONS]

#ifndef __QLINESEGMENT3D__
#define __QLINESEGMENT3D__

#include "QBaseLineSegment.h"
#include "QLineSegment.h"
#include "QBasePlane.h"
#include "EQSpaceRelation.h"
#include "QBaseTriangle.h"
#include "QBaseHexahedron.h"
#include "QQuaternion.h"
#include "QDualQuaternion.h"

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
/// Class which represents a chunk (segment) of straight line in 3D space, defined by two endpoints A and B.
/// These points may be expressed as 3D points or vectors, depending on the template parameter,
/// which may be 3D vector or 4D vector.
/// Please note there's really no "source" and "end" points implicit, that is, it's not an oriented segment.
/// </summary>
template <class VectorType>
class QDllExport QLineSegment3D : public QLineSegment<VectorType>
{

	// CONSTANTS
    // ---------------
public:

    /// <summary>
    /// Unit segment lying on positive X axis (it's length equals 1).
    /// </summary>
	static const QLineSegment3D<VectorType> UnitLine;

    /// <summary>
    /// Zero segment lying in the coordinates center whose endpoints
	/// both equals to (0,0) and it's length equals 0.
    /// </summary>
	static const QLineSegment3D<VectorType> LineZero;


 	// CONSTRUCTORS
	// ---------------
public:

	/// <summary>
	/// Default constructor.
	/// </summary>
    inline QLineSegment3D() { }

    /// <summary>
    /// Constructor from two vectors.
    /// </summary>
    /// <param name="vA">[IN] Vector to define endpoint A.</param>
    /// <param name="vB">[IN] Vector to define endpoint B.</param>
	inline QLineSegment3D (const VectorType &vA, const VectorType &vB) : QLineSegment<VectorType>(vA,vB) { }

	/// <summary>
    /// Constructor from a line segment.
    /// </summary>
    /// <param name="ls">[IN] Line segment in which we want resident line segment is based on.</param>
	inline explicit QLineSegment3D (const QBaseLineSegment<VectorType> &ls) : QLineSegment<VectorType>(ls.A, ls.B)  { }

	// METHODS
	// ---------------
public:

    /// <summary>
    /// Assign operator. Assigns the provided line segment to the resident line segment.
    /// </summary>
    /// <param name="ls">[IN] The line segment to be assigned.</param>
    /// <returns>
    /// A reference to the modified line segment.
    /// </returns>
    inline QLineSegment3D& operator=(const QBaseLineSegment<VectorType> &ls)
    {
        // [TODO] jwladi: it must be done via QLineSegment assign operator.
        reinterpret_cast<QBaseLineSegment<VectorType>&>(*this) = ls;
        return *this;
    }

    /// <summary>
    /// Checks if resident line segment intersects with the provided plane.
    /// Since a plane divides space into two sides (positive and negative), we can check how the end points of
    /// the line segment satisfies the plane equation:
    /// Being the plane equation \f$ ax + by + cz + d = 0 \f$,
    /// and the end points of the line segment \f$ A(A_x, A_y, A_z)\f$, \f$ B(B_x, B_y, B_z)\f$,
    /// we have to check the value of:
    ///
    /// (1) \f$ a\cdot A_x + b\cdot A_y + c\cdot A_z + d \f$
    ///
    /// (2) \f$ a\cdot B_x + b\cdot B_y + c\cdot B_z + d \f$
    ///
    /// If (1) = 0 or (2) = 0, then the line segment intersects the plane (one of the end points lies on plane).
    /// If the sign of (1) and (2) are different, each end point are in a different side of the space
    /// from the plane, and then the line segment intersects the plane.
    /// If (1) and (2) have equal sign, then there are in the same side of the space from the plane,
    /// and the line segment don't intersects the plane.
    /// If one end point of the line segment lies on the plane, we consider there is an intersection.
    /// </summary>
    /// <param name="p">[IN] The plane we want check if intersects with resident line segment.</param>
    /// <returns>
    /// True if plane and line segment intersects, false otherwise.
    /// </returns>
    inline bool Intersection (const QBasePlane &p) const
    {
        const float_q &distA = p.a * this->A.x + p.b * this->A.y + p.c * this->A.z + p.d;

        if (QFloat::IsZero(distA))
            return true;

        const float_q &distB = p.a * this->B.x + p.b * this->B.y + p.c * this->B.z + p.d;

        if (QFloat::IsZero(distB))
            return true;

        else if ( QFloat::IsLessThan(distA * distB, QFloat::_0) )
            return true;
        else
            return false;
    }

    /// <summary>
    /// This method receives a orb, and computes if it intersects the resident segment or not.
    /// </summary>
    /// <param name="orb">[IN] The orb to be compared to.</param>
    /// <returns>
    /// True if the segment intersects the orb (or if they were either tangent or coincident). Otherwise returns false.
    /// </returns>
    template <class VectorTypeParam>
    inline bool Intersection (const QBaseOrb<VectorTypeParam>& orb) const
    {
         return QLineSegment<VectorTypeParam>::Intersection(orb);
    };

    /// <summary>
    /// Checks if resident line segment intersects with the provided triangle.
    /// If one end point of the line segment lies on the triangle, or on an edge or vertex of the triangle,
    /// we consider there is an intersection.
    /// </summary>
    /// <param name="t">[IN] The triangle we want check if intersects with resident line segment.</param>
    /// <returns>
    /// True if triangle and line segment intersects, false otherwise.
    /// </returns>
    template <class VectorTypeParam>
    bool Intersection (const QBaseTriangle<VectorTypeParam> &t) const
    {
        // Calculates if segment intersects with the plane defined by the triangle.

        // This is necessary due to there are dot products between the normal vector to the plane (VectorTypeParam)
        // and the line segment end points, which are VectorType.
        QLineSegment3D<VectorTypeParam> lsAux(VectorTypeParam(this->A), VectorTypeParam(this->B));

        // Plane equation
        QBasePlane pAux;
        PlaneFrom3Points(t.A, t.B, t.C, pAux);

        // Line Segment don't intersects the triangle plane.
        if (!lsAux.Intersection(pAux))
            return false;

        // If both end points satisfy plane equation, the line segment lies on plane
        const float_q &fDot1 = pAux.a * lsAux.B.x + pAux.b * lsAux.B.y + pAux.c * lsAux.B.z + pAux.d;
        const float_q &fDot2 = pAux.a * lsAux.A.x + pAux.b * lsAux.A.y + pAux.c * lsAux.A.z + pAux.d;

        if (QFloat::IsZero(fDot1) && QFloat::IsZero(fDot2))
        {
            // Both triangle and line segment are coplanars. If the line segment
            // intersects one of the edges of the triangle, then the line segment intersects the triangle.
            if (lsAux.QLineSegment<VectorType>::Intersection(QLineSegment<VectorTypeParam> (t.A, t.B)) ||
                lsAux.QLineSegment<VectorType>::Intersection(QLineSegment<VectorTypeParam> (t.B, t.C)) ||
                lsAux.QLineSegment<VectorType>::Intersection(QLineSegment<VectorTypeParam> (t.C, t.A)))
                return true;

            // If not, we check if segment is fully contained in the triangle
            // We only check "A" end point, since if "A" is inside, "B" must be inside too (see previus test).
            else if (!PointsInSameSideOfLine(lsAux.A, t.A, t.B, t.C) ||
                     !PointsInSameSideOfLine(lsAux.A, t.B, t.A, t.C) ||
                     !PointsInSameSideOfLine(lsAux.A, t.C, t.B, t.A))
                return false;
            else
                return true;
        }

        QE_ASSERT(QFloat::IsNotZero(fDot2 - fDot1));

        // The point which satisfies both line and plane equations.
        VectorTypeParam vAux = lsAux.A + (lsAux.B - lsAux.A) * fDot2/(fDot2 - fDot1);

        // For every edge, it tests if the intersection point is in the same side of each edge
        // than the third vextex. If it does, then it's inside the triangle, otherwise it's outside.
        if (!PointsInSameSideOfLine(vAux, t.A, t.B, t.C) ||
            !PointsInSameSideOfLine(vAux, t.B, t.A, t.C) ||
            !PointsInSameSideOfLine(vAux, t.C, t.B, t.A))
            return false;
        else
            return true;
    }

    /// <summary>
    /// Checks if resident line segment intersects with the provided hexahedron.
    /// If one end point of the line segment lies on one of the hexahedron faces,
    /// we consider there is an intersection.
    /// </summary>
    /// <param name="h">[IN] The hexahedron we want check if intersects with resident line segment.</param>
    /// <returns>
    /// True if hexahedron and line segment intersects, false otherwise.
    /// </returns>
    template <class VectorTypeParam>
    bool Intersection (const QBaseHexahedron<VectorTypeParam> &h) const
    {
        QLineSegment3D<VectorTypeParam> lsAux(VectorTypeParam(this->A), VectorTypeParam(this->B));

        // Checks if there is an intersection with any face.
        if (CuadrilateralIntersection(lsAux, h.A, h.B, h.C, h.D) ||
            CuadrilateralIntersection(lsAux, h.E, h.F, h.G, h.H) ||
            CuadrilateralIntersection(lsAux, h.A, h.B, h.H, h.E) ||
            CuadrilateralIntersection(lsAux, h.B, h.C, h.G, h.H) ||
            CuadrilateralIntersection(lsAux, h.A, h.D, h.F, h.E) ||
            CuadrilateralIntersection(lsAux, h.C, h.D, h.F, h.G))
            return true;

        // If not, we check if one of the line segment end points is inside the hexahedron, which means
        // that all the segment is inside it.
        // To do that, we check if "A" end point of segment is in the same side of the
        // space defined by every face than any other vertex not in this face.
        else if (!PointsInSameSideOfPlane(lsAux.A, h.E, h.A, h.B, h.C) ||
                 !PointsInSameSideOfPlane(lsAux.A, h.A, h.E, h.F, h.G) ||
                 !PointsInSameSideOfPlane(lsAux.A, h.C, h.A, h.B, h.H) ||
                 !PointsInSameSideOfPlane(lsAux.A, h.A, h.B, h.C, h.G) ||
                 !PointsInSameSideOfPlane(lsAux.A, h.C, h.A, h.D, h.F) ||
                 !PointsInSameSideOfPlane(lsAux.A, h.A, h.C, h.D, h.F))
            return false;
        else
            return true;
    }

	/// <summary>
	/// This method receives another line segment, and computes wheter they intersect each other or not.
	/// This method calls base class' implementation.
	/// </summary>
	/// <param name="segmt">[IN] The segment to be compared to.</param>
	/// <returns>
	/// True if they intersect each other (or if they were coincident), false if they don't.
	/// </returns>
	inline bool Intersection (const QBaseLineSegment<VectorType>& segmt) const
	{
		return QLineSegment<VectorType>::Intersection(segmt);
	}

    /// <summary>
    /// Calculates the maximum distance between the resident line segment and a plane provided.
    /// </summary>
    /// <param name="q">[IN] The plane we want to know the maximum distance from the line segment.</param>
    /// <returns>
    /// A floating point value containing the maximum distance between the resident line segment and a plane provided.
    /// </returns>
    inline float_q MaxDistance(const QBasePlane &p) const
    {
        const float_q &fSquaredLength = p.a*p.a + p.b*p.b + p.c*p.c;

        QE_ASSERT(QFloat::IsNotZero(fSquaredLength));

        const float_q &fInvNormalLenght = QFloat::_1/sqrt(fSquaredLength);

        const float_q &distA = abs(p.a * this->A.x + p.b * this->A.y + p.c * this->A.z + p.d) * fInvNormalLenght;
        const float_q &distB = abs(p.a * this->B.x + p.b * this->B.y + p.c * this->B.z + p.d) * fInvNormalLenght;

        return std::max(distA, distB);
    }

    /// <summary>
	/// Given an input line segment, this method returns the maximum distance between this and the input one,
	///	that is, the distance between their farthest points.
	/// This method calls base class' implementation.
    /// </summary>
    /// <param name="segmt">[IN] The line segment the distance will be measured to.</param>
    /// <returns>
    /// A floating point value containing the maximum distance between both line segments.
    /// </returns>
    inline float_q MaxDistance(const QBaseLineSegment<VectorType>& segmt) const
    {
		return QLineSegment<VectorType>::MaxDistance(segmt);
    }

    /// <summary>
	/// Given an input vector (which represents a point), this method returns the maximum distance between this and
	/// the segment, that is, the distance between the input point and the farthest point lying into the segment...
	/// ...and this will be one of the segment endpoints!.
	/// Please note the above is correct only when the point lies outside the segment; if it's inside the segment,
	/// the maximum distance equals to 0.
	/// This method calls base class' implementation.
	/// </summary>
	/// <param name="vPoint">[IN] The point the distance will be measured to.</param>
    /// <returns>
    /// A floating point value containing the maximum distance between the resident line segment and a point provided.
    /// </returns>
    inline float_q MaxDistance(const VectorType& vPoint) const
    {
		return QLineSegment<VectorType>::MaxDistance(vPoint);
    }

    /// <summary>
    /// Calculates the minimum distance between the resident line segment and a plane provided.
    /// </summary>
    /// <param name="q">[IN] The plane we want to know the minimum distance from the line segment.</param>
    /// <returns>
    /// A floating point value containing the minimum distance between the resident line segment and a plane provided.
    /// </returns>
    inline float_q MinDistance(const QBasePlane &p) const
    {
        const float_q &fSquaredLength = p.a*p.a + p.b*p.b + p.c*p.c;

        QE_ASSERT(QFloat::IsNotZero(fSquaredLength));

        const float_q &fInvNormalLenght = QFloat::_1/sqrt(fSquaredLength);

        const float_q &distA = abs(p.a * this->A.x + p.b * this->A.y + p.c * this->A.z + p.d) * fInvNormalLenght;
        const float_q &distB = abs(p.a * this->B.x + p.b * this->B.y + p.c * this->B.z + p.d) * fInvNormalLenght;

        return std::min(distA, distB);
    }

	/// <summary>
	/// Given an input line segment, this method returns the minimum distance between this and the input one,
	///	that is, the distance between their closest points.
	/// This method calls base class' implementation.
	/// </summary>
	/// <param name="segmt">[IN] The line segment the distance will be measured to.</param>
	/// <returns>
	/// A floating point value (always nonnegative) which represents the minimum distance between the two segments.
	/// </returns>
	inline float_q MinDistance (const QBaseLineSegment<VectorType>& segmt) const
	{
		return QLineSegment<VectorType>::MinDistance(segmt);
	}

	/// <summary>
	/// Given an input vector (which represents a point), this method returns the minimum distance between this and
	/// the segment, that is, the distance between the input point and the closest point lying into the segment.
	/// This method calls base class' implementation.
	/// </summary>
	/// <param name="vPoint">[IN] The point the distance will be measured to.</param>
	/// <returns>
	/// A floating point value (always nonnegative) which represents the minimum distance between point and segment.
	/// </returns>
	inline float_q MinDistance (const VectorType& vPoint) const
	{
		return QLineSegment<VectorType>::MinDistance(vPoint);
	}

    /// <summary>
    /// Projects the resident line segment over the plane provided.
    /// </summary>
    /// <param name="p">[IN] The plane where we want to project the resident line segment.</param>
    inline void ProjectToPlane (const QBasePlane &p)
    {
        const float_q &fSquaredLength = p.a*p.a + p.b*p.b + p.c*p.c;

        QE_ASSERT(QFloat::IsNotZero(fSquaredLength));

        const float_q &fInvSquaredLength = QFloat::_1/fSquaredLength;

        const float_q &fProjA = -(p.a * this->A.x + p.b * this->A.y + p.c * this->A.z + p.d);

        this->A.x += fProjA * p.a * fInvSquaredLength;
        this->A.y += fProjA * p.b * fInvSquaredLength;
        this->A.z += fProjA * p.c * fInvSquaredLength;

        const float_q &fProjB = -(p.a * this->B.x + p.b * this->B.y + p.c * this->B.z + p.d);

        this->B.x += fProjB * p.a * fInvSquaredLength;
        this->B.y += fProjB * p.b * fInvSquaredLength;
        this->B.z += fProjB * p.c * fInvSquaredLength;
    }

    /// <summary>
    /// Projects the resident line segment over the plane provided. The projection is stored in the line segment provided.
    /// </summary>
    /// <param name="p">[IN] The plane where we want to project the resident line segment.</param>
    /// <param name="ls">[OUT] The line segment where to store the result of projection.</param>
    inline void ProjectToPlane (const QBasePlane &p, QBaseLineSegment<VectorType> &ls) const
    {
        ls = *this;
        reinterpret_cast<QLineSegment3D<VectorType> &> (ls).ProjectToPlane(p);
    }

    /// <summary>
    /// Transforms the resident line segment with the rotation contained in the quaternion provided, acting
    /// the coordinate axis as center of rotation.
    /// </summary>
    /// <param name="q">[IN] The quaternion which contains the rotation.</param>
    inline void Transform(const QQuaternion &q)
    {
        this->TransformFromPivot(q, VectorType::ZeroVector);
    }

    /// <summary>
    /// Transforms the resident line segment with the rotation contained in the quaternion provided, acting
    /// the coordinate axis as center of rotation. The resultant line segment is stored in the line segment provided.
    /// </summary>
    /// <param name="q">[IN] The quaternion which contains the rotation.</param>
    /// <param name="ls">[OUT] Line segment to store the rotated one.</param>
    inline void Transform(const QQuaternion &q, QLineSegment3D<VectorType> &ls) const
    {
		this->TransformFromPivot(q, VectorType::ZeroVector, ls);
    }

    /// <summary>
    /// Transforms the resident line segment with the transformation contained in the dual quaternion provided, acting
    /// the coordinate axis as center of rotation.
    /// </summary>
    /// <param name="dq">[IN] The dual quaternion which contains the transformation.</param>
    inline void Transform(const QDualQuaternion &dq)
    {
		this->TransformFromPivot(dq, VectorType::ZeroVector);
    }

    /// <summary>
    /// Transforms the resident line segment with the transformation contained in the dual quaternion provided, acting
    /// the coordinate axis as center of rotation. The resultant line segment is stored in the line segment provided.
    /// </summary>
    /// <param name="dq">[IN] The dual quaternion which contains the transformation.</param>
    /// <param name="ls">[OUT] Line segment to store the transformed one.</param>
    inline void Transform(const QDualQuaternion &dq, QLineSegment3D<VectorType> &ls) const
    {
		this->TransformFromPivot(dq, VectorType::ZeroVector, ls);
    }

    /// <summary>
    /// Transforms the resident line segment with a transformation of types rotation, scale, translation,
    /// generic transformation or space conversion transformation contained in the matrix provided, acting
    /// the coordinate origin as pivot.
    /// </summary>
    /// <param name="m">[IN] The matrix which contains the transformation to be applied.</param>
    template <class MatrixType>
    inline void Transform (const MatrixType &m)
    {
        this->A.Transform(m);
        this->B.Transform(m);
    }

    /// <summary>
    /// Transforms the resident line segment with a transformation of types rotation, scale, translation,
    /// generic transformation or space conversion transformation contained in the matrix provided, acting
    /// the coordinate origin as pivot.
    /// The resultant line segment is stored in the line segment provided.
    /// </summary>
    /// <param name="m">[IN] The matrix which contains the transformation to be applied.</param>
    /// <param name="ls">[OUT] Line segment to store the transformed one.</param>
    template <class MatrixType>
    inline void Transform (const MatrixType &m, QBaseLineSegment<VectorType> &ls) const
    {
        ls = *this;
        reinterpret_cast<QLineSegment3D<VectorType> &> (ls).Transform(m);
    }

	/// <summary>
    /// Transforms the resident line segment with the rotation contained in the quaternion provided, acting
    /// the pivot point as center of rotation.
    /// </summary>
    /// <param name="q">[IN] The quaternion which contains the rotation.</param>
	/// <param name="vPivot">[IN] The pivot point which the rotation will be accomplished around.</param>
    inline void TransformFromPivot(const QQuaternion &q, const VectorType &vPivot)
    {
		VectorType vPivotAux = vPivot; // We use another local vector object as pivot
									   // because the pivot point could be one of the
									   // whole segment endpoints, and the whole endpoint
									   // is modified despite the const modifier in
									   // 'const VectorType &vPivot'.
        this->A -= vPivotAux;
        this->B -= vPivotAux;

        this->A.Transform(q);
        this->B.Transform(q);

        this->A += vPivotAux;
        this->B += vPivotAux;
    }

    /// <summary>
    /// Transforms the resident line segment with the rotation contained in the quaternion provided, acting
    /// the pivot point as center of rotation. The resultant line segment is stored in the line segment provided.
    /// </summary>
    /// <param name="q">[IN] The quaternion which contains the rotation.</param>
	/// <param name="vPivot">[IN] The pivot point which the rotation will be accomplished around.</param>
    /// <param name="ls">[OUT] Line segment to store the rotated one.</param>
    inline void TransformFromPivot(const QQuaternion &q, const VectorType &vPivot, QLineSegment3D<VectorType> &ls) const
    {
        ls = *this;
        ls.TransformFromPivot(q, vPivot);
    }

    /// <summary>
    /// Transforms the resident line segment with the transformation contained in the dual quaternion provided, acting
    /// the pivot point of line segment as center of rotation.
    /// </summary>
    /// <param name="dq">[IN] The dual quaternion which contains the transformation.</param>
	/// <param name="vPivot">[IN] The pivot point around the rotation will be accomplished.</param>
    inline void TransformFromPivot(const QDualQuaternion &dq, const VectorType &vPivot)
    {
		VectorType vPivotAux = vPivot; // We use another local vector object as pivot
									   // because the pivot point could be one of the
									   // whole segment endpoints, and the whole endpoint
									   // is modified despite the 'const' modifier in
									   // 'const VectorType &vPivot'.
        this->A -= vPivotAux;
        this->B -= vPivotAux;

        this->A.Transform(dq);
        this->B.Transform(dq);

        this->A += vPivotAux;
        this->B += vPivotAux;
    }

    /// <summary>
    /// Transforms the resident line segment with the transformation contained in the dual quaternion provided, acting
    /// the pivot point of line segment as center of rotation. The resultant line segment is stored in the line segment provided.
    /// </summary>
    /// <param name="dq">[IN] The dual quaternion which contains the transformation.</param>
	/// <param name="vPivot">[IN] The pivot point around the rotation will be accomplished.</param>
    /// <param name="ls">[OUT] Line segment to store the transformed one.</param>
    inline void TransformFromPivot(const QDualQuaternion &dq, const VectorType &vPivot, QLineSegment3D<VectorType> &ls) const
    {
        ls = *this;
        ls.TransformFromPivot(dq, vPivot);
    }

    /// <summary>
    /// Transforms the resident line segment with a transformation of types rotation, scale, translation,
    /// generic transformation or space conversion transformation contained in the matrix provided, acting
    /// the point provided as pivot.
    /// </summary>
    /// <param name="m">[IN] The matrix which contains the transformation to be applied.</param>
    /// <param name="vPivot">[IN] A 3D or 4D point we want to act as pivot of transformation.</param>
    template <class MatrixType>
    inline void TransformFromPivot (const MatrixType &m, const VectorType &vPivot)
    {
        this->A -= vPivot;
        this->B -= vPivot;

        this->A.Transform(m);
        this->B.Transform(m);

        this->A += vPivot;
        this->B += vPivot;
    }

    /// <summary>
    /// Transforms the resident line segment with a transformation of types rotation, scale, translation,
    /// generic transformation or space conversion transformation contained in the matrix provided, acting
    /// the point provided as pivot.
    /// The resultant line segment is stored in the line segment provided.
    /// </summary>
    /// <param name="m">[IN] The matrix which contains the transformation to be applied.</param>
    /// <param name="vPivot">[IN] A 3D or 4D point we want to act as pivot of transformation.</param>
    /// <param name="ls">[OUT] Line segment to store the transformed one.</param>
    template <class MatrixType>
    inline void TransformFromPivot (const MatrixType &m, const VectorType &vPivot, QBaseLineSegment<VectorType> &ls) const
    {
        ls = *this;
        reinterpret_cast<QLineSegment3D<VectorType> &> (ls).TransformFromPivot(m, vPivot);
    }

    /// <summary>
    /// Checks the relation between resident line segment and the provided plane.
    /// Since a plane divides space into two parts, we can check if the "distances" (allowing distances having sign) from
    /// the plane to both end points of line segment are 0, or have diferent sign, in which case the segment crosses the plane.
    /// If distances from plane to both end points have the same sign, all line segment is in the same
    /// side of the space, and they haven't a common point.
    ///
    /// </summary>
    /// <remarks>
    /// Note that if only one end point of the resident line segment lies on the plane, we consider that it is
    /// in one of the sides in which the plane divides the space.
    /// </remarks>
    /// <param name="p">[IN] The plane we want check the relation with resident line segment.</param>
    /// <returns>
    /// An integer value like follows:
    ///     0 (Contained): All the line segment lies on plane.
    ///     1 (PositiveSide): The line segment is fully contained in the positive side of the space defined by the plane.
    ///     2 (NegativeSide): The line segment is fully contained in the negative side of the space defined by the plane.
    ///     3 (BothSides): One end point of the line segment is in the positive side and the other is in the negative one.
    /// We consider "positive part of the space" the locus of points which verifies \f$ Ax + By + Cz + D > 0 \f$.
    /// </returns>
    EQSpaceRelation SpaceRelation(const QBasePlane &p)
    {
        const float_q &distA = p.a * this->A.x + p.b * this->A.y + p.c * this->A.z + p.d;
        const float_q &distB = p.a * this->B.x + p.b * this->B.y + p.c * this->B.z + p.d;

        if (QFloat::IsZero(distA) && QFloat::IsZero(distB))
            return EQSpaceRelation::E_Contained;
        else if ( QFloat::IsGreaterOrEquals(distA, QFloat::_0) && QFloat::IsGreaterOrEquals(distB, QFloat::_0) )
            return EQSpaceRelation::E_PositiveSide;
        else if ( QFloat::IsLowerOrEquals(distA, QFloat::_0) && QFloat::IsLowerOrEquals(distB, QFloat::_0) )
            return EQSpaceRelation::E_NegativeSide;
        else
            return EQSpaceRelation::E_BothSides;
    }

protected:

    // [TODO] jwladi: This method will be substituted by a constructor of QPlane;
    // Constructs a plane from three (different) points.
    template <class VectorTypeParam>
    inline void PlaneFrom3Points(const VectorTypeParam &vA, const VectorTypeParam &vB, const VectorTypeParam &vC,
        QBasePlane &pOut) const
    {
        // Creates two vectors, to obtain the normal vector of the plane via cross product
        VectorTypeParam vAux1(vB - vA);
        VectorTypeParam vAux2(vC - vA);

        vAux1.CrossProduct(vAux2);

        QE_ASSERT (vAux1 != VectorTypeParam::ZeroVector);

        // Plane equation
        pOut = QBasePlane(vAux1.x, vAux1.y, vAux1.z, -(vAux1.DotProduct(vA)));
    }

    // Calculates if two points are in the same side of a line segment. Can be used to know
    // if a point is inside or outside a plane convex polygon, being point and polygon coplanars.
    // The point must be in the same side of every polygon edge than any
    // other polygon vertex not included in the analized edge.
    template <class VectorTypeParam>
    inline bool PointsInSameSideOfLine(const VectorTypeParam &vP1, const VectorTypeParam &vP2,
        const VectorTypeParam &vLine1, const VectorTypeParam &vLine2) const
    {
        VectorTypeParam vLine(vLine2 - vLine1);
        VectorTypeParam vCP1;
        VectorTypeParam vCP2;

        vLine.CrossProduct(vP1 - vLine1, vCP1);
        vLine.CrossProduct(vP2 - vLine1, vCP2);

        if ( QFloat::IsLessThan(vCP1.DotProduct(vCP2), QFloat::_0) )
            return false;
        else
            return true;
    }

    // Calculates if two points are in the same side of a plane defined by 3 points.
    template <class VectorTypeParam>
    inline bool PointsInSameSideOfPlane(const VectorTypeParam &vP1, const VectorTypeParam &vP2,
        const VectorTypeParam &vA, const VectorTypeParam &vB, const VectorTypeParam &vC) const
    {
        QBasePlane p;

        PlaneFrom3Points(vA, vB, vC, p);

        const float_q &distP1 = p.a * vP1.x + p.b * vP1.y + p.c * vP1.z + p.d;
        const float_q &distP2 = p.a * vP2.x + p.b * vP2.y + p.c * vP2.z + p.d;

        if ( QFloat::IsGreaterThan(distP1 * distP2, QFloat::_0) )
            return true;
        else
            return false;
    }

    // [TODO] jwladi: it must be convenient to implement this method for QBaseQuadrilateral
    // Checks if a segment intersects a cuadrilateral. It's supossed that A, B, C, D are consecutive
    // vertices of a cuadrilateral.
    template <class VectorTypeParam>
    bool CuadrilateralIntersection(const QLineSegment3D<VectorTypeParam> &ls,
        const VectorTypeParam &vA, const VectorTypeParam &vB, const VectorTypeParam &vC, const VectorTypeParam &vD) const
    {
        // Plane equation
        QBasePlane pAux;
        PlaneFrom3Points(vA, vB, vC, pAux);

        // Line Segment don't intersects the cuadrilateral plane.
        if (!ls.Intersection(pAux))
            return false;

        // If both end points satisfy plane equation, the line segment lies on plane
        const float_q &fDot1 = pAux.a * ls.B.x + pAux.b * ls.B.y + pAux.c * ls.B.z + pAux.d;
        const float_q &fDot2 = pAux.a * ls.A.x + pAux.b * ls.A.y + pAux.c * ls.A.z + pAux.d;

        if (QFloat::IsZero(fDot1) && QFloat::IsZero(fDot2))
        {
            // Both cuadrilateral and line segment are coplanar. If the line segment
            // intersects one of the edges of the cuadrilateral, then the line segment intersects the cuadrilateral.
            if (ls.QLineSegment<VectorType>::Intersection(QLineSegment<VectorTypeParam> (vA, vB)) ||
                ls.QLineSegment<VectorType>::Intersection(QLineSegment<VectorTypeParam> (vB, vC)) ||
                ls.QLineSegment<VectorType>::Intersection(QLineSegment<VectorTypeParam> (vC, vD)) ||
                ls.QLineSegment<VectorType>::Intersection(QLineSegment<VectorTypeParam> (vD, vA)))
                return true;

            // Now we check if segment is fully contained in the cuadrilateral
            // We only check "A" end point, since if "A" is inside, "B" must be inside too (see previus test).
            else if (!PointsInSameSideOfLine(ls.A, vC, vA, vB) ||
                !PointsInSameSideOfLine(ls.A, vA, vB, vC) ||
                !PointsInSameSideOfLine(ls.A, vA, vC, vD) ||
                !PointsInSameSideOfLine(ls.A, vC, vD, vA))
                return false;
            else
                return true;
        }

        QE_ASSERT(QFloat::IsNotZero(fDot2 - fDot1));

        // The point which satisfies both line and plane equations.
        VectorTypeParam vAux = ls.A + (ls.B - ls.A) * fDot2/(fDot2 - fDot1);

        // For every edge, it tests if the intersection point is in the same side of each edge
        // than any other vextex (not of the edge). If it does, then it's inside the cuadrilateral,
        // otherwise it's outside.
        if (!PointsInSameSideOfLine(vAux, vC, vA, vB) ||
            !PointsInSameSideOfLine(vAux, vA, vB, vC) ||
            !PointsInSameSideOfLine(vAux, vA, vC, vD) ||
            !PointsInSameSideOfLine(vAux, vC, vD, vA))
            return false;
        else
            return true;
    }

    // Changes the coordinate system of a point to other system based in three normal
    // vectors and a point which is the origin.
    template <class VectorTypeParam>
    inline void ChangeCoordSys(const VectorTypeParam &vPoint, VectorTypeParam &vNewPoint,
        const VectorTypeParam &vX, const VectorTypeParam &vY, const VectorTypeParam &vZ,
        const VectorTypeParam &vO) const
    {
        vNewPoint.x = (vPoint.x-vO.x)*vX.x + (vPoint.y-vO.y)*vX.y + (vPoint.z-vO.z)*vX.z;
        vNewPoint.y = (vPoint.x-vO.x)*vY.x + (vPoint.y-vO.y)*vY.y + (vPoint.z-vO.z)*vY.z;
        vNewPoint.z = (vPoint.x-vO.x)*vZ.x + (vPoint.y-vO.y)*vZ.y + (vPoint.z-vO.z)*vZ.z;
    }

};

//##################=======================================================##################
//##################			 ____________________________			   ##################
//##################			|							 |			   ##################
//##################		    |    CONSTANTS DEFINITIONS	 |			   ##################
//##################		   /|							 |\			   ##################
//##################			 \/\/\/\/\/\/\/\/\/\/\/\/\/\/			   ##################
//##################													   ##################
//##################=======================================================##################

template <class VectorType>
const QLineSegment3D<VectorType> QLineSegment3D<VectorType>::UnitLine(VectorType::ZeroVector, VectorType::UnitVectorX);

template <class VectorType>
const QLineSegment3D<VectorType> QLineSegment3D<VectorType>::LineZero(VectorType::ZeroVector, VectorType::ZeroVector);

} //namespace Math
} //namespace Tools
} //namespace QuimeraEngine
} //namespace Kinesis

#endif // __QLINESEGMENT3D__
