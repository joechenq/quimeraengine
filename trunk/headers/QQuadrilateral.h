// [TERMS&CONDITIONS]

#ifndef __QQUADRILATERAL__
#define __QQUADRILATERAL__

#include "QBaseQuadrilateral.h"
#include "QLineSegment2D.h"
#include "QVector2.h"
#include "QAngle.h"

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
/// Class which represents a quadrilateral in 2D space. Methods in this class are related to transformations in 2D.
/// The quadrilateral is defined by four consecutive vertices A, B, C, D, being the edges AB, BC, CD and DA segments.
/// </summary>
class QDllExport QQuadrilateral : public QBaseQuadrilateral
{
    // CONSTANTS
    // ---------------
public:

    /// <summary>
    /// Stores a square with center in coordinate origin and unitary length edges which are parallels to axes.
    /// </summary>
    static const QQuadrilateral UnitSquare;

	// CONSTRUCTORS
	// ---------------
public:

    /// <summary>
    /// Default constructor.
    /// </summary>
    inline QQuadrilateral() { }

    /// <summary>
    /// Constructor from four 2D vectors.
    /// </summary>
    /// <remarks>
    /// Note that the four vertices must be consecutive, so that the egdes of the quadrilateral must be AB, BC, CD and DA.
    /// </remarks>
    /// <param name="vA">[IN] The 2D vector which defines A vertex.</param>
    /// <param name="vB">[IN] The 2D vector which defines B vertex.</param>
    /// <param name="vC">[IN] The 2D vector which defines C vertex.</param>
    /// <param name="vD">[IN] The 2D vector which defines D vertex.</param>
    inline QQuadrilateral(const QVector2 &vA, const QVector2 &vB,
                          const QVector2 &vC, const QVector2 &vD ) : QBaseQuadrilateral(vA, vB, vC, vD) { }


    // METHODS
    // ---------------
public:

    //Unary operators

    /// <summary>
    /// Assign operator. Assigns the provided quadrilateral to the resident quadrilateral.
    /// </summary>
    /// <param name="q">[IN] The quadrilateral to be assigned.</param>
    /// <returns>
    /// A reference to the modified quadrilateral.
    /// </returns>
    inline QQuadrilateral& operator=(const QBaseQuadrilateral &q)
    {
        QBaseQuadrilateral::operator=(q);
        return *this;
    }

    //Methods

    /// <summary>
    /// Checks if a given point is inside quadrilateral or not. This is made in a different way depending on the
    /// kind of quadrilateral we have (crossed, standard convex or concave).
    /// </summary>
    /// <param name="v">[IN] The point we want to check.</param>
    /// <returns>
    /// True if the given point is inside quadrilateral, false otherwise.
    /// The quadrilateral perimeter is considered inside.
    /// </returns>
    bool Contains (const QBaseVector2 &v) const;

    /// <summary>
    /// Checks if the resident quadrilateral intersects with the provided one. To do that, it checks the intersection
    /// with the four segments of the resident quadrilateral with the provided quadrilateral. Additionally, it checks if
    /// one arbitrary edge of provided quadrilateral intersects with the resident one, to check the case where the provided
    /// quadrilateral is included in the resident one.
    /// </summary>
    /// <param name="q">[IN] The quadrilateral we want to check the intersection with resident one.</param>
    /// <returns>
    /// True if the given quadrilateral intersects with resident quadrilateral, false otherwise.
    /// </returns>
    inline bool Intersection (const QBaseQuadrilateral &q) const
    {

        // Checks if any edge of resident quadrilateral intersects with q
        QLineSegment2D ls1(this->A, this->B);
        if ( ls1.Intersection(q) )
            return true;

        ls1 = QLineSegment2D(this->B, this->C);
        if ( ls1.Intersection(q) )
            return true;

        ls1 = QLineSegment2D(this->C, this->D);
        if ( ls1.Intersection(q) )
            return true;

        ls1 = QLineSegment2D(this->D, this->A);
        if ( ls1.Intersection(q) )
            return true;

        // q may be contained by resident quadrilateral, we check it.
        if ( this->Contains(q.A) )
            return true;

        return false;
    }

