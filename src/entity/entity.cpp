//
// Created by mat on 5/19/2024.
//

#include "entity.h"

Entity::Entity(float x, float y, float width, float height) {
    m_PositionX = x;
    m_PositionY = y;
    m_Width = width;
    m_Height = height;
}

Entity::~Entity() {
    for (const auto &item: m_Components) {
        delete item;
    }
    m_Components.clear();
}

void Entity::AddComponent(Component *component) {
    component->m_EntityPositionX = &m_PositionX;
    component->m_EntityPositionY = &m_PositionY;

    component->m_EntityWidth = &m_Width;
    component->m_EntityHeight = &m_Height;

    component->m_Screen = m_Screen;
    component->m_Entity = this;

    m_Components.push_back(component);
}

void Entity::OnUpdate(float sc_width, float sc_height, float frame_time) {
    for (const auto &component: m_Components) {
        component->OnUpdate(sc_width, sc_height, frame_time);
    }
}
