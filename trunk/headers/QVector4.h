// [TERMS&CONDITIONS]

#ifndef __QVECTOR4__
#define __QVECTOR4__

#include "QBaseVector4.h"
#include "QBaseVector3.h"

namespace Kinesis
{
namespace QuimeraEngine
{
namespace Tools
{
namespace Math
{

/// <summary>
/// This class implements a four components vector functionality. It inherits from QBaseVector4.
/// A vector is a geometric object that has both a magnitude (or length) and direction. 
/// It is frequently represented by a line segment with a definite direction, or graphically as an arrow, 
/// connecting an initial point A with a terminal point B. The vector is then denoted by AB with an arrow hat.
/// The fourth component may be a 0, if the vector represents a vector in 3D space, or a 1, if vector represents a point.
/// </summary>
class QDllExport QVector4 : public QBaseVector4
{
    // CONSTANTS
    // ---------------
public:

    /// <summary>
    /// Stores a vector with all components set to 0
    /// </summary>
    static const QVector4 ZeroVector;
    /// <summary>
    /// Stores a vector with all components set to 1
    /// </summary>
    static const QVector4 VectorOfOnes;
    /// <summary>
    /// Stores a unit vector in X positive direction
    /// </summary>
    static const QVector4 UnitVectorX;
    /// <summary>
    /// Stores a unit vector in Y positive direction
    /// </summary>
    static const QVector4 UnitVectorY;
    /// <summary>
    /// Stores a unit vector in Z positive direction
    /// </summary>
    static const QVector4 UnitVectorZ;
    /// <summary>
    /// Stores a unit vector in X negative direction
    /// </summary>
    static const QVector4 UnitVectorInvX;
    /// <summary>
    /// Stores a unit vector in Y negative direction
    /// </summary>
    static const QVector4 UnitVectorInvY;
    /// <summary>
    /// Stores a unit vector in Z negative direction
    /// </summary>
    static const QVector4 UnitVectorInvZ;

    // FRIENDS
    // ---------------   
public:

    /// <summary>
    /// Product by a scalar: all components are multiplied by the floating point value provided.
    /// Shortcut to multiply on the left.
    /// </summary>
    /// <param name="fValue">[IN] Multiplying floating point value.</param>
    /// <param name="v">[IN] Vector to be multiplied.</param>
    /// <returns>
    /// A vector that is the result of the product.
    /// </returns>
    friend QVector4 operator * (const float_q &fValue, const QBaseVector4 &v);

    // CONSTRUCTORS
    // ---------------   
public:

    /// <summary>
    /// Default constructor.
    /// </summary>
    inline QVector4() : QBaseVector4() { }

    /// <summary>
    /// Constructor from a QBaseVector4.
    /// </summary>
    /// <param name="v">[IN] The vector in which we want resident vector to be based.</param>
    inline explicit QVector4(const QBaseVector4 &v) : QBaseVector4(v) { }

    /// <summary>
    /// Constructor from a QBaseVector3.
    /// </summary>
    /// <param name="v">[IN] The 3D vector in which we want resident vector to be based.</param>
    inline explicit QVector4(const QBaseVector3 &v) : QBaseVector4(v.x, v.y, v.z, QFloat::_0) { }

    /// <summary>
    /// Constructor from four floating point values for each component x, y, z and w.
    /// </summary>
    /// <param name="fValueX">[IN] Floating point value for x component.</param>
    /// <param name="fValueY">[IN] Floating point value for y component.</param>
    /// <param name="fValueZ">[IN] Floating point value for z component.</param>
    /// <param name="fValueW">[IN] Floating point value for w component.</param>
    inline QVector4(const float_q &fValueX, const float_q &fValueY, const float_q &fValueZ, const float_q &fValueW) : 
        QBaseVector4(fValueX, fValueY, fValueZ, fValueW) { }

    /// <summary>
    /// Constructor from a single floating point value for all components.
    /// </summary>
    /// <param name="fValue">[IN] Floating point value for all components.</param>
    inline explicit QVector4(const float_q &fValue) : QBaseVector4(fValue) { }
    
