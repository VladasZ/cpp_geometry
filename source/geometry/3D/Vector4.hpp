//
//  Vector4.hpp
//  geometry
//
//  Created by Vladas Zakrevskis on 1/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vector3.hpp"


namespace gm {

    class Vector4 {

    public:

        Float x = 0;
        Float y = 0;
        Float z = 0;
        Float w = 1;

        Vector4() = default;
        Vector4(Float x, Float y, Float z, Float w);

        const Vector3& vector3() const;

        Float length() const;

        Vector4& normalize();

        template<class T>
        void append_to_container(T& container) {
            container.push_back(x);
            container.push_back(y);
            container.push_back(z);
            container.push_back(w);
        }

        Vector4& operator *= (Float);
        Vector4& operator /= (Float);

        Vector4 operator * (const Vector4&) const;

		Vector4 change_hand() const;
		Vector4 flip_height() const;

        std::string to_string() const;

        struct transform {
            static Vector4 quaternion_rotating_x(Float);
            static Vector4 quaternion_rotating_y(Float);
            static Vector4 quaternion_rotating_z(Float);
        };


		static Vector4 from_json(const std::string&);
		std::string to_json() const;

    };

}
