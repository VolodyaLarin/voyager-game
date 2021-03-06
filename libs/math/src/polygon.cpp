#include <debug/exception.hpp>

#include "polygon.hpp"
#include "math.hpp"

namespace math {


//  --------------------------------Position-----------------------------------


PositionateObject::PositionateObject()
        : _pos(0, 0) {}

PositionateObject::PositionateObject(math::coords_t pos)
        : _pos(pos) {}

void PositionateObject::set_pos(math::coords_t pos) {
    _pos = pos;
}

math::coords_t PositionateObject::get_pos() const noexcept {
    return _pos;
}


//  -------------------------------RotateObject-------------------------------


RotateObject::RotateObject()
        : _angle(0) {}

RotateObject::RotateObject(math::decimal_t angle)
        : _angle(angle) {}

void RotateObject::set_rotation(math::decimal_t angle) {
    _angle = angle;
}

void RotateObject::rotate(math::decimal_t offset_angle) {
    _angle += offset_angle;
}

math::decimal_t RotateObject::get_rotation() const noexcept {
    return _angle;
}


//  -------------------------------Polygon-----------------------------------


Polygon::Polygon(math::coords_t pos, math::decimal_t angle)
        : RotateObject(angle)
          , PositionateObject(pos) {}


//  --------------------------RectanglePolygon-------------------------------


RectanglePolygon::RectanglePolygon()
        : Polygon()
          , _height(0)
          , _width(0) {}

RectanglePolygon::RectanglePolygon(math::coords_t pos, math::decimal_t height,
                                   math::decimal_t width, math::decimal_t angle)
        : Polygon(pos, angle)
          , _height(height)
          , _width(width) {}

void RectanglePolygon::resize(math::decimal_t height, math::decimal_t width) {
    _height = height;
    _width = width;
}

void RectanglePolygon::scale(math::decimal_t scale) {
    if (Utilits::is_null(scale)) {
        throw debug::MathException("Unavailable zero scale");
    }

    _height *= scale;
    _width *= scale;
}

bool RectanglePolygon::is_point_in_polygon(math::coords_t point) const {
    math::coords_t left_top = _pos + coords_t(-_width / 2, _height / 2);
    math::coords_t left_bottom = _pos + coords_t(-_width / 2, -_height / 2);
    math::coords_t right_top = _pos + coords_t(_width / 2, _height / 2);
    math::coords_t right_bottom = _pos + coords_t(_width / 2, -_height / 2);

    GeometryFunction geometry;

    left_top = geometry.rotate_point(left_top, _angle, _pos);
    left_bottom = geometry.rotate_point(left_bottom, _angle, _pos);
    right_top = geometry.rotate_point(right_top, _angle, _pos);
    right_bottom = geometry.rotate_point(right_bottom, _angle, _pos);

    math::Vector2d top_line(right_top - left_top);
    math::Vector2d left_line(left_top - left_bottom);
    math::Vector2d right_line(right_bottom - right_top);
    math::Vector2d bottom_line(left_bottom - right_bottom);

    GeometryFunction::point_relative under_top_line
            = geometry.point_relative_line(top_line, left_top, point);
    GeometryFunction::point_relative on_right_left_line
            = geometry.point_relative_line(left_line, left_bottom, point);
    GeometryFunction::point_relative leftward_right_line
            = geometry.point_relative_line(right_line, right_top, point);
    GeometryFunction::point_relative over_bottom_line
            = geometry.point_relative_line(bottom_line, right_bottom, point);

    return under_top_line == GeometryFunction::point_relative::at_right
           && on_right_left_line == GeometryFunction::point_relative::at_right
           && leftward_right_line == GeometryFunction::point_relative::at_right
           && over_bottom_line == GeometryFunction::point_relative::at_right;
}

bool RectanglePolygon::intersects(const IIntresectable &object) const {
    math::coords_t left_top = _pos + coords_t(-_width / 2, _height / 2);
    math::coords_t left_bottom = _pos + coords_t(-_width / 2, -_height / 2);
    math::coords_t right_top = _pos + coords_t(_width / 2, _height / 2);
    math::coords_t right_bottom = _pos + coords_t(_width / 2, -_height / 2);

    GeometryFunction geometry;

    left_top = geometry.rotate_point(left_top, _angle, _pos);
    left_bottom = geometry.rotate_point(left_bottom, _angle, _pos);
    right_top = geometry.rotate_point(right_top, _angle, _pos);
    right_bottom = geometry.rotate_point(right_bottom, _angle, _pos);

    return object.is_point_in_polygon(left_top) ||
           object.is_point_in_polygon(left_bottom) ||
           object.is_point_in_polygon(right_top) ||
           object.is_point_in_polygon(right_bottom);
}

math::decimal_t RectanglePolygon::get_height() const noexcept {
    return _height;
}

math::decimal_t RectanglePolygon::get_width() const noexcept {
    return _width;
}

Rect RectanglePolygon::get_bounders_rect() const {
    math::coords_t left_top = _pos + coords_t(-_width / 2, _height / 2);
    math::coords_t right_bottom = _pos + coords_t(_width / 2, -_height / 2);

    GeometryFunction geometry;

    left_top = geometry.rotate_point(left_top, _angle, _pos);
    right_bottom = geometry.rotate_point(right_bottom, _angle, _pos);

    return Rect(left_top, right_bottom);
}

//  ---------------------------TrianglePolygon-------------------------------


TrianglePolygon::TrianglePolygon()
        : Polygon()
          , _height(0)
          , _width(0) {}

TrianglePolygon::TrianglePolygon(math::coords_t pos, math::decimal_t height,
                                 math::decimal_t width, math::decimal_t angle)
        : Polygon(pos, angle)
          , _height(height)
          , _width(width) {}

void TrianglePolygon::resize(math::decimal_t height, math::decimal_t width) {
    _height = height;
    _width = width;
}

void TrianglePolygon::scale(math::decimal_t scale) {
    if (Utilits::is_null(scale)) {
        throw debug::MathException("Unavailable zero scale");
    }

    _height *= scale;
    _width *= scale;
}

bool TrianglePolygon::is_point_in_polygon(math::coords_t point) const {
    math::coords_t top = _pos + coords_t(0, _height * 2 / decm(3));
    math::coords_t left = _pos + coords_t(-_width / 2, -_height * 1 / decm(3));
    math::coords_t right = _pos + coords_t(_width / 2, -_height * 1 / decm(3));

    GeometryFunction geometry;

    top = geometry.rotate_point(top, _angle, _pos);
    left = geometry.rotate_point(left, _angle, _pos);
    right = geometry.rotate_point(right, _angle, _pos);

    math::Vector2d left_line(top - left);
    math::Vector2d right_line(right - top);
    math::Vector2d bottom_line(left - right);

    GeometryFunction::point_relative on_right_left_line
            = geometry.point_relative_line(left_line, left, point);
    GeometryFunction::point_relative leftward_right_line
            = geometry.point_relative_line(right_line, top, point);
    GeometryFunction::point_relative over_bottom_line
            = geometry.point_relative_line(bottom_line, right, point);

    return on_right_left_line == GeometryFunction::point_relative::at_right
           && leftward_right_line == GeometryFunction::point_relative::at_right
           && over_bottom_line == GeometryFunction::point_relative::at_right;
}

bool TrianglePolygon::intersects(const IIntresectable &object) const {
    math::coords_t top = _pos + coords_t(0, _height * 2 / decm(3));
    math::coords_t left = _pos + coords_t(-_width / 2, -_height * 1 / decm(3));
    math::coords_t right = _pos + coords_t(_width / 2, -_height * 1 / decm(3));

    GeometryFunction geometry;

    top = geometry.rotate_point(top, _angle, _pos);
    left = geometry.rotate_point(left, _angle, _pos);
    right = geometry.rotate_point(right, _angle, _pos);

    return object.is_point_in_polygon(top) ||
           object.is_point_in_polygon(left) ||
           object.is_point_in_polygon(right);
}

math::decimal_t TrianglePolygon::get_height() const noexcept {
    return _height;
}

math::decimal_t TrianglePolygon::get_width() const noexcept {
    return _width;
}

Rect TrianglePolygon::get_bounders_rect() const {
    math::coords_t left_up =
            _pos + coords_t(-_width / 2, _height * 2 / decm(3));
    math::coords_t right_down =
            _pos + coords_t(_width / 2, -_height * 1 / decm(3));

    GeometryFunction geometry;

    left_up = geometry.rotate_point(left_up, _angle, _pos);
    right_down = geometry.rotate_point(right_down, _angle, _pos);
    return Rect(left_up, right_down);
}


//  ---------------------------CirclePolygon---------------------------------


CirclePolygon::CirclePolygon()
        : Polygon()
          , _radius(0) {}

CirclePolygon::CirclePolygon(math::coords_t pos, math::decimal_t radius,
                             math::decimal_t angle)
        : Polygon(pos, angle)
          , _radius(radius) {}

void CirclePolygon::resize(math::decimal_t radius) {
    _radius = radius;
}

void CirclePolygon::scale(math::decimal_t scale) {
    if (Utilits::is_null(scale)) {
        throw debug::MathException("Unavailable zero scale");
    }

    _radius *= scale;
}

bool CirclePolygon::is_point_in_polygon(math::coords_t point) const {
    return Vector2d(point - _pos).sqr_len() <= _radius * _radius;
}

static constexpr size_t sides_in_circle = 30;

bool CirclePolygon::intersects(const IIntresectable &object) const {
    math::decimal_t angle = decm(360) / (decimal_t) sides_in_circle;

    coords_t point = {_pos.x, _pos.y + _radius};

    GeometryFunction geometry;
    for (size_t i = 0; i < sides_in_circle; ++i) {
        point = geometry.rotate_point(point, i == 0 ? 0 : angle, _pos);

        if (object.is_point_in_polygon(point)) {
            return true;
        }
    }
    return false;
}

math::decimal_t CirclePolygon::get_radius() const noexcept {
    return _radius;
}

Rect CirclePolygon::get_bounders_rect() const {
    return Rect{{_pos.x - _radius, _pos.y + _radius},
                {_pos.x + _radius, _pos.y - _radius}};
}
}  // namespace math
