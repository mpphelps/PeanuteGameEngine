﻿#include "camera.h"

#define LOG(x) std::cout << x << std::endl;

namespace peanut {
	namespace graphics {
		Camera::Camera()
		= default;

		Camera::Camera(glm::vec3 position)
		{
			cameraPos = position;
		}

		Camera::~Camera()
		{

		}

		void Camera::ProcessInput(int key)
		{
			//std::cout << "Processing input: " << key << std::endl;
			const float cameraSpeed = 0.10f;
			switch (key)
			{
			case GLFW_KEY_W:
				std::cout << "W Key Pressed" << std::endl;
				cameraPos += cameraSpeed * cameraFront;
				break;
			case GLFW_KEY_S:
				std::cout << "S Key Pressed" << std::endl;
				cameraPos -= cameraSpeed * cameraFront;
				break;
			case GLFW_KEY_A:
				std::cout << "A Key Pressed" << std::endl;
				cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
				break;
			case GLFW_KEY_D:
				std::cout << "D Key Pressed" << std::endl;
				cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
				break;
			}
		}

		glm::mat4 Camera::View()
		{
			return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		}
	}
}
