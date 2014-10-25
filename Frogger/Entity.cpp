#include "stdafx.h"
#include "Entity.h"


Entity::Entity()
{
	position = new Vector3D();
}


Entity::~Entity()
{
}

Vector3D * Entity::getPosition(){

	return position;
}

void Entity::setPosition(float x, float y, float z){

	position->set(x, y, z);
}

void Entity::setPosition(Vector3D * vector){

	position = vector;
}