    /// <summary>
    /// Constructor from a four component array of floating point values.
    /// </summary>
    /// <param name="pValue">[IN] Pointer to array of floating point values. It must have at least four elements.</param>
    inline explicit QVector4(const float_q *pValue) : QBaseVector4(pValue) { }

    /// <summary>
    /// Constructor from a 4x32 packed floating point value.
    /// </summary>
    /// <param name="fValue">[IN] 4x32 packed floating point value containing the four components.</param>
    inline QVector4(const vf32_q fPackComps) : QBaseVector4 (fPackComps) { }

    // METHODS
    // ---------------
public:

    // binary operators

    /// <summary>
    /// Vectors addition: it's performed component by component.
    /// </summary>
    /// <param name="v">[IN] Adding vector.</param>
    /// <returns>
    /// A vector that is the result of the addition.
    /// </returns>
    QVector4 operator + (const QBaseVector4 &v) const;

    /// <summary>
    /// Vectors subtraction: it's performed component by component.
    /// </summary>
    /// <param name="v">[IN] Subtracting vector.</param>
    /// <returns>
    /// A vector that is the result of the subtraction.
    /// </returns>
    QVector4 operator - (const QBaseVector4 &v) const;

    /// <summary>
    /// Product by a scalar: all components are multiplied by the floating point value provided.
    /// </summary>
    /// <param name="fValue">[IN] Multiplying floating point value.</param>
    /// <returns>
    /// A vector that is the result of the product.
    /// </returns>
    QVector4 operator * (const float_q &fValue) const;

    /// <summary>
    /// Product by a vector: it's performed component by component. It's not dot product or cross product!
    /// </summary>
    /// <param name="v">[IN] Multiplying vector.</param>
    /// <returns>
    /// A vector that is the result of the product.
    /// </returns>
    QVector4 operator * (const QBaseVector4 &v) const;

    /// <summary>
    /// Division by a scalar: all components are divided by the floating point value provided.
    /// </summary>
    /// <param name="fValue">[IN] Dividing floating point value.</param>
    /// <returns>
    /// A vector that is the result of the division.
    /// </returns>
    QVector4 operator / (const float_q &fValue) const;
        
    /// <summary>
    /// Division by a vector: it's performed component by component.
    /// </summary>
    /// <param name="v">[IN] Dividing vector.</param>
    /// <returns>
    /// A vector that is the result of the division.
    /// </returns>
    QVector4 operator / (const QBaseVector4 &v) const;

    /// <summary>
    /// Compares two vectors.
    /// </summary>
    /// <param name="v">[IN] Vector with which to compare.</param>
    /// <returns>
    /// True if vectors are the same, false otherwise.
    /// </returns>
    inline bool operator == (const QBaseVector4 &v) const
    {
        return QFloat::AreEquals(v.x, this->x) && QFloat::AreEquals(v.y, this->y) && 
               QFloat::AreEquals(v.z, this->z) && QFloat::AreEquals(v.w, this->w);
    }

    /// <summary>
    /// Compares two vectors.
    /// </summary>
    /// <param name="v">[IN] Vector with which to compare.</param>
    /// <returns>
    /// True if vectors are not the same, false otherwise.
    /// </returns>
    inline bool operator != (const QBaseVector4 &v) const
    {
        return QFloat::AreNotEquals(v.x, this->x) || QFloat::AreNotEquals(v.y, this->y) || 
               QFloat::AreNotEquals(v.z, this->z) || QFloat::AreNotEquals(v.w, this->w);
    }

    // assignment operators

    /// <summary>
    /// Adds a vector provided to current vector. It's performed component by component.
    /// </summary>
    /// <param name="v">[IN] Adding vector.</param>
    /// <returns>
    /// A reference to vector result of the addition.
    /// </returns>
    inline QVector4& operator += (const QBaseVector4 &v) 
    { 
        this->x += v.x;
        this->y += v.y;
        this->z += v.z; 
        this->w += v.w; 

        return *this; 
    }

