#ifndef HEALTHPOINTS_H
#define HEALTHPOINTS_H

#include <iostream>

class HealthPoints {
    public:
    /*
    * C'tor of HealthPoints:
    *
    * @param maxHP- the maximum HP amount an instance can have.
    * @result
    *      An instance of HealthPoints.
     *
     * NOTICE: WILL THROW  InvalidArgument() EXCEPTION IF PARAMETER RECEIVED IS 0 OR NEGATIVE
   */
    HealthPoints(int maxHP=DEFAULT_MAX_HP);



    /*
    * copy C'tor of HealthPoints:
    *
    * @param objectToCopy- the HP instance we want to duplicate.
    * @result
    *      An instance of HealthPoints.
   */
    HealthPoints(const HealthPoints& objectToCopy);



    /*
     * D'tor of HealthPoints
     *
     * @result
     *      The instance of HealthPoints being destroyed
    */
    ~HealthPoints() =default;




    /*
     * Overloading operator +=
     *
     * @param addPoints- the number we want to add to our current healthPoints.
     * @return
     *      A reference to current healthPoints instance
    */
    HealthPoints& operator+=(int addPoints);



    /*
     * Overloading operator -=
     *
     * @param removePoints- the number we want to subtract from our current healthPoints.
     * @return
     *      A reference to current healthPoints instance
    */
    HealthPoints& operator-=(int removePoints);



    /*
     * Overloading operator ==
     *
     * @param first - reference to the first HealthPoints instance to compare.
     * @param second - reference to the second HealthPoints instance to compare.
     * @return
     *      true if both of healthPoints objects currently have the same amount of points.
     *      false otherwise.
    */
    friend bool operator ==(const HealthPoints& first, const HealthPoints& second);



    /*
     * Overloading operator >
     *
     * @param first - reference to the first HealthPoints instance to compare.
     * @param second - reference to the second HealthPoints instance to compare.
     * @return
     *      true if currently first has more points than second .
     *      false otherwise.
    */
    friend bool operator >(const HealthPoints& first, const HealthPoints& second);



    /*
     * EXCEPTION TO THROW IF INVALID ARGUMENT WAS RECEIVED
     */
    class InvalidArgument{};


    int getCurrentPoints() const;



    private:
    int m_currentPoints;
    int m_maxPoints;
    static const int DEFAULT_MAX_HP=100;
    static const int NO_POINTS=0;

};



/*
 * Overloading operator !=
 *
 * @param first - reference to the first HealthPoints instance to compare.
 * @param second - reference to the second HealthPoints instance to compare.
 * @return
 *      true if the two healthPoints objects currently don't have the same amount of points.
 *      false otherwise.
 */
bool operator !=(const HealthPoints& first, const HealthPoints& second);



/*
 * Overloading operator <
 *
 * @param first - reference to the first HealthPoints instance to compare.
 * @param second - reference to the second HealthPoints instance to compare.
 * @return
 *      true if currently second has more points than first .
 *      false otherwise.
 */
bool operator <(const HealthPoints& first, const HealthPoints& second);



/*
 * Overloading operator <=
 *
 * @param first - reference to the first HealthPoints instance to compare.
 * @param second - reference to the second HealthPoints instance to compare.
 * @return
 *      true if currently second has more points than first or if their amount of points is equal .
 *      false otherwise.
 */
bool operator <=(const HealthPoints& first, const HealthPoints& second);



/*
 * Overloading operator >=
 *
 * @param first - reference to the first HealthPoints instance to compare.
 * @param second - reference to the second HealthPoints instance to compare.
 * @return
 *      true if currently first has more points than second or if their amount of points is equal .
 *      false otherwise.
 */
bool operator >=(const HealthPoints& first, const HealthPoints& second);



/*
 * Overloading operator +
 *
 * @param addPoints -  the number we want to add.
 * @param healthPoints - reference to the HealthPoints instance we want to add the points to.
 * @return
 *      HealthPoints object - the result of points addition
 */
HealthPoints operator+(int addPoints, const HealthPoints& healthPoints);
HealthPoints operator+(const HealthPoints& healthPoints, int addPoints);



/*
 * Overloading operator +
 *
 * @param removePoints -  the number we want to subtract.
 * @param healthPoints - reference to the HealthPoints instance we want to subtract the points from.
 * @return
 *      HealthPoints object - the result of points subtraction.
 */
HealthPoints operator-(int removePoints, const HealthPoints& healthPoints);
HealthPoints operator-(const HealthPoints& healthPoints, int removePoints);

#endif //HEALTHPOINTS_H
