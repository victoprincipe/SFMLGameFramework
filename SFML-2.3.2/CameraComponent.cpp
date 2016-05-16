#include "CameraComponent.h"

void CameraComponent::setZoom(float zoom)
{
	this->camera.zoom(zoom);
}

void CameraComponent::setRotation(float rotation)
{
	this->camera.setRotation(rotation);
}

void CameraComponent::rotateCamera(float rotation)
{
	this->camera.rotate(rotation);
}

void CameraComponent::move(float x, float y)
{
	this->camera.move(x, y);
}

void CameraComponent::Start(GameEngine *game)
{
	this->camera = game->get_window_()->getDefaultView();
}

void CameraComponent::Update(GameEngine *game)
{
	game->get_window_()->setView(this->camera);
}