    /// <summary>
    /// Subtracts a vector provided to current vector. It's performed component by component.
    /// </summary>
    /// <param name="v">[IN] Subtracting vector.</param>
    /// <returns>
    /// A reference to vector result of the subtraction.
    /// </returns>
    inline QVector4& operator -= (const QBaseVector4 &v) 
    { 
        this->x -= v.x; 
        this->y -= v.y; 
        this->z -= v.z; 
        this->w -= v.w;

        return *this; 
    }

    /// <summary>
    /// Multiplies current vector by a floating point value provided. It's performed component by component.
    /// </summary>
    /// <param name="fValue">[IN] Multiplying floating point value.</param>
    /// <returns>
    /// A reference to vector result of the product.
    /// </returns>
    inline QVector4& operator *= (const float_q &fValue) 
    { 
        this->x *= fValue; 
        this->y *= fValue; 
        this->z *= fValue; 
        this->w *= fValue; 

        return *this;
    }

    /// <summary>
    /// Multiplies current vector by a vector provided. It's performed component by component. 
    /// It's not dot product or cross product!
    /// </summary>
    /// <param name="v">[IN] Multiplying vector.</param>
    /// <returns>
    /// A reference to vector result of the product.
    /// </returns>
    inline QVector4& operator *= (const QBaseVector4 &v) 
    { 
        this->x *= v.x; 
        this->y *= v.y; 
        this->z *= v.z; 
        this->w *= v.w; 

        return *this; 
    }

    /// <summary>
    /// Divides current vector by a floating point value provided.
    /// </summary>
    /// <param name="fValue">[IN] Dividing floating point value.</param>
    /// <returns>
    /// A reference to vector result of the division.
    /// </returns>
    inline QVector4& operator /= (const float_q &fValue) 
    { 
        // Checkout to avoid division by 0
        QE_ASSERT(QFloat::IsNotZero(fValue));

        this->x /= fValue; 
        this->y /= fValue; 
        this->z /= fValue; 
        this->w /= fValue;

        return *this; 
    }
    
    /// <summary>
    /// Divides current vector by a vector provided. It's performed component by component.
    /// </summary>
    /// <param name="v">[IN] Dividing vector.</param>
    /// <returns>
    /// A reference to vector result of the division.
    /// </returns>
    inline QVector4& operator /= (const QBaseVector4 &v)
    {
        // Checkout to avoid division by 0
        QE_ASSERT (QFloat::IsNotZero(v.x) && QFloat::IsNotZero(v.y) &&
            QFloat::IsNotZero(v.z) && QFloat::IsNotZero(v.w));

        this->x /= v.x; 
        this->y /= v.y; 
        this->z /= v.z; 
        this->w /= v.w;

        return *this;
    }

    
    //Methods

    /// <summary>
    /// Calculates the length of current vector.
    /// </summary>
    /// <returns>
    /// A floating point value which is the length of the vector.
    /// </returns>
    inline float_q GetLength() const
    { 
        return sqrt(this->x*this->x + this->y*this->y + this->z*this->z + this->w*this->w); 
    }


    /// <summary>
    /// Makes current vector unitary.
    /// </summary>
    inline void Normalize() 
    {
        // Gets vector length
        float_q fLength = this->GetLength(); 

        // Checkout to avoid division by 0
        QE_ASSERT(QFloat::IsNotZero(fLength));

        //Normalize
        this->x /= fLength; 
        this->y /= fLength;    
        this->z /= fLength;
        this->w /= fLength;
    }

    /// <summary>
    /// Convert current vector in its opposite vector.
    /// </summary>
    inline void Reverse() 
    { 
        this->x = -this->x; 
        this->y = -this->y; 
        this->z = -this->z; 
        this->w = -this->w; 
    }

    /// <summary>
    /// Resets all components of current vector to 1.
    /// </summary>
    inline void ResetToOne() 
    { 
        this->x = QFloat::_1; 
        this->y = QFloat::_1; 
        this->z = QFloat::_1; 
        this->w = QFloat::_1; 
    }

    /// <summary>
    /// Resets all components of current vector to 0, except fourth component which is set to 1.
    /// </summary>
    inline void ResetToZeroPoint() 
    { 
        this->x = QFloat::_0; 
        this->y = QFloat::_0; 
        this->z = QFloat::_0; 
        this->w = QFloat::_1; 
    }