    /// <summary>
    /// Checks if the resident quadrilateral is crossed. To do that, it checks if A and D vertices are in the
    /// same side of BC segment AND C and D vertices are in the same side of AB segment, in which case the quadrilateral
    /// is not crossed.
    /// </summary>
    /// <returns>
    /// True if the resident quadrilateral is crossed, false otherwise.
    /// </returns>
    inline bool IsCrossed () const
    {
        if ( ( !PointsInSameSideOfLine(this->A, this->D, this->B, this->C) &&
               !PointsInSameSideOfLine(this->C, this->B, this->A, this->D) ) ||
             ( !PointsInSameSideOfLine(this->A, this->B, this->D, this->C) &&
               !PointsInSameSideOfLine(this->C, this->D, this->A, this->B) ) )
            return true;
        else
            return false;
    }

    /// <summary>
    /// Checks if the resident quadrilateral is convex. To do that, it checks if the quadrilateral diagonals intersects.
    /// </summary>
    /// <remarks>
    /// Crossed quadrilaterals are considered as convex. Quadrilaterals with a 180� angle are considered convex too.
    /// </remarks>
    /// <returns>
    /// True if the resident quadrilateral is convex, false otherwise.
    /// </returns>
    inline bool IsConvex () const
    {
        // [TODO] jwladi: May be it can be optimized if it is considered that most of quadrilateral are convex

        if (this->IsCrossed()) // Crossed quadrilateral diagonals don't intersects.
            return true;

        QLineSegment2D ls1(this->A, this->C);
        QLineSegment2D ls2(this->B, this->D);

        if (ls1.Intersection(ls2))
            return true;
        else
            return false;
    }

    /// <summary>
    /// Checks if the resident quadrilateral is concave.
    /// </summary>
    /// <returns>
    /// True if the resident quadrilateral is concave, false otherwise.
    /// </returns>
    inline bool IsConcave () const
    {
        return !this->IsConvex();
    }

    /// <summary>
    /// Computes the interior angle between AB and AD edges of resident quadrilateral.
    /// </summary>
    /// <returns>
    /// A floating point value which is the angle computed.
    /// </returns>
    inline float_q GetAngleA() const
    {
        const float_q &fAngle = (this->D - this->A).DotProductAngle(this->B - this->A);

        if (this->IsConcaveHere(this->A, this->B, this->D, this->C))
        {
            #if QE_CONFIG_ANGLENOTATION_DEFAULT == QE_CONFIG_ANGLENOTATION_DEGREES
                return QAngle::_360 - fAngle;
            #else
                return QAngle::_2Pi - fAngle;
            #endif
        }
        else
            return fAngle;
    }

    /// <summary>
    /// Computes the interior angle between BC and BA edges of resident quadrilateral.
    /// </summary>
    /// <returns>
    /// A floating point value which is the angle computed.
    /// </returns>
    inline float_q GetAngleB() const
    {
        const float_q &fAngle = (this->A - this->B).DotProductAngle(this->C - this->B);

        if (this->IsConcaveHere(this->B, this->A, this->C, this->D))
        {
            #if QE_CONFIG_ANGLENOTATION_DEFAULT == QE_CONFIG_ANGLENOTATION_DEGREES
                return QAngle::_360 - fAngle;
            #else
                return QAngle::_2Pi - fAngle;
            #endif
        }
        else
            return fAngle;
    }

    /// <summary>
    /// Computes the angle between CD and CB edges of resident quadrilateral.
    /// </summary>
    /// <returns>
    /// A floating point value which is the angle computed.
    /// </returns>
    inline float_q GetAngleC() const
    {
        const float_q &fAngle = (this->B - this->C).DotProductAngle(this->D - this->C);

        if (this->IsConcaveHere(this->C, this->B, this->D, this->A))
        {
            #if QE_CONFIG_ANGLENOTATION_DEFAULT == QE_CONFIG_ANGLENOTATION_DEGREES
                return QAngle::_360 - fAngle;
            #else
                return QAngle::_2Pi - fAngle;
            #endif
        }
        else
            return fAngle;
    }

