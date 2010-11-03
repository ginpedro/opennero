#ifndef _OPENNERO_AI_SENSOR_RAYSENSOR_H_
#define _OPENNERO_AI_SENSOR_RAYSENSOR_H_

#include "core/Common.h"
#include "ai/sensors/Sensor.h"
#include <iostream>

namespace OpenNero
{
    BOOST_SHARED_DECL(RaySensor);

    class RaySensor : public Sensor {
    private:
        //! x-direction of the ray
        double x;

        //! y-direction of the ray
        double y;

        //! z-direction of the ray
        double z;
        
        //! the radius of the ray (how far it extends)
        double radius;
        
    public:
        RaySensor() : Sensor(1,0), x(0), y(0), z(0), radius(0) {}
    
        //! Create a new RaySensor
        //! @param x x-direction of the ray
        //! @param y y-direction of the ray
        //! @param z z-direction of the ray
        //! @param radius the radius of the ray (how far it extends)
        RaySensor(double x, double y, double z, double radius, U32 types = 0);
        
        //! non-virtual destructor (final class)
        ~RaySensor();
        
        //! Get the region of interest for this sensor
        BBoxf getBoundingBox();

        //! get the minimal possible observation
        double getMin() { return 0.0; }
        
        //! get the maximum possible observation
        double getMax() { return radius; }

        //! Process an object of interest
        bool process(SimEntityPtr source, SimEntityPtr target);
        
        //! Get the value computed for this sensor
        double getObservation();

        //! Output this sensor in a human-readable form
        virtual void toStream(std::ostream& out) const;

    protected:
        
        void toXMLParams(std::ostream& out) const;

    };
}

#endif /* _OPENNERO_AI_SENSOR_RAYSENSOR_H_ */
