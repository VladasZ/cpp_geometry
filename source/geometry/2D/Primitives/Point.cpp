//
//  Point.cpp
//  geometry
//
//  Created by Vladas Zakrevskis on 8/16/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include <cmath>

#include "Point.hpp"

using namespace gm;

const Point Point::zero;

Point::Point(Direction direction, float length) {
    switch (direction) {
        case Direction::Left:  x = -length; y =  0;      break;
        case Direction::Right: x =  length; y =  0;      break;
        case Direction::Up:    x =  0;      y = -length; break;
        case Direction::Down:  x =  0;      y =  length; break;
    }
}

float Point::angle() const {
    return std::atan2(y, x);
}

bool Point::is_zero() const {
	return x == 0 && y == 0;
}

float Point::length() const {
    return static_cast<float>(std::sqrt(x * x + y * y));
}

void Point::invert() {
	x = -x;
	y = -y;
}

void Point::invert_x() {
	x = -x;
}

void Point::invert_y() {
	y = -y;
}

Point Point::with_length(float length) const {
    const auto ratio = length / this->length();
	return { x * ratio, y * ratio };
}

void Point::set_length(float length) {
	const auto ratio = length / this->length();
	x *= ratio;
	y *= ratio;
}

void Point::add_length(float value) {
	set_length(length() + value);
}

void Point::trim(float max_lenght) {
    if (length() < max_lenght) {
        return;
    }
    set_length(max_lenght);
}

Point Point::trimmed(float max_length) const {
    Point result = *this;
    result.trim(max_length);
    return result;
}

Direction Point::directionX() const {
    return x > 0 ? Direction::Right : Direction::Left;
}

float Point::distanceTo(const Point& p) const {
    const auto _x = x - p.x;
    const auto _y = y - p.y;
    return std::sqrt(_x * _x + _y * _y);
}

const float* Point::data() const {
    return &x;
}

Point Point::operator + (const Point &point) const {
	return { x + point.x, y + point.y };
}

void Point::operator += (const Point &point) {
    x += point.x;
    y += point.y;
}

Point Point::operator - (const Point &point) const {
	return { x - point.x, y - point.y };
}

void Point::operator -= (const Point &point) {
    x -= point.x;
    y -= point.y;
}

Point Point::operator * (float value) const {
	return { x * value, y * value };
}

void Point::operator *= (float value) {
    x *= value;
    y *= value;
}

Point Point::operator / (float value) const {
    return { x / value, y / value };
}

void Point::operator /= (float value) {
    x /= value;
    y /= value;
}

std::string Point::to_string() const {
    return std::string() + "x: " + std::to_string(x) + " y: " + std::to_string(y);
}

Point Point::on_circle(float radius, float angle, const Point& center) {
    return { (radius / 2) * std::cos(angle) + center.x, (radius / 2) * std::sin(angle) + center.y };
}
