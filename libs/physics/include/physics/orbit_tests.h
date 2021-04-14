#pragma once

#include <umath.h>
#include <physics/engine.h>
#include <physics/interface.h>

namespace physics {

class Orbit {
  public:
    struct orbit_properties_t {
        math::coords_t variables;
        math::coords_t pos;
        bool is_ellipse;
    };


    Orbit() = delete;

    explicit Orbit(Engine& physical_engine);

    explicit Orbit(orbit_properties_t orbit_properties);

    math::coords_t get_current_pos(IInfluenceableByForce& object, Engine& physical_engine);

    orbit_properties_t get_orbit_properties();

    void move_by_angle(math::decimal_t angle);

  private:
    math::decimal_t _major_axis;
    math::decimal_t _eccentricity;
    math::decimal_t _inclination;
    math::decimal_t _lgitude_ascend_node;
    math::decimal_t _lgitude_of_periapsis;
    math::decimal_t _mean_lgitude;
    bool _use_kepler;
};

}