    /// <summary>
    /// Resets all components of current vector to 0.
    /// </summary>
    inline void ResetToZeroDirection() 
    { 
        this->x = QFloat::_0; 
        this->y = QFloat::_0; 
        this->z = QFloat::_0; 
        this->w = QFloat::_0; 
    }

    /// <summary>
    /// Check if all components of current vector are 0.
    /// </summary>
    /// <returns>
    /// True if all components are 0. False otherwise.
    /// </returns>
    inline bool IsZero() const
    { 
        return QFloat::IsZero(this->x) && QFloat::IsZero(this->y) && 
               QFloat::IsZero(this->z) && QFloat::IsZero(this->w); 
    }

    /// <summary>
    /// Check if all components of current vector are 1.
    /// </summary>
    /// <returns>
    /// True if all components are 1. False otherwise.
    /// </returns>
    inline bool IsVectorOfOnes() const
    { 
        return QFloat::AreEquals(this->x, QFloat::_1) && QFloat::AreEquals(this->y, QFloat::_1) && 
               QFloat::AreEquals(this->z, QFloat::_1) && QFloat::AreEquals(this->w, QFloat::_1); 
    }

    /// <summary>
    /// Calculates Dot Product by a vector provided.
    /// </summary>
    /// <param name="v">[IN] Multiplying vector.</param>
    /// <returns>
    /// A floating point value which is the result of Dot Product.
    /// </returns>
    inline float_q DotProduct(const QBaseVector4 &v) const
    { 
        return(this->x * v.x + this->y * v.y + this->z * v.z + this->w * v.w); 
    }

    /// <summary>
    /// Calculates cross product by a vector provided (left handed rules), and stores it in current vector.
    /// Due to cross product between two 4D vectors isn't defined (is a ternary operation in 4D space),
    /// we treat it as a cross product between two 3D vectors, maintaining the W component of the resident vector.
    /// </summary>
    /// <param name="v">[IN] Multiplying vector.</param>
    void CrossProduct(const QBaseVector4 &v);

    /// <summary>
    /// Makes a Linear Interpolation between current vector and other vector provided. It stores result in current vector.
    /// </summary>
    /// <param name="fFactor">[IN] A floating point value which represents how close is the result vector from the current vector (per one).</param>
    /// <param name="v">[IN] Vector with which to interpolate.</param>
    inline void Lerp(const float_q &fFactor, const QBaseVector4 &v)
    { 
        float_q fDiff = QFloat::_1 - fFactor;

        this->x = this->x * fFactor + v.x * fDiff;
        this->y = this->y * fFactor + v.y * fDiff;
        this->z = this->z * fFactor + v.z * fDiff; 
        this->w = this->w * fFactor + v.w * fDiff; 
    }

    /// <summary>
    /// Calculates the distance between two vector heads (or two points). It computes the difference of two vectors and returns its length.
    /// </summary>
    /// <param name="v">[IN] Vector we want to calculate the distance from current vector.</param>
    /// <returns>
    /// A positive floating point value containing the distance between both vectors.
    /// </returns>
    inline float_q Distance(const QBaseVector4 &v) const
    {
        return sqrt( (this->x-v.x)*(this->x-v.x) + (this->y-v.y)*(this->y-v.y) + 
                     (this->z-v.z)*(this->z-v.z) + (this->w-v.w)*(this->w-v.w) );
    }
    
    /// <summary>
    /// Converts vector into a string with the following format:
    /// "V4(x, y, z, w)".
    /// </summary>
    /// <returns>The string with the format specified.</returns>
    inline string_q ToString() const
    {
        return QE_L("V4(") + QFloat::ToString(this->x) + 
               QE_L(", ")  + QFloat::ToString(this->y) + 
               QE_L(", ")  + QFloat::ToString(this->z) +
               QE_L(", ")  + QFloat::ToString(this->w) + QE_L(")");
    }

};

} //namespace Math
} //namespace Tools
} //namespace QuimeraEngine
} //namespace Kinesis

#endif // __QVECTOR4__