    /// <summary>
    /// Computes the angle between DA and DC edges of resident quadrilateral.
    /// </summary>
    /// <returns>
    /// A floating point value which is the angle computed.
    /// </returns>
    inline float_q GetAngleD() const
    {
        const float_q &fAngle = (this->C - this->D).DotProductAngle(this->A - this->D);

        if (this->IsConcaveHere(this->D, this->A, this->C, this->B))
        {
            #if QE_CONFIG_ANGLENOTATION_DEFAULT == QE_CONFIG_ANGLENOTATION_DEGREES
                return QAngle::_360 - fAngle;
            #else
                return QAngle::_2Pi - fAngle;
            #endif
        }
        else
            return fAngle;
    }

	/// <summary>
	/// This method applies to the resident quadrilateral the rotation defined by the provided angle
	/// around the coordinate axis centre.
	/// </summary>
	/// <param name="fRotationAngle">[IN] The angle of rotation.</param>
	inline void Rotate (const float_q &fRotationAngle)
	{
        QPoint::Rotate(fRotationAngle, reinterpret_cast<QVector2*> (this), 4);
	}

	/// <summary>
	/// This method applies to the resident quadrilateral the rotation defined by the provided angle
	/// around the coordinate axis centre, and stores the resulting quadrilateral in the output parameter.
	/// </summary>
	/// <param name="fRotationAngle">[IN] The angle of rotation.</param>
	/// <param name="quadOut">[OUT] It receives the resulting quadrilateral.</param>
	/// <remarks>
	/// -The quadrilateral is NOT modified, it stays the same.
	/// </remarks>
	inline void Rotate (const float_q &fRotationAngle, QBaseQuadrilateral &quadOut) const
	{
	    quadOut = *this;
	    QPoint::Rotate(fRotationAngle, reinterpret_cast<QVector2*> (&quadOut), 4);
	}

	/// <summary>
	/// This method performs a translation of the resident quadrilateral given by the provided vector.
	/// </summary>
	/// <param name="vTranslation">[IN] The 2D vector which contains the translation to be applied.</param>
    inline void Translate(const QBaseVector2 &vTranslation)
	{
	    QPoint::Translate(vTranslation, reinterpret_cast<QVector2*> (this), 4);
	}

	/// <summary>
	/// This method performs a translation of the resident quadrilateral given by the provided amounts for every axis.
	/// </summary>
	/// <param name="fTranslationX">[IN] The amount of translation to be applied in X direction.</param>
	/// <param name="fTranslationY">[IN] The amount of translation to be applied in Y direction.</param>
	inline void Translate(const float_q &fTranslationX, const float_q &fTranslationY)
	{
	    QPoint::Translate(fTranslationX, fTranslationY, reinterpret_cast<QVector2*> (this), 4);
	}

	/// <summary>
	/// This method performs a translation of the resident quadrilateral given by the provided vector, storing the
	/// resultant quadrilateral in the provided one.
	/// </summary>
	/// <param name="vTranslation">[IN] The 2D vector which contains the translation to be applied.</param>
	/// <param name="quadOut">[OUT] The translated quadrilateral.</param>
	inline void Translate(const QBaseVector2 &vTranslation, QBaseQuadrilateral &quadOut) const
	{
	    quadOut = *this;
	    QPoint::Translate(vTranslation, reinterpret_cast<QVector2*> (&quadOut), 4);
	}

	/// <summary>
	/// This method performs a translation of the resident quadrilateral given by the provided amounts for every axis, storing the
	/// resultant vector in the provided one.
	/// </summary>
	/// <param name="fTranslationX">[IN] The amount of translation to be applied in X direction.</param>
	/// <param name="fTranslationY">[IN] The amount of translation to be applied in Y direction.</param>
	/// <param name="quadOut">[OUT] The translated quadrilateral.</param>
	inline void Translate(const float_q &fTranslationX, const float_q &fTranslationY, QBaseQuadrilateral &quadOut) const
	{
	    quadOut = *this;
	    QPoint::Translate(fTranslationX, fTranslationY, reinterpret_cast<QVector2*> (&quadOut), 4);
	}

	/// <summary>
	/// This method scales the resident quadrilateral by the scale contained in the provided vector.
	/// </summary>
	/// <param name="vScale">[IN] The 2D vector which contains the scale to be applied in every axis.</param>
	inline void Scale(const QBaseVector2 &vScale)
	{
	    QPoint::Scale(vScale, reinterpret_cast<QVector2*> (this), 4);
	}

	/// <summary>
	/// This method scales the resident quadrilateral by the provided amounts for every axis.
	/// </summary>
	/// <param name="fScaleX">[IN] The scale to be applied in X direction.</param>
	/// <param name="fScaleY">[IN] The scale to be applied in Y direction.</param>
	inline void Scale(const float_q &fScaleX, const float_q &fScaleY)
	{
	     QPoint::Scale(fScaleX, fScaleY, reinterpret_cast<QVector2*> (this), 4);
	}

	/// <summary>
	/// This method scales the resident quadrilateral by the scale contained in the provided vector, storing the
	/// resultant quadrilateral in the provided one.
	/// </summary>
	/// <param name="vScale">[IN] The 2D vector which contains the scale to be applied in every axis.</param>
	/// <param name="quadOut">[OUT] The scaled quadrilateral.</param>
	inline void Scale(const QBaseVector2 &vScale, QBaseQuadrilateral &quadOut) const
	{
	    quadOut = *this;
	    QPoint::Scale(vScale, reinterpret_cast<QVector2*> (&quadOut), 4);
	}

	/// <summary>
	/// This method scales the resident quadrilateral by the provided amounts for every axis, storing the
	/// resultant quadrilateral in the provided one.
	/// </summary>
	/// <param name="fScaleX">[IN] The scale to be applied in X direction.</param>
	/// <param name="fScaleY">[IN] The scale to be applied in Y direction.</param>
	/// <param name="quadOut">[OUT] The scaled quadrilateral.</param>
	inline void Scale(const float_q &fScaleX, const float_q &fScaleY, QBaseQuadrilateral &quadOut) const
	{
	    quadOut = *this;
	    QPoint::Scale(fScaleX, fScaleY, reinterpret_cast<QVector2*> (&quadOut), 4);
	}

	/// <summary>
	/// Receives a transformation matrix and applies the transformations to the resident
	/// quadrilateral. The transformation pivot is the origin of coordinates.
	/// </summary>
	/// <param name="matrix">[IN] Matrix that contains the transformation to apply.</param>
	inline void Transform(const QTransformationMatrix3x3 &matrix)
	{
	    QPoint::Transform(matrix, reinterpret_cast<QVector2*> (this), 4);
	}

	/// <summary>
	/// Receives a transformation matrix and an output quadrilateral and applies the transformations
	/// to a copy of the resident quadrilateral, storing the results in the output parameter. The transformation pivot is the
	/// origin of coordinates.
	/// </summary>
	/// <param name="matrix">[IN] Matrix that contains the transformation to apply.</param>
	/// <param name="quadOut">[OUT] Quadrilateral that stores the result of the transformation.</param>
	inline void Transform(const QTransformationMatrix3x3 &matrix, QBaseQuadrilateral &quadOut) const
	{
	    quadOut = *this;
	    QPoint::Transform(matrix, reinterpret_cast<QVector2*> (&quadOut), 4);
	}

	/// <summary>
	/// This method transforms the 2D quadrilateral by rotating an amount defined by a rotation angle
	/// around a pivot point (as center of rotation).
	/// </summary>
	/// <param name="fRotationAngle">[IN] The angle of rotation.</param>
	/// <param name="vPivot">[IN] The pivot point which the rotation will be accomplished around.</param>
	inline void RotateWithPivot (const float_q &fRotationAngle, const QVector2 &vPivot)
	{
	    QPoint::RotateWithPivot(fRotationAngle, vPivot, reinterpret_cast<QVector2*> (this), 4);
	}

	/// <summary>
	/// This method performs a rotation of the 2D quadrilateral by rotating it an amount defined by a rotation angle
	/// around a pivot point (as center of rotation), and then storing the resulting quadrilateral in the output parameter.
	/// </summary>
	/// <param name="fRotationAngle">[IN] The angle of rotation.</param>
	/// <param name="vPivot">[IN] The pivot point which the rotation will be accomplished around.</param>
	/// <param name="quadOut">[OUT] It receives the resulting quadrilateral.</param>
	/// <remarks>
	/// The quadrilateral is NOT modified, it stays the same.
	/// </remarks>
	inline void RotateWithPivot (const float_q &fRotationAngle, const QVector2 &vPivot, QBaseQuadrilateral &quadOut) const
	{
	    quadOut = *this;
	    QPoint::RotateWithPivot(fRotationAngle, vPivot, reinterpret_cast<QVector2*> (&quadOut), 4);
	}

	/// <summary>
	/// This method scales the resident quadrilateral by the scale contained in the provided vector,
	/// acting the provided vector as pivot of scale.
	/// </summary>
	/// <param name="vScale">[IN] The 2D vector which contains the scale to be applied in every axis.</param>
	/// <param name="vPivot">[IN] The point which acts as pivot of the scale.</param>
	inline void ScaleWithPivot(const QBaseVector2 &vScale, const QBaseVector2 &vPivot)
	{
	    QPoint::ScaleWithPivot(vScale, vPivot, reinterpret_cast<QVector2*> (this), 4);
	}

	/// <summary>
	/// This method scales the resident quadrilateral by the provided amounts for every axis,
	/// acting the provided vector as pivot of scale.
	/// </summary>
	/// <param name="fScaleX">[IN] The scale to be applied in X direction.</param>
	/// <param name="fScaleY">[IN] The scale to be applied in Y direction.</param>
	/// <param name="vPivot">[IN] The point which acts as pivot of the scale.</param>
	inline void ScaleWithPivot(const float_q &fScaleX, const float_q &fScaleY, const QBaseVector2 &vPivot)
	{
	     QPoint::ScaleWithPivot(fScaleX, fScaleY, vPivot, reinterpret_cast<QVector2*> (this), 4);
	}

	/// <summary>
	/// This method scales the resident quadrilateral by the scale contained in the provided vector,
	/// acting the other provided vector as pivot of scale, and storing the resultant quadrilateral in the provided one.
	/// </summary>
	/// <param name="vScale">[IN] The 2D vector which contains the scale to be applied in every axis.</param>
	/// <param name="vPivot">[IN] The point which acts as pivot of the scale.</param>
	/// <param name="quadOut">[OUT] The scaled quadrilateral.</param>
	inline void ScaleWithPivot(const QBaseVector2 &vScale, const QBaseVector2 &vPivot, QBaseQuadrilateral &quadOut) const
	{
	    quadOut = *this;
	    QPoint::ScaleWithPivot(vScale, vPivot, reinterpret_cast<QVector2*> (&quadOut), 4);
	}

	/// <summary>
	/// This method scales the resident quadrilateral by the provided amounts for every axis,
	/// acting the provided vector as pivot of scale, storing the resultant quadrilateral in the provided one.
	/// </summary>
	/// <param name="fScaleX">[IN] The scale to be applied in X direction.</param>
	/// <param name="fScaleY">[IN] The scale to be applied in Y direction.</param>
	/// <param name="vPivot">[IN] The point which acts as pivot of the scale.</param>
	/// <param name="quadOut">[OUT] The scaled quadrilateral.</param>
	inline void ScaleWithPivot(const float_q &fScaleX, const float_q &fScaleY, const QBaseVector2 &vPivot, QBaseQuadrilateral &quadOut) const
	{
	    quadOut = *this;
	    QPoint::ScaleWithPivot(fScaleX, fScaleY, vPivot, reinterpret_cast<QVector2*> (&quadOut), 4);
	}


	/// <summary>
	/// Receives a transformation matrix and a vector (transformation pivot) and applies the transformations
	/// to the resident quadrilateral. The transformation pivot is the vector received as parameter.
	/// </summary>
	/// <param name="matrix">[IN] Matrix that contains the transformation to apply.</param>
	/// <param name="vPivot">[IN] Pivot point used for the transformation.</param>
	inline void TransformWithPivot(const QTransformationMatrix3x3 &matrix, const QBaseVector2 &vPivot)
	{
	    QPoint::TransformWithPivot(matrix, vPivot, reinterpret_cast<QVector2*> (this), 4);
	}

	/// <summary>
	/// Receives a transformation matrix, a vector (transformation pivot) and an output quadrilateral,
	/// and applies the transformations to a copy of the resident quadrilateral, storing the results in the output parameter.
	/// The transformation pivot is the vector received as parameter.
	/// </summary>
	/// <param name="matrix">[IN] Matrix that contains the transformation to apply.</param>
	/// <param name="vPivot">[IN] Pivot point used for the transformation.</param>
	/// <param name="quadOut">[OUT] Quadrilateral that stores the result of the transformation.</param>
	inline void TransformWithPivot(const QTransformationMatrix3x3 &matrix, const QBaseVector2 &vPivot, QBaseQuadrilateral &quadOut) const
	{
	    quadOut = *this;
	    QPoint::TransformWithPivot(matrix, vPivot, reinterpret_cast<QVector2*> (&quadOut), 4);
	}

    /// <summary>
    /// Converts quadrilateral into a string with the following format:
    /// "QL:A(<A.ToString>), B(<B.ToString>), C(<C.ToString>), D(<D.ToString>)".
    /// </summary>
    /// <returns>The string with the specified format.</returns>
    string_q ToString();

protected:

    // Calculates if two points are in the same side of a line segment. Used to know if
    // a quadrilateral is crossed, and to check if a point is inside a triangle.
    // In 2D case, I think is more efficient than the baricentric method.
    // It is bassed on the orientation of the two tringles compossed by
    // each point of the two we want to check and the end points of the line. If both triangles have
    // the same orientation, both points are in the same side of the line.
    bool PointsInSameSideOfLine(const QBaseVector2 &vP1, const QBaseVector2 &vP2,
                                const QBaseVector2 &vLine1, const QBaseVector2 &vLine2) const
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

    // Checks if exists concavity in the "AngleVertex" vertex.
    // AngleEndVertex1 and 2 are the two vertices in the end of the segments which defines the angle (adjacent vertices)
    bool IsConcaveHere(const QVector2 &AngleVertex, const QVector2 &AngleEndVertex1,
                   const QVector2 &AngleEndVertex2, const QVector2 &OppositeVertex) const
    {
        if (this->IsConvex())
            return false;
        else if ( !PointsInSameSideOfLine(OppositeVertex, AngleVertex, AngleEndVertex1, AngleEndVertex2) )
            return false; // The outer diagonal should not divide quadrilateral
        else
        {
            QLineSegment2D ls(AngleEndVertex1, AngleEndVertex2);

            // Angle vertex must be the closest to outer diagonal
            if ( ls.MinDistance(AngleVertex) < ls.MinDistance(OppositeVertex) )
                return true;
            else
                return false;
        }
    }
};

} //namespace Math
} //namespace Tools
} //namespace QuimeraEngine
} //namespace Kinesis

#endif // __QQUADRILATERAL__
